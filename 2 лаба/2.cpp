#include <fstream>
#include <string>


using namespace std;

void Merge(string *a, int low, int high, int mid) {
    int i, j, k;
    string temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (a[i] <
            a[j]) {
            temp[k] = a[i];
            k++;
            i++;
        } else {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        temp[k] = a[i];
        k++;
        i++;
    }

    while (j <= high) {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}
void MergeSort(string *a, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, high, mid);
    }
}

int main() {
    ifstream in ("race.in");
    ofstream out ("race.out");
    int n;
    in >> n;
    string c[n];
    string name[n];
    string sc[n];
    for (int i = 0; i < n; i++) {
        in >> c[i];
        in >> name[i];
    }
    for (int i = 0; i < n; ++i) {
        sc[i] = c[i];
    }
    MergeSort(sc, 0, n - 1);
    for(int i = 0; i < n; i++) {
        if (sc[i] != sc[i + 1]) {
            out << "=== " << sc[i] << " ===" << endl;
            for (int j = 0; j < n; ++j) {
                if (sc[i] == c[j]) {
                    out << name[j] << endl;
                }
            }
        }
    }
    return 0;
}