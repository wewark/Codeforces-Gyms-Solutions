#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n; cin >> n;
	vi pos(n), pp(n), bef(n), af(n), r(n, -1);
	vii ppsrtd(n), possrtd(n);
	for (int i = 0; i < n; ++i) {
		cin >> pos[i] >> pp[i];
		ppsrtd[i] = pii(pp[i], i);
		possrtd[i] = pii(pos[i], i);
	}
	sort(ppsrtd.begin(), ppsrtd.end());
	sort(possrtd.begin(), possrtd.end());
	if (n == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	bef[possrtd[0].second] = -1;
	af[possrtd[0].second] = possrtd[1].second;
	bef[possrtd[n - 1].second] = possrtd[n - 2].second;
	af[possrtd[n - 1].second] = -1;
	for (int i = 1; i < possrtd.size() - 1; ++i)
		bef[possrtd[i].second] = possrtd[i - 1].second,
		af[possrtd[i].second] = possrtd[i + 1].second;

	for (int i = 0; i < ppsrtd.size(); ++i) {
		int cur = ppsrtd[i].second, befi = bef[cur], afi = af[cur];
		if (befi != -1 && afi != -1 && pos[cur] - pos[befi] < pos[afi] - pos[cur] || afi == -1)
			r[cur] = befi;
		else if (befi != -1 && afi != -1 && pos[cur] - pos[befi] > pos[afi] - pos[cur] || befi == -1)
			r[cur] = afi;
		else if (befi != -1 && afi != -1 && pos[cur] - pos[befi] == pos[afi] - pos[cur]
				&& pp[befi] > pp[afi])
			r[cur] = befi;
		else if (befi != -1 && afi != -1 && pos[cur] - pos[befi] == pos[afi] - pos[cur]
				&& pp[befi] < pp[afi])
			r[cur] = afi;
		if (befi != -1)
			af[befi] = af[cur];
		if (afi != -1)
			bef[afi] = bef[cur];
	}
	cout << (r[0] == -1 ? r[0] : r[0] + 1);
	for (int i = 1; i < n; ++i)
		cout << " " << (r[i] == -1 ? r[i] : r[i] + 1);
	cout << endl;
}
