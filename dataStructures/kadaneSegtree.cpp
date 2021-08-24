#include<bits/stdc++.h>
using namespace std;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
#define ford(i, a, b) for(int i = int(a); i >= (int)b; i--)
#define tam 100
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<vector<ll>> dpi;
struct Node{
    ll soma, pref, suf, maximo;
    void seta(ll x){
        soma = pref = suf = maximo= x;
    }
    void merge(const Node &left, const Node &right){
        soma = left.soma + right.soma;
        pref = max(left.pref, left.soma + right.pref);
        suf = max(right.suf, right.soma + left.suf);
        maximo = max({left.maximo, right.maximo, left.suf + right.pref});
    }
    void print(){ /* debug */
        cout<<soma<<" "<<pref<<" "<<suf<<" "<<maximo<<endl;
    }
};


class SegTree{
    public:
    ll n;
    vector<ll>vet;
    vector<Node>tree;
    
    SegTree(){
        cin>>n;
        vet.resize(n+3);
        tree.resize((n+3)*4);
        forc(i,1,n+1){
            cin>>vet[i];
        }
        build(1,1,n);
    }
    void build(ll p, ll l, ll r){
        if(l==r){
            tree[p].seta(vet[l]);
        } else{
            ll m = (l+r)/2, lc = p*2, rc = lc+1; 
            build(lc, l, m);
            build(rc, m+1, r);
            tree[p].merge(tree[lc], tree[rc]);
        }
    }
    void update(ll p, ll l, ll r, ll i, ll x){
        if(l==r){
            tree[p].seta(x);
            vet[i] = x;
        } else{
            ll m = (l+r)/2, lc = p*2, rc = lc+1; 
            if(i<=m){
                update(lc, l, m, i,x);
            } else{
                update(rc, m+1, r, i,x);
            }
            tree[p].merge(tree[lc], tree[rc]);
        }
    }
    Node query(ll p, ll l, ll r, ll ql, ll qr){
        if(l>=ql && r<=qr){
            return tree[p];
        } else{
            ll m = (l+r)/2, lc = p*2, rc = lc+1; 
            if(qr<=m){
                return query(lc, l, m, ql, qr);
            } else if(ql>m){
                return query(rc, m+1, r, ql, qr);
            } else{
                Node resp;
                resp.merge(query(lc, l, m, ql, qr), query(rc, m+1, r, ql, qr));
                return resp;
            }
        }
    }
    void logica(){
        
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return 0;
}