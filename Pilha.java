import java.util.*;

class Pilha {

    private Pilha top;
    private Pilha next;
    private int size;
    private int length;
    private char bracket;
    private Pilha previous;


    Pilha() {
        this.next = null;
        this.previous = null;
        this.top = null;
        this.bracket = 0;
        this.size = 0;
        this.length = 0;

    }

    public void setBracket(char bracket) {
        this.bracket = bracket;
    }


    public void setPrevious(Pilha previous) {
        this.previous = previous;
    }

    public Pilha getPrevious() {
        return previous;
    }

    public int getSize() {
        return size;
    }

    public char getBracket() {
        return bracket;
    }


    public void push() {
        if (top.getBracket() == 0) {
            System.err.print("Não há nada para remover.");
        } else {
            top = top.getPrevious();
        }

    }

    public void pop(char bracket) {
        Pilha newbracket = new Pilha();
        newbracket.setBracket(bracket);
        newbracket.setPrevious(top);
        top =  newbracket;
        size = size++;

    }

    public void verify() {
        if (top.getBracket() == '(') {
            top.push();
        }

        if (top.getBracket() == ')') {
            if (top.getPrevious().getBracket() == '(') {
                length++;
            } else {
                previous.verify();
            }
        }
    }



    public boolean isEmpty() {
        if (top == null) {
            return true;
        }
        return false;
    }

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);

        Pilha pilha = new Pilha();

        String bracketline = in.nextLine();

        for (int i = 0; i < bracketline.length(); i++) {
            pilha.pop(bracketline.charAt(i));
        }

        for (int i = 0; i < bracketline.length(); i++) {
            if (bracketline.charAt(0) ==')') {

            }
        }

        pilha.verify();

    }
}







