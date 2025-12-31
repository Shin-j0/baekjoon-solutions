/*
[BOJ] 2580 - 스도쿠
https://www.acmicpc.net/problem/2580
- Algorithm: Backtracking
- Data Structure: Array
- Time: O()
- Space: O()
- Trick:
  * 아직 succcess 못함
  * 
*/
import java.io.*;
import java.util.*;

public class Main {
    static int[][] sudoku;
    static int count;
    public static void scan_x_line(List<String> list_cpy,int i){
        Stack<Integer> stack = new Stack<>();
        List<String> list = new ArrayList<>();
        list.addAll(list_cpy);
        for (int j = 0; j < 9; j++) {
            int dot = sudoku[i][j];
            if(dot == 0) stack.push(j);
            else list.remove(String.valueOf(dot));
        }
        if(stack.size()==1){
            sudoku[i][stack.pop()] = Integer.parseInt(list.get(0));
            count--;
        }
    }
    public static void scan_y_line(List<String> list_cpy,int i){
        Stack<Integer> stack = new Stack<>();
        List<String> list = new ArrayList<>();
        list.addAll(list_cpy);
        for (int j = 0; j < 9; j++) {
            int dot = sudoku[j][i];
            if(dot == 0) stack.push(j);
            else list.remove(String.valueOf(dot));
        }
        if(stack.size()==1){
            sudoku[stack.pop()][i] = Integer.parseInt(list.get(0));
            count--;
        }
    }

    public static void scan_3x3(List<String> list_cpy,int i,int j){
        Stack<Integer> stack_x = new Stack<>();
        Stack<Integer> stack_y = new Stack<>();
        List<String> list = new ArrayList<>();
        list.addAll(list_cpy);
        for (int k = i; k <i+3; k++) {
            for (int l = j; l <j+3 ; l++) {
                int dot = sudoku[k][l];
                if(dot == 0) {
                    stack_x.push(k);
                    stack_y.push(l);
                }
                else list.remove(String.valueOf(dot));
            }
        }
        if(list.size()==1){
            sudoku[stack_x.pop()][stack_y.pop()] = Integer.parseInt(list.get(0));
            count--;
        }
    }

    public static void print(){
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(sudoku[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        count=0;
        sudoku = new int[9][9];
        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                int temp = Integer.parseInt(st.nextToken());
                sudoku[i][j] = temp;
                if(temp == 0) count++;
            }
        }
        List<String> list = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            list.add(String.valueOf(i+1));
        }
        while(count>0){
            int c = count;
            for (int i = 0; i < 9; i++) {
                scan_x_line(list,i);
            }
            for (int i = 0; i < 9; i++) {
                scan_y_line(list,i);
            }
            for (int i = 0; i <9; i+=3){
                for (int j = 0; j < 9; j+=3) {
                    scan_3x3(list,i,j);
                }
            }
            if(c==count) break;
        }
        print();
    }
}