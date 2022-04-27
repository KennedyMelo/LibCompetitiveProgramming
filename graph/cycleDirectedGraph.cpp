#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph(10);
vector<int>visited(10,0); // 0 -> unisited, 1 -> visited, 2 -> processed
int n=10;

bool dfsCycle(int x){
    visited[x]=1;
    bool cycle =0;
    for(auto v: graph[x]){
        if(cycle==1){
            break;
        } else if(visited[v]==0){
            cycle = dfsCycle(v);
        } else if(visited[v]==1){
            cycle = true;
        }
    }
    visited[x]=2;
    return cycle;
}
bool detectCycle(){
    for(int i = 0; i < n; i++){
        if(visited[i]==0 && dfsCycle(i)){
            return true;
        }
    }
    return false;
}
int main(){
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(3);
    graph[1].push_back(2);
    graph[2].push_back(0);
    
    cout<<detectCycle()<<endl;

    
    return 0;
}