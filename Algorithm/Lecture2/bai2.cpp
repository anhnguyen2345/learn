#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int problems_round = 0, problems_prepare = 0;
    cin >> problems_round;
    cin >> problems_prepare;
    int arr1[problems_round], arr2[problems_prepare];
    for (size_t i = 0; i < problems_round; i++)
    {
        cin >> arr1[i];
    }
    for (size_t i = 0; i < problems_prepare; i++)
    {
        cin >> arr2[i];
    }
    int cnt = 0, index = 0;
    while (cnt < problems_round && index < problems_prepare)
    {
        if(arr1[cnt] <= arr2[index]){
            cnt++;
        }
        index++;
    }
    cout << problems_round - cnt;
    return 0;
}
// 20 25
// 30 32 34 39 42 43 45 46 47 48 52 55 56 57 58 59 60 65 67 69
// 2 3 4 5 8 9 14 16 18 20 24 27 29 30 34 35 36 37 40 41 42 43 44 45 46