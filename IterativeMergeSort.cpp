/*
    author: Rishi Mohan Jha
    created_at: 07-08-2022  12:08 AM
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

void Merge(vector<int> &v, int l, int mid, int h) {
	int i = l, j = mid + 1, k = 0;
	vector<int> temp(h - l + 1, 0);

	while (i <= mid && j <= h) {
		if (v[i] < v[j])
			temp[k++] = v[i++];
		else
			temp[k++] = v[j++];
	}

	while (i <= mid)
		temp[k++] = v[i++];

	while (j <= h)
		temp[k++] = v[j++];


	k = 0;
	for (int o = l; o <= h; o++) {
		v[o] = temp[k++];
	}
}

void IterativeMergeSort(vector<int> &v, int n) {
	int p = 0, i=0;
	for (p = 2; p <= n; p *= 2) {
		for (i = 0; i + p - 1 < n; i += p) {
			int l = i;
			int h = p + i - 1;
			int mid = l + (h - l) / 2;

			Merge(v, l, mid, h);
		}
		if (n - i > p / 2) {
			int l = i;
			int h = i + p - 1;
			int mid = l + (h - l) / 2;
		
			Merge(v, l, mid, n - 1);
		}
	}
	debug(v);
	if (p / 2 < n)
		Merge(v, 0, (p / 2) - 1, n - 1);
}

void Solve() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	IterativeMergeSort(v, n);

	debug(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	while (T--) Solve();


#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}
