public class Fila {
    private final int[] elemento;
    private int inicio;
    private int fim;
    private int tamanho;

    public Fila(int tamanho) {
        this.elemento = new int[tamanho];
        this.inicio = 0;
        this.fim = 0;
        this.tamanho = 0;
    }

    public boolean isVazia() {
        return this.tamanho == 0;
    }

    public boolean isCheia() {
        return this.tamanho == this.elemento.length;
    }

    public int getTamanho() {
        return this.tamanho;
    }

    public int getElemento() {
        return this.elemento[this.inicio];
    }

    public void inserir(int elemento) {
        this.elemento[this.fim] = elemento;
        this.fim = (this.fim + 1) % this.elemento.length;
        this.tamanho++;
    }

    public int remover() {
        int numero = this.elemento[this.inicio];
        this.inicio = (this.inicio + 1) % this.elemento.length;
        this.tamanho--;
        return numero;
    }
}