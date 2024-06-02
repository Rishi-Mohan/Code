/*
   author: rishi_mohan
   created_at: 20-03-2021  10:41 AM
*/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<long long> bit(100005);
void upd(int node, int value)
{
    for(int i = node; i <= n; i += (i & (-i)))
        bit[i] += value;
}

long long calc(int node)
{
    long long ans = 0;
    for(int i = node; i > 0; i -= (i & (-i)))
        ans += bit[i];
    return ans;
}


void Solve(){
    int q;
    cin >> n >> q;

    vector<int> v(n+1);
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        upd(i, v[i]);
    }

    for(int i=0; i<q; i++){
        int process;
        cin >> process;

        if(process == 1){
            int ind, val;
            cin >> ind >> val;
            ind++;
            upd(ind, val-v[ind]);
            v[ind] = val;
        }
        else{
            int a, b;
            cin >> a >> b;

            a+=1;
            cout << calc(b) - calc(a-1) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  int t = 1;
    while(t--) Solve();
}
