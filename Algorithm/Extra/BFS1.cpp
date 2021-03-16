#include<bits/stdc++.h>
using namespace std;
int main()

{
    int n, c=0;
    cin>>n;
    vector<int> level(n+1);
    vector<bool> vis(n+1, false);
    vector<int> al[n+1];
    int n1, n2, x ;
    for(int i = 0; i<n-1; i++)
    {
        cin>>n1>>n2;
        // since it has undirected edges
        al[n1].push_back(n2);
        al[n2].push_back(n1);
    }
    cin>>x;
    queue<int> q;
    q.push(1);
    level[1] = 1;
    vis[1] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i=0; i<al[p].size(); i++)
        {
            if(vis[al[p][i]]==false)
            {
                level[al[p][i]] = level[p] + 1;
                if(level[al[p][i]]==x)
                    c++;

                q.push(al[p][i]);

                vis[al[p][i]]=true;
            }
        }
    }
    cout<<c;
}