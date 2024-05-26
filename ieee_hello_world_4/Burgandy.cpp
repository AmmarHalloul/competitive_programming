#include "cstdlib"
#include "cstring"
#include "cmath"
#include "iostream"
#include "stack"
#include "vector"
#include "array"
#include "queue"
#include "algorithm"
#include "map"
#include "set"
#include "unordered_map"
#include "unordered_set"
#include "numeric"
#include "string"
#include "iomanip"
#include "climits"
#include "functional"
#include "cctype"

using namespace std; 

#define all(a) a.begin(), a.end()
using ll = long long;
#define nl '\n'
#define MOD 1000000007

#define dbg(value) cerr << "#" #value << ": " << (value) << nl;

template<typename type> 
struct matrix : vector<vector<type>> {
    matrix(int N, int M, type Val = {}) : 
        ::vector<vector<type>>(N, vector<type>(M, Val)){}     
}; 


vector<vector<int>> g;
vector<bool> v;

void dfs(int node) {
    v[node] = true;
    for (int i: g[node]) {
        if (!v[i]) {
            dfs(i);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    g.resize(n+1);
    v.resize(n+1);
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int, int>> result;
    
    dfs(1);
    for (int i=2; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
            if (result.size()) {
                result.push_back({result.back().second, i});
            } else {
                result.push_back({1, i});
            }
        } 
    }
    cout << result.size() << nl;
    for (auto[i, j]: result) {
        cout << i << ' ' << j << nl;
    }

}   

int main() {
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #endif
    // preprocess();
    int t=1;
    // cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
}




 