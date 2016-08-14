#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

int getSum(int *st, int ss, int se, int qs, int qe, int si)
{
    if(qs<=ss && qe>=se)
    {
        return st[si];
    }
    if(se < qs || ss > qe)
        return 0;

    int mid = ss + (se-ss)/2;
    return getSum(st,ss,mid,qs,qe,2*si+1) + getSum(st,mid+1,se,qs,qe,2*si+2);
}

void updateValue(int *st,int ss, int se, int index, int diff, int si)
{

    if(index<ss || index>se)
        return;

    st[si]=st[si]+diff;
    if(se!=ss)
    {
        int mid = ss + (se-ss)/2;
        updateValue(st,ss,mid,index,diff,2*si+1);
        updateValue(st,mid+1,se,index,diff,2*si+2);
    }
}

int *constructST(vector<int> &v,int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2,x)-1;
    int *st = new int[max_size];
    for(int i=0;i<max_size;i++)
        st[i]=0;
    for(int i=0;i<n;i++)
    {
        updateValue(st,0,n-1,i,v[i],0);
    }
    return st;
}

int main()
{
    int ar[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(ar)/sizeof(ar[0]);
    vector<int> arr(ar,ar+n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;

    // Build segment tree from given array
    int *st = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
            getSum(st,0,n-1,1,3,0));

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(st,0,n-1,1,7,0);

    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
             getSum(st,0,n-1,1,3,0));
    return 0;
}
