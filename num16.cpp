#include<bits/stdc++.h>
using namespace std;


int main(){
    string st; cin >> st;
    stack < char > tk;
    set < char > s[3];
    s[0].insert('+'); s[0].insert('-');
    s[1].insert('*'); s[1].insert('/');
    s[2].insert('&'); s[2].insert('^'); s[2].insert('|');
    string ans;
    for(auto u : st){
        if(u == '(') tk.push(u);
        else if(s[0].count(u)){
            while(tk.top() != '('){
                ans.push_back(tk.top()); tk.pop();
            }
            tk.push(u);
        }
        else if(s[1].count(u)){
            while(s[1].count(tk.top())){
                ans.push_back(tk.top()); tk.pop();
            }
            tk.push(u);
        }
        else if(u == ')'){
            while(tk.top() != '('){
                ans.push_back(tk.top()); tk.pop();
            }
            tk.pop();
        }
        else ans.push_back(u);
    }

    cout << ans;
    

    return 0;
}