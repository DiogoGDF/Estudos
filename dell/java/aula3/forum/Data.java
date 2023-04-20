public class Data{
    private int dia;
    private int mes;
    private int ano;
    private int hora;
    private Cliente cliente;
    private Animal animal;

    public Data(int dia, int mes, int ano, int hora, Cliente cliente, Animal animal){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
        this.hora = hora;
        this.cliente = cliente;
        this.animal = animal;
    }

    public void remarcarConsulta(int dia, int mes, int ano, int horario){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
        this.hora = hora;
    }

    public int getDia(){
        return dia;
    }
    public int getMes(){
        return mes;
    }
    public int getAno(){
        return ano;
    }
    public int getHora(){
        return hora;
    }
    public Cliente getCliente(){
        return cliente;
    }
    public Animal getAnimal(){
        return animal;
    }
    public void setDia(int dia){
        this.dia = dia;
    }
    public void setMes(int mes){
        this.mes = mes;
    }
    public void setAno(int ano){
        this.ano = ano;
    }
    public void setHora(int hora){
        this.hora = hora;
    }
    public void setCliente(Cliente cliente){
        this.cliente = cliente;
    }
    public void setAnimal(Animal animal){
        this.animal = animal;
    }
}
