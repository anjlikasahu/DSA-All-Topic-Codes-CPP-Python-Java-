#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<"\t";
}

void insertion_sort(vector<int>&A)
{
    for(int i=1;i<A.size();i++)
    {
        int temp=A[i];

        int j=i;
        while(j>=1&&temp<A[j-1])
        
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
}

int main()
{
    vector<int>A={2,5,3,1,6,4,7};
    insertion_sort(A);
    print(A);
}