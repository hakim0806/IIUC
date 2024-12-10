#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

class Heap
{
    vector<int> heap;

public:
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
    void display()
    {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
    void del_heap()
    {
        if (heap.empty())
            return;

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        int cur = 0;
        while (1)
        {
            int l = cur * 2 + 1, r = cur * 2 + 2;
            int last = heap.size() - 1;
            if (l <= last && r <= last)
            {
                if (heap[l] >= heap[r] && heap[l] > heap[cur])
                {
                    swap(heap[l], heap[cur]);
                    cur = l;
                }
                else if (heap[r] >= heap[l] && heap[r] > heap[cur])
                {
                    swap(heap[r], heap[cur]);
                    cur = r;
                }
                else
                {
                    break;
                }
            }
            else if (l <= last)
            {
                if (heap[l] > heap[cur])
                {
                    swap(heap[l], heap[cur]);
                    cur = l;
                }
                else
                {
                    break;
                }
            }
            else if (r <= last)
            {
                if (heap[r] > heap[cur])
                {
                    swap(heap[r], heap[cur]);
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

    int getFront()
    {
        if (heap.size() > 0)
            return heap[0];
        return -1;
    }
      bool empty()
    {
        return heap.empty();  
    }
};

class Priority_queue
{
public:
    Heap h;

    void enque(int x)
    {
        h.insert(x);
    }

    void deque()
    {
        h.del_heap();
    }

    int get_front()
    {
        return h.getFront();
    }
    bool empty()
    {
        return h.empty();  
    }
};

int main()
{
    int n;
    cin >> n;
    // cout << "Option 1 for MAX PQ" << endl;
    // cout << "Option 2 for MIN PQ" << endl;
    // int op;
    // cin >> op;

    Priority_queue pq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.enque(x);
           // cout << "Front: " << pq.get_front() << endl;
        }    
        // pq.deque();
        // cout << "After Deque Front: " << pq.get_front() << endl;
        while(!pq.empty())
        {
            cout<< pq.get_front() <<" ";
            pq.deque();
        }
    return 0;
}
