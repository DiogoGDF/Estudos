// Crie uma classe chamada ExemploMetodos e, dentro dela, crie os seguintes métodos:
//   1. somar();
//   2. subtrair();
//   3. multiplicar();
//   4. dividir().

// Especificações:
//   1. Crie os métodos fora do método main();
//   2. Todos os métodos deverão ser estáticos (usar a palavra-chave static);
//   3. Todos os métodos deverão receber dois parâmetros valor_1 e valor_2 do tipo double;
//   4. Os métodos deverão retornar um valor do tipo double;
//   Exemplo: public static void soma (double valor_1, double valor_2 ){...}
//
// 1. Dentro do método main(), chame os métodos que você criou e passe valores conforme os tipos de parâmetros:
//  Exemplo: somar(2.6, 4.7);
//  2. Coloque os métodos dentro de um comando System.out.println() para mostrar o resultado.
//  Exemplo: System.out.println(Somar(2.6, 4.7));

public class Test {
    public static double somar(double valor1, double valor2){
        return valor1 + valor2;
    }

    public static double subtrair(double valor1, double valor2){
        return valor1 - valor2;
    }

    public static double multiplicar(double valor1, double valor2){
        return valor1 * valor2;
    }

    public static double dividir(double valor1, double valor2){
        return valor1 / valor2;
    }

   public static void main(String args[]) {
       System.out.println(somar(2.0, 4.0));
       System.out.println(subtrair(5.0, 4.0));
       System.out.println(multiplicar(2.0, 4.0));
       System.out.println(dividir(4.0, 2.0));

   }
}
