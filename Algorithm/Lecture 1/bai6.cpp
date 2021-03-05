#include <iostream>
#include "math.h"
using namespace std;


int main(int argc, char const *argv[])
{
    int index = 1;
    int total_segments;
    cin >> total_segments;
    int arr[2*total_segments];
    for (size_t i = 0; i < 2*total_segments; i++)
    {
        cin >> arr[i];
    }
    int _min = arr[0];
    int _max = arr[1];
    for (size_t i = 2; i < 2*total_segments; i = i + 2)
    {
        if (_min >= arr[i] && _max <= arr[i+1])
        {
            index = index + i/2;
            _min = arr[i];
            _max = arr[i+1];
        }
    }
    if(_min == _max){
        printf("-1");
    }
    else{
        cout << index;
    }
    return 0;
}