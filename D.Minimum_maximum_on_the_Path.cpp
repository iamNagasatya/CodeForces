#include <bits/stdc++.h>

#define ll long long

using namespace std;


const int N = 1e5 + 1;

vector<pair<ll, ll>> gr[N];

ll n, m, d;

pair<ll, vector<int>> bfs(int src, int dest, int d, int ans){
    vector<bool> vis(n+1, false);
    vector<int> parent(n+1, -1);
    vector<int> dist(n+1, -1);
    
    dist[src] = 0;
    parent[src] = src;
    
    queue<int> Q;
    Q.push(src);
    // vis[src] = true;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        for(auto x : gr[cur]){
             if(!vis[x.first]){
                if(x.second<=ans){
                    Q.push(x.first);
                    vis[x.first] = true;
                    dist[x.first] = dist[cur] + 1;
                    parent[x.first] = cur;
                }
             }
        }
    }

    return make_pair(dist[dest], parent);
}

int main() {
    cin >> n >> m >> d;
    ll x, y, z;
    ll min_wt = INT_MAX, max_wt = INT_MIN;

    for(int i=0; i<m; i++){
        cin >> x >> y >> z;
        min_wt = min(min_wt, z);
        max_wt = max(max_wt, z);
        gr[x].push_back({y, z});
    }

    ll l = min_wt, h = max_wt;

    ll ans = -1;
    vector<int> par;
    while(l<=h){
        ll mid = l+(h-l)/2;
        pair<ll, vector<int>> res = bfs(1, n, d, mid);

        if(res.first == -1 || res.first>d){
            l = mid + 1;
        }
        else{
            ans = res.first;
            par = res.second;
            h = mid-1;
        }
    }
    cout << ans << endl;
    if(ans != -1){
        vector<int> path;
        int v = n;
        while(par[v]!=v){
            path.push_back(v);
            v = par[v];
        }
        path.push_back(v);
        for(int i=path.size()-1; i>=0; i--){
            cout << path[i] << " ";
        }
    }
    return 0;
}
