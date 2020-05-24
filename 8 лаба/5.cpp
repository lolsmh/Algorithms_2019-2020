#include<fstream>

using namespace std;
int n, m, a, b;
vector<int> g[100000], dist;
vector<bool> checked;

void bfs(int i) {
    checked[i] = true;
    dist[i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int E = q.front();
        for (int j = 0; j < g[E].size(); j++) {
            if (!checked[g[E][j]]) {
                checked[g[E][j]] = true;
                dist[g[E][j]] = dist[E] + 1;
                q.push(g[E][j]);
            }
        }
        q.pop();
    }
}

int main() {
    ifstream in ("pathbge1.in");
    ofstream out ("pathbge1.out");
    in >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; i++) {
        checked.push_back(false);
        dist.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        if (!checked[i]) {
            bfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        out << dist[i] << " ";
    }
}
