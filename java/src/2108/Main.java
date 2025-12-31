/*
[BOJ] 2108 - 통계학
https://www.acmicpc.net/problem/2108
- Algorithm: Sorting
- Data Structure: Array
- Time: O(N)
- Space: O(N)
- Trick:
  * 
  * 
*/
import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        StringBuffer sb = new StringBuffer();
        List<Integer> list = new ArrayList<>();
        List<Integer> list_reverse = new ArrayList<>();
        double sum = 0;
        for (int i = 0; i < num; i++) {
            int tmp = Integer.parseInt(br.readLine());
            sum += (double) tmp;
            list.add(tmp);
            list_reverse.add(tmp);
        }
        sb.append(Math.round(sum/num)).append("\n");
        Collections.sort(list_reverse,Collections.reverseOrder());
        int size = list_reverse.get(0)-list_reverse.get(list_reverse.size()-1);
        int center = list_reverse.get((int)Math.round((double)num/2)-1);
        Map<Integer,Integer> map = new HashMap<>();
        int M = 0;
        for (int i = 0; i < num; i++) {
            if(!map.containsKey(list.get(i))) map.put(list.get(i),0);
            else{
                int o = map.get(list.get(i));
                o++;
                map.replace(list.get(i),o);
            }
            if(map.get(list.get(i))>M) M = map.get(list.get(i));
        }
        int count = 0;
        for (Integer a: map.values()) {
            if(M==a) count++;
        }
        List<Integer> x = new ArrayList<>();
        int many = 0;
        if(count>1){
            for (Integer a: map.keySet()) {
                if(M == map.get(a)) x.add(a);
            }
            Collections.sort(x);
            many = x.get(1);
        }
        else{
            for (Integer a: map.keySet()) {
                if(M == map.get(a)) {
                    many = a;
                    break;
                }
            }
        }
        sb.append(center).append("\n");
        sb.append(many).append("\n");
        sb.append(size).append("\n");

        System.out.println(sb);
    }
}