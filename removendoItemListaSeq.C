#include <stdlib.h>
#include <iostream>
using namespace std;

struct Lista
{
    int valores[50];
    int tamanho;
};

void InicializarLista(Lista *lista)
{
    lista->tamanho = 0;
}

bool InserirValorNaLista(Lista *lista, int valor)
{
    if (lista->tamanho < 50)
    {
        lista->valores[lista->tamanho] = valor;
        lista->tamanho++;
        return true;
    }
    else
    {
        printf("Tamanho maximo atingido!!");
        return false;
    }
}

int PegarPosicaoItem(Lista *lista, int valorProcurado)
{
    if (lista->tamanho > 0)
    {
        for (int i = 0; i < lista->tamanho; i++)
        {
            if (lista->valores[i] == valorProcurado)
            {
                return i;
            }
        }
        printf("Nenhum valor encontrado!!");
        return 0;
    }
    else
    {
        printf("Insira pelo menos um valor");
        return 0;
    }
}

bool RemovendoItemLista(Lista *lista, int valorParaRetirar)
{
    if (lista->tamanho > 0)
    {
        int indice = PegarPosicaoItem(lista, valorParaRetirar);
        int ultimaPosicao = lista->tamanho - 1;
        lista->valores[indice] = lista->valores[ultimaPosicao];
        lista->tamanho--;
        return true;
    }
    else
    {
        printf("Nao e possivel retirar um item de uma lista vazia");
        return false;
    }
}

void ImprimindoValores(Lista *lista)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("valor: %d \n", lista->valores[i]);
    }
}

int PegarInteiroDigitado()
{
    int valor;
    cin >> valor;
    return valor;
}

void ColocarValoresRecursivos(Lista *lista, int quantidadeDeItens)
{
    for (int i = 0; i < quantidadeDeItens; i++)
    {
        printf("Insira um valor: ");
        InserirValorNaLista(lista, PegarInteiroDigitado());
    }
}

int main()
{
    struct Lista listaDeValores;
    InicializarLista(&listaDeValores);
    ColocarValoresRecursivos(&listaDeValores, 4);

    printf("Informe um valor para buscar sua posicao: ");
    printf("indice: %d \n", PegarPosicaoItem(&listaDeValores, PegarInteiroDigitado()));

    printf("Informe um valor para ser retirado da lista: ");
    printf("foi retirado? : %d \n", RemovendoItemLista(&listaDeValores, PegarInteiroDigitado()));

    ImprimindoValores(&listaDeValores);

    return 0;
}