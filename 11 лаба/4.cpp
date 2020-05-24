#include <fstream>
#include <vector>

long long n, m, start;

const unsigned long long MAX_N = 2017;

using namespace std;

ifstream in("path.in");
ofstream out("path.out");

long long ans = 0;

struct edge {
    long long from, to, weight;

    edge(long long x, long long y, long long z) {
        from = x;
        to = y;
        weight = z;
    }
};

long long inf = LLONG_MAX / 2;

vector<edge> edges;
vector<vector<long long>> edgesDFS(MAX_N);
vector<long long> d(MAX_N, inf);
vector<long long> proceed(MAX_N, true);
vector<bool> was(MAX_N);


void dfs(long long v) {
    was[v] = true;
    proceed[v] = false;
    for (auto to : edgesDFS[v]) {
        if (!was[to])
            dfs(to);
    }
}


void solve() {
    d[start] = 0;
    long long x;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            if (d[edges[j].from] < inf) {
                if (d[edges[j].to] > d[edges[j].from] + edges[j].weight) {
                    d[edges[j].to] = max(-inf, d[edges[j].from] + edges[j].weight);
                    if (i == n - 1) {
                        for (long long i = 0; i < n; ++i) {
                            was[i] = false;
                        }
                        dfs(edges[j].to);
                    }
                }
            }
        }
    }
}

int main() {
    in >> n >> m >> start;
    start--;
    for (long long i = 0; i < m; ++i) {
        long long from, to, weight;
        in >> from >> to >> weight;
        from--;
        to--;
        edges.push_back(edge(from, to, weight));
        edgesDFS[from].push_back(to);
    }
    solve();
    for (long long i = 0; i < n; ++i) {
        if (d[i] == inf) {
            out << '*' << "\n";
        } else if (!proceed[i]) {
            out << '-' << "\n";
        } else {
            out << d[i] << "\n";
        }
    }
    return 0;
}