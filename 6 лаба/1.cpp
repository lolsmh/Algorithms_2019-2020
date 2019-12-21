#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream in("height.in");
ofstream out("height.out");

int find(int root, int child[][2])
{
    if (child[root][0] == -1 && child[root][1] == -1)
        return 1;

    int left = 0;
    int right = 0;

    if (child[root][1] != -1)
        right = find(child[root][1], child);
    if (child[root][0] != -1)
        left = find(child[root][0], child);
    return max(left + 1, right + 1);
}

int main()
{
    int n;
    in >> n;
    int child[n][2];
    int key, left_child, right_child;
    for (int i = 0; i < n; ++i) {
        in >> key >> left_child >> right_child;
        child[i][0] = left_child - 1;
        child[i][1] = right_child - 1;
    }
    if (n != 0)
        out << find(0, child);
    else
        out << "0";
    return 0;
}