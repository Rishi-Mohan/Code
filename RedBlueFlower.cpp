/*
    author: Rishi Mohan Jha
    created_at: 19-10-2022  10:17 PM
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

int res = 0;

void solve(int ind, vector<int> &r, vector<int> &b, int red, int blue) {
	if (ind == sz(r))
		return;

	solve(ind + 1, r, b, red + r[ind], blue);
	solve(ind + 1, r, b, red, blue + b[ind]);

}

void Solve() {
	int n;
	cin >> n;

	vector<int> r(n), b(n);

	for (int i = 0; i < n; i++)
		cin >> r[i];

	for (int i = 0; i < n; i++)
		cin >> b[i];


	int x = 0, y = 0;

	// cout << solve(0,r, b) << endl; // ind, taken(R/B)
	solve(0, r, b, 0, 0); // ind, taken(R/B)
	cout << res << endl;
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
