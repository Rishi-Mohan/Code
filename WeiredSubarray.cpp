/*
    author: Rishi Mohan Jha
    created_at: 19-10-2022  08:08 PM
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

void Solve() {
	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	// vector<array<int,2>> range;
	// int cnt = 1;
	// for(int i=1; i<n; i++){
	// 	if(v[i-1] < v[i])
	// 		cnt += 1;
	// 	else{
	// 		range.pb({i-cnt,i-1});
	// 		cnt = 1;
	// 	}
	// }
	// if(cnt >= 1)
	// 	range.pb({n - cnt, n-1});

	// vector<array<int,2>> u;

	// int prev = 0, now = 0;
	// for(int i=1; i<sz(range); i++){
	// 	if((range[i-1][1] - range[i-1][0] == 0) && (range[i-1][1] - range[i-1][0] == 0) && v[i-1] > v[i]){
	// 		prev = range[i-1][0];
	// 		now = range[i][1];
	// 	}
	// 	else{
	// 		u.pb({prev, now});
	// 		prev = 0;
	// 		now = 0;
	// 		u.pb(range[i]);
	// 	}
	// }

	// debug(range);
	// debug(u);

	vector<array<ll, 3>> _v;

	int cnt = 1, ok = 0;

	for (int i = 1; i < n; i++) {
		if (v[i] > v[i - 1] && cnt == 1) {
			cnt += 1;
			ok = 1;
			continue;
		}

		if (v[i] < v[i - 1] && cnt == 1) {
			cnt += 1;
			ok = 2;
			continue;
		}

		if (ok == 1 && v[i] > v[i - 1]) {
			cnt += 1;
		}
		else if (ok == 2 && v[i] < v[i - 1]) {
			cnt += 1;
		}
		else {
			_v.pb({v[i - cnt], v[i - 1], cnt});
			cnt = 1;
			if (ok == 2) {
				ok = 1;
				continue;
			}
			if (ok == 1) {
				ok = 2;
				continue;
			}
		}
	}

	if (cnt >= 1)
		_v.pb({v[n - cnt], v.back(), cnt});

	// debug(_v);

	ll ans = 0;

	for (int i = 0; i < sz(_v); i++) {
		ans += (_v[i][2] * (_v[i][2] + 1)) / 2;
	}

	for (int i = 1; i < sz(_v); i++) {
		if (_v[i - 1][1] < _v[i][0]) {
			ans += _v[i - 1][2];
		}
		else {
			ans += 1;
		}
	}


	vector<array<ll, 3>> __v;

	cnt = 1; ok = 0;

	for (int i = n-2; i >= 0; i--) {
		if (v[i] > v[i + 1] && cnt == 1) {
			cnt += 1;
			ok = 1;
			continue;
		}

		if (v[i] < v[i + 1] && cnt == 1) {
			cnt += 1;
			ok = 2;
			continue;
		}

		if (ok == 1 && v[i] > v[i + 1]) {
			cnt += 1;
		}
		else if (ok == 2 && v[i] < v[i + 1]) {
			cnt += 1;
		}
		else {
			__v.pb({v[i+1], v[i + cnt], cnt});
			cnt = 1;
			if (ok == 2) {
				ok = 1;
				// cnt = 1;
				continue;
			}
			if (ok == 1) {
				ok = 2;
				// cnt = 0;
				continue;
			}
		}
	}

	if (cnt >= 1)
		__v.pb({v[0], v[cnt-1], cnt});


	ll ans1 = 0;

	for (int i = 0; i < sz(__v); i++) {
		ans1 += (__v[i][2] * (__v[i][2] + 1)) / 2;
	}
	reverse(all(__v));
	// debug(__v, ans1);

	for (int i = 1; i < sz(__v); i++) {
		// if (_v[i - 1][1] < _v[i][0]) {
			ans1 += __v[i - 1][2];
		// }
		// else {
			// ans += 1;
		// }
	}


	cout << max(ans, ans1) << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();


#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}
