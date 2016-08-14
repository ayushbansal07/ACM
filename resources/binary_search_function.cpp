int bsearch(vector<long long int> &v,int first,int last,long long int val)
{

    if(first>last)
        return -1;
    int mid = first + (last-first)/2;
    if(val == v[mid])
        return mid;
    if(val<v[mid])
        return bsearch(v,first,mid-1,val);
    else
        return bsearch(v,mid+1,last,val);

}
