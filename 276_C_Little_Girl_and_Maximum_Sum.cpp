#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int l , r;
    vector<int> diff(n+2, 0);

    for(int i=0; i<q; i++){
        cin >> l >> r;
        diff[l-1]++;
        diff[r]--;
    }

    for(int i=1; i<n; i++){
        diff[i] += diff[i-1];
    }

    sort(v.begin(), v.end());
    sort(diff.begin(), diff.end()-2);

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += 1LL * v[i] * diff[i];
    }
    cout << ans << endl;
    
    return 0;
}