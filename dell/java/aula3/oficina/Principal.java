public class Principal{
    public static void main(String[] args) {
      Aluno alunoLead = new Aluno("Diogo", 950, 10.0, 10.0);
      System.out.println(alunoLead.nome);
      System.out.println(alunoLead.codigo);
      System.out.println(alunoLead.nota1);
      System.out.println(alunoLead.nota2);

      NovoAluno aluno2 = new NovoAluno();
      aluno2.setNome("João");
      aluno2.setCodigo(355);
      aluno2.setNota1(10.0);
      aluno2.setNota2(9.5);
      System.out.println(aluno2.getNome());
      System.out.println(aluno2.getCodigo());
      System.out.println(aluno2.getNota1());
      System.out.println(aluno2.getNota2());
      System.out.println("Media: " + aluno2.media());
   }
}
