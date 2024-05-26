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
struct Node {
    vector<int> w;
    vector<int> next;
    Node() : next(128, -1) {}
};
 
void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int m; cin >> m;
    vector<Node> prefix_tree(1);
 
    for (int i=0; i<m; i++) {
        string s; cin >> s;
        
        int index = 0;
        for (char c: s) {
            if (prefix_tree[index].next[c] == -1) {
                int new_index  = prefix_tree.size();
                prefix_tree[index].next[c] = new_index;   
                index = new_index;   
                prefix_tree.emplace_back();
            } else {
                index = prefix_tree[index].next[c];
            }
        }
        prefix_tree[index].w.push_back(i);
    }
    
    vector<set<int>> result(m); 
    for (int i=0; i<n; i++) {
        for (int j=0; j<a[i].size(); j++) {
            int pti = 0;
            for (int k=j; prefix_tree[pti].next[a[i][k]] != -1; k++) {
                pti = prefix_tree[pti].next[a[i][k]];
                for (int w: prefix_tree[pti].w)
                    result[w].insert(i);
                
            }   
        }  
    }  
    
    for (int i=0; i<m; i++) {
        if (result[i].size()) {
            cout << result[i].size() << ' ' << a[*result[i].begin()] << nl;
        } else {
            cout << "0 -"<< nl;
        }
 
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




 