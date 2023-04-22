public class Principal{
    public static void main(String[] args) {
      // Funcionario funcionario = new Funcionario();
      // funcionario.setCpf(12345678901L);
      // funcionario.setSalario(1209.75);
      // funcionario.setDesconto(102.35);
      // System.out.println("Salário líquido: " + funcionario.calcularSalario());

      // Vendedor vendedor = new Vendedor(12345678902L, 1620.50, 120.45, 50.55);
      // System.out.println("Salário líquido: " + vendedor.calcularSalario());

      // Computador computador = new Computador(120, 1, 3124);
      // System.out.println(computador.autenticaCodigo(3124));
      // System.out.println(computador.calculaPreco(12, 12));

      Funcionario vendedor = new Vendedor(1234567890L, 900, 20, 200);
      Funcionario diarista = new Diarista(200, 8);

      System.out.println("Salário do vendedor: " + vendedor.calcularSalario());
      System.out.println("Salário do diarista: " + diarista.calcularSalario());

   }
}
