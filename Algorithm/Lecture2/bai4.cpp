#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int numbers, len_seg, sum_distinct = 0, L, R, Flag = 0;
    cin >> numbers;
    cin >> len_seg;
    int arr[numbers];
    int occurrences[199999];
    for (int i = 1; i <= numbers; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= numbers; i++)//get R
    {
        if (occurrences[arr[i]])//if occurrences then jump i++;
        {   
            // cout << "index " << i; 
            continue;
        }
        occurrences[arr[i]]=1;
        sum_distinct++;
        if (sum_distinct == len_seg)
        {
            R = i;
            Flag = 1;
            break;
        }
    }
    sum_distinct = 0;
    memset(occurrences,0,sizeof(occurrences));
    for (int i = R; i >= 1; i--)//get L
    {
        
        if (occurrences[arr[i]]) //if occurrences then jump i++;
        {
            // cout << "index1 " << i; 
            continue;
        }
        occurrences[arr[i]]=1;
        sum_distinct++;
        if (sum_distinct == len_seg)
        {
            L = i;
            break;
        }
    }
    if (Flag)
    {
        cout << L << " " << R;
    }
    else{
        cout << "-1 -1";
    }
    return 0;
}