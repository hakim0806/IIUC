#include <bits/stdc++.h>
using namespace std;
vector<int> v(10001);
int partition(int st, int end)
{
    int idx = st - 1, privot = v[end];
    for (int j = st; j < end; j++)
    {
        if (v[j] <= privot)
        {
            idx++;
            swap(v[j], v[idx]);
        }
    }
    idx++;
    swap(v[idx], v[end]);
    return idx;
}
void Quick_sort(int st, int end)
{
    if (st < end)
    {
        int pividx = partition(st, end);
        Quick_sort(st, pividx - 1);  // left half
        Quick_sort(pividx + 1, end); // right half
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
    Quick_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}