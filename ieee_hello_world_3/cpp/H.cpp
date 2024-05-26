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


int first(multiset<int> const& s) {
    return *s.begin();
}

int last(multiset<int> const& s) {
    auto it = s.end();
    it--;
    return *it;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    set<int> ids;
    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
        ids.insert(a[i].second);
    }
    int m = ids.size();
    sort(all(a));
    int result = INT_MAX;
    multiset<int> s;
    map<int, int> last_pos;
    for (int i=0; i<n; i++) {
        if (last_pos.count(a[i].second)) {
            s.erase(s.find(last_pos[a[i].second]));     
        }
        last_pos[a[i].second] = a[i].first;
        s.insert(a[i].first);
        if (s.size() == m) {
            result = min(result, last(s)-first(s));
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





