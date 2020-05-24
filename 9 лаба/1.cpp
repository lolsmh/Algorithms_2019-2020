#include <vector>
#include <fstream>

using namespace std;

vector<bool> used;
vector<int> order;
vector<int> temp;
vector<int> cycle;
vector<vector<int>> graph;

void top_sort(int vertex) {
    used[vertex] = true;
    for (int i: graph[vertex]) {
        if (!used[i]) {
            top_sort(i);
        }
    }
    order.push_back(vertex);
}

bool check(int &vertex, int &start, int &end) {
    cycle[vertex] = 1;
    for (auto i : graph[vertex]) {
        int tmp = i;
        if (cycle[tmp] == 0) {
            temp[tmp] = vertex;
            if (check(tmp, start, end)) {
                return true;
            }
        } else if (cycle[tmp] == 1) {
            start = tmp;
            end = vertex;
            return true;
        }
    }
    cycle[vertex] = 2;
    return false;
}

int main() {
    ifstream in ("topsort.in");
    ofstream out ("topsort.out");
    int n, m;
    int end, start = -1;
    in >> n >> m;
    graph.resize(n);
    used.assign(n, false);
    cycle.assign(n, 0);
    temp.assign(n, -228);
    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    for (int i = 0; i < n; i++) {
        if (check(i, start, end)) {
            out << -1;
            exit(0);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            top_sort(i);
        }
    }
    reverse(order.begin(), order.end());
    for (auto i : order) {
        out << i + 1 << " ";
    }
}