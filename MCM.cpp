/*
    author: Rishi Mohan Jha
    created_at: 18-10-2022  09:08 PM
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

// Recursive Approach
int mcm(int i, int j, vector<int> &A) {
	if (i == j)
		return 0;

	int mn = 1e7;

	for (int k = i; k <= j - 1; k++) {
		int ans = mcm(i, k, A) + mcm(k + 1, j, A) + A[i - 1] * A[k] * A[j];
		mn = min(ans, mn);
	}

	return mn;
}


void Solve() {
	vector<int> A = {2, 4, 6, 3, 5, 4};
	int i = 1, j = 5;

	cout << mcm(1, 5, A) << endl;
}


// Tabulation Matrix Chain Multiplication
void Solve() {
	vector<int> A = {2, 4, 6, 3, 5, 4};

	int n = A.size();
	vector<vector<int>> dp(n, vector<int>(n, 400));

	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j < n; j++) {
			for (int k = i; k <= j - 1; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + A[i - 1] * A[k] * A[j]);
			}
		}
	}

	// To print the table of MCM
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}

	// Answer
	cout << dp[1][n - 1] << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	while (T--) Solve();
}
