/*
[BOJ] 14888 - 연산자 끼워넣기
https://www.acmicpc.net/problem/14888
- Algorithm: Backtracking
- Data Structure: Array
- Time: O(N^2)
- Space: O(N)
- Trick:
  * 
  * 
*/
import java.io.*;
import java.util.*;

public class Main {
    static int[] arr;
    static String[] operator;
    static int[] operator_num;
    static int x;
    static int num;
    static long min;
    static long max;
    static int Q = 0;
    public static void get_operator(int N, String o){
        while(N-- > 0)
            operator[x++] = o;
    }
    public static void combination(ArrayList<Integer> list,int count){
        if(count == 0){
            Q++;
            long sum = arr[0];
            for (int i = 0; i < num-1; i++) {
                String o = operator[list.get(i)];
                switch (o){
                    case"+":
                        sum += arr[i+1];
                        break;
                    case"-":
                        sum -= arr[i+1];
                        break;
                    case"*":
                        sum *= arr[i+1];
                        break;
                    case"/":
                        sum /= arr[i+1];
                        break;
                }
            }
            if(Q==1){
                max = sum;
                min = sum;
            }
            if(max<sum) max = sum;
            if(min>sum) min = sum;
        }
        else{
            for (int i = 0; i < num-1; i++) {
                if(list.contains(operator_num[i]))
                    continue;
                list.add(operator_num[i]);
                combination(list,count-1);
                list.remove(list.size()-1);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        num = Integer.parseInt(br.readLine());
        arr = new int[num];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < num; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        x = 0;
        operator = new String[num-1];
        operator_num = new int[num-1];
        for (int i = 0; i < num-1; i++) {
            operator_num[i] = i;
        }
        st = new StringTokenizer(br.readLine());
        get_operator(Integer.parseInt(st.nextToken()),"+");
        get_operator(Integer.parseInt(st.nextToken()),"-");
        get_operator(Integer.parseInt(st.nextToken()),"*");
        get_operator(Integer.parseInt(st.nextToken()),"/");

        combination(new ArrayList<>(),num-1);
        System.out.println(max+"\n"+min);

    }
}