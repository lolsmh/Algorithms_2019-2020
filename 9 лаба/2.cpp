#include <fstream>
#include <vector>

using namespace std;

ifstream in("cycle.in");
ofstream out("cycle.out");

vector<vector<int>> g;
vector<int> p, color;
int start = -1;
int n, m;
int ending;

void dfs(int v) {
    color[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (color[g[v][i]] == 1) {
            start = g[v][i];
            ending = v;
        }
        if (color[g[v][i]] == 0) {
            p[g[v][i]] = v;
            dfs(g[v][i]);
        }
    }
    color[v] = 2;
}

int main() {
    in >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    p.assign(n, -1);
    color.assign(n, 0);
    for (int i = 0; i < n; i++) if (color[i] == 0) dfs(i);
    if (start == -1) out << "NO" << endl;
    else {
        out << "YES" << endl;
        vector<int> ans;
        ans.push_back(start + 1);
        for (int i = ending; i != start; i = p[i]) {
            ans.push_back(i + 1);
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            out << ans[i] << " ";
        }
    }
    return 0;
}
