#include <iostream>
#include <list>
#include <fstream>

using namespace std;

int main() {
    ifstream in("queue.in");
    ofstream out("queue.out");
    int n;
    int y; //переменная, в которой храним число, следующее после команды '+'
    char x; //переменная, в которой храним команды
    in >> n;
    list<int> list1; //создали список
    for (int i = 0; i < n; ++i) {
        in >> x; //ввели команду
        if (x == '+') { //если команда '+', то ввели число после нее, запихнули в начало списка
            in >> y;
            list1.insert(list1.begin(), y);
        }
        if (x != '+') { //если команда не '+', то выводим последний элемент, затем удаляем его
            out << list1.back();
            list1.pop_back();
            out << endl;
        }
    }
    return 0;
}



