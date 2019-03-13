// 2018-2019 ACM-ICPC Asia Jiaozuo Regional Contest
// 102028I

//I might only have one match
//but I can make an explosion

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int t, n;
long long acc[N], arr[N];

long long sum(int st, int ed) {
    return acc[ed] - acc[st - 1];
}

int main() {


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("out.in", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 2; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
            acc[i] = arr[i];
        }

        for (int i = 2; i <= n; i++) {
            acc[i] += acc[i - 1];
        }

        vector<long long> ans;
        ans.push_back(0);
        ans.push_back(arr[n] - arr[0]);


        int st = 1, ed = n;
        bool flag = 0;
        while (ed - st > 1) {
            if (!flag) {
                int cnt1 = st;
                long long sum1 = acc[st];
                st++;
                long long element = arr[st];

                int cnt2 = n - ed + 1;
                long long sum2 = sum(ed, n);
                ans.push_back((1LL * cnt1 * element - sum1) + (sum2 - 1LL * cnt2 * element));
            } else {
                int cnt1 = st;
                long long sum1 = acc[st];
                int cnt2 = n - ed + 1;
                long long sum2 = sum(ed, n);
                ed--;
                long long element = arr[ed];
                ans.push_back((1LL * cnt1 * element - sum1) + (sum2 - 1LL * cnt2 * element));
            }

            flag = !flag;
        }

        long long a = 0;
        for (int i = 0; i < ans.size(); i++) {
            a += ans[i];
            cout << a << " \n"[i == ans.size() - 1];
        }

    }


    return 0;
}
