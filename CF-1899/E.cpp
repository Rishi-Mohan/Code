/*
    author: Rishi Mohan Jha
    created_at: 17-11-2023  09:08 PM
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
	int n;
	cin >> n;

	vector<int> v(n);
	ll small = 1e10, ind = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] < small) {
			small = v[i];
			ind = i;
		}
	}

	for (int i = ind; i + 1 < n; i++) {
		if (v[i] > v[i + 1]) {
			cout << "-1" << endl;
			return;
		}
	}

	cout << ind << endl;
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
