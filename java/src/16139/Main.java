/*
[BOJ] 16139 - 인간-컴퓨터 상호작용
https://www.acmicpc.net/problem/16139
- Algorithm: prefix sum
- Data Structure: Array
- Time: O(N + Q)
- Space: O(N)
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
        String str = br.readLine();
        int N = Integer.parseInt(br.readLine());
        int [][] arr = new int[str.length()+1][26];
        int[] arr_al = new int[26];
        for (int i = 0; i <str.length(); i++) {
            for (int j = 0; j < 26; j++) {
                if(str.charAt(i)-97==j){
                    arr_al[j]++;
                }
                arr[i+1][j] = arr_al[j];
            }
        }
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String x = st.nextToken();
            int alpha = x.charAt(0)-97;
            int start = Integer.parseInt(st.nextToken())+1;
            int end = Integer.parseInt(st.nextToken())+1;
            sb.append(arr[end][alpha]-arr[start-1][alpha]).append("\n");
        }
        System.out.println(sb);
    }
}