import java.util.Scanner;

public class Classe {

         public static void main(String[] args) {

                 double altura;
                 double base;
                 double area = 0.0;

                  Scanner scanner = new Scanner(System.in);

                 System.out.println("Digite um valor para altura: ");
                 altura = scanner.nextDouble();

                 System.out.println("Digite um valor para base: ");
                 base = scanner.nextDouble();

                 area = (base * altura) / 2;
                 System.out.println(area);

                 scanner.close();
          }
}
