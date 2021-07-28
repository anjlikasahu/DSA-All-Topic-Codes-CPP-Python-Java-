// { Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader() { br = new BufferedReader(new InputStreamReader(System.in)); }

    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() { return Integer.parseInt(next()); }

    long nextLong() { return Long.parseLong(next()); }

    double nextDouble() { return Double.parseDouble(next()); }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}

class GFG {
    public static void main(String[] args) {

        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            ;
            int knightpos[] = new int[2];
            knightpos[0] = sc.nextInt();
            ;
            knightpos[1] = sc.nextInt();
            ;
            int targetpos[] = new int[2];
            targetpos[0] = sc.nextInt();
            ;
            targetpos[1] = sc.nextInt();

            Solution T = new Solution();
            System.out.println(T.minStepToReachTarget(knightpos, targetpos, n));
            t--;
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Coordinates{
    int x;
    int y;
    int dist;
    Coordinates(int x,int y,int dist){
        this.x=x;
        this.y=y;
        this.dist=dist;
    }
}
class Solution {
    // KnightPos : knight position coordinates
    // targetPos : target position coordinated
    // N : square matrix size
    public int minStepToReachTarget(int source[], int target[], int N) {
        boolean visited[][]=new boolean[N+1][N+1];
        int dx[]={-2,-2,-1,-1,1,1,2,2};
        int dy[]={-1,1,-2,2,-2,2,-1,1};
        Queue<Coordinates> q= new LinkedList<>();
        q.add(new Coordinates(source[0],source[1],0));
        while(!q.isEmpty()){
            Coordinates curr=q.remove();
            
            if(curr.x==target[0]&&curr.y==target[1])
                return curr.dist;
            for(int i=0;i<8;i++){
                int x=curr.x+dx[i];
            int y=curr.y+dy[i];
                if(isSafe(x,y,N)&&!visited[x][y]){
                    visited[x][y]=true;
                    q.add(new Coordinates(x,y,curr.dist+1));
                }
            }
        }
        return Integer.MAX_VALUE;
    }
    
    public boolean isSafe(int x,int y,int n){
        return x>=1&&x<=n&&y>=1&&y<=n;
    }
    
}
