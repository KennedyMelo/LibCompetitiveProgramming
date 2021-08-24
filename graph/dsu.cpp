
struct DSU{
    vector<int> pai, alt;
    int n;
    DSU(int nTam){
        pai.resize(nTam+1);
        alt.resize(nTam+1);
        int n= nTam;
        forc(i,1,nTam){
            pai[i]=i;
            alt[i]=1;
        }
    }
    int find(int x){
        return (pai[x]==x)?x: pai[x]= find(pai[x]);
    }
    void uniao(int x, int y){
        x= pai[x]; y= pai[y];
        if(x!=y){
            if(alt[x]==alt[y]){
                alt[x]++; pai[y]=x;
            } else if(alt[x]<alt[y]){
                pai[x]=y;
            } else{
                pai[y]=x;
            }
        }
    }
};
