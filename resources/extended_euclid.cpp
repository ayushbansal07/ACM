#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
using namespace std;
pair<int,int> extendedEuclid(int a,int b)
{
    if(b==0)
        return mp(1,0);
    else
    {
        pair<int,int> p = extendedEuclid(b,a%b);
        int temp = p.F;
        p.F=p.S;
        p.S=temp-(a/b)*p.S;
        return p;
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    pair<int,int> res = extendedEuclid(a,b);
    cout<<res.F<<' '<<res.S<<endl;
}
