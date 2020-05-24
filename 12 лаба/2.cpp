#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<bool> used;
vector<int> ans;
vector<vector<int> > g;

bool dfs(int v) {
    used[v] = true;
    for (auto it = g[v].begin(); it != g[v].end(); it++) {
        if (ans[*it] == -1 || (!used[ans[*it]] && dfs(ans[*it]))) {
            ans[*it] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream in("matching.in");
    ofstream out("matching.out");
    int n, k, m;
    in >> n >> k >> m;
    ans.resize(k, -1);
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        used = vector<bool>(n, false);
        if (dfs(i))
            res++;
    }
    out << res << "\n";
}