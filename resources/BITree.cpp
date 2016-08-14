#include<iostream>
using namespace std;
int getSum(int bitree[],int index)
{
    int sum=0;
    index+=1;
    while(index>0)
    {
        sum+=bitree[index];
        index-=index&(-index);
    }
    return sum;
}

void update(int bitree[],int n, int index, int val)
{
    index+=1;
    while(index<=n)
    {
        bitree[index]+=val;
        index+=index&(-index);
    }
}

int *createbitree(int arr[],int n)
{
    int *bitree = new int [n+1];
    for(int i=0;i<n+1;i++)
        bitree[i]=0;

    for(int i=0;i<n;i++)
        update(bitree,n,i,arr[i]);
    return bitree;
}

int main()
{
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = createbitree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
         << getSum(BITree, 5);

    // Let use test the update operation
    freq[3] += 6;
    update(BITree, n, 3, 6); //Update BIT for above change in arr[]

    cout << "\nSum of elements in arr[0..5] after update is "
         << getSum(BITree, 5);

    return 0;
}
