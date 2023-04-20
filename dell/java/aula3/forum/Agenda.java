public class Agenda{
    private Data horarios_marcados[];
    private Cliente cadastros[];
    // private Animal animais[];

    public Agenda(){
        horarios_marcados = new Data[999];
        cadastros = new Cliente[999];
    }

    // public void novoAnimal(Animal novoAnimal, Cliente dono){
    //     for(int i = 0; i < animais.length; i++){
    //         if(animais[i] == null){
    //             animais[i] = novoAnimal;
    //         }
    //     }
    // }

    public void novoCadastro(Cliente novoCliente){
        for(int i = 0; i < cadastros.length; i++){
            if(cadastros[i].getCpf() = novoCliente.getCpf()){
                // System.out.println("Cliente já registrado!");
                break;
            }
            else if(cadastros[i] == null){
                cadastros[i] = novoCliente;
                break;
            }
        }
    }
    public void novoHorario(Data data){
        // novoAnimal(data.animal);
        novoCadastro(data.Cliente);
        for(int i = 0; i < horarios_marcados.length; i++){
            if(horarios_marcados[i].getDia() == data.getDia()){
                if(horarios_marcados[i].getMes() == data.getMes()){
                    if(horarios_marcados[i].getAno == data.getAno()){
                        if(horarios_marcados[i].getHora == data.getHora()){
                            System.out.println("Horário já reservado!");
                            break;
                        }
                    }
                }
            }
            else if(horarios_marcados[i] == null){
                horarios_marcados[i] = data;
                break;
            }
        }
    }
}
