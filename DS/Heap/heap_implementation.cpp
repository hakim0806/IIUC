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
};

int main()
{
    int n;
    cin >> n;
    Heap h(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        h.del_heap();
    }
    h.display();
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
