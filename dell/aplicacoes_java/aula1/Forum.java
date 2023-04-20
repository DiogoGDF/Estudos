import java.util.Scanner;

public class Forum {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.println("Qual é o seu nome?");
		String nome = scanner.nextLine();

		System.out.println("Bem vindo " + nome);
		System.out.println("Vamos calcular a mensalidade da sua família");
		System.out.println("Para isso informe a quantidade de pessoas em sua família para cada idade");

		System.out.print("Pessoas de 0 a 5 anos: ");
		int zeroAcinco = scanner.nextInt();

		System.out.print("Pessoas de 6 a 11 anos: ");
		int quantCriancas = scanner.nextInt();

		System.out.print("Pessoas de 12 a 18 anos: ");
		int quantAdolecentes = scanner.nextInt();

		System.out.print("Pessoas acima de 18: ");
		int quantAdultos = scanner.nextInt();

		double mensalidade = zeroAcinco*5.00 + quantCriancas*50.00 + quantAdolecentes*100.00 + quantAdultos*150.00;

		System.out.printf("A mensalidade de sua família será de R$%.2f\n", mensalidade);
		scanner.close();
	}
}
