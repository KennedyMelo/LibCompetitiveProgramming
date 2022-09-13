#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>trie;
int state=0, id, cur_state;
vector<int>terminal, prefix;
void init(int sum_strings, int sz_alpha){
    terminal.assign(sum_strings,0);
    prefix.assign(sum_strings,0);
    trie.assign(sum_strings, vector<int>(sz_alpha, -1));
}
void insert(string s){
    cur_state=0;
    for(auto u: s){
        id = (u-'a');
        if(trie[cur_state][id]==-1){
            trie[cur_state][id] = ++state;
        }
        cur_state = trie[cur_state][id];
        prefix[cur_state]++;
    }
    if(s.size()==0) prefix[cur_state]++;
    terminal[cur_state]++;
}
int count(string s){
    cur_state = 0;
    for(auto u: s){
        id = (u-'a');
        if(trie[cur_state][id]==-1) return 0;
        cur_state = trie[cur_state][id];
    }
    return terminal[cur_state];
}
int count_prefix(string s){
    cur_state = 0;
    for(auto u: s){
        id = (u-'a');
        if(trie[cur_state][id]==-1) return 0;
        cur_state = trie[cur_state][id];
    }
    return prefix[cur_state];
}
int main(){
    init(100,26);
    insert("laura");
    insert("laurinha");
    insert("laurete");
    insert("love");
    insert("");
    cout<<count_prefix("laur")<<endl;
    cout<<count_prefix("l")<<endl;
    cout<<count_prefix("")<<endl;

    
    return 0;
}