#include <fstream>

using namespace std;

ifstream in ("input.txt");
ofstream out ("output.txt");

int main() {
    int n, m, v1, v2;
    in >> n >> m;
    int count[n];
    for (int j = 0; j < n; ++j) {
        count[j] = 0;
    }
    for (int i = 0; i < m; ++i) {
        in >> v1 >> v2;
        count[v1 - 1]++;
        count[v2 - 1]++;
    }
    for (int j = 0; j < n; ++j) {
        out << count[j] << ' ';
    }
    return 0;
}
