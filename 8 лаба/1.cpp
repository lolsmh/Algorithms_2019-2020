#include <fstream>

using namespace std;

int main(){
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int n, m;
    in >> n >> m;
    int arr[n][n], vertex1, vertex2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        in >> vertex1 >> vertex2;
        arr[vertex1 - 1][vertex2 - 1] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            out << arr[i][j] << ' ';
        }
        out << endl;
    }
    return 0;
}