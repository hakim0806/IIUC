#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    int prior;
    Node *next;
    Node(int val, int pval)
    {
        data = val;
        prior = pval;
        next = NULL;
    }
};
class pc
{
public:
    Node *head;

    pc()
    {
        head = NULL;
    }

    void enque(int val, int pval)
    {
        Node *newnode = new Node(val, pval);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            head->next = NULL;
        }
        else if (head->prior < newnode->prior)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *tmp = head;
            while (tmp->next != NULL && tmp->next->prior > newnode->prior)
            {
                tmp = tmp->next;
            }
            newnode->next = tmp->next;
            tmp->next = newnode;
        }
    }

    void deque()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    int front()
    {
        return head->data;
    }

    bool isempty()
    {
        return head == NULL;
    }
};

int main()
{
    pc a;
    a.enque(10, 6);
    a.enque(15, 5);
    a.enque(16, 3);
    a.enque(9, 4);

    while (!a.isempty())
    {
        cout << a.front() << " ";
        a.deque();
    }
}
