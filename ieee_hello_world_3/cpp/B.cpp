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

int dx[4] = {1, -1, 0,  0};
int dy[4] = {0,  0, 1, -1};

struct vec2 {
    int x, y;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    matrix<bool> v(n, m);
    vec2 start, goal;
    for (int i=0; i<n; i++) {
        cin >> g[i];
        for (int j=0; j<m; j++) {
            if (g[i][j] == 'S') {
                start = {i, j};
            } else if (g[i][j] == 'T') {
                goal = {i, j};
            }
        }
    }
    using T = tuple<int, int, int, int>; //turns, dir, x, y
    priority_queue<T, vector<T>, greater<T>> q; 
    q.push({0, -1, start.x, start.y});
    while (q.size()) {
        auto [turns, dir, x, y] = q.top(); q.pop();
        if (x < 0 || x >= n ||
            y < 0 || y >= m || 
            g[x][y] == '*' || v[x][y] || turns > k) continue;
        
        v[x][y] = true;
        for (int i=0; i<4; i++) {
            int t = turns;
            if (i != dir && dir != -1) t++;
            q.push({t, i, x+dx[i], y+dy[i]});  
        }  
    }
    if (v[goal.x][goal.y]) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
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





