/*
[BOJ] 11053 - 가장 긴 증가하는 부분 수열
https://www.acmicpc.net/problem/11053
- Algorithm: Dynamic Programming
- Data Structure: Array
- Time: O(N)
- Space: O(N)
- Trick:
  * 
  * 
*/
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int [] arr = new int[n];
        for(int i = 0; i<n; ++i)
        	arr[i] = scanner.nextInt();
        
        int [] dp = new int[n];
        for(int i = 0;i<n;++i)dp[i] = 1;
        int max = 1;
        
        for(int i = 1; i<n; ++i) {
        	for(int j = 0; j<i; ++j) {
        		if(arr[i]>arr[j])
        			dp[i] = Math.max(dp[i], dp[j]+1);
        	}
            max = dp[i]>max? dp[i]:max;
        }
        System.out.println(max);
    }
}
