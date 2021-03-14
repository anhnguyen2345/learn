#include <iostream>
#include <stack>
using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    while ( cin>>n && n != 0) {
        int arr[n];
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int i = 0, truck_value = 0;
        stack<int> mainstack;
        while (i < n)
        {
            while (mainstack.size() && mainstack.top() == truck_value + 1)
            {
                truck_value++;
                mainstack.pop();
            }
            if (arr[i] != truck_value + 1)
            {
                mainstack.push(arr[i]);
            }
            else{
                truck_value++;
            }
            i++;
        }
        while (mainstack.size() && mainstack.top() == truck_value + 1)
        {
            truck_value++;
            mainstack.pop();
        }
        if(n == truck_value){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}