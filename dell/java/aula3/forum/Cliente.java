public class Cliente{
    private String nome;
    private int cpf;
    private Animal animais[];

    public Cliente(String nome, int cpf){
        this.nome = nome;
        this.cpf = cpf;
        animais = new Animal[99];
    }

    public String getNome(){
        return nome;
    }
    public int getCpf(){
        return cpf;
    }
    public void setNome(String nome){
        this.nome = nome;
    }
    public void setCpf(int cpf){
        this.cpf = cpf;
    }

    public void novoAnimal(Animal novoAnimal){
        for(int i = 0; i < animais.length; i++){
            if(animais[i] == null){
                animais[i] = novoAnimal;
                break;
            }
        }
    }

}
