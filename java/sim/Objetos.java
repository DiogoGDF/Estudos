public class Objetos{
 public static void main(String args[]){
  char letras[][] = new char[2][3];
  letras[0][0] = 'a';
  letras[0][1] = 'b';
  letras[0][2] = 'c';
  letras[1][0] = 'd';
  letras[1][1] = 'e';
  letras[1][2] = 'f';
  for (int i = 0 ; i < 2 ; i++){
      for (int j = 0 ; j < 3; j++){
          System.out.println(letras[i][j]);
      }
  }


 }
}
