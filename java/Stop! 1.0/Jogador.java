public class Jogador {
private String nome;
private String[] respostas = new String[5];
private Fluxo fluxo;

public Jogador(Fluxo fluxo, String nome) {
	this.fluxo = fluxo;
	this.nome = nome;
}

public String getNome(){
	return nome;
}

public void setNome(String nome){
	this.nome = nome;
}

public Fluxo getFluxo(){
	return fluxo;
}

public String getRespota(int i){
	return respostas[i];
}

public void setResposta(int i, String resposta){
	this.respostas[i] = resposta;
}
}
