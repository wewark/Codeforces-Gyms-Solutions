// 101484 - 2017 USP-ICMC
// 101484A

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> num(n);
  for (int i = 0; i < n; ++i)
    cin >> num[i];
  sort(num.begin(), num.end());

  if (binary_search(num.begin(), num.end(), k)) {
    cout << 1 << endl;
  }
  else if (num[0] < k && num.size() > 1 && num.back() > k) {
    cout << 2 << endl;
  }
  else {
    cout << -1 << endl;
  }
  return 0;
}
