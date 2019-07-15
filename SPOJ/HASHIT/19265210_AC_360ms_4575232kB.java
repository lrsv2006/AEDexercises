
import java.util.*;

class Words {
    String key;
    String name[] = new String[101];

    Words() {
        this.key = null;
        for (int i = 0; i < 101; i++) {
            name[i] = "-1";
        }
    }

    public void setKey(String key) {
        this.key = key;
    }

    public String getKey(int pos) {
        return key;
    }

    public void setName(String name, int pos) {
        this.name[pos] = name;
    }

    public String getName(int pos) {
        return name[pos];
    }

    public int Hash(String key) {
        return ((h(key)) % 101);
    }

    public int h(String key) {
        int sum = 0;
        for (int i = 1, j = 0; i <= key.length(); i++, j++) {
            if (key.charAt(j) == ' ') {
                sum = sum + 32*i;
            } else {
                sum = sum + (key.charAt(j) * i);
            }
        }
        sum = sum * 19;
        return sum;
    }

    int collisions(String key, int j) {
        int freepos = (Hash(key) + (j * j) + (23 * j));
        if (freepos>=101) {
            freepos = freepos%101;
        }
        return freepos;
    }

    boolean insert(Words Word, String key) {
        int pos = Hash(key);
            if (Word.find(Word, key) == -1) {
                if (Word.getName(pos).equals("-1")) {
                    Word.setName(key, pos);
                    return true;
                } else {
                    boolean inserted = false;
                    for (int i = 1; i < 20 && !inserted; i++) {
                        int freepos = collisions(key, i);
                        inserted = insertaftercollision(Word, key, freepos);
                        if (inserted == true) {
                            return true;
                        }
                    }
                }

                return false;
            }
            return false;
    }

    boolean insertaftercollision(Words Word, String key, int freepos) {
        if (Word.getName(freepos).equals("-1")) {
            Word.setName(key, freepos);
            return true;
        } else {
            return false;
        }

    }

    boolean insertemptystr(Words Word) {
        if (find(Word, " ") == -1) {
            Word.setName(" ", 0);
            return true;
        }
        return false;
    }

    boolean deletemptystr(Words Word) {
        if (find(Word, " ") != -1) {
            Word.setName("-1", 0);
            return true;
        }
        return false;
    }


    int find(Words Word, String key) {
        int index = Hash(key);
        if (Word.getName(index).equals(key)) {
            return index;
        } else {
            int found = 0;
            for (int i = 1; i <= 101; i++) {
                int newpos = collisions(key, i);
                found = findaftercollision(Word, key, newpos);
                if (found != -1) {
                    return newpos;
                }
            }
        }
        return -1;
    }

    int findaftercollision(Words Word, String key, int newpos) {
        if (Word.getName(newpos).equals(key)) {
            return newpos;
        } else {
            return -1;
        }
    }

    boolean deletekey(Words Word, String key) {
        int pos = find(Word, key);
        if (pos == -1) {

        } else {
            if (Word.getName(pos).equals(key)) {
                Word.setName("-1", pos);
                return true;
            } else {
                boolean deleted = false;
                for (int i = 1; i <= 101; i++) {
                    int newpos = collisions(key, i);
                    deleted = deletekeyaftercollision(Word, key, newpos);
                    if (deleted == true) {
                        return true;
                    }
                }
            }
        }
        return false;

    }

    boolean deletekeyaftercollision(Words Word, String key, int newpos) {

        if (newpos == -1) {
            return true;
        } else {

            if (Word.getName(newpos).equals(key)) {
                Word.setName("-1", newpos);
                return true;
            } else {
                return false;
            }
        }

    }

    public static void main (String[] args){
        Scanner in = new Scanner(System.in);

        int testcases = in.nextInt();

        for (int i = 0; i < testcases; i++) {
            Words words = new Words();

            int operations = in.nextInt();
            in.nextLine();
            int numberofwords = 0;

            for (int j = 0; j < operations; j++) {
                String operation = in.nextLine();

                if (operation.charAt(0) == 'A') {
                    int size = operation.length();
                    if (size == 4) {

                    } else {
                        String word = operation.substring(4, size);
                        if (word.equals(" ")) {
                            if (words.insertemptystr(words) == true) {
                                numberofwords++;
                            }
                        } else {
                            if (words.insert(words, word) == true) {
                                numberofwords++;
                            }
                        }
                    }

                } else {
                    int size = operation.length();
                    if (size == 4) {

                    } else {
                        String word = operation.substring(4, size);
                        if (word.equals(" ")) {
                            if (words.deletemptystr(words) == true) {
                                numberofwords--;
                            }
                        } else {
                            if (words.deletekey(words, word) == true) {
                                numberofwords--;
                            }
                        }

                    }
                }
            }
            System.out.println(numberofwords);
            for (int j = 0; j < 101; j++) {
                if (!words.name[j].equals("-1")) {
                    System.out.print(j);
                    System.out.print(":");
                    System.out.println(words.name[j]);
                }
            }
        }
    }
}