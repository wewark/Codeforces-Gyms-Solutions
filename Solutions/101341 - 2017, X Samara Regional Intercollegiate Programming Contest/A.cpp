// 101341 - 2017, X Samara Regional Intercollegiate Programming Contest
// 101341A

﻿#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = { 0, 0, 1, -1 };
const int dj[] = { 1, -1, 0, 0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-6;
#define all(x) x.begin(),x.end()

class SegmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
		 int n;
		 inline int left(int p) { return p << 1; }     // same as binary heap operations
		 inline int right(int p) { return (p << 1) + 1; }

		 void build(int p, int L, int R) {                           // O(n log n)
			 if (L == R)                            // as L == R, either one is fine
				 st[p] = L;                                         // store the index
			 else {                                // recursively compute the values
				 build(left(p), L, (L + R) / 2);
				 build(right(p), (L + R) / 2 + 1, R);
				 int p1 = st[left(p)], p2 = st[right(p)];
				 st[p] = (A[p1] >= A[p2]) ? p1 : p2;
			 }
		 }

		 int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
			 if (i > R || j < L) return -1; // current segment outside query range
			 if (L >= i && R <= j) return st[p];               // inside query range

															   // compute the min position in the left and right part of the interval
			 int p1 = rmq(left(p), L, (L + R) / 2, i, j);
			 int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

			 if (p1 == -1) return p2;   // if we try to access segment outside query
			 if (p2 == -1) return p1;                               // same as above
			 return (A[p1] >= A[p2]) ? p1 : p2;
		 }          // as as in build routine

		 int update_point(int p, int L, int R, int idx, int new_value) {
			 // this update code is still preliminary, i == j
			 // must be able to update range in the future!
			 int i = idx, j = idx;

			 // if the current interval does not intersect 
			 // the update interval, return this st node value!
			 if (i > R || j < L)
				 return st[p];

			 // if the current interval is included in the update range,
			 // update that st[node]
			 if (L == i && R == j) {
				 A[i] = new_value; // update the underlying array
				 return st[p] = L; // this index
			 }

			 // compute the minimum pition in the 
			 // left and right part of the interval
			 int p1, p2;
			 p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
			 p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

			 // return the pition where the overall minimum is
			 return st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		 }

public:
	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size();              // copy content for local usage
		st.assign(4 * n, 0);            // create large enough vector of zeroes
		build(1, 0, n - 1);                                  // recursive build
	}

	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }   // overloading

	int update_point(int idx, int new_value) {
		return update_point(1, 0, n - 1, idx, new_value);
	}
};

int n;
vector<pair<pii, int>> num;

inline bool valid(int idx, int mx) {
	return num[idx].first.first <= mx;
}

int BS(int mx) {
	int a = 0, b = n - 1, mid = (a + b + 1) / 2;
	while (a < b) {
		if (valid(mid, mx))
			a = mid;
		else
			b = mid - 1;
		mid = (a + b + 1) / 2;
	}
	return valid(mid, mx) ? mid : -1;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	int sum = 0;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		num[i].second = i;

		int c = 0;
		num[i].first = pii(0, 0);
		for (auto& j : s) {
			if (j == '(') {
				num[i].first.second++;
			}
			else {
				if (num[i].first.second) num[i].first.second--;
				else num[i].first.first++;
			}
		}
	}
	sort(num.begin(), num.end());

	vi v(n);
	for (int i = 0; i < n; i++) {
		v[i] = num[i].first.second;
	}
	SegmentTree seg(v);

	bool w = false;
	vector<pair<pii, int>> r;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		int b = BS(cur);
		if (b == -1) {
			w = true; break;
		}

		int mxi = seg.rmq(0, b);
		if (v[mxi] == -INF) {
			w = true; break;
		}

		r.push_back(num[mxi]);
		cur += num[mxi].first.second;
		cur -= num[mxi].first.first;

		seg.update_point(mxi, -INF);
		v[mxi] = -INF;
	}

	if (cur != 0 || w)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << r[i].second + 1 << " \n"[i == n - 1];
		}
	}

	cin.ignore(), cin.get();
}
