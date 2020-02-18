#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int log2(ll u){
    int r=0;
    ll x=1;
    while (x<u) {
        x*=2;
        r++;
    }
    if (x>u) r--;
    return r;
}
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    unordered_map<ll,ll> nodes;
    int q;cin>>q;
    for (int i=0; i<q; i++){
        int t; cin>>t;
        if (t==1){
            ll u,v,w; cin>>u>>v>>w;
            if (u<=v) swap(u,v);
            while (int (log2(u)) != int(log2(v))){
                nodes[u]+=w;
                u>>=1;
            }
            
            if (u==v) continue;
            while (u != v){
                nodes[u]+=w;
                nodes[v]+=w;
                u>>=1;
                v>>=1;
            }
        }
        else {
            ll ans=0;
            ll u,v; cin>>u>>v;
            if (u<=v) swap(u,v);
            while (int (log2(u)) != int(log2(v))){
                ans+=nodes[u];
                u>>=1;
            }
            if (u==v) {
                cout<<ans<<'\n';
                continue;
            }
            while (u != v){
                ans+=nodes[u];
                ans+=nodes[v];
                u>>=1;
                v>>=1;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}