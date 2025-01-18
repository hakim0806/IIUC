
#include <bits/stdc++.h>
using namespace std;
vector<int>h;
int t_size;
int hashing_fun(int key)
{
    return key % t_size;

}
void insert(int key)
{
    int idx = hashing_fun(key);
    while(h[idx] !=-1)
    {
        idx = (idx+1)% t_size;
    }
    h[idx] = key;
}
 void disply()
 {
    for(int i = 0; i<t_size; i++)
    {
        if( h[i] == -1)
        {
            cout<< i <<" : " << " empty" <<endl;
        }
        else{
           cout<< i <<" : " << h[i] <<endl;
        }
    }
 }
int main()
{
    cin>>t_size;
    // memset(h,-1,sizeof(h));
    h.assign(t_size,-1);
    int key; 
    while(cin>>key)
    {
        if (key == -1) break;
        insert(key);
    }
    disply();
}