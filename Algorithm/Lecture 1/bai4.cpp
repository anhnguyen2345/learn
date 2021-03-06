#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string S_string,T_string;
    cin >> S_string >> T_string;
    for (size_t i = S_string.size()-1; i >=0; i--)
    {
        if (S_string[i]== 'z')
        {
            S_string[i] = 'a';
        }
        else{
            S_string[i]++;
            break;
        }
    }
    if (S_string == T_string)
    {
        cout << "No such string";
    }
    else{
        cout << S_string;
    }
    return 0;
}
