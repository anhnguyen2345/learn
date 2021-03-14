#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,x;
    cin >> n;
    cin >> x;
    vector<int> arr(n);
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    long long sum = 0;
    for (int i : arr)
    {
        sum += 1LL*x*i;
        if(x>1)x--;
    }
    cout << sum;
    return 0;
}