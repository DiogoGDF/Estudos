public class Computador extends Produto implements Autenticacao{

    public Computador(double preco, int quantidade, long codigoDeBarras){
        // super(preco, quantidade, codigoDeBarras);
        this.preco = preco;
        this.quantidade = quantidade;
        this.codigoDeBarras = codigoDeBarras;
    }

    @Override
    public double calculaPreco(double valorCompra, double valorLucro) {
        return valorCompra + valorLucro;
    }

    @Override
    public boolean autenticaCodigo(long codigo) {
        return (codigo == codigoDeBarras);
    }

}
