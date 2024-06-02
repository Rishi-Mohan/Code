/*
    author: Rishi Mohan Jha
    created_at: 23-12-2021  08:19 PM
*/

#include<bits/stdc++.h>
using namespace std;

#define ll        long long
#define ff        first
#define ss        second
#define pb        push_back
#define sz(x)     ((int)(x).size())
#define all(a)    (a).begin(),(a).end()

void Solve() {
      int n, sum;
      cin >> n >> sum;

      vector<int> v(n);
      for (int i = 0; i < n; i++) {
            cin >> v[i];
      }

      vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
      for (int i = 0; i <= sum; i++) {
            dp[0][i] = 0;
      }
      for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
      }

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                  if (dp[i - 1][j] == 1 || (j - v[i - 1] >= 0 && dp[i - 1][j - v[i - 1]] == 1)) {
                        dp[i][j] = 1;
                  }
                  else {
                        dp[i][j] = 0;
                  }
            }
      }

      cout << (dp[n][sum] == 1 ? "YES" : "NO") << endl;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int t = 1;
      while (t--) Solve();
}
