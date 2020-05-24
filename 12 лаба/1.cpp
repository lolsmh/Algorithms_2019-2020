#include <fstream>

using namespace std;

const int MAX_E = 1e6, MAX_V = 1e3, INF = 1e9;

int n, m, firstEdge[MAX_V], visited[MAX_V], weight[MAX_E], End[MAX_E], Next[MAX_E], Count;

void add(int v1, int v2, int w) {
    End[Count] = v2;
    Next[Count] = firstEdge[v1];
    firstEdge[v1] = Count;
    weight[Count++] = w;
    End[Count] = v1;
    Next[Count] = firstEdge[v2];
    firstEdge[v2] = Count;
    weight[Count++] = 0;
}

int findFlow(int start, int flow) {
    if (start == n) {
        return flow;
    }
    visited[start] = true;
    for (int edge = firstEdge[start]; edge != -1; edge = Next[edge]) {
        int to = End[edge];
        if (!visited[to] && weight[edge] > 0) {
            int minResult = findFlow(to, min(flow, weight[edge]));
            if (minResult > 0) {
                weight[edge] -= minResult;
                weight[edge ^ 1] += minResult;
                return minResult;
            }
        }
    }
    return 0;
}

int main() {
    ifstream in("maxflow.in");
    ofstream out("maxflow.out");
    fill(firstEdge, firstEdge + MAX_V, -1);
    in >> n >> m;
    for (int i = 0, vertex1, vertex2, w; i < m; i++) {
        in >> vertex1 >> vertex2 >> w;
        add(vertex1, vertex2, w);
    }
    int maxFlow = 0;
    int iterationResult = 0;
    while ((iterationResult = findFlow(1, INF)) > 0) {
        fill(visited, visited + MAX_V, false);
        maxFlow += iterationResult;
    }
    out << maxFlow << endl;
    return 0;
}