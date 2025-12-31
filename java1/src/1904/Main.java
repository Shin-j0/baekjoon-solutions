/*
[BOJ] 1904 - 01타일
https://www.acmicpc.net/problem/1904
- Algorithm: 
- Data Structure: 
- Time: 
- Space:
- Trick:
  * 
  * 
*/
import java.io.*;
import java.util.*;

public class Main {
    static StringBuffer sb = new StringBuffer();
    static int max;
    static int[] arr = new int[1000001];
    public static int get_arr(int N) {

        if(arr[N] == 0) arr[N] = 0;
        if(arr[N] != 0) return arr[N];
        arr[N] = (get_arr(N - 1) + get_arr((N - 2))) % 15746;
        return arr[N];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        get_arr(num);
        System.out.println(arr[num]);

    }
}