#include<bits/stdc++.h>
using namespace std;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
#define ford(i, a, b) for(int i = int(a); i >= (int)b; i--)
#define tam 100
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<vector<int>> dpi;
int n, INF = 0x3f3f3f3f;
dpi capacity;
dpi adj;

int bfs(int s, int t, vector<int>&parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s]= -2;
    queue<ii>q;
    q.push({s, INF});
    while(!q.empty()){
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int next: adj[cur]){
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next]=cur;
                int new_flow = min(flow, capacity[cur][next]);
                if(next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}


int maxFlow(int s, int t){
    int flow =0;
    vector<int>parent(n);
    int new_flow;
    
    while(new_flow = bfs(s,t, parent)){
        flow += new_flow;
        int cur= t;
        while(cur!= s){
            int prev= parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[prev][cur] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return 0;
}