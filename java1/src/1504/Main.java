/*
[BOJ] 1504 - 특정한 최단 경로
https://www.acmicpc.net/problem/1504
- Algorithm: Dijkstra
- Data Structure: Array
- Time: O(ElogN)
- Space: O(N+E)
- Trick:
  * 두 가지 경로를 모두 계산하여 더 짧은 경로 선택
  * 
*/
import java.util.*;
import java.io.*;
public class Main {
	static int INF = 200_000_000;
	static int node, line;
	static List<Node>[] graph;
	
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] input = br.readLine().split(" ");
		node = Integer.parseInt(input[0]);
		line = Integer.parseInt(input[1]);
		
		graph = new ArrayList[node+1];
		for(int i=1; i<=node; ++i)
			graph[i] = new ArrayList<Node>();
		
		for(int i=0; i<line; ++i) {
			input = br.readLine().split(" ");
			int node1 = Integer.parseInt(input[0]);
			int node2 = Integer.parseInt(input[1]);
			int weight = Integer.parseInt(input[2]);
			graph[node1].add(new Node(node2,weight));
			graph[node2].add(new Node(node1,weight));
		}
		
		input = br.readLine().split(" ");
		int v1 = Integer.parseInt(input[0]);
		int v2 = Integer.parseInt(input[1]);
		
		int result_1, result_2;
		result_1 = result_2 = 0;
		result_1 += dijkstra(1,v1);
		result_1 += dijkstra(v1,v2);
		result_1 += dijkstra(v2,node);
		
		result_2 += dijkstra(1,v2);
		result_2 += dijkstra(v2,v1);
		result_2 += dijkstra(v1,node);
		
		int answer = (result_1>=INF || result_2 >= INF)? -1 : Math.min(result_1, result_2);
		System.out.println(answer);
		
		
	}
	
	static int dijkstra(int start, int end) {

        PriorityQueue<Node> pq = new PriorityQueue<>();
        
        int[] distance = new int[node + 1];
        for(int i=0; i<=node; i++) {
            distance[i] = INF;
        }

        pq.add(new Node(start, 0));
        distance[start] = 0;

        while(!pq.isEmpty()) {
            Node node = pq.poll();

            int dist = node.weight;
            int nowNum = node.end;
            if(distance[nowNum] < dist) {
                continue;
            }
            for(Node nxt : graph[nowNum]) {
                int nxtNum = nxt.end;
                int nxtDist = nxt.weight;

                int cost = dist + nxtDist;

                if(cost < distance[nxtNum]) {
                    distance[nxtNum] = cost;
                    pq.add(new Node(nxtNum, cost));
                }
            }
        }

        return distance[end];
    }
	static class Node implements Comparable<Node>{
		int end, weight;
		
		Node(int end, int weight){
			this.end = end;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Node n) {
			return this.weight - n.weight;
		}
	}
}
