#include<bits/stdc++.h>
using namespace std;

void Solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int> (m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	map<vector<int>, int> mp;

	for (int i = 0; i < n; i++) {
		vector<int> temp(m, -1);
		for (int j = 0; j < m; j++) {
			
			if (v[i][j] == -1) break;
			temp[j] = v[i][j];
			mp[temp]++;
		}
	}

	// for (auto i : mp) {
	// 	vector<int> tt = i.ff;N
	// 	debug(tt, i.ss);
	// }

	int q;
	cin >> q;

	vector<int> ans(q);

	for (int i = 0; i < q; i++) {
		vector<int> Q(m);
		for (int i = 0; i < m; i++) {
			cin >> Q[i];
		}

		if (mp.find(Q) != mp.end())
			ans[i] = mp[Q];
	}

	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	while (T--) Solve();
}
