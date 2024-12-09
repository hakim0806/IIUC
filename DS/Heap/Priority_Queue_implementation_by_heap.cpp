#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
class Heap
{
    vector<int> heap;
    int SIZE = 0;

public:
    Heap(int n)
    {
        heap.resize(n + 1, 0);
    }
    void insert(int x)
    {
        heap[++SIZE] = x;
        int n = SIZE;
        while (n > 1)
        {
            if (heap[n / 2] < heap[n])
            {
                swap(heap[n / 2], heap[n]);
            }
            else
                break;
            n = n / 2;
        }
    }
    void Insert(int x) 
    {
        heap[++SIZE] = x;
        int n = SIZE;
        while (n > 1)
        {
            if (heap[n / 2] > heap[n])
            {
                swap(heap[n / 2], heap[n]);
            }
            else
                break;
            n = n / 2;
        }
    }
    void display()
    {
        for (int i = 1; i <= SIZE; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
    void del_heap()
    {
        if (SIZE == 0)
            return;
        ans.push_back(heap[1]);
        heap[1] = heap[SIZE--];
        int cur = 1;
        while (true)
        {
            int l = cur * 2;
            int r = cur * 2 + 1;
            int largest = cur;
            if (l <= SIZE && heap[l] > heap[largest])
                largest = l;
            if (r <= SIZE && heap[r] > heap[largest])
                largest = r;

            if (largest != cur)
            {
                swap(heap[cur], heap[largest]);
                cur = largest;
            }
            else
            {
                break;
            }
        }
    }
    void del_heap_m()
    {
        if (SIZE == 0)
            return;
        ans.push_back(heap[1]);
        heap[1] = heap[SIZE--];
        int cur = 1;
        while (true)
        {
            int l = cur * 2;
            int r = cur * 2 + 1;
            int largest = cur;
            if (l <= SIZE && heap[l] < heap[largest])
                largest = l;
            if (r <= SIZE && heap[r] < heap[largest])
                largest = r;

            if (largest != cur)
            {
                swap(heap[cur], heap[largest]);
                cur = largest;
            }
            else
            {
                break;
            }
        }
    }
    int getFront()
    {
        if (SIZE > 0)
            return heap[1];
        return -1; 
    }
};
class Priority_queue
{
public:
    Heap h;
    Priority_queue(int n) : h(n) {}
    void enque_max(int x)
    {
        h.insert(x);
    }
    void enque_min(int x)
    {
        h.Insert(x);
    }
    void deque_max()
    {
        h.del_heap();
    }
    void deque_min()
    {
        h.del_heap_m();
    }
    int get_front()
    {
        return h.getFront();
    }
};

int main()
{
    int n;
    cin >> n;
    cout << "Option 1 for MAX PQ" << endl;
    cout << "Option 2 for MIN PQ" << endl;
    int op;
    cin >> op;
    Priority_queue pq(n);
    if (op == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.enque_max(x);
            cout << "Front: " << pq.get_front() << endl;
        }
        pq.deque_max();
        cout << "After Deque Front: " << pq.get_front() << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.enque_min(x);
            cout << "Front: " << pq.get_front() << endl;
        }
        pq.deque_min();
        cout << "After Deque Front: " << pq.get_front() << endl;
    }
    return 0;
}
