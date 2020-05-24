#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in ("aplusbb.in");
    ofstream out ("aplusbb.out");
    long long int a, b;
    in >> a >> b;
    out << a + b * b;
    return 0;
}
