#include <fstream>

using namespace std;

int main() {
    ifstream in("antiqs.in");
    ofstream out("antiqs.out");
    int n;
    in >> n;
    int a[n];
    int k = 1;
    for (int i = 0; i < n; i++) {
        a[i] = k;
        k++;
    }
    int t;
    for (int i = 2; i < n; i++) {
        t = a[i];
        a[i] = a[i / 2];
        a[i / 2] = t;
    }
    for (int i = 0; i < n; i++) {
        out << a[i] << ' ';
    }
    return 0;
}