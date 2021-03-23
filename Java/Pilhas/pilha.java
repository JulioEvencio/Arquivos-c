public class Pilha {
    private final int[] elemento;
    private int tamanho;

    public Pilha(int tamanho) {
        this.elemento = new int[tamanho];
        this.tamanho = 0;
    }
}