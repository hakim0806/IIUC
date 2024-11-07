#include <bits/stdc++.h>
using namespace std;
class CirculerQueue
{
public:
    int front, rear, size;
    int *queue;
    CirculerQueue(int s)
    {
        front = rear = -1;
        size = s;
        queue = new int[s];
    }
    ~CirculerQueue()
    {
        delete[] queue;
    }
    void enqueue(int v)
    {
        if ((front == -1 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            queue[rear] = v;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            queue[rear] = v;
        }
        else
        {
            rear++;
            queue[rear] = v;
        }
    }
    int dqueue()
    {
        if (front == -1)
        {
            cout << "empty" << endl;
            return -1;
        }
        int data = queue[front];
        queue[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return data;
    }
    void display()
    {
        if (front == -1)
        {
            cout << "empty" << endl;
            return;
        }
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    CirculerQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    cout << "Deleted value = " << q.dqueue() << endl;
    cout << "Deleted value = " << q.dqueue() << endl;
    q.display();

    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.display();

    return 0;
}