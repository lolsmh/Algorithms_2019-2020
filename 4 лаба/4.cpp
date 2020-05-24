#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream in("postfix.in");
    ofstream out("postfix.out");
    stack<int> num;
    char x;
    int y;
    while (in) { //пока ввод
        in >> x;
        if (!in.eof()) { // если не конец файла
            if (x != '+' && x != '-' && x != '*') { //если не операция
                y = x - '0'; // переводим в число
                num.push(y); // пихаем в стек
            }
            if (x == '+') { // если команда + берем из стека два числа, складываем и запихиваем в стек
                int a, b;
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                b += a;
                num.push(b);
            }
            if (x == '-') { // если команда - берем из стека два числа, вычитаем и запихиваем в стек
                int a, b;
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                b -= a;
                num.push(b);
            }
            if (x == '*') { // если команда * берем из стека два числа, умножаем и запихиваем в стек
                int a, b;
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                b *= a;
                num.push(b);
            }
        }
    }
    out << num.top() << endl; // выводим результат
    return 0;
}

