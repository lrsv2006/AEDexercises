package List1Question1;
import java.util.*;

class Pilha {



    private Pilha next;
    private Object pilhaelement;
    static Pilha topo;

    Pilha() {
        this.next = null;
        this.pilhaelement = null;
        this.topo = null;
    }
}

interface PilhaInterface {

    public void push(Pilha pilhabracket, char bracket);
    public Object pop();
    public Object top();
    public boolean isEmpty();

}

class PilhaRep implements PilhaInterface {

    Pilha lista = new Pilha();


    public void push(Pilha pilhabracket, char bracket) {


    }

    public Object pop() {
        return null;
    }


    public Object top() {
        return null;
    }


    public boolean isEmpty() {

        return false;
    }
}



