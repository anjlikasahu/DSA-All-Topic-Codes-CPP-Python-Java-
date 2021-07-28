#include<iostream>
#include<vector>

int isvalid(vector<int> &A, int B, int mid)
{
    int stud = 1;
    int s =0;
    for(int i=0;i<A.size();i++)
    {
        s+=A[i];
        if(s>mid)
        {
            stud++;
            s=A[i];
        }
    }
    if(stud>B)
    {
        return false;
    }
    else{
        return true;
    }
}
int books(vector<int> &A, int B) {
    int start = INT_MIN;
    int end=0;
    if(A.size()<B)
    {
        return -1;
    }
    for(int i=0;i<A.size();i++)
    {
        start = max(start, A[i]);
        end += A[i];
    }
    int res = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(isvalid(A, B, mid)==true)
        {
            res=mid;
            end = mid -1;
        }
        else
        {
            start = mid+1;
        }
    }
    return res;
}

int main()
{
    vector<int>A={12, 34, 67, 90};
    int B=2;
    cout<<books(A,B);
    return 0;
}

