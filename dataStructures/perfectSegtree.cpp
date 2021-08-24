#include<bits/stdc++.h>
using namespace std;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
#define ford(i, a, b) for(int i = int(a); i >= (int)b; i--)
#define tam 100
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<vector<ll>> dpi;

class SegTree{
    public:
    ll n;
    vector<ll>vet, tree;
    SegTree(){
        cin>>n;
        vet.resize(n+3);
        tree.resize((n+3)*4);
        forc(i,0,n){
            cin>>vet[i];
        }
        build();
    }
    void build() {  // build the tree
        for (ll i = n - 1; i > 0; --i) tree[i] = tree[i<<1] + tree[i<<1|1];
    }

    void modify(ll p, ll value) {  // set value at position p
        for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
    }

    ll query(ll l, ll r) {  // sum on interval [l, r)
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += tree[l++];
            if (r&1) res += tree[--r];
        }
        return res;
    }
    void logica(){
        
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return 0;
}