#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,a, len = 2;
    int last_occurrences[100100] ={0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        last_occurrences[a] = i;
        if (last_occurrences[a-1]>last_occurrences[a+1])
        {
            len = max(len, i - max(last_occurrences[a-2],last_occurrences[a+1]));
        }
        else{
            len = max(len, i - max(last_occurrences[a+2],last_occurrences[a-1]));
        }
    }
    cout << len;
    return 0;
}