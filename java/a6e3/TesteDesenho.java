public class TesteDesenho {
    public static void main(String[ ] args) {

        Desenhavel [ ] listaDesenhos = new Desenhavel [10];

        listaDesenhos[0] = new Triangulo(2, 10, 8);
        listaDesenhos[1] = new Triangulo(5, 20, 15);
        listaDesenhos[2] = new Pentagono(25, 30, 50, 50 ,20);
        listaDesenhos[3] = new Pentagono(2, 3, 7 ,2 1);
        //...
        listaDesenhos [9] = new Triangulo(10, 20, 30);

        for(int i = 0; i < listaDesenhos.length; i++) {
            listaDesenhos[i].desenhar();
        }
    }
}
