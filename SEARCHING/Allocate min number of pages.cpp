int findPages(int arr[], int n, int m) {
    int sum = 0, mx = INT_MIN;
    for(int i=0;i<n;i++) {="" sum="sum" +="" arr[i];="" mx="max(mx," arr[i]);="" }="" if(m=""> n) {
        return -1;
    }
    int f=mx, l=sum;
    int ans = INT_MAX;
    while(f<=l) {
        int mid = (f+l)/2;
        int cnt = 1, t1 = 0;
        for(int i=0;i<n;i++) {="" if(arr[i]="">mid)
            {
                cnt = m+1;
                break;
            }
            if (t1 + arr[i] > mid) 
            { 
                cnt++; 
                t1 = arr[i]; 
                if (cnt > m) 
                    break; 
            }
            else
                t1 += arr[i]; 
        
        }
        
        if(cnt > m) {
            f = mid+1;
        }
        else {
            l = mid-1;
            ans = mid;
        }
    
                
    }
    return ans;
    
}