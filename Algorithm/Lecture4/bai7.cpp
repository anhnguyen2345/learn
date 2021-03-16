#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct my_query
{
    long long int t_appear;
    long long int t_toprocess;
    int rank;
};

long long int _max(long long int a, long long int b){
    if(a > b) return a;
    return b;
}
int main(int argc, char const *argv[])
{
    int n,b;
    cin >> n;
    cin >> b;
    my_query arr[n];
    long long int t_process_q[n];
    queue<my_query> q;
    long long int time_start = 0, time_finish = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i].t_appear;
        cin >> arr[i].t_toprocess;
        arr[i].rank = i;
    }
    for (size_t i = 0; i < n; i++)
    {
        if(!q.empty()){
            time_start = _max(time_finish,q.front().t_appear);

        }
        else{
            time_start = _max(time_finish,arr[i].t_appear);
        }
        if(time_finish > arr[i].t_appear && q.size() < b){
            //cout << "push when i = " << i << endl;
            q.push(arr[i]);
        }
        else if(time_finish <= arr[i].t_appear && !q.empty()){
            //cout << "pop q when i = " << i << endl;
            my_query v = q.front();
            q.pop();
            time_finish = time_start + v.t_toprocess;
            //cout << "rank " << i << " " << time_start + v.t_toprocess << endl; 
            t_process_q[v.rank] = time_start + v.t_toprocess;
            q.push(arr[i]);
        }
        else if(time_finish >= arr[i].t_appear && q.size() >= b)
        {
            //cout << "reject when i = " << i << endl;
            t_process_q[arr[i].rank] = -1;
        }
        if (q.empty())
        {
            //cout << "q  empty when i = " << i << endl;
            time_finish = time_start + arr[i].t_toprocess;
            t_process_q[arr[i].rank] = time_finish;
        }    
        
    }
    while(!q.empty()){
        //cout << "get query in q" << endl;
        my_query v = q.front();
        q.pop();
        time_finish = time_finish + v.t_toprocess;
        t_process_q[v.rank] = time_finish;
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << t_process_q[i] << " ";
    }
            
    return 0;
}