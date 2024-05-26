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

ll fact_pow (ll n, ll k) {
    ll res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}

vector<pair<ll, ll>> prime_factorization(ll n) {
    vector<pair<ll, ll>> factorization;
    for (ll d = 2; d * d <= n; d++) {
        ll count = 0;
        while (n % d == 0) {
            count++;
            n /= d;
        }
        if (count) {
            factorization.push_back({d, count});
        }
    }
    if (n > 1)
        factorization.push_back({n, 1});
    return factorization;
}

void solve() {
    ll n, k; cin >> n >> k;
    auto factors = prime_factorization(k);
    ll res = LLONG_MAX;
    for (auto [p, i]: factors) {
        ll a = fact_pow(n, p);
        res = min(res, a/i);
    }
    cout << res << nl;
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
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
}




 