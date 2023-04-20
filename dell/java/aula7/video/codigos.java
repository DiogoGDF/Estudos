// Criando a classe Operacao:
public abstract class Operacao {
    public abstract double calcular(double x, double y);
}

// Criando a classe Soma:
public class Soma extends Operacao {
    public double calcular(double x, double y) {
        return x + y ;
    }
}


// Implementando o método calcular() da classe Divisao:
public class Divisao extends Operacao {
    public double calcular(double x, double y) {
        return x / y ;
    }
}

// Implementando a classe Principal:
public class Principal {
    public static void mostrarCalculo(Operacao operacao, double x, double y) {
        System.out.println("O resultado é: " + operacao.calcular(x, y));
    }

    public static void main(String args[]) {
        Principal.mostrarCalculo(new Soma(), 3, 2);
        Principal.mostrarCalculo(new Divisao(), 16, 2);
    }
}

// Saída no Console:
// O resultado é: 5.0
// O resultado é: 8.0
