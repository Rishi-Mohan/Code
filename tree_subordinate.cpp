/*
   author: rishi_mohan
   created_at: 19-04-2021  04:07 PM
*/
#include<bits/stdc++.h>
using namespace std;

#define    ll            long long
#define    all(x)        (x).begin(),(x).end()

const int mxn = 2e5+5;

vector<int> adj[mxn];
vector<bool> vis(mxn);

void Solve(){
    int n;
    cin >> n;

    for(int i=2; i<=n; i++){
        int u;
        cin >> u ;

        adj[i-1].push_back(u);
        adj[u].push_back(i-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  int t = 1;
    cin >> t;
    while(t--) Solve();
}
