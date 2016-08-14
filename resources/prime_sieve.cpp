vector<lli> v(10000001,true);
    for(lli i=2;i*i<10000000;i++)
    {
        if(v[i])
        {
            for(lli j=i*i;j<=10000000;j+=i)
            {
                v[j]=false;
            }
        }
    }
