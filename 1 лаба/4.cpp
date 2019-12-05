#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int n;
    in >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        in >> a[i];
    }
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        out << a[i] << ' ';
    }
    return 0;
}