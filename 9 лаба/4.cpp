#include <fstream>
#include <vector>

using namespace std;

ifstream in ("cond.in");
ofstream out ("cond.out");

vector<vector<int>> edges, tr_edges;
vector<int> order, comp, visited;

void dfs(int v, int x) {
    visited[v] = 1;
    if (x == 2) {
        comp.push_back(v);
        for (int i : tr_edges[v]) {
            if (visited[i] == 0){
                dfs(i, x);
            }
        }
    } else {
        for (int i : edges[v]) {
            if (visited[i] == 0){
                dfs(i, x);
            }
        }
        order.push_back(v);
    }
}

int main() {
    int n, m;
    in >> n >> m;
    edges.resize(n);
    tr_edges.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        edges[a - 1].push_back(b - 1);
        tr_edges[b - 1].push_back(a - 1);
    }
    vector<int> result;
    visited.assign(n, 0);
    for (int i = 0; i < n; i++){
        if (visited[i] == 0){
            dfs(i, 1);
        }
    }
    visited.assign(n, 0);
    result.assign(n, 0);
    int cnt = 0;
    for (int i = order.size() - 1; i >= 0; i--) {
        if (visited[order[i]] == 0) {
            comp.clear();
            dfs(order[i], 2);
            cnt++;
            for (int j : comp){
                result[j] = cnt;
            }
        }
    }
    out << cnt << endl;
    for (int i : result){
        out << i << " ";
    }
    return 0;
}