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
void print_r(Node *tail)
{
    Node *tmp = tail; // 50
    while (tmp != NULL)
    {
        cout << tmp->v << " ";
        tmp = tmp->p;
    }
}
void inset_head(Node *&head, int v)
{
    Node *nn = new Node(v);
    if (head == NULL)
    {
        head = nn;
        return;
    }
    nn->next = head;
    head->p = nn;
    head = nn;
}

void insert_at_tail(Node *&head, Node *&tail, int v)
{
    Node *nn = new Node(v);
    if (tail == NULL)
    {
        head = nn; // null
        tail = nn; // null
        return;
    }
    tail->next = nn;
    nn->p = tail;
    tail = tail->next; // 10 20 30 40
}
void insert_at_p(Node* &head, int p, int v)
{
    Node* nn = new Node(v);
    Node* tmp = head;
    for(int i = 1; i<p-1; i++)//10 20 30 40 50 
    {
        tmp = tmp->next;
    }                           //  70
    // tmp ekon p er aghe // 10 20     30 40 50 
    nn->next = tmp->next;
    tmp->next =nn;
    nn->next->p = nn;
    nn->p = tmp;
}
void delete_head(Node* &head)
{
    Node* deleteNode = head;
    head = head->next;
    delete  deleteNode;
    head->p = NULL;

}
void delete_tail(Node* &tail)
{
     Node* deleteNode = tail;
    tail = tail->p;
    delete  deleteNode;
    tail->next = NULL;
}
void delete_p(Node* head,int p)
{
    Node* tmp = head;
    for(int i =1; i<p-1; i++)
    {
        tmp = tmp->next;
    }
    // tmp ekon p er aghe 10 20 70 30 40 
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
    tmp->next->p = tmp;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (1)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        insert_at_tail(head, tail, x);
    }
    print(head);
    inset_head(head, 10);
    print(head);
    int p,v; cin>>p>>v;
    insert_at_p(head,p,v);
    print(head);
    delete_head(head);
    print(head);
    delete_tail(tail);
    print(head);
    delete_p(head,3);
    print(head);
}