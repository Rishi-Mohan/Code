#include<bits/stdc++.h>
using namespace std;

void Solve() {
	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;

	for (int i = 1; i <= (1 << n); i++) {
		map<char, int> mp;

		for (int j = 0; j < n; j++) {
			bool ok = 1;
			if (i & (1 << j)) {
				for (auto k : v[j]) {
					mp[k]++;
				}
			}
		}

		int cnt = 0;
		bool ok = 1;

		for (auto j : mp) {
			if (j.second >= 2)
				break;
			else
				cnt += j.second;
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	while (T--) Solve();
}
