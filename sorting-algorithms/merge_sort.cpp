#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<"\t";
}

void merge(vector<int>&A,vector<int>&left,vector<int>&right)
{
   int i1=0;
   int i2=0;
   for(int i=0;i<left.size()+right.size();i++)
   {
       if(i2>right.size()||(i1<left.size()&&left[i1]<right[i2]))
       {
           A.push_back(left[i1]);
           i1++;
       }
       else
       {
           A.push_back(right[i2]);
           i2++;
       }
       
   }
}

void merge_sort(vector<int>&A)
{
    if(A.size()>=2)
    {
        vector<int>left;
        vector<int>right;
        for(int i=0;i<A.size()/2;i++)
            left.push_back(A[i]);
        for(int i=A.size()/2;i<A.size();i++)
            right.push_back(A[i]);
        merge_sort(left);
        merge_sort(right);

        A.clear();
        merge(A,left,right);
    }
}

int main()
{
    vector<int>A={2,5,3,1,6,4,7};
    merge_sort(A);
    print(A);
}