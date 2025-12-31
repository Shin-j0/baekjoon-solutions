/*
[BOJ] 14889 - 스타트와 링크
https://www.acmicpc.net/problem/14889
- Algorithm: Backtracking
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
    static int[][] score;
    static Integer [] arr;
    static List<Integer> start_team;
    static List<Integer> link_team;
    static boolean team;

    static int comCount=0;
    static int n;
    static int min;
    static int k;
    public static void combination_score(ArrayList<Integer> list, int index, int count, int[] o) {
        if (count == 0) {
            int temp = score[list.get(0)][list.get(1)] + score[list.get(1)][list.get(0)];
            if(team)
                start_team.add(temp);
            else
                link_team.add(temp);
            return;
        }

        for(int i = index; i < k; i++) {
            list.add(o[i]);
            combination_score(list, i + 1,count - 1,o);
            list.remove(list.size() - 1);
        }
    }
    public static void combination_team(ArrayList<Integer> list, int index, int count) {
        if (count == 0) {
            start_team = new ArrayList<>();
            link_team = new ArrayList<>();
            int[] o1 = new int[k];
            int[] o2 = new int[k];
            int p=0,q=0;
            for (int i = 0; i < n; i++) {
                if(list.contains(arr[i]))
                    o1[p++] = arr[i];
                else
                    o2[q++] = arr[i];
            }
            team = true;
            combination_score(new ArrayList<Integer>(),0,2,o1);
            team = false;
            combination_score(new ArrayList<Integer>(),0,2,o2);

            int sum = 0;

            for (int i = 0; i < start_team.size(); i++) {
                sum += start_team.get(i);
                sum -= link_team.get(i);
            }
            if(min>Math.abs(sum)) min = Math.abs(sum);
            return;
        }

        for(int i = index; i < n; i++) {
            list.add(arr[i]);
            combination_team(list, i + 1,count - 1);
            list.remove(list.size() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        k = n/2;
        min = 200;
        arr = new Integer[n];
        score = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i] = i;
            for (int j = 0; j < n; j++) {
                score[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        combination_team(new ArrayList<>(),0,k);

        System.out.println(min);
    }
}