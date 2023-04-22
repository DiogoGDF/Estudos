public class Principal{
    public static void main(String[] args) {
        Computador computador = new Computador(120, 1, 3124);
        System.out.println(computador.autenticaCodigo(3124));
        System.out.println(computador.calculaPreco(12, 12));
   }
}
