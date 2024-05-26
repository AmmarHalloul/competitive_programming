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

#define dbg(value) cerr << "#" << #value << ": " << (value) << nl;

vector<int> Bit;

void Bit_Add(int K, int V) {
    for (;K<Bit.size(); K+=K&-K) {
        Bit[K] += V;
    }
}   

int Bit_Sum(int K) {
    int S = 0;
    for (;K>0; K-=K&-K) {
        S += Bit[K];
    }
    return S;
}   

void Solve() {
    int N; cin >> N;
    map<int, int> Compress;
    // Y, QIndex, X 
    vector<tuple<int, int, int>> A;
    for (int I=0; I<N; I++) {
        int X1, Y1, X2, Y2; 
        cin >> X1 >> Y1 >> X2 >> Y2;
        Compress[X2] = 0;
        A.push_back({Y2, 0, X2});
    }
    int Q; cin >> Q;
    vector<int> Result(Q+1);

    for (int I=1; I<=Q; I++) {
        int X, Y; cin >> X >> Y;
        Compress[X] = 0;
        A.push_back({Y, I, X});
    }

    int Index = 1;
    for (auto& I: Compress) {
        I.second = Index++;
    }
    Bit.resize(Compress.size()+1);

    sort(all(A));
    for (auto [Y, QIndex, X]: A) {
        if (QIndex) {
            Result[QIndex] += Bit_Sum(Compress[X]);
        } else {
            Bit_Add(Compress[X], 1);
        }

    }   
    for (int I=1; I<=Q; I++) {
        cout << Result[I] << nl;
    }
    // dbg(Bit_Sum(Compress.size()));
}
	

int main() {
	#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#endif
	// preprocess();
	int T=1;
	// cin >> T;
	for (int I=0; I<T; I++){
		Solve();
	}

}





