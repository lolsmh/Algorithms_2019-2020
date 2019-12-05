#include <fstream>

using namespace std;
int h, w;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> h >> w;
    int **p;
    p = new int *[h + 2];
    for (int i = 0; i < h + 2; i++) {
        p[i] = new int[w + 2];
        for (int j = 0; j < w + 2; j++) {
            p[i][j] = 0;
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            in >> p[i][j];

        }
    }
    for (int i = h; i >= 1; i--) {
        for (int j = 1; j <= w; j++) {
            if (p[i + 1][j] > p[i][j - 1]) {
                p[i][j] += p[i + 1][j];
            } else {
                p[i][j] += p[i][j - 1];

            }
        }
    }
    out << p[1][w];
}
