#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix;
vector<vector<int> > ans;

void getPrefix(string image) {
    prefix[0] = 0;
    int j = 0, i = 1;
    while (i < image.length() && j < image.length()) {
        if (image[i] == image[j]) {
            prefix[i] = j + 1;
            i++;
            j++;
        } else if (j == 0) {
            prefix[i] = 0;
            i++;
        } else {
            j = prefix[j - 1];
        }
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    s += "#";
    prefix.resize(s.size());
    getPrefix(s);
    ans.resize(s.size(), vector<int>(n, 0));
    for (int i = 0; i < s.size(); i++) {
        for (char c = 'a'; c < 'a' + n; c++) {
            if (i > 0 && c != s[i]) {
                ans[i][c - 'a'] = ans[prefix[i - 1]][c - 'a'];
            } else {
                ans[i][c - 'a'] = i + (c == s[i]);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}