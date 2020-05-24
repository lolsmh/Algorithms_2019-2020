#include <fstream>

using namespace std;

int main() {
    ifstream in("garland.in");
    ofstream out("garland.out");
    int n;
    double h, down = 0, last = -1;
    in >> n >> h;
    double up = h;
    while ((up - down) > 0.001 / (n - 1)) {
        double mid = (up + down) / 2, prev = h, now = mid;
        bool over = now > 0;
        for (int i = 3; i <= n; i++) {
            double next = 2 * now - prev + 2;
            over &= next > 0;
            prev = now;
            now = next;
        }
        if (over) {
            up = mid;
            last = now;
        } else {
            down = mid;
        }
    }
    out << fixed;
    out.precision(3);
    out << last << endl;
    return 0;
}