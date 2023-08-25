/*
    author: Rishi Mohan Jha
    created_at: 25-08-2023  03:31 PM
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
	int n, m, d;
	cin >> n >> m >> d;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	ll res = 0, ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		if (v[i] > 0) {
			pq.push(v[i]);
			res += v[i];
		}
		if (sz(pq) > m) {
			res -= pq.top();
			pq.pop();
		}

		ans = max(ans, res -  1LL * (i + 1) * d);
	}

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
