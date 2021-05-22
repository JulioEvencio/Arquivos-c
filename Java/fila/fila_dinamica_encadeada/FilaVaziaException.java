package fila.fila_dinamica_encadeada;

public class FilaVaziaException extends RuntimeException {
    public FilaVaziaException() {
    }

    public FilaVaziaException(String message) {
        super(message);
    }
}