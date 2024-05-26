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

vector<int> ps;
const int maxr = 200000000;
const int maxp = maxr/15; // 3 * 5


void preprocess() {
    
    vector<int> primes;
    {
        // sieve of eratosthenes
        vector<bool> is_prime(maxp+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= maxp; i++) {
            if (is_prime[i] && (ll)i * i <= maxp) {
                for (int j = i * i; j <= maxp; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        for (int i=3; i<=maxp; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
    }
    
    int m = primes.size();
    ps.resize(maxr+1);
    for (int i=0; i<m; i++) {
        ll pi = primes[i];
        for (int j=i+1; j<m; j++) {
            ll pj = pi * primes[j];
            if (pj > maxr) break;
            for (int k=j+1; k<m; k++) {
                ll pk = pj * primes[k];
                if (pk > maxr) break;
                ps[pk] = 1;
            }
        }
    }
    
    // prefix sum 
    for (int i=1; i<=maxr; i++) {
        ps[i] += ps[i-1];
    }
}


int solve(int l, int r) {
    return ps[r] - ps[l-1];
}

int main() {
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #endif
    preprocess();
    int t=1;
    cin >> t;
    for (int i=0; i<t; i++){
        int l, r; cin >> l >> r;
        cout << "Case " << i+1 << ": " << solve(l, r) << nl;
    }

}





