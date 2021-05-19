package pilha.pilha_dinamica_encadeada;

public Pilha<Elemento>
{
    private Nodo<Elemento> pilha;

    public Pilha()
    {
        this.pilha = null;
    }

    public void formatar()
    {
        this.pilha = null;
    }

    public int getTamanho()
    {
        int tamanho = 0;
        Nodo<Elemento> nodo = this.pilha;

        while (nodo != null)
        {
            nodo = nodo.getProximo();
            tamanho++;
        }

        return tamanho;
    }

    public boolean isVazia()
    {
        return this.pilha == null;
    }

    public void empilhar(Elemento elemento)
    {
        Nodo<Elemento> nodo = new Nodo<>(elemento, this.pilha);

        this.pilha = nodo;
    }

    public Elemento desempilhar()
    {
        Elemento elemento = this.pilha.getElemento();

        this.pilha = this.pilha.getProximo();

        return elemento;
    }

    public Elemento getElemento()
    {
        return this.pilha.getElemento();
    }

    public void setElemento(Elemento elemento)
    {
        this.pilha.setElemento(elemento);
    }
}