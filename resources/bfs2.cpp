#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    int t,n,m,s,v1,v2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int> > adj (n+1);
        while(m--)
        {
            cin>>v1>>v2;
            adj[v1].pb(v2);
            adj[v2].pb(v1);
        }
        cin>>s;
        queue<pair<int,int> > q;
        vector<bool> visited(n+1,false);
        vector<int> dis(n+1);
        q.push(mp(s,0));
        visited[s]=true;
        while(!q.empty())
        {
            pair<int,int> current = q.front();
            dis[current.F]=current.S;
            q.pop();
            int len = adj[current.F].size();
            for(int i=0;i<len;i++)
            {
                if(!visited[adj[current.F][i]])
                {
                    visited[adj[current.F][i]]=true;
                    q.push(mp(adj[current.F][i],current.S+1));
                }
            }
        }
        int out;
        for(int i=1;i<=n;i++)
        {
            if(i==s)
                continue;
            if(dis[i]==0)
                out=-1;
            else
                out=dis[i]*6;
            cout<<out<<' ';
        }
        cout<<endl;

    }
}
