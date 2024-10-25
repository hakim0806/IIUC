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
int main()
{
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);
    // connection
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    b->right = d;
    d->left = f;
    d->right = g;
    h->right = i;
    preOrder(root);
    cout<<endl<<endl;
    postOrder(root);
     cout<<endl<<endl;
     inOrder(root);
}