#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int craw[n];
    for (size_t i = 1; i <= n; i++)
    {
        cin >> craw[i];
    }
    int alive_person = 1;
    int last_craw = craw[n];
    for (int  i = n - 1; i >= 1; i--)
    {
        if (!last_craw)
        {
            alive_person++;
        }
        last_craw = max(last_craw - 1, craw[i]);
    }
    cout << alive_person;
    
    return 0;
}