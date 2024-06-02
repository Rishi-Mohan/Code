/*
   author: rishi_mohan
   created_at: 27-03-2021  04:15 PM
*/
#include<bits/stdc++.h>
using namespace std;

#define    ll            long long
#define    all(x)        (x).begin(),(x).end()

const ll mxn = 1e7 + 1;
vector<ll> pr(mxn + 1);
vector<bool> vis(mxn + 1);

// Using Sieve Prime factorisation in O(Logn);
void prime() {
    for (ll i = 2; i <= mxn; i += 2) {
        pr[i] = 2;
    }
    for (ll i = 3; i <= mxn; i += 2) {
        if (!vis[i]) {
            pr[i] = i;
            for (ll j = i; j * i <= mxn; j += 2) {
                if (!vis[j * i]) {
                    vis[j * i] = 1;
                    pr[j * i] = i;
                }
            }
        }
    }
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);

    prime();

    map<ll, ll> num, den;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        ll x = a[i];
        while (x != 1) {
            num[pr[x]]++;
            x /= pr[x];
        }
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
        ll x = b[i];
        while (x != 1) {
            den[pr[x]]++;
            x /= pr[x];
        }
    }

    for (auto j : num) {
        if (den.find(j.first) != den.end()) {
            ll w = min(num[j.first], den[j.first]);
            num[j.first] -= w;
            den[j.first] -= w;
        }
    }

    // printing logic
    cout << n << ' ' << m << endl;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int ans = 1;
        while (x > 1)
        {
            if (num[pr[x]])
            {
                num[pr[x]]--;
                ans *= pr[x];
            }
            x /= pr[x];
        }
        cout << ans << ' ';
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        int x = b[i];
        int ans = 1;
        while (x > 1)
        {
            if (den[pr[x]])
            {
                den[pr[x]]--;
                ans *= pr[x];
            }
            x /= pr[x];
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  ll t = 1;
    while (t--) Solve();
}
