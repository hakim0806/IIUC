#include <bits/stdc++.h>
using namespace std;
vector<int> v(10001);
void merge(int l, int mid, int r)
{
    int n1 = mid - 1 + 1;
    int n2 = r - mid;
    vector<int> a(n1);
    vector<int> b(n2);
    for (int i = 0; i < n1; i++)
    {
        a[i] = v[l + i]; 
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = v[mid + 1 + i]; 
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            v[k] = a[i];
            i++;
            k++;
        }
        else
        {
            v[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        v[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        v[k] = b[j];
        j++;
        k++;
    }
}
void Merge_sort(int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        Merge_sort(l, mid);
        Merge_sort(mid + 1, r);
        merge(l, mid, r);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}