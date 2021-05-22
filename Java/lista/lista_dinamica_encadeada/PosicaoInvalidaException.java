package lista.lista_dinamica_encadeada;

public class PosicaoInvalidaException extends RuntimeException {
    public PosicaoInvalidaException() {
    }
    public PosicaoInvalidaException(String message) {
        super(message);
    }
}