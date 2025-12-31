/*
[BOJ] 9461 - 파도반 수열
https://www.acmicpc.net/problem/9461
- Algorithm: Dynamic Programming
- Data Structure: Array
- Time: O(N)
- Space: O(N)
- Trick:
  * 
  * 
*/
import java.io.*;
import java.util.*;

public class Main {
    static StringBuffer sb = new StringBuffer();
    static long[] pado;
    static int max;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.parseInt(br.readLine());
        int[] arr = new int[num];
        max = 0;
        for (int i = 0; i < num; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            if(max<arr[i]) max = arr[i];
        }
        pado = new long[max+5];
        get_pado();
        for (int i = 0; i < num; i++) {
            sb.append(pado[arr[i]-1]).append("\n");
        }
        System.out.println(sb);
    }
    public static void get_pado(){
        pado[0] = pado[1] = pado[2] = 1;
        pado[3] = 2;
        for(int i = 4; i<=max; i++){
            pado[i] = pado[i-2] + pado[i-3];
            //System.out.println(pado[i]);
        }
    }
}