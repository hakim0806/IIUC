#include <bits/stdc++.h>
using namespace std;
#define s 5
int front[s] = {-1, -1, -1, -1, -1};
int rear[s] = {-1, -1, -1, -1, -1};
int pq[s][s] =
{
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1},
};

void display()
{
    cout << "Display priorityQueue:" << endl;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (pq[i][j] == -1) cout << "- ";
            else cout << pq[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void insert(int v, int p)
{
    p--;
    if (rear[p] == s - 1)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        if (rear[p] == -1)
        {
            front[p] = 0;
            rear[p] = 0;
        }
        else
        {
            rear[p]++;
        }
        pq[p][rear[p]] = v;
        cout << "Element inserted" << endl;
    }
}

void del()
{
    for(int i =0; i<s; i++)
    {
        for(int j =0; j<s; j++)
        {
            if(pq[i][j]!=-1)
            {
                pq[i][j] =-1;
                return ;
            }
        }
    }
    cout<<"No element deleted"<<endl;
}
int main()
{
    int op, v, priority;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Quit" << endl;
        cin >> op;
        if (op == 1)
        {
            cout << "Enter value and priority: ";
            cin >> v >> priority;
            insert(v, priority);
        }
        else if (op == 2)
        {
            del();
        }
        else if (op == 3)
        {
            display();
        }
        else if (op == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid option, please try again." << endl;
        }
    }
    return 0;
}
