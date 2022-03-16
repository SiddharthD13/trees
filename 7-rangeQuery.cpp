// finding the max element in a given range using segmented trees

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rangequery(int segmentree[], int low, int high, int qlow, int qup, int position)
{

    if (qlow <= low && qup >= high)
        return segmentree[position]; // total overlap
    if (qlow > high || qup < low)
        return INT_MIN; // no overlap
    int mid = (low + high) / 2;
    int max1 = rangequery(segmentree, low, mid, qlow, qup, 2 * position + 1);
    int max2 = rangequery(segmentree, mid + 1, high, qlow, qup, 2 * position + 2);
    return max(max1, max2);
}

int main()
{
    int s[15]={10,10,7,9,10,7,6,3,9,8,10,7,4,6,5};
    int x=rangequery(s,0,7,4,7,0);
    cout<<x<<endl;
    return 0;
}