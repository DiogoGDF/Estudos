public abstract class Produto{
    double preco;
    int quantidade;
    long codigoDeBarras;
    public abstract double calculaPreco(double preco, double lucro);
}
