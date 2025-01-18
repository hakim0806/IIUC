#include <bits/stdc++.h>
using namespace std;

int fib_recursive(int n) {
    if (n == 0 || n == 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_non_recursive(int n) {
    if (n == 0 || n == 1) return n;
    int prev1 = 0, prev2 = 1, curr;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}

int main() {
    int n;
    cin >> n;
    cout << "Recursive: " << fib_recursive(n) << endl;
    cout << "Non-Recursive: " << fib_non_recursive(n) << endl;
}
