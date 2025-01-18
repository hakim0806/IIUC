// insert , delete , and sort of Max heap 
#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
vector<int> heap_sort;
void Insert(int v)
{
    heap.push_back(v);
    int cur_idx = heap.size() - 1;
    while (cur_idx != 0)
    {
        int per_idx = (cur_idx - 1) / 2;
        if (heap[per_idx] < heap[cur_idx])
        {
            swap(heap[per_idx], heap[cur_idx]);
        }
        else
        {
            break;
        }
        cur_idx = per_idx;
    }
}
void heap_del()
{
    heap_sort.push_back(heap[0]);
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    int cur = 0;
    while (1)
    {
        int l_idx = cur * 2 + 1;
        int r_idx = cur * 2 + 2;
        int last = heap.size() - 1;
        if (l_idx <= last && r_idx <= last)
        {
            // 2ti ache
            if (heap[l_idx] >= heap[r_idx] && heap[l_idx] > heap[cur])
            {
                // left boru
                swap(heap[l_idx], heap[cur]);
                cur = l_idx;
            }
            else if (heap[r_idx] >= heap[l_idx] && heap[r_idx] > heap[cur])
            {
                // right boru
                swap(heap[r_idx], heap[cur]);
                cur = r_idx;
            }
            else
            {
                break;
            }
        }
        else if (l_idx <= last)
        {
            // left ache only
            if (heap[l_idx] > heap[cur])
            {
                swap(heap[l_idx], heap[cur]);
                cur = l_idx;
            }
            else
            {
                break;
            }
        }
        else if (r_idx <= last)
        {
            //right ache only
            if (heap[r_idx] > heap[cur])
            {
                swap(heap[r_idx], heap[cur]);
                cur = r_idx;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << heap[i] << " ";
    }
    cout<<endl;
    
     for (int i = 0; i < n; i++)
    {
        heap_del();
    }
    for(int i : heap_sort)
    {
        cout<< i << " ";
    }
    return 0;
}
