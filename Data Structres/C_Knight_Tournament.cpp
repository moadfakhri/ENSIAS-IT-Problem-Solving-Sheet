#include <iostream>
 
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    int trans[n+1];
    int ans[n+1];
    for (int i=1; i<=n; i++) trans[i]=i;
    for (int i=1; i<=n ;i++) ans[i]=0;
    for (int i =0 ;i<m; i++){
        int l,r,x; cin >>l>>r>>x;
        int j=l;
        while (j<=r){
            if (trans[j]!=j) {
                int k = trans[j];
                if (j<=x ) trans[j]=x;
                else if (trans[j]<=r) trans[j]=r;
                j=k;
            }
            else {
                if (j!=x) ans[j]=x;
                if (j<=x) trans[j]=x;
                else trans[j]=r;
                if (j==r && r!=x) trans[r]=r+1;
                j++;
            }
        }
    }
    for (int i=1; i<=n ; i++ ) cout<<ans[i]<<' ';
    return 0;
}