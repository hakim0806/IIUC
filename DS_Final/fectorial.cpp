#include <bits/stdc++.h>
using namespace std;
// int fect(int n)// recursive 
// {
//     if( n == 1)
//     { 
//         return 1;
//     }
//     return n*fect(n-1);
// }
int fect(int n)// non resursive 
{
    int r = 1;
    for(int i = 2; i<=n; i++)
    {
        r*=i;
    }
    return r;
}
int main()
{
    int n;
    cin>>n;
    cout<<fect(n)<<endl;
}