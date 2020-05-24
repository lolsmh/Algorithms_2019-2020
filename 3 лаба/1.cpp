#include <iostream>
#include <fstream>

using namespace std;
ifstream in("binsearch.txt");
ofstream out("binsearch2.txt");

int BinSearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key) {
            left = mid + 1;
        }
        if (arr[mid] > key) {
            right = mid - 1;
        }
    }
    return -1;
}

int entry(int arr[], int N, int key) {
    int result = 0;
    result = BinSearch(arr, 0, N - 1, key);
    if (result == -1) {
        out << "-1 -1" << endl;
    } else {
        int first = result;
        int last = result;
        while (arr[first + 1] == arr[result]) {
            first++;
        }
        while (last > 0 && arr[last - 1] == result) {
            last--;
        }
        out << last + 1 << ' ' << first + 1 << endl;
    }
    return 0;
}

int main() {
    int N, key;
    in >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        in >> arr[i];
    }
    int k;
    in >> k;
    for (int i = 0; i < k; i++) {
        in >> key;
        entry(arr, N, key);
    }
}





