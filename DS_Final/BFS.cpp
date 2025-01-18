#include <bits/stdc++.h>
using namespace std;
vector<int>m[10005];
bool vis[10005];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        cout<< p <<" ";
        for( int child : m[p])
        {
            if(vis[child] == false)
            {
                 q.push(child);
                vis[child] = true;
            }
        }
    }
}
int main()
{
     int n,e;
    cin>>n>>e;
    //vector<int> m[n];
    while(e--)
    {
        int a,b; cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int s; cin>>s;
    memset(vis,false,sizeof(vis));
    bfs(s);
}