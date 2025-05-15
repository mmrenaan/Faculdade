import java.util.Scanner;
public class Computador {
    
    
    
    public static void main(String[] args) {
     Pc meuPc = new Pc();
     meuPc.imprimir();
    }
}

class Pc {
    //atributos
    String marca;
    String processador;
    int memoriaRam;
    int armazenamento;
    
    public Pc(){
    //solicitacao de dados ao usuario
    Scanner scanner = new Scanner(System.in);

        System.out.print("Digite a marca do computador: ");
        this.marca = scanner.nextLine();
        System.out.print("Digite o processador do computador: ");
        this.processador = scanner.nextLine();
        System.out.print("Digite a memoria RAM do seu computador: ");
        this.memoriaRam = scanner.nextInt();
        System.out.print("Digite o armazenamento do seu computador (em GB): ");
        this.armazenamento = scanner.nextInt();
    }
    //imprimir na tela
    public void imprimir() {
        System.out.println("Marca: " + marca);
        System.out.println("Processador: " + processador);
        System.out.println("Memoria RAM: " + memoriaRam + " GB");
        System.out.println("Armazenamento: " + armazenamento + " GB");
    }
}


