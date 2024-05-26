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



void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    int result = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i].second >> v[i].first;
    }   
    sort(all(v));
    int l = 0;
    int r = n-1;
    while (l<=r) {
        result = max(result, v[l].first+v[r].first);
        if (v[l].second == v[r].second) {
            l++;
            r--;
        } else if (v[l].second > v[r].second) {
            v[l].second -= v[r].second;
            r--;
        } else {
            v[r].second -= v[l].second;
            l++;
        }
    }
    cout << result << nl;
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





