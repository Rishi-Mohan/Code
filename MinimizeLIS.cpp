/*
    author: Rishi Mohan Jha
    created_at: 19-10-2022  08:50 PM
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

	string a, b;
	cin >> a >> b;

	map<int, int> A;
	for (auto i : a)
		A[i]++;

	map<int, int> B;
	for (auto i : b)
		B[i]++;

	int ans = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		if (A.find(i) != A.end() && B.find(i) != B.end())
			ans = max(min(A[i], B[i]), ans);
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();
}
