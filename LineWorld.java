// BFS in Java

import java.io.*;
import java.util.*;

public class LineWorld {
    public static void main(String args[]) {

        Scanner scan = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(scan.nextLine());

        int N = Integer.parseInt(st.nextToken()); // Number of cells
        int T = Integer.parseInt(st.nextToken()); // Desired destination

        Graph g = new Graph(N);

        st = new StringTokenizer(scan.nextLine());

        for (int i = 1; i < N; i++) {
            int next = Integer.parseInt(st.nextToken());
            g.addEdge(i, i + next);
        }

        if (g.existsPath(1, T)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

    }
}

class Graph {
    private final int V;
    private int E;
    private HashSet<Integer>[] adj; // An array of hashsets.

    public Graph(int V) {
        if (V < 0) {
            throw new IllegalArgumentException("Number of vertices must be nonnegative");
        }
        
        this.V = V;
        this.E = 0;
        adj = new HashSet[V+1];
        for (int v = 1; v <= V; v++) {
            adj[v] = new HashSet<Integer>();
        }
    }

    // From v to w.
    public void addEdge(int v, int w) {
        E++;
        adj[v].add(w);
    }

    // Breadth-first search implementation
    public boolean existsPath(int source, int destination) {


        Queue<Integer> q = new LinkedList();
        boolean[] visited = new boolean[V+1];
        visited[source] = true;
        q.offer(source);

        while (!q.isEmpty()) {
            int current = q.poll();

            HashSet<Integer> neighbors = getNeighbors(current);
            for (int w : neighbors) {
                if (visited[w] == false) {
                    q.offer(w);
                    visited[w] = true;
                }
            }

        }
        // Now, we have finished the traversal.
        if (visited[destination]) {
            return true;
        } else {
            return false;
        }
    }

    // Neighbors are where you can get to from a given source.
    public HashSet<Integer> getNeighbors(int source) {
//        System.out.println("Getting neighbors!");
        return adj[source];
    }

}
