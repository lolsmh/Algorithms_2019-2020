#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, k = 0;
    in >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((arr[i][j] == 1 && arr[j][i] == 0) || ((arr[i][j] == 1 && arr[j][i] == 1) && i == j)){
                k++;
            }
        }
    }
    if (k == 0) {
        out << "YES\n";
    } else {
        out << "NO\n";
    }
}
