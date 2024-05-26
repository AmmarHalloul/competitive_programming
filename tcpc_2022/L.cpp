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
using ilong = long long;
#define nl '\n'
#define MOD 1000000007

void DFS(vector<vector<int>> const& Tree, vector<int> const& Color, 
		 int PrevSum, int Node, int Prev, multiset<int> &Freq, vector<int> &Result) {
	int Sum = PrevSum + Color[Node];
	for (int I: Tree[Node]) {
		if (I != Prev) {
			multiset<int> NextFreq;
			DFS(Tree, Color, Sum, I, Node, NextFreq, Result);
			if (NextFreq.size() > Freq.size()) {
				swap(NextFreq, Freq);
			}
			for (int I: NextFreq) {
				Freq.insert(I);
			}
		}
	}
	Result[Node] = Freq.count(PrevSum);
	Freq.insert(Sum);
}
	
void solve() {
	int N, Q; cin >> N >> Q;
	vector<int> Color(N+1);
	vector<vector<int>> Tree(N+1);
	vector<int> Result(N+1);

	for (int I=1; I<=N; I++) {
		int X; cin >> X;
		Color[I] = (X) ? 1 : -1;

	}
	for (int I=0; I<N-1; I++) {
		int A, B; cin >> A >> B;
		Tree[A].push_back(B);
		Tree[B].push_back(A);
	}
	multiset<int> Freq;
	DFS(Tree, Color, 0, 1, 0, Freq, Result);

	for (int I=0; I<Q; I++) {
		int X; cin >> X;
		cout << Result[X] << nl;
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





