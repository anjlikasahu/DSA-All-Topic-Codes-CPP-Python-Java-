#include <vector>
#include <iostream>
#include <stdio.h>
void stockBuySell(int price[], int n);
int main()
{   
    
    int price[10000],n,i,T;
    
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&price[i]);
    // fucntion call
    stockBuySell(price, n);
    }
    return 0;
}

void stockBuySell(int price[], int n)
{
    std::vector<int> localMin, localMax;
    int i=1;
    if(price[0]<price[1])
        localMin.push_back(0);
    while(i<n-1){
        if(price[i]<price[i-1] && price[i]<price[i+1]){
            localMin.push_back(i);
        }
        i++;
    }
    i=1;
    while(i<n-1){
        if(price[i]>price[i-1] && price[i]>price[i+1]){
            localMax.push_back(i);
        }
        i++;
    }
    if(price[n-2]<price[n-1])
        localMax.push_back(n-1);
        
        
    if(localMax.empty())
        std::cout << "No Profit" << std::endl;
    for(auto x=localMin.begin(), y=localMax.begin(); x<localMin.end(), y<localMax.end(); x++, y++)
        std::cout << "(" << *x << " " << *y << ") ";
    std:: cout << "\n";
}