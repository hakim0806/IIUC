#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int priority;
    int v;
    Node *next;
    Node(int v, int priority)
    {
        this->priority = priority;
        this->v = v;
        this->next = NULL;
    }
};
Node *front = NULL;
void insert(int v, int priority)
{
    Node *rear;
    Node *tmp = new Node(v, priority);

    if (front == NULL || priority <= front->priority)
    {
        tmp->next = front;
        front = tmp;
    }
    else
    {
        rear = front;
        while (rear->next != NULL && rear->next->priority <= priority)
        {
            rear = rear->next;
        }
        tmp->next = rear->next;
        rear->next = tmp;
    }
}
void del()
{
    if (front == NULL)
    {
        cout << "No priority queue" << endl;
    }
    else
    {
        Node *tmp = front;
        front = front->next;
        delete tmp;
    }
}
void display()
{
    if (front == NULL)
    {
        cout << "No element" << endl;
    }
    else
    {
        Node *tmp = front;
        while (tmp)
        {
            cout << tmp->v << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}
int main()
{
    int op, v, priority;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Quit" << endl;
        cin >> op;
        if (op == 1)
        {
            cout << "Enter value and priority: ";
            cin >> v >> priority;
            insert(v, priority);
        }
        else if (op == 2)
        {
            del();
        }
        else if (op == 3)
        {
            display();
        }
        else if (op == 4)
        {
            break;
        }
        else
        {
         cout << "Invalid option, please try again." << endl;
        }
    }
    return 0;
}
