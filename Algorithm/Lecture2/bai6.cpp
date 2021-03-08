#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int arr[N];
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    int len_max = 0, len_max_temp = 0, idx_start = 1, idx_end = 1;
    while (idx_end <= N)
    {
        if (abs(arr[idx_start]-arr[idx_end]) > 1)
        {
            cout << "step " << idx_end << endl;
            len_max_temp = idx_end - idx_start - 1;
            if (len_max <= len_max_temp)
            {
                len_max = len_max_temp;
            }
            idx_start++;
        }
        else if (abs(arr[idx_start]-arr[idx_end]) <= 1 && idx_end == N)
        {
            len_max = idx_end - idx_start + 1;
            break;
        }
        else{
            idx_end++;
        }
    }
    cout << len_max;
    return 0;
}