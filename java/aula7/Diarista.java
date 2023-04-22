public class Diarista extends Funcionario{
    private double valorHora;
    private double quantidadeHoras;

    public Diarista(){}

    public Diarista(double valorHora, double quantidadeHoras){
        this.valorHora = valorHora;
        this.quantidadeHoras = quantidadeHoras;
    }

    public double getValorHora(){
        return valorHora;
    }
    public double getQuantidadeHoras(){
        return quantidadeHoras;
    }
    public void setValorHora(double valorHora){
        this.valorHora = valorHora;
    }
    public void setQuantidadeHoras(double quantidadeHoras){
        this.quantidadeHoras = quantidadeHoras;
    }

    public double calcularSalario() {
        return valorHora * quantidadeHoras;
    }


}
