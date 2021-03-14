#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define LEFT  0
#define RIGHT 1
struct car
{
    int time_arrive;
    int rank;
};


int main(int argc, char const *argv[])
{
    int c, n , t, m;
    cin >> c;
    while (c--){
        cin >> n;
        cin >> t;
        cin >> m;
        string pos;
        bool ferry_pos = LEFT;
        int total = 0;
        car _car;
        queue<car> q[2];
        for (size_t i = 0; i < m; i++)
        {
            
            cin >> _car.time_arrive;
            cin >> pos;
            _car.rank = i;
            if(pos == "left"){
                q[0].push(_car);
            }
            else{
                q[1].push(_car);
            }
        }
        
        int time_car[10000] = {0};
        while (!q[0].empty() || !q[1].empty())
        {
            int time = 0, cnt = 0;
            if (q[0].empty()) 
            {
                time = q[1].front().time_arrive;
            }
            else if (q[1].empty()) 
            {
                time = q[0].front().time_arrive;
            }
            else{
                time = min(q[0].front().time_arrive,q[1].front().time_arrive);
            }
            total = max(time,total);
            while (!q[ferry_pos].empty() && cnt < n && q[ferry_pos].front().time_arrive <= total)
            {
                time_car[q[ferry_pos].front().rank] = t + total;
                //cout << "time upload " << "rank car" << time_car[q[ferry_pos].front().rank] << t + total << endl;
                q[ferry_pos].pop();
                ++cnt;
            }
            total += t;
            ferry_pos = !ferry_pos;
            
        }
        for (size_t i = 0; i < m; i++)
        {
            cout << time_car[i] << endl;
        }
        if(c)cout << endl;
    }
    return 0;
}