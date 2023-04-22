public class Vendedor extends Funcionario{
   private double comissao;

   public Vendedor(long cpf, double salario, double desconto, double comissao){
      super(cpf, salario, desconto);
      this.comissao = comissao;
   }

   public double calcularSalario(){
      return (super.calcularSalario() + comissao);
   }
}
