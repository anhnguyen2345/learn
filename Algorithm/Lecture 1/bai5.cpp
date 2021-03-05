#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int sum_arr1,sum_arr2;
    int K, M;
    cin >> sum_arr1;
    cin >> sum_arr2;
    int arr1[sum_arr1];
    int arr2[sum_arr2];
    cin >> K;
    cin >> M;
    for ( int i = 0; i < sum_arr1; i++)
    {
        cin >> arr1[i];
    }
    for ( int i = 0; i < sum_arr2; i++)
    {
        cin >> arr2[i];
    }
    if(arr1[K - 1] < arr2[sum_arr2 - M]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }   
    return 0;
}