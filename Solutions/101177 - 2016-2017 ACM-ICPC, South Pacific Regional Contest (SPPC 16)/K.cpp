#include <bits/stdc++.h>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
#endif

	string kan = "kangaroo", ki = "kiwibird";
	string s;
	cin >> s;
	int nkan = 0, nki = 0;
	for (char &i : s) {
		i = tolower(i);
		nkan += count(kan.begin(), kan.end(), i);
		nki += count(ki.begin(), ki.end(), i);
	}

	if (nkan > nki)
		cout << "Kangaroos" << endl;
	else if (nkan < nki)
		cout << "Kiwis" << endl;
	else
		cout << "Feud continues" << endl;

	return 0;
}