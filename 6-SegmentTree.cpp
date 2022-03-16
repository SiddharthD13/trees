// constructing of segment tree 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void constructMaxSegTree(int segmentTree[],int arr[],int low,int high,int position)
{
    if(low==high)
    {
        segmentTree[position]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    constructMaxSegTree(segmentTree,arr,low,mid,2*position+1);
    constructMaxSegTree(segmentTree,arr,mid+1,high,2*position+2);
    segmentTree[position]=max(segmentTree[2*position+1],segmentTree[2*position+2]);
}

int main()
{
    return 0;
}