#include <bits/stdc++.h>
using namespace std;
vector<int>m[10005];
bool vis[10005];
void dfs(int s)
{
    stack<int>q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int p = q.top();
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
    dfs(s);
}



// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<int> v[N];
// bool vis[N];

// void dfs(int src)
// {
//     cout << src << endl;
//     vis[src] = true;
//     for (int child : v[src])
//     {
//         if (vis[child] == false)
//             dfs(child);
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;
//         v[a].push_back(b);
//         v[b].push_back(a);
//     }
//     memset(vis, false, sizeof(vis));
//     dfs(0);
//     return 0;
// }