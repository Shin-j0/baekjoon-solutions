
/*
[BOJ] 24416 - 알고리즘 수업 - 피보나치 수 1
https://www.acmicpc.net/problem/24416
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
    static int[] f;
    static int count_1;
    static int count_2;

    public static void fibonacci(int n) {
        f[1] = f[2] = 1;
        for(int i=3; i<=n; i++){
            count_2++;
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    public static int fib(int n) {
        if (n == 1 || n == 2){
            count_1++;
            return 1;
        }
    else return (fib(n - 1) + fib(n - 2));
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        f = new int[num+2];
        fib(num);
        fibonacci(num);
        System.out.println(count_1+" "+count_2);
    }
}