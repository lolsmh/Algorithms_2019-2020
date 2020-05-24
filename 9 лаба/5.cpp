#include <fstream>
#include <vector>

using namespace std;

ifstream in("hamiltonian.in");
ofstream out("hamiltonian.out");

vector<vector<int>> g;
vector<int> order, used;

void dfs(int v) {
    used[v] = 1;
    for (int i : g[v]) {
        if (used[i] == 0) {
            dfs(i);
        }
    }
    order.push_back(v);
}

int main() {
    int n, m;
    in >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    used.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i);
        }
    }
    bool flag = false;
    for (int i = order.size() - 1; i > 0; i--) {
        bool flag2 = false;
        for (int j = 0; j < g[order[i]].size(); j++) {
            if (g[order[i]][j] == order[i - 1]) {
                flag2 = true;
            }
        }
        if (!flag2) {
            flag = true;
            break;
        }
    }
    if (flag) {
        out << "NO";
    } else {
        out << "YES";
    }
    return 0;
}