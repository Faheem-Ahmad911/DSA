#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct P {
    int x, y;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok(int x, int y, int r, int c, vector<string>& m, vector<vector<bool>>& v) {
    return (x >= 0 && y >= 0 && x < r && y < c && m[x][y] == '*' && !v[x][y]);
}

void bfs(vector<string>& m, P s, P e) {
    int r = m.size();
    int c = m[0].size();
    vector<vector<P>> par(r, vector<P>(c, {-1, -1}));
    vector<vector<bool>> v(r, vector<bool>(c, false));
    queue<P> q;
    q.push(s);
    v[s.x][s.y] = true;
    bool f = false;
    size_t mem = sizeof(v) + sizeof(par) + sizeof(q);
    size_t cnt = 0;
    auto st = high_resolution_clock::now();
    while (!q.empty()) {
        P p = q.front(); q.pop();
        cnt++;
        if (p.x == e.x && p.y == e.y) {
            f = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (ok(nx, ny, r, c, m, v)) {
                v[nx][ny] = true;
                par[nx][ny] = p;
                q.push({nx, ny});
                mem += sizeof(P);
            }
        }
    }
    auto et = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(et - st);
    if (f) {
        cout << "\nPath Found using BFS:\n";
        vector<P> path;
        P cur = e;
        while (!(cur.x == -1 && cur.y == -1)) {
            path.push_back(cur);
            cur = par[cur.x][cur.y];
        }
        reverse(path.begin(), path.end());
        for (auto p : path) m[p.x][p.y] = 'o';
        cout << "Maze with BFS path:\n";
        for (auto &row : m) cout << row << "\n";
        cout << "\nBFS Time: " << dur.count() << " microseconds\n";
        cout << "Approx BFS Memory: " << mem / 1024.0 << " KB\n";
        cout << "Nodes Visited: " << cnt << "\n";
    } else {
        cout << "No path found using BFS.\n";
    }
}

bool dfsr(vector<string>& m, P cur, P e, vector<vector<bool>>& v, vector<P>& path, size_t &mem, size_t &cnt) {
    if (cur.x == e.x && cur.y == e.y) {
        path.push_back(cur);
        return true;
    }
    v[cur.x][cur.y] = true;
    cnt++;
    path.push_back(cur);
    for (int i = 0; i < 4; i++) {
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];
        if (ok(nx, ny, m.size(), m[0].size(), m, v)) {
            mem += sizeof(P);
            if (dfsr(m, {nx, ny}, e, v, path, mem, cnt)) return true;
        }
    }
    path.pop_back();
    return false;
}

void dfs(vector<string>& m, P s, P e) {
    vector<vector<bool>> v(m.size(), vector<bool>(m[0].size(), false));
    vector<P> path;
    size_t mem = sizeof(v);
    size_t cnt = 0;
    auto st = high_resolution_clock::now();
    bool f = dfsr(m, s, e, v, path, mem, cnt);
    auto et = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(et - st);
    if (f) {
        cout << "\nPath using DFS:\n";
        for (auto p : path) m[p.x][p.y] = 'x';
        cout << "Maze with DFS path:\n";
        for (auto &row : m) cout << row << "\n";
        cout << "\nDFS Time: " << dur.count() << " microseconds\n";
        cout << "Approx DFS Memory: " << mem / 1024.0 << " KB\n";
        cout << "Nodes Visited: " << cnt << "\n";
    } else {
        cout << "No path found using DFS.\n";
    }
}

int main() {
    ifstream f("maze.txt");
    vector<string> m;
    string l;
    while (getline(f, l)) {
        if (!l.empty()) m.push_back(l);
    }
    f.close();
    int r = m.size();
    int c = m[0].size();
    P s = {-1, -1}, e = {-1, -1};
    for (int j = 0; j < c; j++) {
        if (m[0][j] == '*') { s = {0, j}; break; }
    }
    for (int j = c - 1; j >= 0; j--) {
        if (m[r - 1][j] == '*') { e = {r - 1, j}; break; }
    }
    if (s.x == -1 || e.x == -1) {
        cout << "Start or End point not found.\n";
        return 0;
    }
    cout << "Start: (" << s.x << "," << s.y << ")\n";
    cout << "End: (" << e.x << "," << e.y << ")\n";
    bfs(m, s, e);
    ifstream f2("maze.txt");
    m.clear();
    while (getline(f2, l)) {
        if (!l.empty()) m.push_back(l);
    }
    f2.close();
    dfs(m, s, e);
    return 0;
}
