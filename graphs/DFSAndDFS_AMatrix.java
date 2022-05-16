public class DFSAndDFS_AMatrix {
    static int[] visited = null;
    public static void main(String[] args) {
        int[][] graph = {
                {0,1,1,0},
                {1,0,0,1},
                {1,0,0,1},
                {0,1,1,0}
        };
//        DFSWithMatrix dfs = new DFSWithMatrix();
        visited = new int[4];
        print(graph);
        System.out.println("DFS");
        dfs(graph, 0);
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

    static void dfs(int[][] graph, int nodeIndex){
        //if a node at index is not visited yet
        if (visited[nodeIndex] == 0){
            //
            //System.out.println("["+index+"]-> ");
            // iterate through all the row's , at index
            visited[nodeIndex] = 1;
            System.out.print(nodeIndex+", ");
            for (int i = 0; i < graph[nodeIndex].length; ++i){
                //
                if (graph[nodeIndex][i] != 0 && visited[i] != 1){

                    dfs(graph,i);
                }
            }
        }
    }

}


