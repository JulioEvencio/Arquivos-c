package arvore.arvore_binaria;

class Nodo<Elemento>
{
    private int chave;
    private Elemento elemento;
    private Nodo<Elemento> esquerda;
    private Nodo<Elemento> direita;

    public Nodo(int chave, Elemento elemento, Nodo<Elemento> esquerda, Nodo<Elemento> direita)
    {
        this.chave = chave;
        this.elemento = elemento;
        this.esquerda = esquerda;
        this.direita = direita;
    }

    public int getChave()
    {
        return this.chave;
    }

    public void setChave(int chave)
    {
        this.chave = chave;
    }

    public Elemento getElemento()
    {
        return this.elemento;
    }

    public void setElemento(Elemento elemento)
    {
        this.elemento = elemento;
    }

    public Nodo<Elemento> getEsquerda()
    {
        return this.esquerda;
    }

    public void setEsquerda(Nodo<Elemento> nodo)
    {
        this.esquerda = nodo;
    }

    public Nodo<Elemento> getDireita()
    {
        return this.direita;
    }

    public void setDireita(Nodo<Elemento> nodo)
    {
        this.direita = nodo;
    }
}