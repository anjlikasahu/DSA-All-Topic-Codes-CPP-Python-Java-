int peak(int a[], int n)
{
   // Your code here
   for(int i=0;i<n;i++)
   {
       if(i==0&&a[i]>a[i+1])
        return i;
        else if(i==n-1&&a[i]>a[i-1])
        return i;
        else
        {
            if(a[i-1]<a[i]&&a[i]>a[i+1])
            return i;
        }
   }
}