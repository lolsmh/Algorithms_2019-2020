#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct edge {
    int start, end, weight;
};
const int inf = 1000000000;;
int n;
vector <edge> g;
vector<int> d;
vector<int> parent;
vector<int> path;

int main() {
    ifstream in("negcycle.in");
    ofstream out("negcycle.out");
    in >> n;
    d.resize(n, inf);
    parent.resize(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            in >> x;
            g.push_back({i, j, x});
        }
    }
    int cstart;
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        cstart = -1;
        for (int j = 0; j < g.size(); j++) {
            int start = g[j].start;
            int end = g[j].end;
            int weight = g[j].weight;
            if (d[end] > d[start] + weight) {
                d[end] = max(d[start] + weight, -inf);
                parent[end] = start;
                cstart = end;
            }
        }
    }
    if (cstart == -1) {
        out << "NO" << endl;
    } else {
        int cend = cstart;
        for (int i = 0; i < n; i++) {
            cend = parent[cend];
        }
        for (int current = cend; ;current = parent[current]) {
            path.push_back(current);
            if (current == cend && path.size() > 1) {
                break;
            }
        }
        reverse(path.begin(), path.end());
        out << "YES" << endl;
        out << path.size() << endl;
        for (int i : path) {
            out << i + 1 << " ";
        }
        out << endl;
    }
    return 0;
}
