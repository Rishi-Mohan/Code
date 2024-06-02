/*
    author: Rishi Mohan Jha
    created_at: 22-12-2021  02:02 PM
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
      int n;
      cin >> n;

      vector<int> v(n);
      for (int i = 0; i < n; i++)
            cin >> v[i];

      vector<int> check;
      for (int i = 0; i < n; i++) {
            if (sz(check) == 0 || check.back() < v[i]) {
                  check.pb(v[i]);
            }
            else {
                  int ind = upper_bound(all(check), v[i]-1) - check.begin();
                  check[ind] = v[i];
            }
      }
      cout << sz(check) << endl;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int t = 1;
      while (t--) Solve();
}
