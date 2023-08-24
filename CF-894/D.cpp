/*
    author: Rishi Mohan Jha
    created_at: 24-08-2023  09:20 PM
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
	ll n;
	cin >> n;

	ll l = 1, r = 1e10, ans = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if ((mid * (mid + 1)) / 2  <= n) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	ll res = (ans * (ans + 1)) / 2;
	// debug(ans, n - res);

	cout << ans + (n - res) + 1 << endl;
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
