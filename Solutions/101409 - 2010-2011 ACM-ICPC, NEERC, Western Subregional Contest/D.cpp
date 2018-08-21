// 101409 - 2010-2011 ACM-ICPC, NEERC, Western Subregional Contest
// 101409D

#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back

using namespace std;

typedef long long ll;
const ll N=1313132, M=4e6 + 7, INF=1e9;
const double PI = 3.141592653589793238462643383279502884197;

int k, R;
vector<pair<int,int>> b;

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	freopen("domino.out","w",stdout);
	freopen("domino.in","r",stdin);

	cin >> k >> R;
	b.resize(k);
	int sum = 0;
	for (int i = 0; i < k; ++i) {
		cin >> b[i].first >> b[i].second;
		sum += b[i].first + b[i].second;
	}
	vector<int> tb(2 * R);
	for (int i = 0; i < 2 * R; ++i)
		cin >> tb[i];

	int r = sum;
	int rmv;
	for (int i = 0; i < k; ++i) {
		if (b[i].first == tb[0] || b[i].first == tb.back() ||
			b[i].second == tb[0] || b[i].second == tb.back()) {
			if (sum - b[i].first - b[i].second < r)
				r = sum - b[i].first - b[i].second, rmv = 1;
		}

		for (int j = i + 1; j < k; ++j) {
			if (b[i].first == b[i].second && b[j].first == b[j].second &&
					(b[i].first == tb[0] && b[j].first == tb.back() ||
					b[i].first == tb.back() && b[j].first == tb[0])) {
				if (sum - b[i].first * 2 - b[j].first * 2 <= r)
					r = sum - b[i].first * 2 - b[j].first * 2, rmv = 2;
			}
		}
	}
	cout << (r == 0 && (b.size() - rmv == 0) ? -1 : r) << endl;
	return 0;
}
