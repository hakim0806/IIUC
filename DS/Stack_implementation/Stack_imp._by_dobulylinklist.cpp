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
class mystack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sze = 0;
    void Push(int v)
    { 
        sze++;
        Node *nn = new Node(v);
        if (head == NULL)
        {
            head = nn;
            tail = nn;
            return;
        }
        nn->p = tail;
       tail->next= nn;
       tail = tail->next;
    }
    void Pop()
    {
      sze--;
      Node* deleteNode = tail;
      tail = tail->p;
      if(tail == NULL )
      {
        head = NULL;
      }
      else 
      {
        tail->next = NULL;
      }
      delete deleteNode;
    }
    
    int  Top()
    {
        return tail->v;
    }
   int size()
   {
      return sze;
   }
   bool empty()
   {
    if(sze== 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
   }
};

int main()
{
    mystack st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.Push(x);
    }
    while (!st.empty())
    {
        cout<<st.Top()<<" ";
        st.Pop();
    }
}