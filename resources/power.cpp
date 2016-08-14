long long int power (long long int a,long long int n,long long int m)
{
    if(n==1)
    {
        return (a%m);
    }
    if(n==0)
    {
        return 1;
    }
    long long int c = power(a,n/2,m)%m;
    if(n%2==0)
    {
        return (c*c)%m;
    }
    else
    {
        return (((c*c)%m)*(a%m))%m;
    }
}
