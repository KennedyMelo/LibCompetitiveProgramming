#include<bits/stdc++.h>
using namespace std;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
#define ford(i, a, b) for(int i = int(a); i >= (int)b; i--)
#define tam 100
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<vector<ll>> dpi;
const ll inf= 1e18;
class Bit{
    public:
    ll n;
    vector<ll>vet, tree;
    vector<ii>pares;
    Bit(){
        cin>>n;
        vet.resize(n+5);
        tree.assign(n+5,0);
        forc(i,1,n+1){
            cin>>vet[i];
            pares.push_back({vet[i],i});
        }
        
    }
    ll query(ll x){
        ll somador=0;
        while(x>0){
            somador+= tree[x];
            x-= (x & -x); 
        }
        return somador;
    }
    void update(ll x ,ll val){
        ll lastVal = query(x) - query(x-1);
        while(x<=n){
            tree[x]-= lastVal;
            tree[x]+=val;
            x += (x & -x);
        }
    }
    ll contaInversaoRep(){
        sort(pares.begin(), pares.end());
        ll cont =0;
        ll ind, val;
        vector<ll>rep;
        ll last= inf;
        ford(i,pares.size()-1, 0){
            val = pares[i].first;
            ind = pares[i].second;
            
            if(last!=val){
                for(auto u: rep){
                    update(u,1);        
                }
                rep.clear();
            }
            last = val;
            rep.push_back(ind);
            cont+=query(ind);
            
        }
        
        return cont;
    }
    void logica(){
        cout<<contaInversaoRep()<<endl;   
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Bit aux;
    aux.logica();
    return 0;
}