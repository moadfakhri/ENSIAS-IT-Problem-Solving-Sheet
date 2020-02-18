#include <iostream>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,q ; cin>>n>>q;
    set<int> x[n+1];
    set<ii> s;
    int id=0;
    for (int e =0 ; e<q; e++){
        int type; cin>>type;
        if (type==1){
            id++;
            int i; cin>>i;
            x[i].insert(id);
            s.insert(ii(id,i));
        }
        if (type==2){
            int i; cin>>i;
            while (!x[i].empty()){
                int k=*x[i].begin(); x[i].erase(k);
                s.erase(ii(k,i));
            }
        }
        if (type==3){
            int t; cin>>t;
            while (!s.empty() && s.begin()->first <= t) {
                x[s.begin()->second].erase(s.begin()->first);
                s.erase(*s.begin());
            }
        }
        cout<<s.size()<<'\n';
    }
    return 0;
}