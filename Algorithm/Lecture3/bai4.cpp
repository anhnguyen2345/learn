#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,w;
    cin >> n;
    cin >> w;
    int arr[2*n];
    for (size_t i = 0; i < 2*n; i++)
    {
        cin >> arr[i]; 
    }
    sort(arr,arr+2*n);
    double vol = min(1.0*arr[0],1.0*arr[n]/2.0);
    double _max = vol * 3 * n;
    _max = min(_max,1.0*w);
    printf("%.6lf\n",_max);
    return 0;
}