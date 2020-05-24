#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point {
public:
    int x = 0, y = 0;
    double len2p(const Point& a) {
        return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
    };
};

int main() {
    ifstream in("spantree.in");
    ofstream out("spantree.out");

    int n;
    in >> n;

    Point buff[n];
    int visited[n];
    double edges[n];

    int x, y;
    for (int i = 0; i < n; i++) {
        in >> x >> y;
        buff[i] = Point{x, y};
        visited[i] = 0;
        if (i > 0) {
            edges[i] = buff[0].len2p(buff[i]);
        }
    }
    visited[0] = 1;

    double sum;
    for (int j = 1; j < n; j++) {
        double minLen = INT_MAX;
        int help = 0;
        for(int i = 1; i < n; i++)
            if (edges[i] < minLen && !visited[i]) {
                minLen = edges[i];
                help = i;
            }
        visited[help] = 1;
        sum += minLen;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                double len = buff[help].len2p(buff[i]);
                if (len < edges[i])
                    edges[i] = len;
            }
        }
    }
    out << fixed << setprecision(20) << sum;
    return 0;
}
