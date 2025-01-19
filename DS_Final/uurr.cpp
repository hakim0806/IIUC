// #include <bits/stdc++.h>
// using namespace std;
// class Node
// {
//   public:
//   int v;
//   int priority;
//   Node* next;
//   Node(int v, int priority)
//   {
//     this->priority = priority;
//     this->v = v;
//     this->next = NULL;
//   }

// };

//  class pc
//  {
//     public:
//     Node* head;
//     pc()
//     {
//         head = NULL;
//     }
//     void insert(int v, int priority)
//     {
//         Node* nn = new Node(v,priority);
//         nn->next = NULL;
//         if( head == NULL)
//         {
//             head = nn;
//             head->next = NULL;
//         }
//        else if(head->priority < nn->priority)
//        {
//            nn->next = head;
//            head->next = nn;
//        }
//        else{
//            Node* tmp = head;
//            while(tmp->next != NULL && tmp->next->priority > nn->priority)
//            {
//                 tmp = tmp->next;
//            }
//            nn->next = tmp->next;
//            tmp->next = nn;
//        }
//     }
//     void pop()
//     {
//         if( head == NULL)
//         {
//             cout<< "NO element"<<endl;
//             return;
//         }
//         Node* tmp = head;
//         delete head;
//         head= head->next;
//     }
//     int front()
//     {
//         return head->v;
//     }
//     bool empty()
//     {
//         return head == NULL;
//     }
//  };
//  int main()
//  {
//     pc a;
//     a.insert(10,6);
//     a.insert(15,5);
//     a.insert(16,3);
//     a.insert(9,4);
//     while(!a.empty())
//     {
//         cout<<a.front()<<" ";
//         a.pop();
//     }
//  }

// #include <bits/stdc++.h>
// using namespace std;
// int front = -1, rear = -1;
// void insert(int x, int n, int ar[])
// {
//     if ((rear + 1) % n == front)
//     {
//         cout << "overflow" << endl;
//     }
//     else if (rear == -1 && front == -1)
//     {
//         rear = front = 0;
//         ar[rear] = x;
//     }
//     else
//     {
//         rear = (rear + 1) % n;
//         ar[rear] = x;
//     }
// }
// void del(int n, int ar[])
// {
//     if (rear == -1 && front == -1)
//     {
//         cout << "underflow" << endl;
//     }
//     else if (front == rear)
//     {
//         rear = front = -1;
//     }
//     else
//     {
//         front = (front + 1) % n;
//     }
// }
// void disply(int n, int ar[])
// {
//     if (front == -1 && rear == -1)
//     {
//         cout << " Empty" << endl;
//         return;
//     }
//     int i = front;
//     while (i != rear)
//     {
//         cout << ar[i] << " ";
//         i = (i + 1) % n;
//     }
//     cout << ar[rear] << endl;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int ar[n];
//     fill(ar, ar + n, -1);
//     insert(10, n, ar);
//     insert(20, n, ar);
//     insert(30, n, ar);

//     disply(n, ar);
//     cout << endl;

//     del(n, ar);
//     disply(n, ar);
//     cout << endl;
//     insert(70, n, ar);
//     disply(n, ar);
// }
// 

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> add (const vector<int>&a, vector<int>&b)
// {
//     vector<int>ans;
//     int carry = 0, sum =0;
//     int i = 0, j =0;
//     while(i < a.size() || j< b.size() || carry)
//     {
//         sum = carry;
//         if(i<a.size()) sum +=a[i++];
//         if(j<b.size()) sum +=b[j++];
//         ans.push_back(sum%10);
//         carry = sum/10;
//     }
//     return ans;
// }
// void fibo (int n)
// {
//     if(n == 0)
//     {
//         cout<< 0 <<endl;
//         return ;
//     }
//     if (n == 1)
//     {
//        cout<< 1 <<endl;
//        return;
//     }
//     vector<int> a(1,0);
//     vector<int> b(1,1);
//     vector<int> c;
// for(int i = 2; i <=n; i++)
// {
//     c= add(a,b);
//     a= b;
//     b =c;
// }
// for(auto it = c.rbegin(); it!=c.rend(); it++)
// {
//     cout<<*it;
// }
// cout<<endl;

// }
// int main()
// {
//     int n;
//     cin>>n;
//     fibo(n);
// }


// 

// #include <bits/stdc++.h>
//  using namespace std;
//  class Node
//  {
//     public: 
//     int v;
//     Node* next;
//     Node* pre;
//     Node(int v)
//     {
//         this->v = v;
//         this->next = NULL;
//         this->pre = NULL;
//     }

//  };
//  class myQueue
//  {
//     public:
//     Node* head = NULL;
//     Node* tail = NULL;
//     int s = 0;
//     void Push(int v)
//     {
//         s++;
//         Node* nn = new Node(v);
//         if( head == NULL)
//         {
//             tail = nn;
//             head = nn;
//             return;
//         }
//         tail->next = nn;
//         nn->next = tail;
//         tail = tail->next;   
//     }
//     void Pop()
//     {
//         s--;
//         Node* deleteNode = head;
//         head = head->next;
//         if(head == NULL)
//         {
//             tail == NULL;
//             return;
//         }
//         delete deleteNode;
//     }
//     int front()
//     {
//         return head->v;
//     }
//     int size()
//     {
//         return s;
//     }
//     bool empty()
//     {
//         return s == 0;
//     }
//  };
//  int main()
//  {
//     myQueue q;
//     int n;
//     cin>>n;
//     for(int i = 0; i<n; i++)
//     {
//         int x; 
//         cin>>x;
//         q.Push(x);
//     }
//     while(!q.empty())
//     {
//         cout<< q.front() <<" ";
//         q.Pop();
//     }

//  }

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> v(100001);
// void merge(int l, int mid, int r)
// {
//     int n1 = mid-l+1;
//     int n2 = r-mid;
//     vector<int>a(n1);
//     vector<int>b(n2);
    
//     for(int i = 0; i<n1; i++)
//     {
//          a[i] = v[l+i];
//     }
//      for(int i = 0; i<n2; i++)
//     {
//          b[i] = v[mid+1+i];
//     }
//     int i = 0; 
//     int j =0;
//     int k = l;
//     while(i< n1 && j<n2)
//     {
//         if(a[i] < b[j])
//         {
//             v[k] = a[i];
//             i++;
//             k++;
//         }
//          if(a[i] > b[j])
//         {
//             v[k] = b[j];
//             j++;
//             k++;
//         }
//     }
//     while(i<n1)
//     {
//         v[k] = a[i];
//             i++;
//             k++;
//     }
//      while(j<n2)
//     {
//         v[k] = b[j];
//             j++;
//             k++;
//     }
// }
// void merge_sort(int l, int r)
// {
//     if(l<r)
//     {
//         int mid = (l+r)/2;
//         merge_sort(l,mid);
//         merge_sort(mid+1,r);
//         merge(l,mid,r);
//     }
// }
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i = 0; i<n; i++)
//     {
//         cin>> v[i];
//     }
//     merge_sort(0,n-1);// l r r
//     for(int i = 0; i<n; i++)
//     {
//         cout<< v[i] <<" ";
//     }
// }

#include <bits/stdc++.h>
using namespace std;
vector<int> v(100001);
int partition(int st, int end)
{
    int idx = st-1, privot = v[end];
    for(int i = st; i<end; i++)
    {
        if(v[i]<= privot)
        {
            idx++;
            swap(v[idx],privot);
        }
        
    }
    idx++;
    swap(v[idx],v[end]);
    return idx;
}
void Quick_sort(int st, int end)
{
    if(st<end)
    {
        int privot = partition(st,end);
        Quick_sort(st,privot-1);
        Quick_sort(privot+1,end);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>> v[i];
    }
    Quick_sort(0,n-1);// l r r
    for(int i = 0; i<n; i++)
    {
        cout<< v[i] <<" ";
    }
}