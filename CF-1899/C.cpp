/*
    author: Rishi Mohan Jha
    created_at: 17-11-2023  08:22 PM
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

int fun(int l, int r, vector<int> &v) {
	int sum = 0, mx = -1e8;
	for (int i = l; i <= r; i++) {
		sum += v[i];
		mx = max(sum, mx);
		sum = max(sum, 0);
	}
	// debug(sum, mx);
	return mx;
}

void Solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {cin >> v[i];}

	int l = 0;
	int ans = -1e8;
	for (int i = 1; i < n; i++) {
		if ((abs(v[i]) % 2) == (abs(v[i - 1]) % 2)) {
			ans = max(ans, fun(l, i - 1, v));
			l = i;
		}
	}
	ans = max(ans, fun(l, n - 1, v));
	cout << ans << endl;
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
