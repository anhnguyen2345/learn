#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int chocolate, arr[100100], sum_Alice = 0, sum_Bob = 0;
    cin >> chocolate;
    int left = 0, right = chocolate -1;
    for (size_t i = 0; i < chocolate; i++)
    {
        cin >> arr[i];
    }
    sum_Alice += arr[left];
    left++;
    while (left<=right)
    {
        // cout << "left " << left << "right " << right;
        if(sum_Alice>sum_Bob){
            // cout << "here1" << endl;
            sum_Bob = sum_Bob + arr[right];
            right--;
        }
        else if(sum_Alice<sum_Bob){
            // cout << "here2" << endl;
            sum_Alice = sum_Alice + arr[left];
            left++;
        }
        else if(sum_Alice==sum_Bob && left == right){
            // cout << "here3" << endl;
            sum_Alice = sum_Alice + arr[left];
            left++;
        }
        else{
            // cout << "here4" << endl;
            sum_Bob = sum_Bob + arr[right];
            right--;
            sum_Alice =sum_Alice + arr[left];
            left++;
        }
        // cout << "sum_Alice " << sum_Alice << "sum_Bob " << sum_Bob << endl;

    }
    cout << left << " "<<chocolate - left;
    
    
    return 0;
}
//while(left != right)
// 1 2 2 3 4 1 => sum1 = sum2 && left = right
// 7 
// 4 2 4 6 5 8 
// sum1 - sum2 > 0 => 2 tiep