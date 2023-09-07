/*
    author: Rishi Mohan Jha
    created_at: 07-09-2023  08:18 PM
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

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

void Solve() {
	int l, r;
	cin >> l >> r;


	if (r & 1 ^ 1) {
		if (__gcd(r / 2, r / 2) == 1) {
			cout << "-1" << endl;
			return;
		}
		cout << r / 2 << ' ' << r / 2 << endl;
		return;
	}

	if (r - 1 >= l && r > 3) {
		r -= 1;
		if (__gcd(r / 2, r / 2) == 1) {
			cout << "-1" << endl;
			return;
		}
		cout << r / 2 << ' ' << r / 2 << endl;
		return;
	}

	if (l == r && isPrime(l) == 0) {
		for (int i = 2; i <= r; i += 2) {
			int a = i, b = r - i;
			if (__gcd(a, b) != 1) {
				cout << a << " " << b << endl;
				return;
			}
		}
	}
	cout << "-1" << endl;
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
