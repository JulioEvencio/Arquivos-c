package lista.lista_dinamica_encadeada;

class Nodo<Elemento>
{
    private Elemento elemento;
    private Nodo<Elemento> proximo;
    private Nodo<Elemento> anterior;

    public Nodo(Elemento elemento, Nodo<Elemento> proximo, Nodo<Elemento> anterior)
    {
        this.elemento = elemento;
        this.proximo = proximo;
        this.anterior = anterior;
    }

    public Elemento getElemento()
    {
        return elemento;
    }

    public void setElemento(Elemento elemento)
    {
        this.elemento = elemento;
    }

    public Nodo<Elemento> getProximo()
    {
        return proximo;
    }

    public void setProximo(Nodo<Elemento> proximo)
    {
        this.proximo = proximo;
    }

    public Nodo<Elemento> getAnterior()
    {
        return anterior;
    }

    public void setAnterior(Nodo<Elemento> anterior)
    {
        this.anterior = anterior;
    }
}