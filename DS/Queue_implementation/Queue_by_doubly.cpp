#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int v;
    Node *next;
    Node* p;
    Node(int v)
    {
        this->v = v;
        this->next = NULL; 
        this->p = NULL;
    }
};
class myQueue{
    public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;
    void push(int v)
    {
        sz++;
        Node* nn = new Node(v);
        if(head == NULL)
        {
            head = nn;
            tail = nn;
            return;
        }
        tail->next = nn;
        nn->p = tail;
        tail = tail->next;
    }
    void pop()
    {
        sz--;
        Node* deleteNode = head;
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
            delete deleteNode;
            return;
        }
        head->p = NULL;
        delete deleteNode;
    }
    int front()
    {
        return head->v;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if ( sz == 0) return true;
        else return false ;
    }
};
int main()
{
    myQueue q;
    int n; cin>>n;
     while(n--)
     {
        int x; cin>>x;
         q.push(x);
     }
     while(!q.empty())
     {
        cout<<q.front() <<" ";
        q.pop();
     }
     //cout<<q.front()<<" ";
}