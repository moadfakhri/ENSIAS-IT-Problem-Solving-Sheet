#include <iostream>
using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    
    int n,m,k;cin>>n>>m>>k;
    int a[n+1];
    for (int i=1; i<=n; i++) cin>>a[i];
    int ord[n+1];
    for (int i =1; i<=n; i++) ord[a[i]]=i;
    long long ans=0;
    for (int i=0; i<m; i++){
        int x; cin>>x;
        if (ord[x]==1) ans++;
        else {
            ans += (ord[x]-1)/k +1 ;
            int y = a[ord[x]-1];
            swap(a[ord[x]],a[ord[x]-1]);
            ord[x]--;
            ord[y]++;
        }
    }
    cout<<ans;
    return 0;
}