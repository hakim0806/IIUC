#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> h;
int t_size;
int hashing_fun(int key) {
    return key % t_size;
}
void insert(int key) {
    int idx = hashing_fun(key);
    h[idx].push_back(key);
}
void disply() {
    for (int i = 0; i < t_size; i++) {
        if (h[i].empty()) {
            cout << i << " : " << "empty" << endl;
        } else {
            cout << i << " : ";
            for (int key : h[i]) {
                cout << key << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    cin >> t_size;
    h.assign(t_size, vector<int>());
    int key;
    while (cin >> key) {
        if (key == -1) break;
        insert(key);
    }
    disply();
}
