import java.util.LinkedList;
import java.util.Queue;

public class DFSAndDFS_AMatrix {
    static boolean[] visited = null;
    public static void main(String[] args) {
        int[][] graph = {
                {0,1,1,0},
                {1,0,0,1},
                {1,0,0,1},
                {0,1,1,0}
        };
//        DFSWithMatrix dfs = new DFSWithMatrix();
        visited = new boolean[4];
        print(graph);
        System.out.println("DFS");
        dfs(graph, 0);
        System.out.println("BFS");
        bfs(graph, 0);
    }

    static void print(int[][] mat){
        for(int i = 0; i < mat.length; ++i){
            System.out.print("["+i+"]->");
            for (int j = 0; j < mat[0].length; ++j){
                if (mat[i][j] != 0)
                    System.out.print(j+", ");
            }
            System.out.println();
        }
    }

    //dfs(graph, startingNode/NodeTOBeVisited
    static void dfs(int[][] graph, int nodeIndex){
        //if a node at index is not visited yet
        if (visited[nodeIndex]){
            // mark the node as visited
            visited[nodeIndex] = true;
            //print the node
            System.out.print(nodeIndex+", ");
            // iterate through all the row's , at index
            for (int i = 0; i < graph[nodeIndex].length; ++i){
                //if ith node/column is non-zero/adjacent and ith node is not visited
                // then, pause and call for ith nodes
                if (graph[nodeIndex][i] != 0 && !visited[i]){
                    dfs(graph,i);
                }
            }
        }
    }

    static void bfs(int[][] graph, int nodeIndex){
        Queue<Integer> queue = new LinkedList<>();
        resetVisits();
        queue.add(nodeIndex);
        while (!queue.isEmpty()){
            nodeIndex = queue.remove();
            if (!visited[nodeIndex]) {
                visited[nodeIndex] = true;
                System.out.print(nodeIndex+", ");
                for (int j = 0; j < graph[nodeIndex].length; ++j) {
                    if (graph[nodeIndex][j] != 0){
                        queue.add(j);
                    }
                }
            }
        }
    }

    static void resetVisits(){
        for (int i = 0; i < visited.length; ++i)
            visited[i] = false;
    }
}


