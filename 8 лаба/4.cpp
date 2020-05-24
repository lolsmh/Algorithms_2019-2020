#include <fstream>
#include <vector>

using namespace std;
int n, m, vertex1, vertex2, number = 0;
vector<int> graph[100000], component;
vector<bool> used;

ifstream in("components.in");
ofstream out("components.out");

void dfs(int i) {
    used[i] = true;
    component[i] = number;
    if (!graph[i].empty()) {
        for (int j : graph[i]) {
            if (!used[j])
                dfs(j);
        }
    }
}

int main() {
    in >> n >> m;
    for (int i = 0; i < m; i++) {
        in >> vertex1 >> vertex2;
        graph[vertex1 - 1].push_back(vertex2 - 1);
        graph[vertex2 - 1].push_back(vertex1 - 1);
    }
    for (int i = 0; i < n; i++) {
        used.push_back(false);
        component.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            number++;
            dfs(i);
        }
    }
    out << number << endl;
    for (int i = 0; i < n; i++)
        out << component[i] << " ";
}