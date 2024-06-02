/*
    author: Rishi Mohan Jha
    created_at: 09-08-2022  10:58 PM
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

void CountingSort(vector<int> &v){
	int mx = *max_element(all(v));

	vector<int> cnt(mx + 1);

	for(int i=0; i < sz(v); i++){
		cnt[v[i]]++;
	}

	for(int i=0, j = 0; i<=mx; i++){
		while(cnt[i] > 0){
			v[j++] = i;
			cnt[i]--;
		}
	}
}

void Solve() {
	int n;
	cin >> n;

	vector<int> v(n);

	for(int i=0; i<n; i++)
		cin >> v[i];

	CountingSort(v);

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

Name = ['A', 'B', 'C', 'D', 'E']
Marks = [[20,25,30], [18, 29, 30], [20, 27, 38], [5, 28, 30], [21, 2, 30]]

data = dict()
for i in range(0, len(Name)):
    data[Name[i]] = Marks[i]
print(data)


sumOfMarks = dict()
for i in data:
    s = 0
    for j in data[i]:
        s += j
    sumOfMarks[i] = s
print(sumOfMarks)

D1 = []
for i in sumOfMarks:
    D1.append(sumOfMarks[i])

D1.sort(reverse=1)

j = 0
data.clear()
for i in sumOfMarks:
    data[i] = D1[j]
    j += 1

print(data)
    

import numpy as np
L = [1, 8, 8, 9, 7, 6, 6, 0, 7, 4, 3, 2, 7]

A = np.array(L)
print(A)

R1 = A[::-1]
print(R1)
R2 = np.flipud(A)
print(R2)

print(len(A))

A = np.sort(A)
print(A)

unique, counts = np.unique(A, return_counts = True)
print(np.asarray((unique, counts)))


