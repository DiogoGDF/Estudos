public class Principal{
    public static void main(String[] args) {
      Funcionario funcionario = new Funcionario();
      funcionario.setCpf(12345678901L);
      funcionario.setSalario(1209.75);
      funcionario.setDesconto(102.35);
      System.out.println("Salário líquido: " + funcionario.calcularSalario());

      Vendedor vendedor = new Vendedor(12345678902L, 1620.50, 120.45, 50.55);
      System.out.println("Salário líquido: " + vendedor.calcularSalario());
   }
}
