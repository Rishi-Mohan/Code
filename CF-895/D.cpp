/*
    author: Rishi Mohan Jha
    created_at: 07-09-2023  09:16 PM
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

ll sum(ll n) {
	return (n * (n + 1)) / 2;
}

void Solve() {
	ll n, x, y;
	cin >> n >> x >> y;

	ll cntX = n / x;
	ll cntY = n / y;
	ll cntXY = n / ((x * y) / __gcd(x, y));

	cntX -= cntXY;
	cntY -= cntXY;


	ll ans = 0;

	ans += sum(n) - sum(n-cntX);

	ans -= sum(cntY);

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
