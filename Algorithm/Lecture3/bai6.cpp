#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool option(int a, int b){
    return a > b;
}
int main(int argc, char const *argv[])
{
    int n,distinct = 0,max_ = 0;
    cin >> n;
    int x,occurrences[1010]={0};
    for (size_t i = 0; i < n; i++)
    {
       cin >> x;
       if(occurrences[x] ==0){
           distinct++;
       }
       occurrences[x]++;
        max_ =  max(occurrences[x],max_);
    }
    cout << max_ << " " << distinct;
    return 0;
}