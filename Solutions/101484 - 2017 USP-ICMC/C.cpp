// 101484 - 2017 USP-ICMC
// 101484C

#include <bits/stdc++.h>
using namespace std;

int n, m, p;

struct Team {
  string name;
  vector<int> sub;
  int numSolved = 0, penalty = 0;

  Team(string _name) {
    name = _name;
    sub.assign(p, 0);
  }

  void ac(int pidx, int ctm) {
    penalty += sub[pidx] * 20;
    penalty += ctm;
    numSolved++;
  }

  void wa(int pidx) {
    sub[pidx]++;
  }

  bool operator == (Team other) {
    return numSolved == other.numSolved && penalty == other.penalty;
  }

  bool operator > (Team other) {
    if (numSolved != other.numSolved)
      return numSolved > other.numSolved;
    return penalty < other.penalty;
  }
};

vector<Team> tms;
map<string, int> idx;

int r = 0, start = 0;

void lead(int ctm) {
  if (start == -1) start = ctm;
}
void nolead(int ctm) {
  if (start != -1) {
    r += ctm - start;
    start = -1;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> p;

  string myUni;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    tms.push_back(Team(s));
    idx[s] = i;

    if (i == 0) myUni = s;
  }

  for (int i = 0; i < m; ++i) {
    string s; char c; int t; string msg;
    cin >> s >> c >> t >> msg;
    int cur = idx[s];

    if (msg == "OK") {
      tms[cur].ac(c - 'A', t);
      while (cur > 0 && tms[cur] > tms[cur - 1]) {
        idx[tms[cur - 1].name]++;
        idx[s]--, cur--;
        swap(tms[cur + 1], tms[cur]);
      }
    }
    else {
      tms[cur].wa(c - 'A');
    }

    if (tms[idx[myUni]] == tms[0]) lead(t);
    else nolead(t);
  }

  nolead(300);
  cout << r << endl;
  return 0;
}
