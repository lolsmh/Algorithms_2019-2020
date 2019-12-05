#include <fstream>

using namespace std;

void kth(long arr[], long left, long right, long k) {
    long x = arr[(left + right) / 2];
    long i = left, j = right;
    while (i <= j) {
        while (arr[i] < x) {
            i++;
        }
        while (arr[j] > x) {
            j--;
        }
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    if (left < j && k <= j) {
        kth(arr, left, j, k);
    }
    if (i < right && k >= i) {
        kth(arr, i, right, k);
    }
}

int main() {
    long n;
    long k = 0;

    ifstream in("kth.in");
    ofstream out("kth.out");
    in >> n;
    in >> k;
    long A, B, C, a[n];
    in >> A >> B >> C >> a[0] >> a[1];
    for (long i = 2; i < n; i++) {
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    }
    kth(a, 0, n - 1, k - 1);
    out << a[k - 1];
    return 0;
}