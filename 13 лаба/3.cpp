#include <fstream>
#include <vector>

using namespace std;

ifstream in ("prefix.in");
ofstream out ("prefix.out");

vector<int> prefix;

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

int main() {
    string image;
    in >> image;
    prefix.resize(image.length());
    getPrefix(image);
    for(int i : prefix){
        out << i << ' ';
    }
    return 0;
}
