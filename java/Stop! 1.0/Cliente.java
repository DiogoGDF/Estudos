//Cliente.java

import java.net.*;
import java.io.*;
import java.util.*;

public class Cliente {
private Scanner scanner;
private Fluxo fluxo;
private String check;
private String nome;
private String[] perguntas = new String[] {
	"Categoria: Lugar (país/cidade/estado/...)",
	"Categoria: Ser Vivo (animal/planta/nome de alguem/...)",
	"Categoria: Comida",
	"Categoria: Entretenimento (livro/filme/esporte/...)",
	"Categoria: Objeto (utensílio/veículo/roupa/material/...)"
};
private String[] respostas = new String[perguntas.length];


public Cliente(){
	scanner = new Scanner(System.in);
}


private void resultados(){
	try { Thread.sleep(500); } catch(Exception e) {}
	System.out.println("Resultados da partida: ");
	String leitura = fluxo.getString();
	while (!leitura.equalsIgnoreCase("FIM_RESULTADOS")) {
		try { Thread.sleep(1000); } catch(Exception e) {}
		System.out.println(leitura);
		leitura = fluxo.getString();
	}
}


private void perguntaResposta(String letra, String letraMinuscula){
	String resposta;
	for (int i = 0; i < perguntas.length; i++) {
		System.out.println('\n' + perguntas[i]);
		do {
			resposta = scanner.nextLine();
			if(!resposta.startsWith(letra) && !resposta.startsWith(letraMinuscula)) {
				System.out.printf("Escreva uma palavra que comece com a letra %s!\n", letra);
			} else {
				respostas[i] = resposta;
				fluxo.sendString(respostas[i]);
			}
		} while (!resposta.startsWith(letra)&& !resposta.startsWith(letraMinuscula));
	}
}

private void partida(){

	System.out.println("O host iniciou a partida!");

	String letra = fluxo.getString();
	String letraMinuscula = fluxo.getString();

	try{Thread.sleep(500);}catch(Exception e) {}
	System.out.println("\nDigite uma palavra que comece com a letra escolhida para cada categoria");
	try{Thread.sleep(1000);}catch(Exception e) {}
	System.out.println("\nA letra escolhida foi: " + letra);
	try{Thread.sleep(1000);}catch(Exception e) {}

	Thread thread = new Thread(() -> perguntaResposta(letra, letraMinuscula));
	thread.start();

	String checa = "0";
	while (checa.equalsIgnoreCase("0")) { checa = fluxo.getString(); }

	thread.interrupt();
	System.out.println(checa);
}


private void esperaJogadores(){
	do {
		check = fluxo.getString();
	} while(!check.equalsIgnoreCase("O host iniciou a partida!"));
}


private void novoJogador(){
	System.out.println("Esperando novo jogador...");
	do {
		check = fluxo.getString();
		System.out.println(check);
	} while(!check.contains("se conectou"));
	try { Thread.sleep(500); } catch(Exception e) {}
}


private void opcoes(){
	String op;
	do {
		try { Thread.sleep(500); } catch(Exception e) {}
		System.out.println("Escolha uma opção:");
		System.out.println("1 - começar uma nova partida");
		System.out.println("2 - esperar mais jogadores");
		op = scanner.nextLine();
		fluxo.sendString(op);
		if (op.equalsIgnoreCase("2")) { novoJogador(); }
		else if (!op.equalsIgnoreCase("1")) {
			System.out.println("Opção inválida!");
		}
	} while(!op.equalsIgnoreCase("1"));
}


public void start()throws IOException {
	try{
		fluxo = new Fluxo(new Socket("127.0.1.1", 9753));
		System.out.println("Bem vindo ao Stop de socket! :)");
		System.out.println("Qual é seu nome?");
		nome = scanner.nextLine();
		fluxo.sendString(nome);
		check = fluxo.getString();
		if(check.equalsIgnoreCase("host")) {
			System.out.println("Você é o Host");
			opcoes();
		} else {
			System.out.println("Esperando o host iniciar a partida...");
		}
		esperaJogadores();
		partida();
		resultados();
	} finally { fluxo.close(); System.exit(1); }
}


public static void main(String[] args) {
	try{
		Cliente cliente = new Cliente();
		cliente.start();
	}catch (IOException e) {
		System.out.println("Erro ao iniciar cliente: " + e.getMessage());
	}
}
}
