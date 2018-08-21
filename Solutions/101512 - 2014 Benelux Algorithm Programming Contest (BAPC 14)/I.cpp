// 101512 - 2014 Benelux Algorithm Programming Contest (BAPC 14)
// 101512I

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 7e4;
int fib[55];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 46; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int A = 1, B = n - 1;
        for (int b = 1; b < N; b++) {
            for (int i = 2; i < 46; i++) {
                int x = n - b * fib[i];
                int y = fib[i - 1];
                if (x <= 0)
                    break;
                if (x % y == 0 && x / y <= b) {
                    if (b < B || b == B && x / y < A) {
                        B = b;
                        A = x / y;
                    }
                }
            }
        }

        for (int a = 1; a < N; a++) {
            for (int i = 1; i < 46; i++) {
                int x = n - a * fib[i - 1];
                int y = fib[i];
                int b = x / y;
                if (x <= 0)
                    break;
                if (x % y == 0 && b >= a) {
                    if (b < B || b == B && a < A) {
                        B = b;
                        A = a;
                    }
                }
            }
        }
        printf("%d %d\n", A, B);
    }
    return 0;
}