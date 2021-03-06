#include <iostream>
#include "math.h"
using namespace std;


int main(int argc, char const *argv[])
{
    int total = 0, tries_times = 0, cnt1 = 0, cnt2 = 0;
    cin >> total;
    cin >> tries_times;
    string arr[total+1];
    for (size_t i = 0; i <= total; i++)
    {
        cin >> arr[i];
    }
    int size_pw = arr[total].size();
    for (size_t i = 0; i < total; i++)
    {
        if(arr[i].size() < size_pw){
            cnt1++;
        }
        else if (arr[i].size() == size_pw)
        {
            cnt2++;
        }
    }
    cout << (cnt1 + cnt1/tries_times*5 + 1) << " " << (cnt1+cnt2) + (cnt1+cnt2-1)/tries_times*5;
    return 0;
}