#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void updatetree(int  segtree[],int index,int value,int low,int high,int position)
{
    if(index<low || index>high) return;
    if(low==high) 
    {
        segtree[position]=value;
        return;
    }
    int mid=(low+high)/2;
    updatetree(segtree,index,value,low,mid,2*position+1);
    updatetree(segtree,index,value,low,mid,2*position+2);
    segtree[position]=max(segtree[2*position+1],segtree[2*position+2]);
}

int main()
{
    return 0;
}