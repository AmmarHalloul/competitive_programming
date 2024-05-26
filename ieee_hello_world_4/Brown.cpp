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
    int n, m; cin >> n >> m;
    matrix<int> a(n+2, m+2, -1); 
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }

    set<int> result; 
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int t = a[i][j];
            if (t == -1) continue;
            if (t == a[i+1][j] ||
                t == a[i-1][j] ||
                t == a[i][j+1] ||
                t == a[i][j-1] ||
                t == a[i+1][j+1] ||
                t == a[i-1][j-1] ||
                t == a[i-1][j+1] ||
                t == a[i+1][j-1]) {

                result.insert(t);
            }
        }
    }
    cout << result.size() << nl;
    
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




 