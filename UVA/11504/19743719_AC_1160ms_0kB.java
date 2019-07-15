import java.util.*;

class Main {
    ArrayList<Integer>[] matrix;
    int[] mark;
    int numTiles;
    int numKnocks;
    Stack stack ;

    public Main(int numTiles) {
        this.numTiles = numTiles;
        this.matrix = new ArrayList[numTiles];
        for (int i = 0; i < numTiles; i++) {
            matrix[i] = new ArrayList<Integer>();
        }
        this.mark = new int[numTiles];
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
        if (matrix[i].size() > 0) {
            return matrix[i].get(0);
        }
        return matrix.length;
    }

    public int next(int i, int w) {
        if (w > matrix[i].size()-1) {
            return mark.length;
        } else {
            return matrix[i].get(w);
        }
    }

    public void setKnocked(int i, int j) {
        this.matrix[i].add(j);
    }


    public void graphTraverse() {
        for (int a = 0; a < mark.length; a++) {
            mark[a] = 0;
        }
        for (int i = 0; i < mark.length; i++) {
            int atual = (int) stack.pop();
            if (getMark(atual) == 0) {
                traverseDFS(atual);
                this.numKnocks++;
            }
        }
    }

    public void traverseDFS(int i) {
        setMark(i, 1);
        int w = first(i);
        int cont = 0;
        while (w < mark.length) {
            if (getMark(w) == 0) {
                traverseDFS(w);
            }
            w = next(i, cont+1);
            cont++;
        }

    }

    public void topoSort (int i) {
        setMark(i, 1);
        int w = first(i);
        int cont  = 0;

        while (w < matrix.length) {
            if (getMark(w) == 0) {
                topoSort(w);
            }

            w = next(i, cont+1);
            cont++;
        }
        stack.push(i);
    }


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numTests = in.nextInt();

        for (int i = 0; i < numTests; i++) {

            int numTiles = in.nextInt();
            Main graph = new Main(numTiles);

            int numLines = in.nextInt();

            for (int j = 0; j < numLines; j++) {
                int tile1 = in.nextInt();
                int tile2 = in.nextInt();
                graph.setKnocked(tile1-1, tile2-1);

            }

            for (int k = 0; k < numTiles; k++) {
                if (graph.getMark(k) == 0) {
                    graph.topoSort(k);
                }

            }

            graph.graphTraverse();
            System.out.println(graph.numKnocks);

        }
    }
}