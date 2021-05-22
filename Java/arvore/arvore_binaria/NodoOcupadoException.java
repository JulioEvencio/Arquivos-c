package arvore.arvore_binaria;

public class NodoOcupadoException extends RuntimeException {
    public NodoOcupadoException() {
    }
    public NodoOcupadoException(String message) {
        super(message);
    }
}