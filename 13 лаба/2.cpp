#include <fstream>
#include <vector>

using namespace std;

ifstream in ("search2.in");
ofstream out ("search2.out");

vector<int> prefix;
vector<int> ans;

void getPrefix(string image){
    prefix[0] = 0;
    int j = 0, i = 1;
    while(i < image.length() && j < image.length()){
        if(image[i] == image[j]){
            prefix[i] = j + 1;
            i++;
            j++;
        } else if (j == 0){
            prefix[i] = 0;
            i++;
        } else {
            j = prefix[j - 1];
        }
    }
}

int kmp(string temp, int s1L, int s2L){
    int count = 0;
    getPrefix(temp);
    for (int i = 0; i < s2L; i++){
        if (prefix[s1L + i + 1] == s1L){
            ans.push_back(i - s1L + 2);
            count++;
        }
    }
    return count;
}

int main() {
    string word, image, temp;
    in >> word >> image;
    temp = word + "#" + image;
    int s1L = word.length(), s2L = image.length();
    prefix.resize(temp.length());
    out << kmp(temp, s1L, s2L) << endl;
    for(int i : ans){
        out << i << ' ';
    }
    return 0;
}