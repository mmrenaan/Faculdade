package porto;
import java.util.Scanner;
public class Porto {

    public static void main(String[] args) {
        
        Aviao aviao = new Aviao();
        aviao.imprimir();
        Aviao aviao1 = new Aviao();
        aviao1.imprimir();
        
        Navio navio = new Navio();
        navio.imprimir();
        Navio navio1 = new Navio();
        navio1.imprimir();
        Navio navio2 = new Navio();
        navio2.imprimir();
        Navio navio3 = new Navio();
        navio3.imprimir();
        Navio navio4 = new Navio();
        navio4.imprimir();
    }
    
}

class Transporte{
    
    protected int capacidadeTanque;
    protected int numeroPassageiros;
    protected float preco;
    
    protected int getCapacidadeTanque(){
        return capacidadeTanque;
    }
    protected void setCapacidadeTanque(int capacidadeTanque){
        this.capacidadeTanque = capacidadeTanque;
    }
    
    protected int getNumeroPassageiros(){
        return numeroPassageiros;
    }
    protected void setNumeroPassageiros(int numeroPassageiros){
        this.numeroPassageiros = numeroPassageiros;  
    }
    
    protected float getPreco(){
        return preco;
    }
    protected void setPreco(float preco){
        this.preco = preco;
    }
}
    
class Aviao extends Transporte{
    
    protected String prefixo;
    protected String dataRevisao;
    protected int reajustarPreco;
    protected float novoPreco;
    
    public Aviao(){
    
    Scanner scanner = new Scanner(System.in);
    
        System.out.println("Digite o prefixo do aviao: ");
        this.prefixo = scanner.nextLine();
        System.out.println("Digite a data de revisao do aviao: ");
        this.dataRevisao = scanner.nextLine();
        System.out.println("Digite a capacidade do tanque do aviao: ");
        this.capacidadeTanque = scanner.nextInt();
        System.out.println("Digite o numero de passageiros do aviao: ");
        this.numeroPassageiros = scanner.nextInt();
        System.out.println("Digite o valor do aviao (em reais): ");
        this.preco = scanner.nextFloat();
        System.out.println("Qual a porcentagem de reajuste de preco?: ");
        this.reajustarPreco = scanner.nextInt();
        novoPreco = preco+(preco*reajustarPreco/100);
    }
    
    protected String getPrefixo(){
        return prefixo;
    }
    protected void setPrefixo(String prefixo){
        this.prefixo = prefixo;
    }
    
    protected String getDataRevisao(){
        return dataRevisao;
    }
    protected void setDataRevisao(String dataRevisao){
        this.dataRevisao = dataRevisao;
    }
    
    public void imprimir(){
        System.out.println("Prefixo do aviao: " + prefixo);
        System.out.println("Data de revisao: " + dataRevisao);
        System.out.println("Capacidade do tanque: " + capacidadeTanque + "Litros");
        System.out.println("Numero de passageiros: " + numeroPassageiros);
        System.out.println("Valor: " + novoPreco + " Reais");
    }
}

class Navio extends Transporte{
    
    protected String nome;
    protected int numeroTripulantes;
    protected String dataLancamento;
    
    
    public Navio() {
        
    Scanner scanner = new Scanner(System.in);
        
        System.out.println("Digite o nome do navio: ");
        this.nome = scanner.nextLine();
        System.out.println("Digite o numero de tripulantes do navio: ");
        this.numeroTripulantes = scanner.nextInt();
        System.out.println("Digite a data de lancamento do navio: ");
        this.dataLancamento = scanner.nextLine();
        System.out.println("Digite a capacidade do tanque do navio: ");
        this.capacidadeTanque = scanner.nextInt();
        System.out.println("Digite o numero de passageiros do navio: ");
        this.numeroPassageiros = scanner.nextInt();
        System.out.println("Digite o valor do navio (em reais): ");
        this.preco = scanner.nextFloat();
        
    }
    protected String getNome(){
        return nome;
    }
    protected void setNome(String nome){
        this.nome = nome;
    }   
    
    protected int getNumeroTripulantes(){
        return numeroTripulantes;
    }
    protected void setNumeroTripulantes(int numeroTripulantes){
        this.numeroTripulantes = numeroTripulantes;  
    }   
    
    protected String getDataLancamento(){
        return dataLancamento;
    }
    protected void setDataLancamento(String dataLancamento){
        this.dataLancamento = dataLancamento;
    }
    
    public void imprimir(){
        System.out.println("Nome do navio: " + nome);
        System.out.println("Numero de tripulantes: " + numeroTripulantes);
        System.out.println("Data de lancamento: " + dataLancamento);
        System.out.println("Capacidade do tanque: " + capacidadeTanque + "Litros");
        System.out.println("Numero de passageiros: " + numeroPassageiros);
        System.out.println("Valor: " + preco + "Reais");
        System.out.println("Divisao de passageiros por tripulantes: " + (numeroPassageiros/numeroTripulantes));
    }
}