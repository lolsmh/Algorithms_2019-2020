#include <fstream>
#include <vector>

using namespace std;

ifstream in("pathsg.in");
ofstream out("pathsg.out");

int n, m;
const int inf = INT_MAX;
vector<vector<int>> g;


int main() {
    in >> n >> m;
    g.resize(n, vector<int>(n, inf));
    for (int i = 0; i < m; ++i) {
        int v1, v2, weight;
        in >> v1 >> v2 >> weight;
        g[v1 - 1][v2 - 1] = weight;
    }
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][l] < inf && g[l][j] < inf) {
                    g[i][j] = min(g[i][j], g[i][l] + g[l][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                g[i][j] = 0;
            }
            out << g[i][j] << ' ';
        }
        out << endl;
    }
    return 0;
}