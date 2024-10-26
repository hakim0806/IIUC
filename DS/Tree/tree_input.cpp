#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int v;
    Node *left;
    Node *right;
    Node(int v)
    {
        this->v = v;
        this->left = NULL;
        this->right = NULL;
    }
};
void preOrder(Node *root)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    cout<<root->v<<" ";//10
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->v<<" ";
}
void inOrder(Node* root)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->v<<" ";
    inOrder(root->right);

}
void level_Order_print(Node* root)
{
    queue<Node*>q;
    if(root!=NULL)
    q.push(root);
    while(!q.empty())
    {
        // ber kore anu
        Node* f = q.front();
        q.pop();
        //sob kaj koru
        cout<<f->v<<" ";
        //child golu ke line a push koru 
        if(f->left!=NULL) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}
Node* input_tree()
{
    int v; cin>>v;
    Node* root ;
    if(v == -1)  root == NULL;
    else 
    {
      root = new Node(v);
    }
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())//10
    {
        // linr teke ekjon ke anu
        Node* f = q.front();
        q.pop();
        // kaj kora 
        int l,r;  cin>>l>>r;
        Node* myleft;
        Node* myright;
        if(l == -1) myleft = NULL;
        else 
        {
            myleft= new Node(l);
        }
        if(r == -1) myright = NULL;
        else 
        {
            myright= new Node(r);
        }
        // connection
        f->left = myleft;
        f->right = myright;
        // child golu ke push kora
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    return root;
}

int main()
{
    Node *root = input_tree();
    // Node *a = new Node(20);
    // Node *b = new Node(30);
    // Node *c = new Node(40);
    // Node *d = new Node(50);
    // Node *e = new Node(60);
    // Node *f = new Node(70);
    // Node *g = new Node(80);
    // Node *h = new Node(90);
    // Node *i = new Node(100);
    // // connection
    // root->left = a;
    // root->right = b;
    // a->left = c;
    // a->right = h;
    // c->right = e;
    // b->right = d;
    // d->left = f;
    // d->right = g;
    // h->right = i;
    preOrder(root);
    cout<<endl<<endl;
    postOrder(root);
     cout<<endl<<endl;
     inOrder(root);
     cout<<endl<<endl;
     level_Order_print(root);
     cout<<endl<<endl;
}