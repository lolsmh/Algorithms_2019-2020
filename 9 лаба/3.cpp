#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ifstream in ("bipartite.in");
    ofstream out ("bipartite.out");
    vector<vector<int>> edges;
    vector<int> color;
    bool flag = true;
    int n, m;
    in >> n >> m;
    edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    queue<int> q;
    color.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for (int j = 0; j < edges[u].size(); j++) {
                    if (color[edges[u][j]] == 0) {
                        q.push(edges[u][j]);
                        color[edges[u][j]] = -color[u];
                    } else if (color[u] == color[edges[u][j]]) {
                        flag = false;
                    }
                }
            }
        }
    }
    if (flag){
        out << "YES ";
    } else {
        out << "NO";
    }
    return 0;
}