#include <iostream>
#include <queue>
using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n != 0)
    {
        int arr[n];
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        cout << "Discarded cards:";
        while (q.size() >= 2)
        {
            cout << " " << q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            if (q.size() != 1)
				cout << ",";
        }
        cout << endl << "Remaining card: " << q.front() << endl;
    }
    return 0;
}