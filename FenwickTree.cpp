/*
    author: Rishi Mohan Jha
    created_at: 25-12-2022  02:13 PM
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

struct FenwickTree {
	vector<ll> bit;
	ll n;

	FenwickTree(ll n) {
		this->n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	ll sum(ll r) {
		ll ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	ll sum(ll l, ll r) {
		return sum(r) - sum(l - 1);
	}

	void add(ll idx, ll delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};


void Solve() {
	ll n, q;
	cin >> n >> q;

	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	FenwickTree tree(v);

	while (q--) {
		ll t;	
		cin >> t;

		if (t == 1) { // update
			ll ind, val;
			cin >> ind >> val;
			ind--;
			tree.add(ind, val - v[ind]);

		} else { // query
			ll l, r;
			cin >> l >> r;
			l--; r--;
			cout << tree.sum(r) - (l - 1 >= 0 ? tree.sum(l - 1) : 0) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	while (T--) Solve();
}



