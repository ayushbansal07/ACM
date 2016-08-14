#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
using namespace std;
int main()
{
    int t,k1,k2,n,m;
    cin>>t;
    while(t--)
    {
        long long int ans=0;
        bool flag=false;
        cin>>n>>m>>k1>>k2;
        vector<vector<int> > a(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int> > q;
        visited[0][0]=true;
        q.push(mp(mp(0,0),0));
        while(!q.empty())
        {
            pair<pair<int,int>,int> current = q.front();
            if(current.F.F==0 && current.F.S==m-1)
            {
                flag=true;
                ans=current.S;
                break;
            }
            q.pop();
            //adjacents
            //right
            if(current.F.S+1<m)
            {
                if(!visited[current.F.F][current.F.S+1] && a[current.F.F][current.F.S+1]==0)
                {
                    visited[current.F.F][current.F.S+1]=true;
                    q.push(mp(mp(current.F.F,current.F.S+1),current.S+1));
                }
            }
            //up
            if(current.F.F-1>=0)
            {
                if(!visited[current.F.F-1][current.F.S] && a[current.F.F-1][current.F.S]==0)
                {
                    visited[current.F.F-1][current.F.S]=true;
                    q.push(mp(mp(current.F.F-1,current.F.S),current.S+1));
                }
            }
            //down
            if(current.F.F+1<n)
            {
                if(!visited[current.F.F+1][current.F.S] && a[current.F.F+1][current.F.S]==0)
                {
                    visited[current.F.F+1][current.F.S]=true;
                    q.push(mp(mp(current.F.F+1,current.F.S),current.S+1));
                }
            }
            //left
            if(current.F.S-1>=0)
            {
                if(!visited[current.F.F][current.F.S-1] && a[current.F.F][current.F.S-1]==0)
                {
                    visited[current.F.F][current.F.S-1]=true;
                    q.push(mp(mp(current.F.F,current.F.S-1),current.S+1));
                }
            }

        }
        if(flag)
        {
            if((m+ans)%2!=0)
                cout<<(ans+1)/2<<endl;
            else
                cout<<-1<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}
