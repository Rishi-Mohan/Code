/*
    author: Rishi Mohan Jha
    created_at: 09-08-2022  10:01 PM
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

// // QuickSort using first element as pivot and INT_MAX 
// int partition(vector<int> &v, int l, int h) {
// 	int pivot = v[l];
// 	int i = l;
// 	int j = h;

// 	do {
// 		 // Increment i as long as elements are smaller/equal to pivot
// 		do {i++;} while (v[i] <= pivot);
// 		// Decrement j as long as elements are larger than pivot
// 		do {j--;} while (v[j] > pivot);

// 		if (i < j)
// 			swap(v[i], v[j]);
// 	} while (i < j);

// 	swap(v[l], v[j]);
// 	return j;
// }

// void QuickSort(vector<int> &v, int l, int h) {
// 	if (l < h) {
// 		int j = partition(v, l, h);
// 		QuickSort(v, l, j);
// 		QuickSort(v, j + 1, h);
// 	}
// }

// First Element is Pivot + without using INT_MAX or INFINITY
int partition(vector<int> &v, int low, int high){
    int pivot = v[low];
    int i = low + 1;
    int j = high;
 
    while (true){
        while (i <= j && v[i] <= pivot){
            i++;
        }
        while (v[j] >= pivot && j >= i){
            j--;
        }
        if (j < i){
            break;
        } else {
            swap(v[i], v[j]);
        }
    }
    swap(v[low], v[j]);
    return j;
}
 
void QuickSort(vector<int> &v, int low, int high){
    if (low < high){
        int p = partition(v, low, high);
        QuickSort(v, low, p-1);
        QuickSort(v, p+1, high);
    }
}

void Solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	// v.pb(INT_MAX);

	QuickSort(v, 0, n - 1);

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
