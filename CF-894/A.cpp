/*
    author: Rishi Mohan Jha
    created_at: 24-08-2023  08:05 PM
*/

#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define ll     long long
#define ff     first
#define ss     second
#define pb     push_back
#define sz(x)  ((int)(x).size())
#define all(a) (a).begin(),(a).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

void Solve() {
	int n, m;
	cin >> n >> m;

	vector<string> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	if (m < 4) {
		cout << "NO" << endl;
		return;
	}

	vector<char> want = {'v', 'i', 'k', 'a'};
	int k = 0;

	for (int i = 0; i < m && k < 4; i++) {
		for (int j = 0; j < n && k < 4; j++) {
			if (v[j][i] == want[k]) {
				k++;
				break;
			}
		}
	}

	cout << (k == 4 ? "YES" : "NO") << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();


#ifndef ONLINE_JUDGE
	// cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}
