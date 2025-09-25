public class Computadora {
    //atributos
    private String marca;
    private String modelo;
    private float memoria;
    private String estado; //nueva, usada, no sirve, muy vieja
    private String sistemaOperativo;

    //constructor
    public Computadora(String marca, String modelo, float memoria, String estado,String sistemaOperativo){
        setMarca(marca);
        setModelo(modelo);
        setMemoria(memoria);
        setEstado(estado);
        setSistemaOperativo(sistemaOperativo);
    }

    //getters y setters
    public String getMarca(){
        return marca;
    }

    public void setMarca(String marca){
        this.marca=marca;
    }

    public String getModelo(){
        return modelo;
    }

    public void setModelo(String modelo){
        this.modelo=modelo;
    }

    public float getMemoria(){
        return memoria;
    }

    public void setMemoria(float memoria){
        this.memoria=memoria;
    }

    public String getEstado(){
        return estado;
    }

    public void setEstado(String estado){
        this.estado=estado;
    }

    public String getSistemaOperativo(){
        return sistemaOperativo;
    }

    public void setSistemaOperativo(String sistemaOperativo){
        this.sistemaOperativo=sistemaOperativo;
    }
}
