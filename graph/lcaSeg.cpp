#include<bits/stdc++.h>
using namespace std;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
#define ford(i, a, b) for(int i = int(a); i >= (int)b; i--)
#define lim 2000070
#define endl '\n'
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef long double ld;
typedef vector<ll> dpi;
struct Tree{
    vector<int>height, euler, first, tree;
    vector<vector<int>>arvore;
    vector<bool> visited;
    int n;
    Tree(vector<vector<int>>&x,int root=0){
        this->arvore= x;
        n = arvore.size();
        height.resize(n);
        first.resize(n);
        visited.assign(n, false);
        dfs(root);
        tree.resize((n+2)*8);
        build(1, 0, euler.size()-1);
    }
    void dfs(int x, int h=0){
        visited[x]=true;
        height[x] = h;
        first[x] = euler.size();
        euler.push_back(x);
        for(auto to : arvore[x]){
            if(!visited[to]){
                dfs(to, h+1);
                euler.push_back(x);
            }
        }
    }
    void build(int p, int l, int r){
        if(l==r){
            tree[p]= euler[l];
        } else{
            int m = (l+r)/2, lc = p*2, rc = lc+1; 
            build(lc, l, m);
            build(rc, m+1, r);
            int nlc = tree[lc], nrc = tree[rc];
            tree[p] = (height[nlc]< height[nrc])? nlc: nrc;
        }
    }
    int query(int p, int l, int r, int ql, int qr){
        if(l>=ql && r<=qr){
            return tree[p];
        } else{
            int m = (l+r)/2, lc = p*2, rc = lc+1; 
            if(qr<=m){
                return query(lc, l, m, ql, qr);
            } else if(ql>m){
                return query(rc, m+1, r, ql, qr);
            } else{
                int nlc =query(lc, l, m, ql, qr), nrc = query(rc, m+1, r, ql, qr);
                return (height[nlc]< height[nrc])? nlc : nrc;
            }
        }
    }
    int lca(int u, int v){
        int left = first[u], right = first[v];
        if(left> right) swap(left, right);
        return query(1,0,euler.size()-1, left, right);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    return 0;
}
