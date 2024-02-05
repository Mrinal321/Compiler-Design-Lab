#include<bits/stdc++.h>
using namespace std;

string st[200], root, first[200];
set < char > follow[200], ss; 
char start;
bool eps[100] = {0};
    
void func(int i, string s){
    bool yes = 0;
    for(int inx = 0; inx < s.size(); inx++){
        if(s[inx] == '|') {
            yes = 1;
            continue;
        }
        if(yes){
            if(ss.count(s[inx])){
                if(first[s[inx]].empty()) func(s[inx], st[s[inx]]);
                for(auto u : first[s[inx]]){
                    first[i].push_back(u);
                }
                if(eps[s[inx]]) eps[i] = 1;
                else yes = 0;
            }
            else{
                if(s[inx] == 'e') eps[i] = 1;
                else first[i].push_back(s[inx]);
                yes = 0;
            }
        }
    }
}

void func2(char i){
    if(!follow[i].empty()) return;
    if(i == start) follow[i].insert('$');
    for(auto u : root){
        bool yes = 0;
        for(int inx = 0; inx < st[u].size(); inx++){
            if(st[u][inx] == i){
                yes = 1; continue;
            }
            if(yes){
                if(st[u][inx] == '|'){
                    for(auto uu : follow[u]) follow[i].insert(uu);
                    yes = 0;
                }
                else if(ss.count(st[u][inx])){
                    for(auto uu : first[st[u][inx]]) follow[i].insert(uu);
                    if(!eps[u]) yes = 0;
                }
                else{
                    follow[i].insert(st[u][inx]);
                    yes = 0;
                }
            }
        }
    }
}

int main(){
    int n; cin >> n;
    
    for(int i = 1; i <= n; i++){
        char ch; cin >> ch;
        ss.insert(ch);
        if(i == 1) start = ch;
        root.push_back(ch);
        cin >> st[ch];
    }

    for(auto u : root){
        if(!first[u].empty()) continue;
        func(u, st[u]);
    }

    for(auto u : root){
        func2(u);
    }

    cout << "First of the grammer: \n";
    for(auto u : root){
        cout << u << ": { ";
        for(auto uu : first[u]) cout << uu << ", ";
        if(eps[u]) cout << "e ";
        cout << "}\n";
    }

    cout << "Follow of the grammer: \n";
    for(auto u : root){
        cout << u << ": { ";
        for(auto uu : follow[u]) cout << uu << ", ";
        cout << "}\n";
    }

    return 0;
}