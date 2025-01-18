#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e; // node and edge
    cin >> n >> e;
    int m[n][n];
    memset(m, 0, sizeof(m));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        m[a][b] = 1;
        m[b][a] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}