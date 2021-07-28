#include<iostream>
#include<vector>
using namespace std;

//partition the set into such a way so that the 2 subsets have equal sum
//return T or F

//does a subset exist whose sum of elements is the given sum
bool subsetsum(vector<int>A,int sum){
    vector<vector<bool>>t(A.size()+1,vector<bool>(sum+1,false));

    for(int i=0;i<A.size()+1;i++){
        t[i][0]=true; //since subset null can always genertate a sum zero
    }

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<sum+1;j++){
            if(A[i-1]<=j){
                t[i][j]=t[i-1][j]||t[i-1][j-A[i-1]];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[A.size()][sum];
}

bool equalsum(vector<int>A){
    int sum=0;
    for (int i = 0; i <A.size(); i++){
        sum+=A[i];
    }
    if(sum%2==1)
        return false;
    int halfSum=sum/2;
    if(subsetsum(A,halfSum)){
        //if you can find a subset with half sum
        //then the other subset has a sum equal to half sum
        return true;
    }
    return false;
}

int main(){
    cout<<equalsum({1,5,5,11}); //ans is T {1,5,5},{11}
}
