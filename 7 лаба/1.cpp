#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    int L;
    int R;
    int height = 0;
    Node(int _key, int _L, int _R) : key(_key), L(_L), R(_R) {}
};

int heightR(int index, vector<Node>& vertex) {
    if (vertex[index].R == -1) {
        return 0;
    }
    return vertex[vertex[index].R].height;
}

int heightL(int index, vector<Node>& vertex) {
    if (vertex[index].L == -1) {
        return 0;
    }
    return vertex[vertex[index].L].height;
}

void init_height(int index, vector<Node>& vertex) {
    if (vertex[index].L != -1) {
        init_height(vertex[index].L, vertex);
    }
    if (vertex[index].R != -1) {
        init_height(vertex[index].R, vertex);
    }
    vertex[index].height = max(heightL(index, vertex), heightR(index, vertex)) + 1;
}

int balance(int index, vector<Node>& vertex) {
    int L = 0, R = 0;
    R = vertex[index].R != -1 ? vertex[vertex[index].R].height : 0;
    L = vertex[index].L != -1 ? vertex[vertex[index].L].height : 0;
    return R - L;
}

int main() {
    ifstream in ("balance.in");
    ofstream out ("balance.out");
    int N;
    in >> N;
    vector<Node> vertex;
    for (int i = 0; i < N; i++) {
        int K, L, R;
        in >> K;
        in >> L;
        in >> R;
        vertex.push_back(Node(K, L - 1, R - 1));
    }
    init_height(0, vertex);
    for (int i = 0; i < N; i++) {
        out << balance(i, vertex) << endl;
    }
    return 0;
}