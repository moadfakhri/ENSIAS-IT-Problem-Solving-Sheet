#include <iostream>
    #include <vector>
    #include <queue>
    #include <algorithm>
    using namespace std;
    typedef pair<int,int> ii; 
    int main() {
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        
        /*
            -> sort all segments 
            -> keep adding the segments to a priority queue while the number of covered points is less than k
            -> if the number become bigger than k remove the segment with the maximum right side
        */
        int n,k ; cin>>n>>k;
        vector<ii> seg;
        ii a[n+1];
        for (int i=1; i<=n ;i++){
            int l,r; cin>>l>>r;
            a[i]= ii(r,i);
            seg.push_back(ii(2*l,i));
            seg.push_back(ii(2*r+1,i));
        }
        sort(seg.begin(),seg.end());
        //14 14 14 16 17 17 18 18 19 19 22 23 23 23
        priority_queue<ii> q ; 
        int cnt=0;
        vector<int> ans;
        bool vis[n+1];
        for (int i=0; i<=n ; i++) vis[i]=false;
        for (ii p : seg){
            int x = p.first;
            int i= p.second;
            if (x%2==1) {
                if (!vis[i]) cnt--;
            }
            else{
                cnt++;
                q.push(a[i]);
                if (cnt>k){
                    int j= q.top().second;
                    q.pop();
                    cnt--;
                    vis[j]=1;
                    ans.push_back(j);
                }
            }
        }
        cout<<ans.size()<<'\n';
        for (int i : ans) cout<<i << ' ';
        return 0;
    }