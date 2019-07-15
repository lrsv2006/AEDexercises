import java.util.*;

public class Pilha {

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
            this.size--;
        }

    }

    public void pop(char bracket) {
        Pilha newbracket = new Pilha();
        newbracket.setBracket(bracket);
        newbracket.setPrevious(top);
        top =  newbracket;
        this.size++;

    }
    

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);

        Pilha pilha = new Pilha();


        String bracketline = in.nextLine();
        char[] bracketlineA = new char[bracketline.length()];
        for (int i = 0; i < bracketline.length(); i++) {
            bracketlineA[i] = bracketline.charAt(i);
            
        }

        int stringlength = bracketline.length();


            for (int i = 0; i < bracketline.length(); i++) {

                     if (bracketlineA[i] == '(') {
                         pilha.pop(bracketlineA[i]);


                      } else if (bracketlineA[i] == ')') {
                             if (pilha.getSize() > 0) {
                                 pilha.push();
                             } else {
                                stringlength--;
                             }

                        }


                    }
        System.out.print(stringlength - pilha.getSize());
    }

}
