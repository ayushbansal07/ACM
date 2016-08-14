#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define INF 10000000000
using namespace std;
int main()
{
    int n,m,s,v1,v2,r;
    cin>>n>>m;
    vector<vector<pair<int,long long int> > > adj(n+1);
    while(m--)
    {
        cin>>v1>>v2>>r;
        adj[v1].pb(mp(v2,r));
        adj[v2].pb(mp(v1,r));
    }
    cin>>s;
    vector<bool> mstSet(n+1,false);
    vector<long long int> key(n+1,INF);
    key[s]=0;
    int u;
    int counti=1;
    long long int ans=0;
    while(counti<n+1)
    {
        long long int mink=INF;
        for(int i=1;i<n+1;i++)
        {
            if(!mstSet[i] && key[i]<mink)
            {
                mink=key[i];
                u=i;
            }
        }
        mstSet[u]=true;
        ans+=key[u];
        int len=adj[u].size();
        for(int i=0;i<len;i++)
        {
            if(adj[u][i].S<key[adj[u][i].F])
                key[adj[u][i].F]=adj[u][i].S;

        }
        counti++;
    }
    cout<<ans<<endl;

}
