#include <fstream>
#include <vector>
#include <set>

using namespace std;

struct edge{
    int to, w;
};

struct node{
    int v, p;
    node(int v, int p) : v(v), p(p) {};
    bool operator<(node const& other) const
    {
        return (p < other.p) || (p == other.p && v < other.v);
    }
};

vector<vector<edge>> edg;
vector<int> dist;
set<node> queue;

int main() {
    ifstream in ("pathbgep.in");
    ofstream out ("pathbgep.out");
    in.tie(nullptr);
    out.tie(nullptr);
    int n, m;
    in >> n >> m;
    edg.resize(n);
    int a, b, w;
    for (int i = 0; i < m; ++i){
        in >> a >> b >> w;
        --a, --b;
        edg[a].push_back({ b, w });
        edg[b].push_back({ a, w });
    }
    dist.assign(n, 1000000000);
    dist[0] = 0;
    for (int i = 0; i < n; ++i){
        queue.insert({ i, dist[i] });
    }

    while (!queue.empty()){
        auto v = (*queue.begin());
        queue.erase(queue.begin());
        for (auto e : edg[v.v]){
            if (dist[e.to] > dist[v.v] + e.w){
                queue.erase({ e.to, dist[e.to] });
                dist[e.to] = dist[v.v] + e.w;
                queue.insert({ e.to, dist[e.to] });
            }
        }
    }

    for (auto i : dist){
        out << i << " ";
    }
    return 0;
}