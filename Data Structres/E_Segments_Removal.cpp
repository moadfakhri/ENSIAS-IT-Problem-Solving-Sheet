#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

class DSU{
    int *parent,n;
    public:
        DSU(int n){
            this->n=n;
            parent = new int[n];
        }
        void makeSet(){
            for (int i=0; i<n; i++){
                parent[i]=i;
            }
        }
        int find(int v){
            return (parent[v] == v) ? v : parent[v] = find(parent[v]); 
        }
        void unite(int a, int b){
            a = find(a), b = find(b);
            if (a < b) swap(a, b);
            parent[a] = b;
        }
};
typedef pair<int,int> ii;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n; cin>>n;
    int arr[n+1];
    for (int i=1; i<=n; i++) cin>>arr[i];
    DSU x(n+1);
    x.makeSet();
    int len[n+1];
    int jump[n+1];
    len[n]=jump[n]=1;
    set<ii> s;
    for (int i=n-1; i>0; i--){
        if (arr[i]==arr[i+1]){
            len[i]=1+len[i+1];
            jump[i]=len[i];
            x.unite(i,i+1);
        }
        else len[i]=jump[i]=1;
    }
    for (int i=1; i<=n; i+=jump[i]){
        s.insert(ii(-len[i],i));
    }
    int cnt=0;
    while (!s.empty()){
        cnt++;
        ii t = *s.begin(); s.erase(t);
        int l = -t.first, i=t.second;

        if (x.find(i-1)==0){
            x.unite(i,0);
            continue;
        }
        if (i+jump[i]==n+1){
            jump[x.find(i-1)]=n+1-x.find(i-1);
            continue;
        }

        int j=jump[i];

        if ( arr[x.find(i-1)] == arr[x.find(i+jump[i])]){
            
            s.erase(ii(-len[x.find(i+jump[i])],x.find(i+jump[i])));
            s.erase(ii(-len[x.find(i-1)],x.find(i-1)));
            len[x.find(i-1)]+=len[x.find(i+jump[i])];
            j+=jump[x.find(i+jump[i])];
            x.unite(i-1,i+jump[i]);
            s.insert(ii(-len[x.find(i-1)],x.find(i-1)));
        }
        x.unite(i,i-1);
        jump[x.find(i-1)]+=j;
    }
    cout<<cnt;
    return 0;
}