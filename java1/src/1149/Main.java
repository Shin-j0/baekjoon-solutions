/*
[BOJ] 1149 - RGB거리
https://www.acmicpc.net/problem/1149
- Algorithm: Dynamic Programming
- Data Structure: Array
- Time: O(N)
- Space: O(N)
- Trick:
  * 
  * 
*/
import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    static int[][] arr;
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        arr = new int[num][num];
        dp = new int[num][num];
        for (int i = 0; i < num; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
            arr[i][2] = Integer.parseInt(st.nextToken());
        }
        dp[0][0] = arr[0][0];
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][2];

        System.out.println(Math.min(get_dp(num-1,0),Math.min(get_dp(num-1,1),get_dp(num-1,2))));
    }
    static int get_dp(int N, int color){
        if(dp[N][color] == 0){
            if(color == 0){
                dp[N][0] = Math.min(get_dp(N-1,1),get_dp(N-1,2)) + arr[N][0];
            }
            else if(color == 1){
                dp[N][1] = Math.min(get_dp(N-1,0),get_dp(N-1,2)) + arr[N][1];
            }
            else{
                dp[N][2] = Math.min(get_dp(N-1,0),get_dp(N-1,1)) + arr[N][2];
            }
        }
        return dp[N][color];
    }
}