package lista.lista_dinamica_encadeada;

public class Lista<Elemento>
{
    Nodo<Elemento> lista;

    public Lista()
    {
        this.lista = null;
    }

    public void formatar()
    {
        this.lista = null;
    }

    public int getTamanho()
    {
        int tamanho = 0;
        Nodo<Elemento> nodo = this.lista;

        while (nodo != null)
        {
            nodo = nodo.getProximo();
            tamanho++;
        }

        return tamanho;
    }

    public boolean isVazia()
    {
        return this.lista == null;
    }

    public void adicionarInicio(Elemento elemento)
    {
        Nodo<Elemento> nodo = new Nodo<>(elemento, this.lista, null);

        this.lista = nodo;
    }

    public void adicionarPosicao(Elemento elemento, int posicao)
    {
        Nodo<Elemento> nodo;

        if (posicao == 1)
        {
            nodo = new Nodo<>(elemento, this.lista, null);
            this.lista = nodo;
        }
        else
        {
            Nodo<Elemento> auxiliar = this.lista;

            for (int i = 1; i < posicao; i++)
            {
                auxiliar = auxiliar.getProximo();
            }

            nodo = new Nodo<>(elemento, auxiliar, auxiliar.getAnterior());
            auxiliar = auxiliar.getAnterior();
            auxiliar.setProximo(nodo);
        }
    }

    public void adicionarFinal(Elemento elemento)
    {
        Nodo<Elemento> nodo;

        if (this.lista == null)
        {
            nodo = new Nodo<>(elemento, null, this.lista);
            this.lista = nodo;
        }
        else
        {
            Nodo<Elemento> auxiliar = this.lista;

            while (auxiliar.getProximo() != null)
            {
                auxiliar = auxiliar.getProximo();
            }

            nodo = new Nodo<>(elemento, null, auxiliar);
            auxiliar.setProximo(nodo);
        }
    }

    public Elemento removerInicio()
    {
        if (this.isVazia()) throw new ListaVaziaException();

        Elemento elemento = this.lista.getElemento();

        this.lista = this.lista.getProximo();
        this.lista.setAnterior(null);

        return elemento;
    }

    public Elemento removerPosicao(int posicao)
    {
        if (this.isVazia()) throw new ListaVaziaException();
        if (posicao < 1 || posicao > this.getTamanho()) throw new PosicaoInvalidaException();

        Elemento elemento;

        if (posicao == 1)
        {
            elemento = this.lista.getElemento();
            this.lista = this.lista.getProximo();
            this.lista.setAnterior(null);
        }
        else
        {
            Nodo<Elemento> auxiliar = this.lista;

            for (int i = 1; i < posicao; i++)
            {
                auxiliar = auxiliar.getProximo();
            }

            elemento = auxiliar.getElemento();
            auxiliar = auxiliar.getAnterior();
            auxiliar.setProximo((auxiliar.getProximo()).getProximo());
            auxiliar = auxiliar.getProximo();
            auxiliar.setAnterior((auxiliar.getAnterior()).getAnterior());
        }

        return elemento;
    }

    public Elemento removerFinal()
    {
        if (this.isVazia()) throw new ListaVaziaException();

        Elemento elemento;
        Nodo<Elemento> nodo = this.lista;

        if (nodo.getProximo() == null)
        {
            elemento = this.lista.getElemento();
            this.lista = this.lista.getProximo();
            this.lista.setAnterior(null);
        }
        else
        {
            while (nodo.getProximo() != null)
            {
                nodo = nodo.getProximo();
            }

            elemento = nodo.getElemento();
            nodo = nodo.getAnterior();
            nodo.setProximo(null);
        }

        return elemento;
    }

    public void setElementoInicio(Elemento elemento)
    {
        if (this.isVazia()) throw new ListaVaziaException();

        this.lista.setElemento(elemento);
    }

    public void setElementoPosicao(Elemento elemento, int posicao)
    {
        if (this.isVazia()) throw new ListaVaziaException();
        if (posicao < 1 || posicao > this.getTamanho()) throw new PosicaoInvalidaException();

        Nodo<Elemento> nodo = this.lista;

        for (int i = 1; i < posicao; i++)
        {
            nodo = nodo.getProximo();
        }

        nodo.setElemento(elemento);
    }

    public void setElementoFinal(Elemento elemento)
    {
        if (this.isVazia()) throw new ListaVaziaException();

        Nodo<Elemento> nodo = this.lista;

        while (nodo.getProximo() != null)
        {
            nodo = nodo.getProximo();
        }

        nodo.setElemento(elemento);
    }

    public Elemento getElementoInicio()
    {
        if (this.isVazia()) throw new ListaVaziaException();

        return this.lista.getElemento();
    }

    public Elemento getElementoPosicao(int posicao)
    {
        if (this.isVazia()) throw new ListaVaziaException();
        if (posicao < 1 || posicao > this.getTamanho()) throw new PosicaoInvalidaException();

        Nodo<Elemento> nodo = this.lista;

        for (int i = 1; i < posicao; i++)
        {
            nodo = nodo.getProximo();
        }

        return nodo.getElemento();
    }

    public Elemento getElementoFinal()
    {
        if (this.isVazia()) throw new ListaVaziaException();

        Nodo<Elemento> nodo = this.lista;

        while (nodo.getProximo() != null)
        {
            nodo = nodo.getProximo();
        }

        return nodo.getElemento();
    }
}