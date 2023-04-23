import java.net.*;
import java.io.*;

public class Fluxo {
private Socket socket;
private BufferedReader leitura;
//PrintWriter em vez do buffered reader de escrita, porque o PrintWriter
//já possuí o DataOutputStream e fflush(stdout) embutido,
//assim facilitando as impressões na tela
private PrintWriter escrita;

//construtor
public Fluxo(Socket socket) throws IOException {
	this.socket = socket;
	//abre o canal de fluxo de leitura
	this.leitura = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	//abre o canal de fluxo de saída
	this.escrita = new PrintWriter(socket.getOutputStream(), true);
}


public String getString(){
	try{ return leitura.readLine(); }
	catch (IOException e) { return null; }
}


public boolean sendString(String string){
	escrita.println(string);
	return !escrita.checkError();
}


//função para fechar todos os caminhos e fluxos alocados pelo Sistema Operacional
public void close(){
	try{
		leitura.close();
		escrita.close();
		socket.close();
	} catch (Exception e) {}
}
}
