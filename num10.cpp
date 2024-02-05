#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    cout << "Enter grammers:\n";
    string root[n+1], tree[n+1];
    for(int i = 1; i <= n; i++){
        cin >> root[i] >> tree[i];
    }
    
    cout << "Enter a string: ";
    string st, ck; cin >> st;

    while(st != "$"){
        ck.push_back(st[0]);
        cout << "Shift::" << st[0] << endl;
        st.erase(st.begin());

        for(int i = 1; i <= n; i++){
            if(ck.find(tree[i]) <= ck.size()){
                cout << "Reduce:: " << root[i] << "->" << tree[i] << endl;
                int sz = tree[i].size();
                while(sz--) ck.pop_back();
                ck += root[i];
                i = 0;
            }
        }
    }
    //cout << endl;
    cout << ck << endl;
    if(ck != root[1]) cout << "Rejected";
    else cout << "Accepted";

    return 0;
}