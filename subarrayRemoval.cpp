/*
    author: Rishi Mohan Jha
    created_at: 19-10-2022  08:57 PM
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

	vector<int> v(n);
	int one = 0, zero = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];

		if (v[i] == 1) one += 1;
		else zero += 1;
	}

	int k = min(one, zero);
	ans = k;
	if (k != 0)
		one -= k;

	ans += (one / 3);

	cout << ans << endl;
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
