/*
[BOJ] 1912 - 연속합
https://www.acmicpc.net/problem/1912
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
    static int max;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sum=0;
        max = 0;
        int[] arr = new int[num];
        for (int i = 0; i < num; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            sum += arr[i];
            if (sum < 0)
                sum = 0;
            if(max<sum) max = sum;
        }
        if(max == 0){
            Arrays.sort(arr);
            max = arr[arr.length-1];
        }
        System.out.println(max);


    }

}
