#include <fstream>
#include <string>
#include <stack>


using namespace std;

bool checkString(string str)
{
    stack<char> stack1;
    for(int i = 0; i < str.length(); i++){
        if ((str[i] =='(') || (str[i] =='{') || (str[i] =='[')) {
            stack1.push(str[i]); // если открывающая скобка - помещаем ее в стек
        }
        else { // если не открывающая
            if (stack1.size() == 0) {
                return false; // если стек пуст, значит скобочная последовательность неправильная.
            }
            char c = stack1.top(); // берем последнюю открывающую скобку
            stack1.pop();

            if ((c == '(' && str[i] != ')') ||  // если тип последней открывающей скобки
                (c == '{' && str[i] != '}') ||  // не совпадает с текущей закрывающей скобкой -
                (c == '[' && str[i] != ']')) {   // - скобочная последовательность неправильная
                return false;
            }
        }    
    }
    return (stack1.size() == 0);   // если после обработки строки, остались
    // незакрытые скобки, скобочная последовательность неправильная
}

int main() {
    ifstream in ("brackets.in");
    ofstream out ("brackets.out");
    while(!in.eof()) { //пока файл не пуст
        string t;
        in >> t;
        int n = t.length();
        if(n != 0){ //проверка на нулевую строку
            if (checkString(t)) {
                out << "YES" << endl;
            } else {
                out << "NO" << endl;
            }
        }
    }
    return 0;
}
