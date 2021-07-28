#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<"\t";
}

int partition(vector<int>&A,int i,int j,int pivot)
{
    while (i<=j)
    {
        while(i<=j&&A[i]<pivot) i++;
        while(i<=j&&A[j]>pivot) j--;

        if(i<=j)
        {
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    return i;
}
void quick_sort_helper(vector<int>&A,int min,int max)
{
    if(min>=max)
    {
        return;
    }
    //using a random pivot
    int x=rand()%A.size()-1;
    int pivot=A[x];

    //else u can use first element as pivot
    // int pivot=A[min];
    
    swap(A[x],A[max]);
    int mid=partition(A,min,max-1,pivot);

    swap(A[mid],A[max]);

    quick_sort_helper(A,min,mid-1);
    quick_sort_helper(A,mid+1,max);
}
void quick_sort(vector<int>&A)
{
    quick_sort_helper(A,0,A.size()-1);
}

int main()
{
    vector<int>A={2,5,3,1,6,4,7};
    quick_sort(A);
    print(A);
}