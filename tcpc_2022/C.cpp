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
#define rep(name, start, end) for (int name=(start); name<=(end); name++)
#define repr(name, start, end) for (int name=(start); name<=(end); name--)


using vi = vector<ll>;
using vvi = vector<vector<int>>;

int m = 1e7;
vector<int> nxt(m+1, 1);
void preprocess() {
	for (int i = 2; i <= m; i++) {
	    if (nxt[i]==1 && (long long)i * i <= m) {
	        for (int j = i * i; j <= m; j += i)
	            nxt[j] = max(nxt[j], j/i);
	    }
	}
}
void solve() {
	int n; cin >> n;
	vi a(n), b(n);
	rep(i, 0, n-1) {
		cin >> a[i];
	}
	rep(i, 0, n-1) {
		cin >> b[i];
	}
	ll result = 0;
	rep(i, 0, n-1) {
		int x = a[i];
		int y = b[i];
		while (x != y) {
			if (x > y) {
				x = nxt[x];
			} else {
				y = nxt[y];
			}
			result++;
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
	preprocess();
	int t=1;
	cin >> t;
	rep(i, 1, t)  { 
		solve();
	}
}




