import java.net.*;
import java.io.*;
import java.util.*;

public class Server {
private Jogador[] jogadores = new Jogador[4];
private int quantJogador = 0;
private String sig = "0";
private Thread threads[];
private String[] categorias = new String[] {
	"Lugar:",
	"Ser vivo:",
	"Comida",
	"Entretenimento:",
	"Objeto:"
};


private void enviarAtodosOutros(String mensagem, int proc){
	for (int i = 0; i < quantJogador; i++)
		if(i != proc) jogadores[i].getFluxo().sendString(mensagem);
}


private void enviarAtodos(String mensagem){
	for (int i = 0; i < quantJogador; i++)
		jogadores[i].getFluxo().sendString(mensagem);
}


private void enviaTodasRespostas(){
	String nomeJogador;
	for(int i = 0; i < quantJogador; i++) {
		nomeJogador = "Jogador: " + jogadores[i].getNome();
		enviarAtodos(nomeJogador);
		for(int j = 0; j < 5; j++) {
			String resp = jogadores[i].getRespota(j);
			if(resp != null) {
				enviarAtodos(categorias[j]);
				enviarAtodos("Resposta: " + resp);
			} else {
				enviarAtodos("O jogador foi interrompido aqui!");
				break;
			}
		}
		enviarAtodos("\n");
	}
	enviarAtodos("FIM_RESULTADOS");
}


private int checa(){
	boolean check = true;
	int qual = -1;
	while (check == true) {
		for(int i = 0; i < threads.length; i++) {
			check = threads[i].isAlive();
			if(check == false) {
				qual = i;
				break;
			}
		}
	}
	for(int i = 0; i < threads.length; i++) {
		if(i != qual) threads[i].interrupt();
	}
	return qual;
}


private void recebeRespostas(int proc){
	for (int j = 0; j < 5; j++) {
		String resposta = jogadores[proc].getFluxo().getString();
		jogadores[proc].setResposta(j, resposta);
	}
}


private void inicioPartida(){
	enviarAtodos("O host iniciou a partida!");
	int escolha = (int)(Math.random()*26)+65;
	String letra = String.valueOf(Character.toChars(escolha));
	String letraMinuscula = String.valueOf(Character.toChars(escolha+32));
	enviarAtodos(letra); enviarAtodos(letraMinuscula);
}


private void inicioJogo(){
	threads = new Thread[quantJogador];
	inicioPartida();
	for(int i = 0; i < quantJogador; i++) {
		int t = i;
		threads[i] = new Thread(()-> recebeRespostas(t));
		threads[i].start();
	}
	int qual = checa();
	String qualJogador = jogadores[qual].getNome() + ": STOP!";
	enviarAtodos(qualJogador);
	enviaTodasRespostas();
}


public void start() throws IOException {
	ServerSocket socket = new ServerSocket(9753);
	System.out.println("Servidor iniciado com sucesso");
	do{
		//Recebendo e estabelecendo o fluxo de comunicação com clientes
		Fluxo fluxo = new Fluxo(socket.accept());
		String nome = fluxo.getString();
		jogadores[quantJogador++] = new Jogador(fluxo, nome);

		if(quantJogador == 1) {
			fluxo.sendString("host");
		} else {
			fluxo.sendString("n");//Envia para o clinete que não é host
			String mensagem = nome + " se conectou!";
			enviarAtodosOutros(mensagem, (quantJogador - 1));
		}
		System.out.println("Novo jogador!");
		System.out.println(quantJogador + " jogador(es) entraram");
		try{ Thread.sleep(1000); }catch(Exception e) {}
		sig = "0";
		while(!sig.equalsIgnoreCase("1")&&!sig.equalsIgnoreCase("2")) {
			sig = jogadores[0].getFluxo().getString();
		}

	} while(!sig.equalsIgnoreCase("1"));
	inicioJogo();
	socket.close();
	System.out.println("Server encerrado!");
}


public static void main(String[] args) {
	try{
		Server server = new Server();
		server.start();
	} catch(IOException e) {System.out.println(e.getMessage());}
}
}
