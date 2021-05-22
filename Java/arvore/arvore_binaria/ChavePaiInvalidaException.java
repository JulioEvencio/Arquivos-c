package arvore.arvore_binaria;

public class ChavePaiInvalidaException extends RuntimeException {
    public ChavePaiInvalidaException() {
    }
    public ChavePaiInvalidaException(String message) {
        super(message);
    }
}