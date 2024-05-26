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

    vector<tuple<int, int, int>> spray(n);
    vector<int> score(9);
    vector<int> last_hit(9, -1000);
    
    for (int i=0; i<n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        spray[i] = {t, a, b};
    }

    sort(all(spray));

    for (auto [t, a, b]: spray) {
        int d = t-last_hit[a];
        last_hit[a] = t;
        score[a] += 100;
        if (d <= 10) score[a] += 50;
    }
    
    int s1 = 0;
    int s2 = 0;
    for (int i=1; i<=4; i++) {
        s1 += score[i];
    }
    for (int i=5; i<=8; i++) {
        s2 += score[i];
    }
    cout << s1 << ' ' << s2 << nl;

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





