#include <fstream>
#include <vector>
using namespace std;

ifstream in ("search1.in");
ofstream out ("search1.out");

vector<int> cmp;

int BruteForce(string n, string m){
    int nLength = n.length(), mLength = m.length(), index, count = 0;
    for(int i = 0; i < nLength; i++){
        if(n[i] == m[0]){
            index = i;
            if(mLength != 1) {
                for (int j = 1; j < mLength; ++j) {
                    if (n[i + j] == m[j]) {
                        if (j == mLength - 1) {
                            cmp.push_back(index);
                            count++;
                        }
                        continue;
                    } else {
                        break;
                    }
                }
            } else {
                cmp.push_back(index);
                count++;
            }
        }
    }
    return count;
}

int main() {
    string n, m;
    in >> m >> n;
    int ans = BruteForce(n, m);
    out << ans << endl;
    for(int i : cmp){
        out << i + 1 << ' ';
    }
    return 0;
}
