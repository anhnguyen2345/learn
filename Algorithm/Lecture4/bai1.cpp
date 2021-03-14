#include <iostream>
#include <stack>
using namespace std;
#define OPERAND         1
#define OPERATOR        2
#define CLOSEBRAKETS    3
#define OPENBRAKETS    4
int whatsymbol(char ch){
    if (ch >= 'a' && ch <= 'z'){
        return OPERAND;
    }
    else if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^'){
        return OPERATOR;
    }
    else if (ch == ')'){
        return CLOSEBRAKETS;
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    stack<char> mainstack;
    string exp;
    for (int i = 0; i < t; i++)
    {
        cin >> exp;
       
        for(char symbol : exp){
            int type = whatsymbol(symbol);
            switch (type)
            {
            case OPERAND:{
                cout << symbol;
            }   
                break;
            case OPERATOR:{
                mainstack.push(symbol);
            }   
                break;
            case CLOSEBRAKETS:{
                    cout << mainstack.top();
                    mainstack.pop();
                }   
                break;
            default:
                break;
            }
        }
        cout << endl;        
    }
    return 0;
}