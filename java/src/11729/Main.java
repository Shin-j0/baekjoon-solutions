/*
[BOJ] 11729 - 하노이 탑 이동 순서
https://www.acmicpc.net/problem/11729
- Algorithm: Recursion
- Data Structure: Array
- Time: O(2^N)
- Space: O(2^N)
- Trick:
  * T(n) = 2T(n-1) + 1
  * 
*/
import java.io.*;
import java.util.*;

public class Main {

    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        sb.append((int) (Math.pow(2, N) - 1)).append('\n');
        Hanoi(N,1,2,3);

        System.out.println(sb);

    }
    public static void Hanoi(int n, int A, int B, int end) {
        if(n==1){
            sb.append(A+" "+end+"\n");
            return;
        }
        Hanoi(n-1,A,end,B);

        sb.append(A+" "+end+"\n");

        Hanoi(n-1,B,A,end);

    }
}