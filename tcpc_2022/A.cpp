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
	int x, y; cin >> x >> y;
	cout << max(0, y-x) << nl;
}
	

int main() {
	#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#endif

	int t=1;
	cin >> t;
	rep(i, 1, t)  { 
		solve();
	}
}




