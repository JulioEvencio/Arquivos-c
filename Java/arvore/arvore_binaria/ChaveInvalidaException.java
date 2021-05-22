package arvore.arvore_binaria;

public class ChaveInvalidaException extends RuntimeException {
    public ChaveInvalidaException() {
    }
    public ChaveInvalidaException(String message) {
        super(message);
    }
}