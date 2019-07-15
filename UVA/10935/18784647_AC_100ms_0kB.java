import java.util.*;

 class Main {

    private Main front;
    private Main rear;
    private int number;
    private int size;
    private Main next;


    Main() {
        this.front = null;
        this.rear = null;
        this.size = 0;
        this.number = 0;
        this.next = null;

    }

    public int getNumber() {
        return front.number;
    }

    public void setNumber(int number) {
        this.number = number;
    }


    public int getSize() {
        return this.size;
    }



    public void enqueue(int number) {
        Main newfila = new Main();
        newfila.setNumber(number);

        if (this.getSize() == 0) {
            this.rear = this.front = newfila;
        }

        this.rear.next = newfila;
        this.rear = newfila;
        this.size++;


    }



    public void dequeue( ) {
       if (this.getSize() == 0) {
            System.err.print("There's nothing to remove.");
       }
            this.front = this.front.next;
            if (this.front.next == null) {
                this.rear = this.front;

             }

            Main aux = this.front;
            this.rear.next = this.front;
            this.rear = this.rear.next;
            this.front = aux.next;


        this.size--;

        }





    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int number = -1;

        while (number != 0) {

            Main fila = new Main();
            number = in.nextInt();

            if (number != 0 && number != 1) {
                int removednumbers[] = new int[number - 1];

                if (number != 0) {
                    for (int i = 1; i < number + 1; i++) {
                        fila.enqueue(i);
                    }

                }
                int i = 0;

                while (fila.getSize() > 1) {
                    removednumbers[i] = fila.getNumber();
                    fila.dequeue();
                    i++;
                }
                System.out.print("Discarded cards: ");

                for (int j = 0; j < removednumbers.length - 1; j++) {
                    System.out.print(removednumbers[j] + "," + " ");
                }

                System.out.println(removednumbers[removednumbers.length - 1]);
                System.out.println("Remaining card: " + fila.getNumber());

            } else if (number == 1) {
                System.out.println("Discarded cards:");
                System.out.println("Remaining card: " + 1);
            }

        }

    }

}

