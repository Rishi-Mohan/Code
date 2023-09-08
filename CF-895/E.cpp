/*
    author: Rishi Mohan Jha
    created_at: 08-09-2023  07:06 PM
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
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];

	string s;
	cin >> s;

	int x0 = 0, x1 = 0;

	for(int i=0; i<n; i++){
		if(s[i] == '1')
			x1 ^= v[i];
		else
			x0 ^= v[i];
	}

	vector<int> pre(n);
	int _xor = 0;
	for(int i=0; i<n; i++){
		_xor ^= v[i];
		pre[i] = _xor;
	}

	int q;
	cin >> q;

	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int l, r;
			cin >> l >> r;
			l--; r--;
			x0 ^= (pre[r] ^ (l-1 >= 0 ? pre[l-1] : 0));
			x1 ^= (pre[r] ^ (l-1 >= 0 ? pre[l-1] : 0));

		}else{
			int bit;
			cin >> bit;
			cout << (bit == 0 ? x0 : x1) << " ";
		}
	}
	cout << endl;
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
