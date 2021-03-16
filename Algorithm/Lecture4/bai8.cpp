#include <iostream>
#include <stack>
using namespace std;


int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        stack<int> st;
        cin >> s;
        int size = s.size();
        int len = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (s[i] == '<')
            {
                st.push(i);
            }
            else 
            {
                if (st.empty())
                {
                    break;
                }
                else{
                    
                    st.pop();
                    if(st.empty()){
                        len = i + 1;
                    }
                }

            }
        }

        cout << len << endl;
    }
    
    return 0;
}