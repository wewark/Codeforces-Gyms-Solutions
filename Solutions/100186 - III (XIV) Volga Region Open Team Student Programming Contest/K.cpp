// III (XIV) Volga Region Open Team Student Programming Contest
// 100186K

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

char str[15][100];
int freq[14];

int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);

	for(int i = 0 ; i < 9 ; i++)
		scanf("%s",str[i]);

	int extra = 0;
	for(int i = 0 ; i < 10 ; i++){
		freq[1] += (str[0][extra + 1] == 'x');
		freq[2] += (str[1][extra + 0] == 'x');
		freq[3] += (str[1][extra + 4] == 'x');
		freq[4] += (str[4][extra + 1] == 'x');
		freq[5] += (str[5][extra + 0] == 'x');
		freq[6] += (str[5][extra + 4] == 'x');
		freq[7] += (str[8][extra + 1] == 'x');
		extra += 6;
	}

	for(int i = 1 ; i <= 7 ; i++){
		if(i != 1)printf(" ");
		if(freq[i] == 0){
			printf("-1");
		}else if(freq[i] == 10){
			printf("1");
		}else{
			printf("0");
		}
	}

	printf("\n");

	return 0;
}
