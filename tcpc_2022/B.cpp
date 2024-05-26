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


void solve() {
	int n; cin >> n;
	vi a(n+1);
	rep(i, 1, n) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	int q; cin >> q;
	rep(i, 1, q) {
		int x, y, m; cin >> x >> y >> m;
		cout << min(max<ll>(x, a[n]), y+a[m]) << nl;
	}
}
	

int main() {
	#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#endif

	int t=1;
	// cin >> t;
	rep(i, 1, t)  { 
		solve();
	}
}




n