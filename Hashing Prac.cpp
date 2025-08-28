#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

void BFS(vector<string>& maze, Point start, Point end) {
    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<Point>> parent(rows, vector<Point>(cols, {-1, -1}));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    bool found = false;
    size_t memoryUsage = sizeof(visited) + sizeof(parent) + sizeof(q); // Approximation
    size_t visitedCount = 0;

    auto startTime = high_resolution_clock::now();

    while (!q.empty()) {
        Point p = q.front(); q.pop();
        visitedCount++;

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
                memoryUsage += sizeof(Point); // Approx memory per node
            }
        }
    }

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    if (found) {
        // Commented out path and maze display:
        /*
        cout << "\nPath Found using BFS:\n";
        vector<Point> path;
        Point curr = end;
        while (!(curr.x == -1 && curr.y == -1)) {
            path.push_back(curr);
            curr = parent[curr.x][curr.y];
        }
        reverse(path.begin(), path.end());
        for (auto p : path) maze[p.x][p.y] = 'o';

        cout << "Maze with BFS path:\n";
        for (auto &row : maze) cout << row << "\n";
        */

        cout << "\nBFS Time: " << duration.count() << " microseconds\n";
        cout << "Approx BFS Memory: " << memoryUsage / 1024.0 << " KB\n";
        cout << "Nodes Visited: " << visitedCount << "\n";
    } else {
        cout << "No path found using BFS.\n";
    }
}

bool DFSUtil(vector<string>& maze, Point curr, Point end, vector<vector<bool>>& visited, vector<Point>& path, size_t &memoryUsage, size_t &visitedCount) {
    if (curr.x == end.x && curr.y == end.y) {
        path.push_back(curr);
        return true;
    }

    visited[curr.x][curr.y] = true;
    visitedCount++;
    path.push_back(curr);

    for (int i = 0; i < 4; i++) {
        int nx = curr.x + dx[i];
        int ny = curr.y + dy[i];
        if (isValid(nx, ny, maze.size(), maze[0].size(), maze, visited)) {
            memoryUsage += sizeof(Point);
            if (DFSUtil(maze, {nx, ny}, end, visited, path, memoryUsage, visitedCount)) return true;
        }
    }

    path.pop_back();
    return false;
}

void DFS(vector<string>& maze, Point start, Point end) {
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<Point> path;
    size_t memoryUsage = sizeof(visited);
    size_t visitedCount = 0;

    auto startTime = high_resolution_clock::now();
    bool found = DFSUtil(maze, start, end, visited, path, memoryUsage, visitedCount);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    if (found) {
        // Commented out path and maze display:
        /*
        cout << "\nPath using DFS:\n";
        for (auto p : path) maze[p.x][p.y] = 'x';

        cout << "Maze with DFS path:\n";
        for (auto &row : maze) cout << row << "\n";
        */

        cout << "\nDFS Time: " << duration.count() << " microseconds\n";
        cout << "Approx DFS Memory: " << memoryUsage / 1024.0 << " KB\n";
        cout << "Nodes Visited: " << visitedCount << "\n";
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

    ifstream file2("maze.txt");
    maze.clear();
    while (getline(file2, line)) {
        if (!line.empty()) maze.push_back(line);
    }
    file2.close();

    DFS(maze, start, end);

    return 0;
}
