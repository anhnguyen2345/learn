#include <iostream>
#include <queue>
#include <stack>
using namespace std;


int main(int argc, char const *argv[])
{
    int p,c, patient,_case = 0;
    char command;
    vector<int> emergencies(1001);
    while (cin >> p && p != 0)
    {
        queue<int> q;
        stack<int> st;
        for (size_t i = 1; i <= p; i++)
        {
            q.push(i);
        }
        cin >> c;
        cout << "Case " << ++_case << ":"<<endl;
        while (c--)
        {
            cin >> command;
            int temp;
            switch (command)
            {
            case 'N':{
                    
                    if(st.size()> 0){
                        cout << st.top() << endl;
                        st.pop();
                    }
                    else
                    {
                        temp = q.front();
                        if(emergencies[temp]){
                        //cout << "meet temp " << temp << endl;
                            emergencies[temp]--;
                            q.pop();
                        }
                        temp = q.front(); 
                        cout << temp << endl;
                        q.push(temp);
                        q.pop();
                    }
                }
                break;
            case 'E':{
                cin >> patient;
                st.push(patient);
                //cout << "emergencies occurrence " << patient << endl;
                emergencies[patient]++;
                q.push(patient);
            }
                break;
            default:
                break;
            }
        }
    }
    
    return 0;
}