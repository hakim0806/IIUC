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
Node *input_tree()
{
    int v;
    cin >> v;
    Node *root;
    if (v == -1)
        root = NULL;
    else
        root = new Node(v);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // 1 ber kore ano
        Node *f = q.front();
        q.pop();
        // ja ja kaj kora lage koru
        int l, r;
        cin >> l >> r;
        Node *myleft;
        Node *myright;
        if (l == -1)
            myleft = NULL;
        else
            myleft = new Node(l);
        if (r == -1)
            myright = NULL;
        else
            myright = new Node(r);
        f->left = myleft;
        f->right = myright;
        // children golu ke push koru
        if (f->left)
            q.push(f->left); // f er left thakle
        if (f->right)
            q.push(f->right);
    }
    return root;
}
void print_levelorder(Node *root)
{
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // ber kore ana
        Node *f = q.front();
        q.pop();
        // kaj kora
        cout << f->v << " ";
        // children golu ke push kora
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
bool search(Node *root, int v)
{
    if (root == NULL)
        return false;
    if (root->v == v)
        return true;
    if (v < root->v)
    {
        bool l = search(root->left, v);
        if (l == true)
            return true;
        else
            return false;
    }
    else
    {
        return search(root->right, v);
    }
}
void insert_BST(Node *root, int v)
{
    if (root == NULL)
    {
        root = new Node(v);
        return;
    }
    if (root->v > v)
    {
        if (root->left == NULL)
            root->left = new Node(v);
        else
            insert_BST(root->left, v);
    }
    else if (root->v < v)
    {
        if (root->right == NULL)
            root->right = new Node(v);
        else
            insert_BST(root->right, v);
    }
}
int main()
{
    Node *root = input_tree();
    print_levelorder(root);
    cout << endl;
    int x;
    cin >> x;
    if (search(root, x))
        cout << "YES, Found" << endl;
    else
        cout << "NOT, Not found" << endl;
    int v;
    cin >> v;
    insert_BST(root, v);
    print_levelorder(root);
}