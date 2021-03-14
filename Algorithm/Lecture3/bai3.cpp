#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> sorted_arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }// 1 2 3 4 7 6 5 9    1 2 3 4 5 6 7 9
    sort(sorted_arr.begin(),sorted_arr.end());
    int i = 0, j = 0;
    for (i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1]){
            break;
        }
        else if(i == n - 2 && arr[i] < arr[i+1]){
            cout << "yes" << endl;
            cout << "1 1";
            return 0;
        }
    }
    for (j = i + 1 ; j < n; j++)
    {
        if(arr[j] < arr[j+1]){
            break;
        }
        // else if (j = n - 1)
        // {
        //     j = n - 1;
        //     cout << "OKs";
        //     break;
        // }
               
    }
    sort(arr.begin()+i,arr.begin()+j+1);
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    for (size_t i = 0; i < n; i++)
    {
        if(sorted_arr[i] != arr[i]){
            cout << "no";
            return 0;
        }
    }
    cout << i+1 << " " << j+1;
    return 0;
}