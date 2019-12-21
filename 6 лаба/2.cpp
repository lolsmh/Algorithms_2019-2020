#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool balance = true;

struct elements {
    int key;
    int left;
    int right;
};

vector<elements> Tree(0);

void check(int v, int left_value, int right_value) {
    if (Tree[v].key <= left_value || Tree[v].key >= right_value) {
        balance = false;
    }
    if (Tree[v].left != -1) {
        check(Tree[v].left, left_value, Tree[v].key);
    }
    if (Tree[v].right != -1)
        check(Tree[v].right, Tree[v].key, right_value);
}

int main() {
    ifstream in("check.in");
    ofstream out("check.out");

    int n;
    in >> n;
    Tree.resize(n);
    for (size_t i = 0; i < n; i++) {
        int key;
        int left_child;
        int right_child;
        in >> key >> left_child >> right_child;
        Tree[i].key = key;
        Tree[i].left = left_child - 1;
        Tree[i].right = right_child - 1;
    }
    if (n != 0) {
        int left = Tree[0].left;
        int right = Tree[0].right;
        if (Tree[0].left != -1 && Tree[0].key < Tree[left].key)
            balance = false;
        if (Tree[0].right != -1 && Tree[0].key > Tree[right].key)
            balance = false;
        check(0, -1000000000, 1000000000);
    }

    if (balance != 0) {
        out << "YES";
    } else {
        out << "NO";
    }
    return 0;
}