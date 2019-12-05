#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

ifstream in("radixsort.in");
ofstream out("radixsort.out");

string* radixsort(string a[], int m, int n, int k) { // поразрядная сортировка
    int c[123]; //вспомогательный массив
    string b[n]; // еще один вспомогательный массив
    for (int i = 1; i <= k; i++) { //цикл от 1 до кол-ва разрядов
        for (int j = 97; j <= 122; j++) { //это цикл от a до z, можете поэксперементировать, и повыводить char в int
            c[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            int d = int(a[j][m - i]); //получаем int с char
            c[d]++;
        }
        int count = 0;
        for (int j = 97; j <= 122; j++) { // переписываем в с
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; j++) { // записываем отсортированный массив в d
            int d = int(a[j][m - i]);
            b[c[d]] = a[j];
            c[d]++;
        }
        for (int j = 0; j < n; j++) { //переписываем в a
            a[j] = b[j];
        }
    }
    for(int i = 0; i < n; i++){
        out << a[i] << endl;
    }
    return a;
}

int main() {
    int n, m, k;
    in >> n >> m >> k;
    string s[n];
    for (int i = 0; i < n; i++){
        in >> s[i];
    }
    radixsort(s, m, n, k);
    return 0;
}