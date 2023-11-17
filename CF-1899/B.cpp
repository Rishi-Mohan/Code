/*
    author: Rishi Mohan Jha
    created_at: 17-11-2023  08:10 PM
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

ll fun(int i, vector<int> &v) {
	vector<ll> temp;
	int n = sz(v);
	for (int j = 0; j < n; j += i) {
		ll s = 0;
		for (int k = j; k < j + i; k++) {
			s += v[k];
		}
		temp.pb(s);
	}
	sort(all(temp));
	return (temp.back() - temp[0]);
}

void Solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];


	vector<ll> pref;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		s += v[i];
		pref.pb(s);
	}

	ll sum = 0, ans = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ans = max(ans, fun(i, v));
			if ((n / i) != i)
				ans = max(ans, fun(n / i, v));
		}
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
