#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream in ("map.in");
ofstream out ("map.out");

struct key {
    string x;
    string y;
};

vector<vector<key>> a(10000001, vector<key>());

int hashFun(const string &word) {
    int Hash = 0;
    int p = 41;
    for (int i = 0; i < word.size(); i++) {
        int s = 0;
        if (word[i] - 'a' >= 0 && word[i] - 'a' <= 9)
            s = word[i] - 'a';
        else
            s = word[i] - 'A';
        Hash = (Hash + ((s + 1) * p) % 1000000) % 1000000;
        p = (p * 41) % 1000000;
    }
    return Hash;
}

void Put(const string& key, const string& word){
    int hash = hashFun(key);
    for(auto & i : a[hash]){
        if(i.x == key){
            i.y = word;
            return;
        }
    }
    a[hash].push_back({key, word});
}
void Get(const string& key){
    int hash = hashFun(key);
    for(auto & i : a[hash]){
        if(i.x == key){
            out << i.y << endl;
            return;
        }
    }
    out << "none" << endl;
}
void Delete(const string& key){
    int hash = hashFun(key);
    for(int i = 0; i < a[hash].size(); i++){
        if(a[hash][i].x == key){
            a[hash].erase(a[hash].begin() + i);
            return;
        }
    }
}
int main() {
    string s;
    while(in){
        in >> s;
        if(!in.eof()){
            if(s == "put"){
                string key, word;
                in >> key >> word;
                Put(key, word);
            } else if(s == "get"){
                string key;
                in >> key;
                Get(key);
            } else {
                string key;
                in >> key;
                Delete(key);
            }
        }
    }
    return 0;
}
