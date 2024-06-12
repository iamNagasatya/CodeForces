#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> diff(2*k+2, 0), freq(2*k+2, 0);
        for(int i=0; i<n/2; i++){
            int a = arr[i], b  = arr[n-i-1];
            freq[a+b]++;
            diff[min(a, b)+1]++;
            diff[max(a, b)+k+1]--;
        }
        for(int i=2; i<=2*k; i++){
            diff[i] += diff[i-1];
        }
        
        int ans = INT_MAX;
        for(int i=2; i<=2*k; i++){
            ans = min(ans, diff[i]-freq[i] + 2 * (n/2 - diff[i]));
        }
        cout << ans << endl;
    }
    
    return 0;
}