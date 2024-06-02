/*
    author: Rishi Mohan Jha
    created_at: 19-10-2022  03:20 PM
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

	vector<vector<string>> v(n, vector<string> (5));

	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++)
			cin >> v[i][j];
	}

	int D;
	cin >> D;

	string val;
	cin >> val;

	vector<vector<string>> A;

	for(int i=0; i<n; i++){
		if(v[i][D-1] == val){ // 0 based indexing
			A.push_back(v[i]);
		}
	}

	sort(A.begin(), A.end());

	for(auto i : A)
		cout << i << endl;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);  int T = 1;
      while (T--) Solve();
}
