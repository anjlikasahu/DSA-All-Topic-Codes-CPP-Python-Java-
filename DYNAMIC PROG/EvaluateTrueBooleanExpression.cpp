#include<bits/stdc++.h>
using namespace std;

//given an expression with T and F and operands | ^ & return the number of ways that expression
//would result in a T or F depending upon requirement after solving
//here i coded to evaluate T

unordered_map<string,int>mp; //here using a map for memoization rather than a matrix for better optimization
int expressionEval(string &A,int i,int j,bool eval){  //eval is to check if u want true or false out of the expression
    if(i>j){
        return 0;
    }
    if(i==j){
        if(eval==true){
            return A[i]=='T'; //either 1/0 returned which is fine since our functions returns an int
        }else{
            return A[i]=='F';
        }
    }
    stringstream ss;
    ss<<i<<" "<<j<<" "<<eval;
    string key=ss.str();  //making a unique key(i j)
    if(mp.find(key)!=mp.end())
        return mp[key];
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2){  //k increments by 2 to go from operand to operand and starts from i+1
       int lT=expressionEval(A,i,k-1,true);
       int lF=expressionEval(A,i,k-1,false); //not till k cause element at index k is the operand
       int rT=expressionEval(A,k+1,j,true);
       int rF=expressionEval(A,k+1,j,false);

       if(A[k]=='&'){
           if(eval==true){
               ans+=lT*rT;     //basic boolean algebra ladder to construct a truth table
           }else{
               ans+=lT*rF+rT*lF+rF*lF;
           }
       }
       else if(A[k]=='|'){
           if(eval==true){
               ans+=lT*rF+rT*lF+rT*lT;
           }else{
               ans+=lF*rF;
           }
       }
       else if(A[k]=='^'){
           if(eval==true){
               ans+=lT*rF+rT*lF;
           }else{
               ans+=lF*rF+rT*lT;
           }
       }

    }
    return mp[key]=ans;  //store in mem map
}

int main(){
    string expr="T^T^T^F|F&F^F|T^F^T";
    cout<<expressionEval(expr,0,expr.size()-1,true);
}
