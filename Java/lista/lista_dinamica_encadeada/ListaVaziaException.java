package lista.lista_dinamica_encadeada;

public class ListaVaziaException extends RuntimeException {
    public ListaVaziaException() {
    }
    public ListaVaziaException(String message) {
        super(message);
    }
}