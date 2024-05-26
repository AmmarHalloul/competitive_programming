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
    matrix(int N, int M, type Value = {}) : 
        ::vector<vector<type>>(N, vector<type>(M, Val)){}     
}; 


void solve() {
    string s; cin >> s;
    int n = s.size();
    int result = INT_MAX;
    set<char> letters;
    char first = 'A'; 
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=i; j<n; j++) {
            if (s[j] == first+count) {
                count++;
            }
            if (count == 26) {
                result = min(result, j-i+1);
                break;
            }
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





