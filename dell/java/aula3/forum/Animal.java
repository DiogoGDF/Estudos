public class Animal{
    private String nome;
    private String especie;
    private String[] sintomas;

    public Animal(String nome, String especie, String[] sintomas){
        this.nome = nome;
        this.especie = especie;
        this.sintomas = sintomas;
    }

    public String getNome(){
        return nome;
    }
    public String getEspecie(){
        return especie;
    }
    public String[] getSintomas(){
        return sintomas;
    }
    public void setNome(String nome){
        this.nome = nome;
    }
    public void set(String especie){
        this.especie = especie;
    }
    public void set(String[] sintomas){
        this.sintomas = sintomas;
    }


}
