#include <bits/stdc++.h>
using namespace std;
void TOH(int n, char begin , char aug, char end)
{
    if( n == 1)
    {
        cout<<"MOVE : " <<n << " from " << begin << " to " << end <<endl;
        return;
    }
    TOH(n-1, begin, end, aug);
    cout<<"MOVE : " <<n << " from " << begin << " to " << end <<endl;
    TOH(n-1, aug ,begin, end);
}
int main()
{
    int n;
    cin>>n;
    TOH(n,'A','B','C');
}