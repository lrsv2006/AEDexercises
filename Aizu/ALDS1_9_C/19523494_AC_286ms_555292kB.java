import java.util.*;

class Main {
    int heap[];
    int pos;
    int size;

    public Main() {
        this.heap = new int[2000000];
        this.size = 2000000;
        this.pos = 0;
    }

    void heapify(int i) {
        int leftchild = (2*i) + 1;
        int rightchild = (2*i) + 2;
        int parent = i;

        if (leftchild < this.pos && heap[parent] < heap[leftchild]) {
            parent = leftchild;
        }
        if (rightchild < this.pos && heap[parent] < heap[rightchild]) {
            parent = rightchild;
        }
        if(parent != i) {
            int temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;
            heapify(parent);
        }

    }

    void insert(int value) {
        this.heap[pos] = value;
        boolean isHeap = false;
        int i = pos;
        while(i > 0 && !isHeap) {
            int j = (i-1)/2;
            if (heap[i] > heap[j]) {
                int temp = heap[i];
                heap[i] = heap[j];
                heap[j] = temp;
            } else {
                isHeap = true;
            }
            i = j;
        }
        pos++;
    }

    int remove() {
        if (pos > 0) {
            int removed = heap[0];
            heap[0] = heap[pos-1];
            heapify(0);
            pos--;
            return removed;
        }
        return 0;
    }


        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);

            Main heap = new Main();

            String operation = in.next();

            while (!operation.equals("end")) {
                
                if (operation.charAt(0) == 'i') {
                    int number = in.nextInt();
                    heap.insert(number);
                } else {
                    int removed = heap.remove();
                    System.out.println(removed);
                }
                operation = in.next();
            }
        }
}
