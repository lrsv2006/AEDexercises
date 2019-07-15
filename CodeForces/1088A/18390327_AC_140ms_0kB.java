import java.util.*;

public class L0Q1 {

    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);

        int number = in.nextInt();

        if (number <= 1) {

            int invalidnumber = -1;
            System.out.print(invalidnumber);
        } else if (number == 2 || number == 3) {

            int possiblenumber = 2;
            System.out.println(possiblenumber);
            System.out.println(possiblenumber);
        } else if (number > 3 && number%2 == 0) {

            int possiblenumber1 = 2;
            int possiblenumber2 = number;
            System.out.println(possiblenumber2);
            System.out.print(possiblenumber1);
        } else if (number > 3 && number%2 != 0) {

            int possiblenumber1 = 3;
            int possiblenumber2 =  number;

            if (possiblenumber2 % possiblenumber1 == 0) {

                System.out.println(possiblenumber2);
                System.out.print(possiblenumber1);
            } else {

                while (possiblenumber2 % possiblenumber1 != 0) {
                    possiblenumber2 = possiblenumber2-2;
                }

                System.out.println(possiblenumber2);
                System.out.print(possiblenumber1);
            }
        }

    }
}