#include <bits/stdc++.h>
using namespace std;

int rear = -1, front = -1; 

void insert(int x, int n, int ar[]) 
{
    if ((rear + 1) % n == front)
    {
        cout << "Overflow" << endl;
    }
    else if (rear == -1 && front == -1) 
    {
        front = rear = 0;
        ar[rear] = x;
    }
    else
    {
        rear = (rear + 1) % n;
        ar[rear] = x;
    }
}

void delete_element(int n, int ar[]) 
{
    if (front == -1 && rear == -1)
    {
        cout << "Underflow" << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % n;
    }
}

void display(int n, int ar[]) 
{
    if (front == -1 && rear == -1)
    {
        cout << "Empty" << endl;
        return;
    }

    int i = front;
    while (i != rear)
    {
        cout << ar[i] << " ";
        i = (i + 1) % n;
    }
    cout << ar[rear] << " "; 
}

int main()
{
    int n;
    cin >> n; 
    int ar[n];
    fill(ar, ar + n, -1); 

    insert(10, n, ar); 
    insert(20, n, ar); 
    insert(30, n, ar); 

    display(n, ar); 
    cout << endl;

    delete_element(n, ar); 
    display(n, ar); 
    cout << endl;
    insert(70, n, ar); 
    display(n, ar); 

    return 0;
}
