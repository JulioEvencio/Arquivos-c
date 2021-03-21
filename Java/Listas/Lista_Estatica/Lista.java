public class Lista {
	
	private final int[] elemento;
	private int tamanho;
	
	public Lista(int tamanho) {
		this.elemento = new int[tamanho];
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
	
	public int getElemento(int posicao) {
        return this.elemento[posicao - 1];
    }
	
	public void inserirNoIncio(int elemento) {
        for(int i = this.tamanho; i > 0; i--) {
            this.elemento[i] = this.elemento[i - 1];
        }
        this.elemento[0] = elemento;
        this.tamanho++;
    }
	
	public void inserirNaPosicao(int posicao, int elemento) {
        for(int i = this.tamanho; i > (posicao - 1); i--) {
            this.elemento[i] = this.elemento[i - 1];
        }
        this.elemento[posicao - 1] = elemento;
        this.tamanho++;
    }
	
	public void inserirNoFinal(int elemento) {
        this.elemento[this.tamanho] = elemento;
        this.tamanho++;
    }
	
	public int removerNoInicio() {
        int numero = this.elemento[0];
        for(int i = 0; i < this.tamanho; i++) {
            this.elemento[i] = this.elemento[i + 1];
        }
        this.tamanho--;
        return numero;
    }
	
}