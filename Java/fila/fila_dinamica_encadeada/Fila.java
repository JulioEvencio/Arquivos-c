package fila.fila_dinamica_encadeada;

public Fila<Elemento>
{
    private Nodo<Elemento> fila;

    public Fila()
    {
        this.fila = null;
    }

    public void formatar()
    {
        this.fila = null;
    }

    public int getTamanho()
    {
        int tamanho = 0;
        Nodo<Elemento> nodo = this.fila;

        while (nodo != null)
        {
            nodo = nodo.getProximo();
            tamanho++;
        }

        return tamanho;
    }

    public boolean isVazia()
    {
        return this.fila == null;
    }

    public void adicionar(Elemento elemento)
    {
        Nodo<Elemento> nodo = new Nodo<>(elemento, null);

        if (this.fila == null)
        {
            this.fila = nodo;
        }
        else
        {
            Nodo<Elemento> auxiliar = this.fila;

            while (auxiliar.getProximo() != null)
            {
                auxiliar = auxiliar.getProximo();
            }

            auxiliar.setProximo(nodo);
        }
    }

    public Elemento remover()
    {
        Elemento elemento = this.fila.getElemento();

        this.fila = this.fila.getProximo();

        return elemento;
    }

    public Elemento getElemento()
    {
        return this.fila.getElemento();
    }

    public void setElemento(Elemento elemento)
    {
        this.fila.setElemento(elemento);
    }
}