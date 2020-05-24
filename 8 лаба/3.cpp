#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m, k = 0;
    in >> n >> m;
    int arr[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        int vertex1, vertex2;
        in >> vertex1 >> vertex2;
        if(arr[vertex1 - 1][vertex2 - 1] == 0){
            arr[vertex1 - 1][vertex2 - 1] = 1;
        } else {
            k++;
        }
        if (arr[vertex1 - 1][vertex2 - 1] == 1 && arr[vertex2 - 1][vertex1 - 1] == 1) {
            k++;
        }
    }
    if (k == 0) {
        out << "NO";
    } else {
        out << "YES";
    }
    return 0;
}
