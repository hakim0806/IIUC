#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int v;
    Node *next;
    Node *p;
    Node(int v)
    {
        this->v = v;
        this->next = NULL;
        this->p = NULL;
    }
};

class myDqueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void Push_front(int v)
    {
        Node *nn = new Node(v);
        if (head == NULL)
        {
            head = nn;
            tail = nn;
            return;
        }
        nn->next = head;
        head->p = nn;
        head = nn;
    }

    void Push_rear(int v)
    {
        Node *nn = new Node(v);
        if (tail == NULL)
        {
            head = nn;
            tail = nn;
            return;
        }
        tail->next = nn;
        nn->p = tail;
        tail = nn;
    }

    void Pop_front()
    {
        if (head == NULL)
        {

            return;
        }
        Node *deleteNode = head;
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->p = NULL;
        }
        delete deleteNode;
    }
    void Pop_rear()
    {
        if (tail == NULL)
        {

            return;
        }
        Node *deleteNode = tail;
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->p;
            tail->next = NULL;
        }
        delete deleteNode;
    }
    void display()
    {
        if (head == NULL)
        {

            return;
        }
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->v << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    int get_front()
    {
        if (head == NULL)
        {

            return -1;
        }
        return head->v;
    }
    int get_rear()
    {
        if (tail == NULL)
        {
            return -1;
        }
        return tail->v;
    }
    ~myDqueue()
    {
        while (head != NULL)
        {
            Pop_front();
        }
    }
};

int main()
{
    myDqueue dq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dq.Push_rear(x);
    }
    dq.Pop_front();
    dq.Pop_rear();
    dq.display();

    cout << "Front: " << dq.get_front() << endl;
    cout << "Rear: " << dq.get_rear() << endl;
    return 0;
}
