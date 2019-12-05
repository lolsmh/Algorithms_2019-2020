#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream in ("sortland.in");
    ofstream out ("sortland.out");
    int n;
    in >> n;
    float a[n];
    float b[n];
    int max, min, mid;
    for(int i = 0; i < n; i++){
        in >> a[i];
    }
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }
    float temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(b[i] == a[0]){
            min = i;
        }
        if(b[i] == a[n / 2]){
            mid = i;
        }
        if(b[i] == a[n - 1]){
            max = i;
        }
    }
    out << min + 1 << ' ' << mid + 1 << ' ' << max + 1;
    return 0;
}