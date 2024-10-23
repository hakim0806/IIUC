#include <bits/stdc++.h>
#include<vector>
using namespace std;
    vector<int>v1;
    vector<int>v;

class Node{
    public:
    int v;
    Node* left;
    Node* right;
    
    Node(int v)
    {
        this->v=v;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* input_tree()
{
    int v; cin>>v;
    Node* root;
    if(v==-1) root = NULL;
    else root = new Node(v);
    queue<Node*>q;
    if(root)q.push(root);
    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();
        int l ,r;
        cin>>l>>r;
        Node* myleft;
        Node* myright;
        if(l==-1) myleft=NULL;
        else myleft = new Node(l);
        if(r==-1) myright=NULL;
        else myright = new Node(r);
        p->left= myleft;
        p->right = myright;
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}
void print (Node* root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* p = q. front();
        q.pop();
        cout<<p->v<<" ";
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}
bool search(Node* root,int x)
{
    if(root == NULL) return false;
    if(root->v == x) return true ;
    if(x<root->v)
    {
        // bool l = search(root->left,x);
        // if(l==true) return true;
        // else return false;
        return search(root->left,x);
    }
    else 
    {
        // bool r = search( root->right, x);
        // if(r==true) return true;
        // else return false;
        return search(root->right,x);
    }
}
int main()
{
    int x;
    Node* root = input_tree();
    cin>>x;
    if(search(root,x)) cout<<"YES,found"<<endl;
    else cout<<"NO,NOT found"<<endl;
}