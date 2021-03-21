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
	
}