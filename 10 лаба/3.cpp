#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int x, y, w;
};

int n;
vector<int> parent(n);

int getRoot(int v) {
    if (parent[v] == v) {
        return v;
    } else {
        int root = getRoot(parent[v]);
        parent[v] = root;
        return root;
    }
}

int main() {
    ifstream in("spantree3.in");
    ofstream out("spantree3.out");

    int m;
    in >> n >> m;
    vector<Edge> matrix(m);
    vector<int> color(n);

    int x, y, w;
    for (int i = 0; i < m; i++) {
        in >> x >> y >> w;
        x--, y--;
        matrix[i] = {x, y, w};
    }

    std::sort(matrix.begin(), matrix.end(),[](Edge const & a, Edge const & b) -> bool{ return a.w < b.w; } );
    parent.resize (n);

    for (int i = 0; i < n; ++i)
        parent[i] = i;

    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        int a = matrix[i].x,  b = matrix[i].y,  l = matrix[i].w;
        if (getRoot(a) != getRoot(b)) {
            sum += l;
            a = getRoot(a);
            b = getRoot(b);
            if (rand() & 1)
                swap (a, b);
            if (a != b)
                parent[a] = b;
        }
    }
    out << sum;
    return 0;
}