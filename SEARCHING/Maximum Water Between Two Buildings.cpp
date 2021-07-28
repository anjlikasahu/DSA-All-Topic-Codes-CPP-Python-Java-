int maxWater(int height[], int n)
{
int curr_result = 0;

int low = 0;
int high = n-1;

while(low < high)
{
if(height[low] < height[high]){
curr_result = max(curr_result, (high-low-1) * height[low]);
low++;
}else{
curr_result = max(curr_result, (high-low-1) * height[high]);
high--;
}
}
return curr_result;

}