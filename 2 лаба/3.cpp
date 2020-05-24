#include <fstream>

#define N 100000

using namespace std;

long a[N], b[N];

long long merge(int x, int m, int y) {
    int i = x, j = m, k = x;
    long long r = 0, p = 0;
    while (i <= m - 1 && j <= y) {
        if (a[i] <= a[j]) {
            i++;
            r += p;
        } else {
            j++;
            p++;
        }
    }
    while (i <= m - 1) {
        r += p;
        i++;
    }
    i = x;
    j = m;
    k = x;
    while (i <= m - 1 && j <= y) {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= m - 1)
        b[k++] = a[i++];
    while (j <= y)
        b[k++] = a[j++];
    for (i = x; i <= y; i++) a[i] = b[i];
    return r;
}

long long inv(int x, int y) {
    if (x == y) {
        return 0;
    }
    if (x == y - 1) {
        if (a[x] > a[y]) {
            int t = a[x];
            a[x] = a[y];
            a[y] = t;
            return 1;
        }
        return 0;
    }
    int m = (x + y + 1) / 2;
    long long r = inv(x, m - 1) + inv(m, y);
    r += merge(x, m, y);
    return r;
}

int main() {
    ifstream in("inversions.in");
    ofstream out("inversions.out");
    int n;
    long long res = 0;
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> a[i];
    }
    if (n > 0) {
        res = inv(0, n - 1);
    }
    out << res;
}