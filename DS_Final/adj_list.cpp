#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> m[n];
    while(e--)
    {
        int a,b; cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    for(int i = 0; i<n; i++)
    {
        for(int  x : m[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}