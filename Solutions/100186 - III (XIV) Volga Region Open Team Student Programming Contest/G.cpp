// III (XIV) Volga Region Open Team Student Programming Contest
// 100186G

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;
const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};
const ll MOD = 1e9 + 7;
const long double EPS = 1e-5;
#define all(x) x.begin(),x.end()

#include <ext/hash_set>
#include <ext/numeric>

string bits(int x) {
	string ret = "";
	for (int i = 0; i < 30; ++i) {
		if (x & (1 << i))
			ret.push_back('1');
		else
			ret.push_back('0');
	}
	reverse(all(ret));
	return ret;
}

int num(string& s) {
	int ret = 0;
	for (int i = 0; i < 30; ++i) {
		if (s[29 - i] == '1')
			ret += (1 << i);
	}
	return ret;
}

const int ALPHABET_SIZE = 2;
struct TrieNode {
	TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
};

TrieNode *getNode() {
	TrieNode *pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		pNode->children[i] = NULL;
	}
	return pNode;
}

void insert(TrieNode* root, string& key) {
	TrieNode* pCrawl = root;
	for (int i = 0; i < key.length(); ++i) {
		int idx = key[i] - '0';
		if (!pCrawl->children[idx])
			pCrawl->children[idx] = getNode();
		pCrawl = pCrawl->children[idx];
	}
	pCrawl->isEndOfWord = true;
}

bool search(TrieNode* root, string& key) {
	TrieNode* pCrawl = root;
	for (int i = 0; i < key.length(); ++i) {
		int idx = key[i] - '0';
		if (!pCrawl->children[idx])
			idx = (idx + 1) % 2;
		key[i] = '0' + idx;
		pCrawl = pCrawl->children[idx];
	}
	return (pCrawl != NULL && pCrawl->isEndOfWord);
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	unordered_map<string, int> idx;
	int mn = INT_MAX, mna = -1, mnb = -1;

	unordered_set<string> st;
	TrieNode* root = getNode();

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		string s = bits(x);
		if (i) {
			string cur = s;
			search(root, cur);
			int xr = num(cur) ^x;
			if (i && xr < mn)
				mn = xr, mna = idx[cur], mnb = i;
		}
		insert(root, s);
		idx[s] = i;
	}
	cout << mna + 1 << " " << mnb + 1 << endl;
	return 0;
}