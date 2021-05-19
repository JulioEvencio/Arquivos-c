package arvore.arvore_binaria;

public Arvore<Elemento>
{
    private Nodo<Elemento> arvore;

    public Arvore()
    {
        this.arvore = null;
    }

    public void formatar()
    {
        this.arvore = null;
    }

    public int getNodosQuantidade()
    {
        int quantidade = 0;
        Nodo<Elemento> nodo = this.arvore;

        if (nodo != null)
        {
            quantidade++;
            quantidade += this.getNodosQuantidade(nodo.getEsquerda());
            quantidade += this.getNodosQuantidade(nodo.getDireita());
        }

        return quantidade;
    }

    private int getNodosQuantidade(Nodo<Elemento> nodo)
    {
        int quantidade = 0;

        if (nodo != null)
        {
            quantidade++;
            quantidade += this.getNodosQuantidade(nodo.getEsquerda());
            quantidade += this.getNodosQuantidade(nodo.getDireita());
        }

        return quantidade;
    }

    public boolean isVazia()
    {
        return this.arvore == null;
    }

    private Nodo<Elemento> getNodo(Nodo<Elemento> nodo, int chave)
    {
        Nodo<Elemento> esquerda = null, direita = null;

        if (nodo.getChave() == chave)
        {
            return nodo;
        }

        if (nodo.getEsquerda() != null)
        {
            esquerda = this.getNodo(nodo.getEsquerda(), chave);
        }

        if (esquerda == null)
        {
            if (nodo.getDireita() != null)
            {
                direita = this.getNodo(nodo.getDireita, chave);
            }
            return direita;
        }

        return esquerda;
    }

    private Nodo<Elemento> getNodoPai(Nodo<Elemento> nodo, int chave)
    {
        Nodo<Elemento> nodoPai = null;

        if (nodo.getChave == chave) return nodo;

        Nodo<Elemento> esquerda = nodo.getEsquerda();
        Nodo<Elemento> direita = nodo.getDireita();

        if (esquerda != null)
        {
            if (esquerda.getChave() == chave)
            {
                return esquerda;
            }
            else
            {
                nodoPai = this.getNodo(esquerda, chave);
            }
        }

        if (nodoPai == null)
        {
            if (direita != null)
            {
                if (direita.getChave() == chave)
                {
                    return direita;
                }
                else
                {
                    nodoPai = this.getNodo(direita, chave);
                }
            }
        }

        return nodoPai;
    }

    public void criarRaiz(int chave, Elemento elemento)
    {
        this.arvore = new Nodo<>(chave, elemento, null, null);
    }

    public void adicionarEsquerda(int chave_pai, int chave, Elemento elemento)
    {
        Nodo<Elemento> nodoPai = null, nodoFilho = null;

        if (this.arvore == null) return;

        pai = this.getNodo(this.arvore, chave_pai);

        if (pai == null) return;

        if (pai.getEsquerda != null) return;

        nodoFilho = new Nodo<>(chave, elemento, null, null);
        nodoPai.setEsquerda(nodoFilho);
    }

    public void adicionarDireita(int chave_pai, int chave, Elemento elemento)
    {
        Nodo<Elemento> nodoPai = null, nodoFilho = null;

        if (this.arvore == null) return;

        pai = this.getNodo(this.arvore, chave_pai);

        if (pai == null) return;

        if (pai.getDireita != null) return;

        nodoFilho = new Nodo<>(chave, elemento, null, null);
        nodoPai.setDireita(nodoFilho);
    }

    public Elemento remover(int chave)
    {
        Elemento elemento = null;

        if (this.arvore == null) return;

        if (this.arvore.getChave() == chave)
        {
            elemento = this.arvore.getElemento();
            this.arvore = null;
        }
        else
        {
            Nodo<Elemento> nodoPai = this.getNodoPai(this.arvore, int chave);

            if (nodoPai == null) return null;

            Nodo<Elemento> esquerda = nodoPai.getEsquerda();
            Nodo<Elemento> direita = nodoPai.getDireita();

            if (esquerda != null)
            {
                if (esquerda.getChave() == chave)
                {
                    elemento = esquerda.getElemento();
                    nodoPai.setEsquerda = null;
                }
            }

            if (direita != null)
            {
                if (direita.getChave() == chave)
                {
                    elemento = direita.getElemento();
                    nodoPai.setDireita = null;
                }
            }
        }

        return elemento;
    }

    public Elemento getElemento(int chave)
    {
        Nodo<Elemento> nodo = this.getNodo(this.arvore, chave);

        if (nodo == null) return null;

        return nodo.getElemento();
    }

    public void setElemento(int chave)
    {
        Nodo<Elemento> nodo = this.getNodo(this.arvore, chave);

        if (nodo == null) return null;

        return nodo.setElemento();
    }
}