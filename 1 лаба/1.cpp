#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in ("aplusb.in");
    ofstream out ("aplusb.out");
    int a, b;
    in >> a >> b;
    out << a + b;
    return 0;
}
