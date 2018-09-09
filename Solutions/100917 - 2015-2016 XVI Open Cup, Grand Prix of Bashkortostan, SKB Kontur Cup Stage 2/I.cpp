// 2015-2016 XVI Open Cup, Grand Prix of Bashkortostan, SKB Kontur Cup Stage 2
// 100917I

#include <bits/stdc++.h>
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

const int ALPHABET_SIZE = 2;

// trie node
struct TrieNode
{
	TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
	pii zo; // (zeros, ones)
};

// Returns new trie node (initialized to NULLs)
TrieNode *getNode(void) {
	TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(TrieNode *root, string& key, int nxt) {
	TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - '0';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
	if (nxt)
		pCrawl->zo.second++;
	else
		pCrawl->zo.first++;
}

// Returns true if key presents in trie, else
// false
pii search(TrieNode *root, string& key) {
	TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - '0';
		if (!pCrawl->children[index])
			return pii(-1, -1);

		pCrawl = pCrawl->children[index];
	}

	if (pCrawl && pCrawl->isEndOfWord)
		return pCrawl->zo;
	return pii(-1, -1);
}


int countbits(int x) {
	int ret = 0;
	while (x) {
		ret += (x & 1);
		x >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	//int ee = 0, oo = 0, eo = 0, oe = 0;
	//for (int i = 0; i < (1 << 20); i++) {
	//	int cur = countbits(i);
	//	int nxt = countbits((487237LL * (ll)i + 1011807) % 1048576);
	//	if (cur & 1) {
	//		if (nxt & 1) oo++;
	//		else oe++;
	//	}
	//	else {
	//		if (nxt & 1) eo++;
	//		else ee++;
	//	}
	//}
	//cout << "ee " << ee / double((1 << 20) / 2) << endl;
	//cout << "eo " << eo / double((1 << 20) / 2) << endl;
	//cout << "oo " << oo / double((1 << 20) / 2) << endl;
	//cout << "oe " << oe / double((1 << 20) / 2) << endl;

	ll x = 0;
	string s;
	do {
		s.push_back('0' + (countbits(x) & 1));
		x = (487237LL * x + 1011807) % 1048576;
	} while (x);

	int n = s.length();
	s = s + s;
	TrieNode* root = getNode();
	for (int i = 0; i < n; i++) {
		string cs = "";
		for (int sz = 1; sz <= 20; sz++) {
			cs.push_back(s[i + sz - 1]);
			insert(root, cs, s[i + sz] - '0');
		}
	}


	int cur; cin >> cur;
	int prv = cur;
	int bet = 1;

	s = "";
	for (int i = 0; i < 250; i++) {
		cout << bet << endl;
		cin >> cur;
		if (cur == -1) return 0;
		if (cur < prv) s.push_back('0');
		else s.push_back('1');

		if (s.length() > 20)
			s.erase(s.begin(), s.begin() + 1);
		pii p = search(root, s);
		if (~p.first) {
			if (p.second <= p.first) bet = 1;
			else {
				bet = max(1,
					int(min(cur, 200 - cur) *
					((p.second / double(p.first + p.second) - 0.5) / 0.5)));
			}
		}
		else bet = 1;
		prv = cur;
	}
}
