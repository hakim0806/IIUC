#include <bits/stdc++.h>
using namespace std;

vector<int> add (const vector<int>&a, vector<int>&b)
{
    vector<int>ans;
    int carry = 0, sum =0;
    int i = 0, j =0;
    while(i < a.size() || j< b.size() || carry)
    {
        sum = carry;
        if(i<a.size()) sum +=a[i++];
        if(j<b.size()) sum +=b[j++];
        ans.push_back(sum%10);
        carry = sum/10;
    }
    return ans;
}
void fibo (int n)
{
    if(n == 0)
    {
        cout<< 0 <<endl;
        return ;
    }
    if (n == 1)
    {
       cout<< 1 <<endl;
       return;
    }
    vector<int> a(1,0);
    vector<int> b(1,1);
    vector<int> c;
for(int i = 2; i <=n; i++)
{
    c= add(a,b);
    a= b;
    b =c;
}
for(auto it = c.rbegin(); it!=c.rend(); it++)
{
    cout<<*it;
}
cout<<endl;

}
int main()
{
    int n;
    cin>>n;
    fibo(n);
}

