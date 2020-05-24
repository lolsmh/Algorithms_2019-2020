#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream in("set.in");
ofstream out("set.out");

vector<vector<int>> a(1000001, vector<int>());

int _getHash(int num) {
    return abs(num % 1000001);
}

bool _exists(int num) {
    int hash = _getHash(num);
    for (int i : a[hash]) {
        if (i == num) {
            return true;
        }
    }
    return false;
}

void _insert(int num) {
    int hash = _getHash(num);
    if (!_exists(num)) {
        a[hash].push_back(num);
    }
}

void _delete(int num) {
    int hash = _getHash(num);
    for(int i = 0; i < a[hash].size(); i++){
        if(a[hash][i] == num){
            a[hash].erase(a[hash].begin() + i);
            break;
        }
    }
}

int main() {
    string str;
    int num;
    while(in){
        in >> str;
        if(!in.eof()) {
            if (str == "insert") {
                in >> num;
                _insert(num);
            } else if (str == "delete") {
                in >> num;
                _delete(num);
            } else {
                in >> num;
                if (_exists(num)) {
                    out << "true\n";
                } else {
                    out << "false\n";
                }
            }
        }
    }
    return 0;
}