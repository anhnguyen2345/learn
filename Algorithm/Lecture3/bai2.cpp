#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,a,b;
    cin >> n;
    cin >> a;
    cin >> b;
    vector<int> complexity(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> complexity[i];
    }
    sort(complexity.begin(),complexity.end());
    long int value = complexity[b] - complexity[b-1];
    cout << value;
    return 0;
}