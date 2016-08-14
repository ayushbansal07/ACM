#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define lli long long int
#define INF 1000000000000
#define MOD 1000000007
#define vv(name,type,r,c) vector<vector<type> > name(r,vector<type>(c))
using namespace std;
vector<vector<lli> > multiply(vector<vector<lli> > A,vector<vector<lli> > B)
{
    vector<vector<lli> > M(2,vector<lli>(2,0));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                M[i][j]=((M[i][j]%MOD)+(A[i][k]%MOD)*(B[k][j]%MOD))%MOD;
            }
        }
    }
    return M;
}
vector<vector<lli> > power(vector<vector<lli> > F,lli n)
{
    vv(I,lli,2,2);
    I[0][0]=1;
    I[0][1]=0;
    I[1][0]=0;
    I[1][1]=1;
    if(n==1)
        return F;
    if(n==0)
        return I;
    vv(M,lli,2,2);
    M = power(F,n/2);
    if(n%2==0)
        return multiply(M,M);
    else
        return multiply(multiply(M,M),F);
}
lli fib(lli n)
{
    vv(F,lli,2,2);
    F[0][0]=1;
    F[0][1]=1;
    F[1][0]=1;
    F[1][1]=0;
    if(n==0)
        return 0;
    F = power(F,n-1);
    return F[0][0];
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}
