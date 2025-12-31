/*
[BOJ] 2447 - 별 찍기 - 10
https://www.acmicpc.net/problem/2447
- Algorithm: Recursion
- Data Structure: Array
- Time: O(N^2logN)
- Space: O(1)
- Trick:
  * (i,j)를 3진 분할했을 때 어떤 단계에서라도 가운데(1,1) 블록이면 공백
  * 
*/
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i<n; ++i) {
			for(int j = 0; j<n; ++j) {
				String answer = "*";
				for(int k = n; k!=0; k/=3) {
					if((i/k)%3==1 && (j/k)%3==1) {
						answer = " ";
						continue;
					}
				}
				bw.write(answer);
			}
			bw.write(+ '\n');
		}
		bw.flush();
		bw.close();
	}
}
