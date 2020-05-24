#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<vector<int>> g;
    vector<int> color;
    vector<bool> win;
    ifstream in("game.in");
    ofstream out("game.out");
    int n, m, start;
    in >> n >> m >> start;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        in >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    color.assign(n, 0);
    win.assign(n, false);
    stack<int> stack;
    stack.push(start - 1);
    while (!stack.empty()) {
        int cur = stack.top();
        if (color[cur] == 2) stack.pop();
        else if (color[cur] == 1) {
            bool flag = false;
            for (int i : g[cur]) {
                if (win[i] == 0) {
                    flag = true;
                }
            }
            win[cur] = flag;
            color[cur] = 2;
            stack.pop();
        } else {
            color[cur] = 1;
            for (int i : g[cur]) {
                if (color[i] == 0) {
                    stack.push(i);
                }
            }
        }
    }
    if (win[start - 1]) {
        out << "First player wins";
    } else {
        out << "Second player wins";
    }
    return 0;
}