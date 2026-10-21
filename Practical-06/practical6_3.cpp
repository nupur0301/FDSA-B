#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int precedence(char op){
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
int main(){
    string infix, postfix = "";
    stack<char> s;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    for (char ch : infix){
        if (ch == ' ')
            continue;
        if (isalnum(ch)){
            postfix += ch;
        }
        else if (ch == '('){
            s.push(ch);
        }
        else if (ch == ')'){
            while (!s.empty() && s.top() != '(')   {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)){       {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
}
    while (!s.empty()){
        postfix += s.top();
        s.pop();
    }
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
    }