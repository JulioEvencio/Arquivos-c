package arvore.arvore_binaria;

class Nodo<Elemento>
{
    private int chave;
    private Elemento elemento;
    private Nodo<Elemento> pai;
    private Nodo<Elemento> esquerda;
    private Nodo<Elemento> direita;

    public Nodo(int chave, Elemento elemento, Nodo<Elemento> pai, Nodo<Elemento> esquerda, Nodo<Elemento> direita) {
        this.chave = chave;
        this.elemento = elemento;
        this.esquerda = esquerda;
        this.direita = direita;
        this.pai = pai;
    }

    public int getChave() {
        return chave;
    }

    public void setChave(int chave) {
        this.chave = chave;
    }

    public Elemento getElemento() {
        return elemento;
    }

    public void setElemento(Elemento elemento) {
        this.elemento = elemento;
    }

    public Nodo<Elemento> getPai() {
        return pai;
    }

    public void setPai(Nodo<Elemento> pai) {
        this.pai = pai;
    }

    public Nodo<Elemento> getEsquerda() {
        return esquerda;
    }

    public void setEsquerda(Nodo<Elemento> esquerda) {
        this.esquerda = esquerda;
    }

    public Nodo<Elemento> getDireita() {
        return direita;
    }

    public void setDireita(Nodo<Elemento> direita) {
        this.direita = direita;
    }
}