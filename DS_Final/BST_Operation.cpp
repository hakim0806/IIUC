//  BST Insert search and pre post inorder  traversal and delete operation
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
        this->left = NULL;
        this->right = NULL;
        this->v = v;
    }
};

void insert_BST(Node *&root, int v)
{
    if (root == NULL)
    {
        root = new Node(v);
        return;
    }
    if (root->v > v)
    {
        if (root->left == NULL)
        {
            root->left = new Node(v);
        }
        else
        {
            insert_BST(root->left, v);
        }
    }
    if (root->v < v)
    {
        if (root->right == NULL)
        {
            root->right = new Node(v);
        }
        else
        {
            insert_BST(root->right, v);
        }
    }
}
void pre_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->v << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->v << " ";
}
void IN_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    IN_order(root->left);
    cout << root->v << " ";
    IN_order(root->right);
}
bool search(Node *root, int v)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->v == v)
    {
        return true;
    }
    if (root->v > v)
    {
        bool l = search(root->left, v);
        if (l == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return search(root->right, v);
    }
}
Node *find_min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *delete_val(Node *&root, int v)
{
    if (root == NULL)
    {
        return root;
    }
    if (v < root->v)
    {
        // root er value tke value small
        // go left for search
        root->left = delete_val(root->left, v);
    }
    else if (v > root->v)
    {
        // root er value tke value big
        // go right for search
        root->right = delete_val(root->right, v);
    }
    else
    {
        if (root->left == NULL)
        // left nai
        {
            Node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL)
        // right nai
        {
            Node *tmp = root->left;
            delete root;
            return tmp;
        }
        Node *tmp = find_min(root->right);
        root->v = tmp->v;
        root->right = delete_val(root->right, tmp->v);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        insert_BST(root, v);
    }
    pre_order(root);
    cout << endl;
    post_order(root);
    cout << endl;
    IN_order(root);
    if (search(root, x))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    int del_v;
    cin >> del_v;
    root = delete_val(root, del_v);
    if (root == NULL)
    {
        cout << "tree is now empty." << endl;
    }
    else
    {
        // cout << del_v<< endl;
        pre_order(root);
        cout << endl;
        post_order(root);
        cout << endl;
        IN_order(root);
        cout << endl;
    }
    return 0;
}
