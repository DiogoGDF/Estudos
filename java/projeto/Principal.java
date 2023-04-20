 
package principal;
import modelos.Aluno;
public class Principal{
    public static double calcularMedia(double n1, double n2){
        return ((n1 + n2) / 2);
    }
    public static void main(String args[]){
        Aluno aluno1 = new Aluno("Pedro", 8.75, 6.25);
        System.out.println("Nome: " + aluno1.getNome());
        System.out.println("Nota1: " + aluno1.getNota1());
        System.out.println("Nota2: " + aluno1.getNota2());
        System.out.println("Media: " + calcularMedia(aluno1.getNota1(), aluno1.getNota2()));
    }
}
