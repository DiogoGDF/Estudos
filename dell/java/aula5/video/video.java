// Declarando os atributos:
float peso;
String cor;
float preco;

// Declarando os métodos getters e setters do atributo peso:
public void setPeso(float peso){
	this.peso = peso;
}

	public float getPeso(){
		return this.peso;
}

// Declarando os métodos getters e setters dos atributos cor e preço:
public void setCor(String cor){
	this.cor = cor;
}

	public String getCor(){
		return this.cor;
}

public void setPreco(float preco){
	this.preco = preco;
}

	public float getPreco(){
		return this.preco;
}


// Criando do método imprimeDados()
public void imprimeDados(){
		System.out.println(“Peso: ” + this.getPeso());
System.out.println(“Cor: ” + this.getCor());
System.out.println(“Preço: ” + this.getPreco());
}

// Criando da classe Carro:
public class Carro extends Automovel{
int quantidadeDePortas;

public void setQuantidadeDePortas(int quantidadeDePortas){
	this.quantidadeDePortas = quantidadeDePortas;
}

		public int getQuantidadeDePortas(){
			return quantidadeDePortas;
}

public void imprimeDados(){
	super.imprimeDados();
	System.out.println("Quantidade de portas: " + this.getQuantidadeDePortas());
}
}


// Criando do objeto da classe Carro:
Carro carro = new Carro();


// Acessando os atributos da classe Carro
carro.setPeso(500);
carro.setCor(“Azul”);
carro.setPreco(25000);
carro.setPortas(4);
carro.imprimeDados();

// Saída do Console:
// Peso: 500.0
// Cor: Azul
// Preço: 25000.0
// Quantidade de portas: 4
