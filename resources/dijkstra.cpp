#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define IMAX 1000000
using namespace std;
int n;
int minDistance(vector<int> dis,vector<bool> sptSet)
{
    int mini=IMAX,minindex;
    for(int v=1;v<=n;v++)
    {
        if(!sptSet[v] && dis[v]<=mini)
        {
            mini=dis[v];
            minindex=v;
        }
    }
    return minindex;
}
int main()
{
    int t,m,v1,v2,r,s;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<pair<int,int> > > adj(n+1);
        while(m--)
        {
            cin>>v1>>v2>>r;
            adj[v1].pb(mp(v2,r));
            adj[v2].pb(mp(v1,r));
        }
        cin>>s;
        vector<bool> sptSet(n+1,false);
        vector<int> dis(n+1,IMAX);
        dis[s]=0;
        for(int ct=0;ct<n-1;ct++)
        {
            int u = minDistance(dis,sptSet);
            sptSet[u]=true;
            int len=adj[u].size();
            for(int v=0; v<len; v++)
            {
                if(!sptSet[adj[u][v].F] && dis[u]+adj[u][v].S<dis[adj[u][v].F])
                {
                    dis[adj[u][v].F]=dis[u]+adj[u][v].S;
                }
            }
        }
        int out;
        for(int i=1;i<=n;i++)
        {
            if(i==s)
                continue;
            if(dis[i]==IMAX)
                out=-1;
            else
                out=dis[i];
            cout<<out<<' ';
        }
        cout<<endl;
    }
}
