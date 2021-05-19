package lista.lista_dinamica_encadeada;

public Lista<Elemento>
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
        Noo<Elemento> nodo = this.lista;

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
        Nodo<Elemento> nodo = new Nodo<>(elemento, this.lista);

        this.lista = nodo;
    }

    public void adicionarPosicao(Elemento elemento, int posicao)
    {
        Nodo<Elemento> nodo;

        if (posicao == 1)
        {
            nodo = new Nodo<>(Elemento, this.lista);
            this.lista = nodo;
        }
        else
        {
            Nodo<Elemento> nodo_anterior = null, nodo_atual = this.lista;

            for (int i = 1; i < posicao; i++)
            {
                nodo_anterior = nodo_atual;
                nodo_atual = nodo_atual.getProximo();
            }

            nodo_anterior.getProximo(nodo);
            nodo = new Nodo<>(Elemento, nodo_atual);
        }
    }

    public void adicionarFinal(Elemento elemento)
    {
        Nodo<Elemento> nodo = new Nodo<>(Elemento, null);

        if (this.lista == null)
        {
            this.lista = nodo;
        }
        else
        {
            Nodo<Elemento> auxiliar = this.lista;

            while (auxiliar.getProximo() != null)
            {
                auxiliar = auxiliar.getProximo();
            }

            auxiliar.setProximo(nodo);
        }
    }

    public Elemento removerInicio()
    {
        Elemento elemento = this.lista.getElemento();

        this.lista = this.lista.getProximo();

        return elemento;
    }

    public Elemento removerPosicao(int posicao)
    {
        Elemento elemento = null;

        if (posicao == 1)
        {
            elemento = this.lista.getElemento();
            this.lista = this.lista.getProximo();
        }
        else
        {
            Nodo<Elemento> auxiliar = null, nodo = this.lista;

            for (int i = 1; i < posicao; i++)
            {
                auxiliar = nodo;
                nodo = nodo.getProximo();
            }

            elemento = nodo.getElemento();
            auxiliar.setProximo(nodo.getProximo());
        }

        return elemento;
    }

    public Elemento removerFinal()
    {
        Elemento elemento = null;
        Nodo<Elemento> nodo = this.lista;

        if (this.lista.getProximo() == null)
        {
            elemento = this.lista.getElemento();
            this.lista = this.lista.getProximo();
        }
        else
        {
            Nodo<Elemento> auxiliar = null;

            while (nodo.getProximo() != null)
            {
                auxiliar = nodo;
                nodo = nodo.getProximo();
            }

            elemento = nodo.getElemento();
            auxiliar.setProximo(nodo.getProximo());
        }
    }

    public void setElementoInicio(Elemento elemento)
    {
        this.lista.setElemento(elemento);
    }

    public void setElementoPosicao(Elemento elemento, int posicao)
    {
        Nodo<Elemento> nodo = this.lista;

        for (int i = 1; i < posicao; i++)
        {
            nodo = nodo.getProximo();
        }

        nodo.setElemento(elemento);
    }

    public void setElementoFinal(Elemento elemento)
    {
        Nodo<Elemento> nodo = this.lista;

        while (nodo.getProximo() != null)
        {
            nodo = nodo.getProximo();
        }

        nodo.setElemento(elemento);
    }

    public Elemento getElementoInicio()
    {
        return this.lista.getElemento();
    }

    public Elemento getElementoPosicao(int posicao)
    {
        Nodo<Elemento> nodo = this.lista;

        for (int i = 1; i < posicao; i++)
        {
            nodo = nodo.getProximo();
        }

        return nodo.getElemento();
    }

    public Elemento getElementoFinal()
    {
        Nodo<Elemento> nodo = this.lista;

        while (nodo.getProximo() != null)
        {
            nodo = nodo.getProximo();
        }

        return nodo.getElemento();
    }
}