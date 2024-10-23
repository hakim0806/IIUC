#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int v;
    Node *next;
    Node(int v)
    {
        this->v = v;
        this->next = NULL;
    }
};
void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}
void print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->v << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void insert_at_p(Node *&head, int p, int v)
{
    Node *newNode = new Node(v);
    if (p == 1)
    {
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *tmp = head;
        for (int i = 1; i < p - 1; i++)
        {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}
void deletehead(Node *&head)
{
    if (head == NULL)
    {
        cout << "NO list" << endl;
        return;
    }
    Node *deleteNode = head;//10
    head = head->next;// 20 30
    delete deleteNode;//10
}
void delete_p(Node *head, int p)//10 20 30 40 50
{
    Node *tmp = head;
    for (int i = 1; i < p - 1; i++)
    {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;//30
    tmp->next = tmp->next->next;
    delete deleteNode;
}
int size(Node *head)
{
    Node *tmp = head;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
void print_rev(Node *head)//10 20 30 40 0
{
    if (head == NULL)//base case
    {
        return;
    }
    print_rev(head->next);//
    cout << head->v << " ";//40 30 20 10
}
void sort(Node *head)//selection sort
{
    for (Node *i = head; i->next != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->v > j->v)
                swap(i->v, j->v);
        }
    }
    print(head);
}
int main()
{
    Node *head = NULL;
    while (true)
    {
        int op;
        cout << " option 1 for insert at head " << endl;
        cout << " option 2 for print " << endl;
        cout << " option 3 for insert_at_tail " << endl;
        cout << " option 4 for insert at any position " << endl;
        cout << " option 5 for delete position " << endl;
        cout << " option 6 for delete Head " << endl;
        cout << " option 7 for print reverse " << endl;
        cout << " option 8 for sort list " << endl;
        cout << " option 9 for terminate " << endl;
        cin >> op;
        if (op == 1)
        {
            int v;
            cin >> v;
            insert_at_head(head, v);
        }
        else if (op == 2)
        {
            print(head);
        }
        else if (op == 3)
        {
            int v;
            cin >> v;
            insert_at_tail(head, v);
        }
        else if (op == 4)
        {
            int p, v;
            cin >> p >> v;
            insert_at_p(head, p, v);
        }
        else if (op == 5)
        {
            int p;
            cin >> p;
            if (p == 1)
                deletehead(head);
            else if (p <= size(head))
                delete_p(head, p);
            else
                cout << "invalied" << endl;
        }
        else if (op == 6)
        {
            deletehead(head);
        }
        else if (op == 7)
        {
            print_rev(head);
            cout << endl;
        }
        else if (op == 8)
        {
            sort(head);
        }
        else
        {
            break;
        }
    }
}