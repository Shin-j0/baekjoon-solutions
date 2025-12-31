/*
[BOJ] 11660 - 구간 합 구하기 5
https://www.acmicpc.net/problem/11660
- Algorithm: prefix sum
- Data Structure: Array
- Time: O(N^2 + M)
- Space: O(N^2)
- Trick:
  * 
  * 
*/
import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int num = 0;
        int[][] arr = new int[N+1][N+1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = 0;
            for (int j = 1; j <= N; j++) {
                arr[i][j] = arr[ i ][ j-1 ] + arr[ i-1 ][ j ] - arr[ i-1 ][ j-1 ] + Integer.parseInt(st.nextToken());
            }
        }
        for(int i=0; i<K; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int result = arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1];
            sb.append(result).append("\n");
        }

        System.out.println(sb);
    }
}