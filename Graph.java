import java.util.*;

public class Graph {
    private int[][] matrix;
    private int[] mark;
    private int numTiles;
    private int numKnocks;
    private Stack stack;

    public Graph(int numTiles) {
        this.numTiles = numTiles;
        this.matrix = new int[numTiles+1][numTiles+1];
        this.mark = new int[numTiles+1];
        this.numKnocks = 0;
        this.stack = new Stack();
    }



    public void setMark(int i, int val) {
        this.mark[i] = val;
    }


    public int getMark(int i) {
        return mark[i];
    }


    public int first(int i) {
        for (int j = 0; j < mark.length; j++) {
            if (matrix[i][j] != 0 && getMark(j) == 0) {
                return j;
            }
        }
        return mark.length;
    }

    public int next(int i, int w) {
        for (int j = w+1; j < mark.length; j++) {
            if (matrix[i][j] != 0) {
                return j;
            }
        }
        return mark.length;
    }

    public void setKnocked(int i, int j) {
        this.matrix[i][j] = 1;
    }


    public void graphTraverse() {
        for (int a = 0; a < mark.length; a++) {
            mark[a] = 0;
        }

        for (int i = (int) stack.pop(); i < mark.length; i++) {
            if (getMark(i) == 0) {
                traverseDFS(i);
            }
        }
    }


    public void traverseDFS(int i) {
        setMark(i, 1);
        int w = first(i);
        while (w < mark.length) {
            if (getMark(w) == 0) {
                this.numKnocks++;
                traverseDFS(w);
            }
            w = next(i, w);
        }

    }

    public void topoSort (int i) {
        setMark(i, 1);
        int w = first(i);
        while (w < mark.length) {
            if (getMark(w) == 0) {
                topoSort(w);
            }
            w = next(i, w);
        }
        stack.push(i);
    }

    public int getEdge (int i, int j) {
        return matrix[i][j];
    }



    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numTests = in.nextInt();

        for (int i = 0; i < numTests; i++) {
            int necessaryKnocks = 0;

            int numTiles = in.nextInt();
            Graph graph = new Graph(numTiles);

            int numLines = in.nextInt();

            for (int j = 0; j < numLines; j++) {
                int tile1 = in.nextInt();
                int tile2 = in.nextInt();
                graph.setKnocked(tile1, tile2);

            }

            for (int k = 1; k < numTiles + 1; k++) {
                if (graph.getMark(k) == 0) {
                    graph.topoSort(k);
                }

            }

            graph.graphTraverse();

            for (int m = 1; m < numTiles + 1; m++) {
                if (graph.getMark(m) == 1) {
                    necessaryKnocks++;
                    break;
                }
            }

            for (int k = 1; k < numTiles + 1; k++) {
                if (graph.getMark(k) == 0) {
                    graph.traverseDFS(k);
                    necessaryKnocks++;
                }

            }

            System.out.println(necessaryKnocks);

        }
    }
}