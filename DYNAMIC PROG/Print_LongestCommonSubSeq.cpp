#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


string LCS(string A,string B){
    vector<vector<int>>t(A.size()+1,vector<int>(B.size()+1,0));

    for(int i=1;i<A.size()+1;i++){
        for(int j=1;j<B.size()+1;j++){
            if(A[i-1]==B[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }

        }
    }

    int i=A.size(),j=B.size();
    string res="";
    while (i>0&&j>0){
        if(A[i-1]==B[j-1]){
            res+=A[i-1];
            i--;
            j--;
        }else{
            if(t[i-1][j]>t[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;

}

int main(){
    cout<<LCS("anjlika","samik");
}
