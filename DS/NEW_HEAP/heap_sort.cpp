#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
vector<int> sortheap;
void insert(int x)
{
    heap.push_back(x);
    int cur = heap.size() - 1;
    while (cur != 0)
    {
        int pr = (cur - 1) / 2;
        if (heap[cur] > heap[pr])
        {
            swap(heap[cur], heap[pr]);
        }
        else
        {
            break;
        }
        cur = pr;
    }
}
void insert_m(int x)
{   
    heap.push_back(x);
    int cur = heap.size() - 1;
    while (cur != 0)
    {
        int pr = (cur - 1) / 2;
        if (heap[cur] < heap[pr])
        {
            swap(heap[cur], heap[pr]);
        }
        else
        {
            break;
        }
        cur = pr;
    }
}
void del_heap_m()
{
    sortheap.push_back(heap[0]);
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    int cur = 0;
    while(1)
    {
        int l = cur*2+1, r = cur*2+2;
        int last = heap.size()-1;
        if(l<=last && r <= last)
        {
           // 2ti thakle
             if(heap[l]<=heap[r] && heap[l]< heap[cur])
             {
                   swap(heap[l],heap[cur]);
                   cur = l;
             }
             else if(heap[r]<=heap[l] && heap[r]<heap[cur])
             {
                swap(heap[r],heap[cur]);
                cur = r;
             }
             else
             {
                break;
             }
        }
        else if(l<=last)
        {
            //left thakle
            if(heap[l]<heap[cur])
            {
                swap(heap[l],heap[cur]);
                cur = l;
            }
            else
            {
                break;
            }
        }
        else if (r<=last){
            //right thakle
             if(heap[r]<heap[cur])
            {
                swap(heap[r],heap[cur]);
                cur = r;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
void del_heap()
{
    
    sortheap.push_back(heap[0]);
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    int cur = 0;
    while(1)
    {
        int l = cur*2+1, r = cur*2+2;
        int last = heap.size()-1;
        if(l<=last && r <= last)
        {
           // 2ti thakle
             if(heap[l]>=heap[r] && heap[l]> heap[cur])
             {
                   swap(heap[l],heap[cur]);
                   cur = l;
             }
             else if(heap[r]>=heap[l] && heap[r]>heap[cur])
             {
                swap(heap[r],heap[cur]);
                cur = r;
             }
             else
             {
                break;
             }
        }
        else if(l<=last)
        {
            //left thakle
            if(heap[l]>heap[cur])
            {
                swap(heap[l],heap[cur]);
                cur = l;
            }
            else
            {
                break;
            }
        }
        else if (r<=last){
            //right thakle
             if(heap[r]>heap[cur])
            {
                swap(heap[r],heap[cur]);
                cur = r;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
void print()
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, op;
    cin >> n >> op;
    if (op == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            insert(x);
        }
        //del_heap();
        //print();
        for(int i = 0; i<n; i++)
        {
            del_heap();
        }
        for(int x : sortheap)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else if (op == 2)
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            insert_m(x);
            
        }
        //del_heap_m();
        //print();
        for(int i =0; i<n; i++)
        {
            del_heap_m();
        }
        for(int x : sortheap)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
   // print();
    
    return 0;
}
