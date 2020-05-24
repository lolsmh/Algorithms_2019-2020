#include <fstream>
#include <vector>

using namespace std;

typedef long long ll;

ifstream in("pathmgep.in");
ofstream out("pathmgep.out");

int n;
const ll inf = 1000000000000000000;
vector<vector<ll>> g(2000, vector<ll>(2000));
vector<ll> d(2000, inf);
vector<bool> visit(2000, false);


void Dijkstra(ll start) {
    d[start] = 0;
    for (ll i = 0; i < n; ++i) {
        ll vertex = -1;
        for (ll j = 0; j < n; ++j) {
            if (!visit[j] && (vertex == -1 || d[j] < d[vertex])) {
                vertex = j;
            }
        }
        if (d[vertex] == inf) {
            break;
        }
        visit[vertex] = true;
        for (ll j = 0; j < n; ++j) {
            if (d[vertex] + g[vertex][j] < d[j]){
                d[j] = d[vertex] + g[vertex][j];
            }
        }
    }
}

int main() {
    ll start, final;
    in >> n >> start >> final;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            int vertex;
            in >> vertex;
            if (vertex < 0)
                g[i][j] = inf;
            else
                g[i][j] = vertex;
        }
    }
    Dijkstra(start - 1);
    if(d[final - 1] != inf)
        out << d[final - 1];
    else
        out << -1;
    return 0;
}