#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Check if cell is valid
bool isValid(int x, int y, int rows, int cols, vector<string>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && y >= 0 && x < rows && y < cols && maze[x][y] == '*' && !visited[x][y]);
}

// BFS for shortest path
void BFS(vector<string>& maze, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<Point>> parent(rows, vector<Point>(cols, {-1, -1}));

    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    bool found = false;
    while (!q.empty()) {
        Point p = q.front(); q.pop();

        if (p.x == end.x && p.y == end.y) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (isValid(nx, ny, rows, cols, maze, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = p;
                q.push({nx, ny});
            }
        }
    }

    if (found) {
        cout << "\nShortest Path using BFS:\n";
        vector<Point> path;
        Point curr = end;
        while (!(curr.x == -1 && curr.y == -1)) {
            path.push_back(curr);
            curr = parent[curr.x][curr.y];
        }
        reverse(path.begin(), path.end());
        for (auto p : path) {
            cout << "(" << p.x << "," << p.y << ") ";
            maze[p.x][p.y] = 'o'; // mark BFS path
        }
        cout << "\n\nMaze with BFS path:\n";
        for (auto &row : maze) cout << row << "\n";
    } else {
        cout << "No path found using BFS.\n";
    }
}

// DFS for any path
bool DFSUtil(vector<string>& maze, Point curr, Point end, vector<vector<bool>>& visited, vector<Point>& path) {
    if (curr.x == end.x && curr.y == end.y) {
        path.push_back(curr);
        return true;
    }

    visited[curr.x][curr.y] = true;
    path.push_back(curr);

    for (int i = 0; i < 4; i++) {
        int nx = curr.x + dx[i];
        int ny = curr.y + dy[i];
        if (isValid(nx, ny, maze.size(), maze[0].size(), maze, visited)) {
            if (DFSUtil(maze, {nx, ny}, end, visited, path)) return true;
        }
    }

    path.pop_back();
    return false;
}

void DFS(vector<string>& maze, Point start, Point end) {
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<Point> path;
    if (DFSUtil(maze, start, end, visited, path)) {
        cout << "\nPath using DFS:\n";
        for (auto p : path) {
            cout << "(" << p.x << "," << p.y << ") ";
            maze[p.x][p.y] = 'x'; // mark DFS path
        }
        cout << "\n\nMaze with DFS path:\n";
        for (auto &row : maze) cout << row << "\n";
    } else {
        cout << "No path found using DFS.\n";
    }
}

int main() {
    ifstream file("maze.txt");
    vector<string> maze;
    string line;
    while (getline(file, line)) {
        if (!line.empty()) maze.push_back(line);
    }
    file.close();

    int rows = maze.size();
    int cols = maze[0].size();

    // Find start and end
    Point start = {-1, -1}, end = {-1, -1};
    for (int j = 0; j < cols; j++) {
        if (maze[0][j] == '*') { start = {0, j}; break; }
    }
    for (int j = cols - 1; j >= 0; j--) {
        if (maze[rows - 1][j] == '*') { end = {rows - 1, j}; break; }
    }

    if (start.x == -1 || end.x == -1) {
        cout << "Start or End point not found.\n";
        return 0;
    }

    cout << "Start: (" << start.x << "," << start.y << ")\n";
    cout << "End: (" << end.x << "," << end.y << ")\n";

    BFS(maze, start, end);

    // Reload maze for DFS
    ifstream file2("maze.txt");
    maze.clear();
    while (getline(file2, line)) {
        if (!line.empty()) maze.push_back(line);
    }
    file2.close();

    DFS(maze, start, end);

    return 0;
}
