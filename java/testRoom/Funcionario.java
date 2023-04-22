public class Funcionario{
   private long cpf;
   private double salario;
   private double desconto;

   public long getCpf(){
      return cpf;
   }
   public double getSalario(){
      return salario;
   }
   public double getDesconto(){
      return desconto;
   }
   public void setCpf(long cpf){
      this.cpf = cpf;
   }
   public void setSalario(double salario){
      this.salario = salario;
   }
   public void setDesconto(double desconto){
      this.desconto = desconto;
   }

    public Funcionario(){}

    public Funcionario(long cpf, double salario, double desconto){
        this.cpf = cpf;
        this.salario = salario;
        this.desconto = desconto;
    }

    public double calcularSalario(){
        return (salario - desconto);
    }
}
