package main;
public class Main {
    public static void main(String[] args) {
        Computador computador1 = new Computador();
        computador1.imprimir();
        System.out.println("\n");
        Computador computador2 = new Computador("Dell", "Integrada", "Intel Core i5", "16GB", "1TB");
        computador2.imprimir();
    }
}
class Computador{
    //atributos
    String marca, placaDeVideo, processador, memoriaRam, armazenamento;

//Sem parametros    
public Computador(){
    this.marca = "Asus";
    this.placaDeVideo = "Radeon Graphics";
    this.processador = "Ryzen 5";
    this.memoriaRam = "8GB";
    this.armazenamento = "256GB";
    }
//Com parametros
public Computador(String marca, String placaDeVideo, String processador, String memoriaRam, String armazenamento){
    this.marca = marca;
    this.placaDeVideo = placaDeVideo;
    this.processador = processador;
    this.memoriaRam = memoriaRam;
    this.armazenamento = armazenamento;
    }

    //get e set
    public String getMarca(){
        return marca;
    }
    public void setMarca(String marca){
        this.marca = marca;
    }
    
    public String getPlacaDeVideo(){
        return placaDeVideo;
    }
    public void setPlacaDeVideo(String placaDeVideo){
        this.placaDeVideo = placaDeVideo;
    }
    
    public String getProcessador(){
        return processador;
    }
    public void setProcessador(String processador){
        this.processador = processador;
    }
    
    public String getMemoriaRam(){
        return memoriaRam;
    }
    public void setMemoriaRam(String memoriaRam){
        this.memoriaRam = memoriaRam;
    }
    
    public String getArmazenamento(){
        return armazenamento;
    }
    public void setArmazenamento(String armazenamento){
        this.armazenamento = armazenamento;
    }
    
    //imprimir na tela
    public void imprimir(){
        System.out.println("Marca: " + marca);
        System.out.println("Placa de Video: " + placaDeVideo);
        System.out.println("Processador: " + processador);
        System.out.println("Memoria RAM: " + memoriaRam);
        System.out.println("Armazenamento: " + armazenamento);
    }
}
