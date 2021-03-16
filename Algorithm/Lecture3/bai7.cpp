#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool option(int a, int b){
    return a > b;
}
int main(int argc, char const *argv[])
{
    int k, arr[12];
    cin >> k;
    for (size_t i = 0; i < 12; i++)
    {
        cin >> arr[i];
    }
    if(k==0){cout << "0"; return 0;}
    sort(arr,arr+12,option);
    int sum = 0;
    for (size_t i = 0; i < 12; i++)
    {
        sum = sum + arr[i];
        if(sum >= k){
            cout << i+1;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}