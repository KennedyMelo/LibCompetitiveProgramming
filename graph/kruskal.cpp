struct Kruskal: DSU{
    vector<pair<int, ii>>arestas;
    Kruskal(int n): DSU(n){}
    void solve(vector<pair<int, ii>>&x){
        arestas= x;
        sort(arestas.begin(), arestas.end());
        int cnt=0;
        int a, b;
        forc(i,0, arestas.size()){
            if(cnt==n-1) break;
            a=arestas[i].second.first; b =arestas[i].second.second;
            if(find(a)!=find(b)){
                uniao(a,b); cnt++;
            }
        }
    } 
};