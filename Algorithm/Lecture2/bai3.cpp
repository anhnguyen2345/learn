#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int _soldiers, _vests,X,Y;
    cin >> _soldiers;
    cin >> _vests;
    cin >> X;
    cin >> Y;
    int size_soldiers[_soldiers], size_vests[_vests], match[_soldiers+_vests];
    for (size_t i = 0; i < _soldiers; i++)
    {
        cin >> size_soldiers[i];
    }
    for (size_t i = 0; i < _vests; i++)
    {
        cin >> size_vests[i];
    }
    int idx_soldiers = 0, idx_vests = 0, index_match = 0;
    while (idx_soldiers < _soldiers && idx_vests < _vests)
    {
        if (size_soldiers[idx_soldiers] - X <= size_vests[idx_vests] && size_soldiers[idx_soldiers] + Y >= size_vests[idx_vests])
        {
            match[index_match] = idx_soldiers+1;
            match[++index_match] = idx_vests+1;
            index_match++;
            idx_vests++;
            idx_soldiers++;
        }
        else if (size_vests[idx_vests] < size_soldiers[idx_soldiers])
        {
            idx_vests++;
        }
        else{
            idx_soldiers++;
        }
    }
    
    cout << (index_match+1)/2 << endl;
    for (size_t i = 0; i < index_match; i++)
    {
        cout << match[i];
         if (i%2 == 1 && i != 0)
         {
            cout << endl;
         }
         else{
             cout << " ";
         }
    }
    return 0;
}