#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct InformacoesPacientes
{
    // Guarda o código id do registro do paciente
    int idPaciente;
    char nomePaciente[40];
    char sexoPaciente;
    int idadePaciente;
    char pesoPaciente[8];
    float alturaPaciente;
    char telefonePaciente[14];
} Informacoes;

// Declaração de structs
// Ponteiro de nó de lista
typedef struct NoLista *PtrNoLista;

//  Nó de lista (Paciente)
typedef struct NoLista
{
    Informacoes dados;
    PtrNoLista proximo;
    PtrNoLista anterior;
} NoLista;

//  Lista Duplamente Ordenada Circular sem sentinela (Clínica)
typedef struct
{
    PtrNoLista inicio;
    PtrNoLista fim;
} ListaClinica;

//----------------------------------------------
//----------------------------------------------

// Função que inicializa a lista
void iniciaListaClinica(ListaClinica *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
}

// Função que retorna se a lista está vazia ou não
bool estaVaziaListaClinica(ListaClinica *lista)
{
    return (lista->inicio == NULL);
}

// Função que separa as informações coletadas da linha do arquivo de entrada
void separaConteudo(PtrNoLista paciente, char conteudo[100])
{
    // Declarando variáveis que recebem as informações do arquivo
    int i, k = 0;
    int num = 0;
    char aux[10] = {};
    char nome[40] = {};
    char sexo;
    int idade = 0;
    char auxIdade[5] = {};
    char peso[8] = {};
    char alturac[10] = {};
    double alturad;
    char telefone[15] = {};

    int dadoNum = 1;
    for (i = 0; i < strlen(conteudo); i++)
    {
        // Numerando os dados de acordo com a posição na linha
        if (dadoNum == 1)
        {
            // Buscando o id do paciente na linha, transformando de string para inteiro e atribuindo à struct InformaçõesPacientes da lista
            if (conteudo[i] >= 48 && conteudo[i] <= 57)
            {
                aux[k] = conteudo[i];
                if (num != 0)
                {
                    num += (aux[k] - '0');
                }
                else
                {
                    num = (aux[k] - '0');
                }
                num *= 10;
                k++;
            }
            else if (conteudo[i] == ',')
            {
                num /= 10;
                paciente->dados.idPaciente = num;
                dadoNum++;
            }
        }
        // Buscando o nome do paciente na linha e atribuindo à struct InformaçõesPacientes da lista
        else if (dadoNum == 2)
        {
            if (!(conteudo[i] == ','))
            {
                nome[strlen(nome)] = conteudo[i];
            }
            else
            {
                strcpy(paciente->dados.nomePaciente, nome);
                dadoNum++;
            }
        }
        // Buscando o sexo do paciente na linha e atribuindo à struct InformaçõesPacientes da lista
        else if (dadoNum == 3)
        {
            if (!(conteudo[i] == ','))
            {
                sexo = conteudo[i];
            }
            else
            {
                paciente->dados.sexoPaciente = sexo;
                dadoNum++;
            }
        }
        // Buscando a idade do paciente na linha, transformando de string para inteiro e atribuindo à struct InformaçõesPacientes da lista
        else if (dadoNum == 4)
        {
            if (conteudo[i] >= 48 && conteudo[i] <= 57)
            {
                auxIdade[k] = conteudo[i];
                if (idade != 0)
                {
                    idade += (auxIdade[k] - '0');
                }
                else
                {
                    idade = (auxIdade[k] - '0');
                }
                idade *= 10;
                k++;
            }
            else if (conteudo[i] == ',')
            {
                idade /= 10;
                paciente->dados.idadePaciente = idade;
                dadoNum++;
            }
        }
        // Buscando o peso do paciente na linha e atribuindo à struct InformaçõesPacientes da lista
        else if (dadoNum == 5)
        {
            if (!(conteudo[i] == ','))
            {
                peso[strlen(peso)] = conteudo[i];
            }
            else
            {
                strcpy(paciente->dados.pesoPaciente, peso);
                dadoNum++;
            }
        }
        // Buscando a altura do paciente na linha, transformando de string para float e atribuindo à struct InformaçõesPacientes da lista
        else if (dadoNum == 6)
        {
            if (!(conteudo[i] == ','))
            {
                alturac[strlen(alturac)] = conteudo[i];
            }
            else
            {
                char *nptr = &alturac;
                alturad = atof(nptr);
                paciente->dados.alturaPaciente = alturad;
                dadoNum++;
            }
        }
        // Buscando o telefone do paciente na linha e atribuindo à struct InformaçõesPacientes da lista
        else if (dadoNum == 7)
        {
            if (!(conteudo[i] == '}'))
            {
                telefone[strlen(telefone)] = conteudo[i];
            }
            else
            {
                strcpy(paciente->dados.telefonePaciente, telefone);
                dadoNum++;
            }
        }
    }
}

// Função para inserção de valores na lista de forma ordenada
void inserirListaOrdenada(ListaClinica *lista, char conteudo[100])
{
    // Alocação dinâmica da lista
    PtrNoLista novo = malloc(sizeof(NoLista));
    separaConteudo(novo, conteudo);

    // Inserção caso a lista esteja vazia
    if (estaVaziaListaClinica(lista))
    {
        // Início da lista recebe o novo
        lista->inicio = novo;
        // Fim da lista também recebe novo porque a lista estava vazia
        lista->fim = novo;
        // Próximo do novo aponta para ele mesmo
        novo->proximo = novo;
        // Anterior do novo aponta para ele mesmo também
        novo->anterior = novo;

        // Inserção caso o elemento a ser inserido seja menor que o inicial
    }
    else if (novo->dados.idPaciente < lista->inicio->dados.idPaciente)
    {
        // Novo se torna o início da lista
        novo->proximo = lista->inicio;
        // Anterior do novo aponta o fim da lista
        novo->anterior = lista->fim;
        // O anterior do início aponta para novo
        novo->proximo->anterior = novo;
        // Início da lista recebe o novo elemento
        lista->inicio = novo;
        // Próximo do fim da lista aponta para o novo
        lista->fim->proximo = novo;

        // Inserção caso o elemento a ser inserido seja maior que o final
    }
    else if (novo->dados.idPaciente > lista->fim->dados.idPaciente)
    {
        // Anterior do novo aponta para o fim da lista
        novo->anterior = lista->fim;
        // Próximo do novo aponta para o início da lista
        novo->proximo = lista->inicio;
        // Próximo do fim da lista aponta para o novo
        lista->fim->proximo = novo;
        // Fim da lista recebe o novo
        lista->fim = novo;

        // 	Inserção caso o elemento seja inserido no meio da lista (entre o início e o fim)
    }
    else
    {
        PtrNoLista aux = lista->inicio;
        // Verifica se o valor a ser inserido é maior que o código id na lista
        while (aux->proximo != NULL && novo->dados.idPaciente > aux->proximo->dados.idPaciente)
        {
            // Caso seja maior, guarda o próximo elemento da lista
            aux = aux->proximo;
        }
        // Quando não for maior, ele insere o novo na lista na posição guardada
        novo->proximo = aux->proximo;
        // O anterior do novo recebe aux
        novo->anterior = aux;
        // O anterior do proximo do novo recebe novo
        novo->proximo->anterior = novo;
        // O próximo do auxiliar recebe o novo
        aux->proximo = novo;
    }
}

// Função para imprimir a lista em ordem crescente
void imprimeListaClinica(ListaClinica lista, FILE *saida)
{
    // Se a lista não estiver vazia, imprime as informações dos pacientes do início ao fim da lista
    if (!estaVaziaListaClinica(&lista))
    {
        PtrNoLista aux = lista.inicio;
        do
        {
            // Imprime na saída e no compilador em ordem crescente
            printf("{%d,%s,%c,%d,%s,%.2f,%s}\n", aux->dados.idPaciente, aux->dados.nomePaciente, aux->dados.sexoPaciente, aux->dados.idadePaciente, aux->dados.pesoPaciente, aux->dados.alturaPaciente, aux->dados.telefonePaciente);
            fprintf(saida, "{%d,%s,%c,%d,%s,%.2f,%s}\n", aux->dados.idPaciente, aux->dados.nomePaciente, aux->dados.sexoPaciente, aux->dados.idadePaciente, aux->dados.pesoPaciente, aux->dados.alturaPaciente, aux->dados.telefonePaciente);
            aux = aux->proximo;
        } while (aux != lista.inicio);
    }
}

// Função para imprimir a lista em ordem decrescente
void imprimeListaClinicaDecrescente(ListaClinica lista, FILE *saida)
{
    // Se a lista não estiver vazia, imprime as informações dos pacientes do fim para o início da lista
    if (!estaVaziaListaClinica(&lista))
    {
        PtrNoLista aux = lista.fim;
        do
        {
            // Imprime na saída e compilador em ordem decrescente
            printf("{%d,%s,%c,%d,%s,%.2f,%s}\n", aux->dados.idPaciente, aux->dados.nomePaciente, aux->dados.sexoPaciente, aux->dados.idadePaciente, aux->dados.pesoPaciente, aux->dados.alturaPaciente, aux->dados.telefonePaciente);
            fprintf(saida, "{%d,%s,%c,%d,%s,%.2f,%s}\n", aux->dados.idPaciente, aux->dados.nomePaciente, aux->dados.sexoPaciente, aux->dados.idadePaciente, aux->dados.pesoPaciente, aux->dados.alturaPaciente, aux->dados.telefonePaciente);
            aux = aux->anterior;
        } while (aux != lista.inicio);
        // Imprime o primeiro elemento da lista na saída e no compilador
        printf("{%d,%s,%c,%d,%s,%.2f,%s}", aux->dados.idPaciente, aux->dados.nomePaciente, aux->dados.sexoPaciente, aux->dados.idadePaciente, aux->dados.pesoPaciente, aux->dados.alturaPaciente, aux->dados.telefonePaciente);
        fprintf(saida, "{%d,%s,%c,%d,%s,%.2f,%s}", aux->dados.idPaciente, aux->dados.nomePaciente, aux->dados.sexoPaciente, aux->dados.idadePaciente, aux->dados.pesoPaciente, aux->dados.alturaPaciente, aux->dados.telefonePaciente);
    }
}

//----------------------------------------------
//----------------------------------------------

int main(int argc, const char *argv[])
{
    // Verificando a quantidade de parâmetros
    if (argc != 3)
    {
        printf("Quantidade de parametros invalida\n");
        return 1;
    }

    // Abrindo os arquivos
    FILE *entrada = fopen(argv[1], "r");
    FILE *saida = fopen(argv[2], "w");

    // Declarando e inicializando a lista
    ListaClinica lista;
    iniciaListaClinica(&lista);

    // Declaração de variáveis
    char linha[50];
    char *guardaDados[100];
    int i = 0, j = 0, cod = 0, linhaNum = 0, possuiDados = 0, numRecebido, buscaNum, numVirgulas;
    PtrNoLista aux = lista.inicio;

    while (fgets(linha, 100, entrada) != !EOF)
    {
        // Zerando a variável a cada linha lida
        numVirgulas = 0;
        // Verificando os elementos na linha do arquivo e incrementando as variáveis
        for (j = 0; j < strlen(linha); j++)
        {
            if (linha[j] == 44)
            {
                numVirgulas++;
            }
            else if (linha[j] != '{' && linha[j] != '}')
            {
                possuiDados++;
            }
        }
        // Passando pelas informações do registro do paciente no arquivo de entrada
        if (!(linha[0] >= 48 && linha[0] <= 57))
        {
            // Verifica se o número de informações está correto ou não
            if (numVirgulas != 6)
            {
                printf("Arquivo Invalido!");
                fprintf(saida, "Arquivo Inválido!");
                return 1;
            }

            // Controle para erro de quantidade de caracteres
            if (possuiDados == 0)
            {
                printf("Arquivo Invalido!");
                fprintf(saida, "Arquivo Inválido!");
                return 1;
            }
            // Insere o id do registro e as informações na lista
            inserirListaOrdenada(&lista, linha);

            // Guarda a operação a ser realizada e número a ser buscado, se for o caso
        }
        else if (linha[0] >= 48 && linha[0] <= 57)
        {
            // Números depois dos infoPaciente
            linhaNum++;
            int cod = 0, ind = 0;
            // Converte o número de string para inteiro
            while (linha[ind] >= 48 && linha[ind] <= 57)
            {
                if (cod == 0)
                {
                    cod = (linha[ind] - '0');
                }
                else
                {
                    cod += (linha[ind] - '0');
                }
                cod *= 10;
                ind++;
            }
            cod /= 10;
            // Verifica se são as operações 1, 2 ou 3, caso seja a operação 3, guarda os dois valores do final do arquivo de entrada (a operação e o valor a ser pesquisado)
            if (linhaNum == 1)
            {
                numRecebido = cod;
            }
            else if (linhaNum == 2)
            {
                buscaNum = cod;

                // Caso encontre valores inválidos, retorna erro
            }
            else
            {
                printf("Elemento nao encontrado!");
                fprintf(saida, "Elemento não encontrado!");
            }
        }
    }

    // Contador para verificar se o elemento a ser buscado existe na lista ou não
    int count = 0;
    // Verifica o comando passado no final do arquivo de entrada
    switch (numRecebido)
    {
    // Caso o comando seja 1, imprime a lista em ordem crescente no arquivo de saída
    case 1:
        imprimeListaClinica(lista, saida);
        break;
    // Caso o comando seja 2, imprime a lista em ordem decrescente no arquivo de saída
    case 2:
        imprimeListaClinicaDecrescente(lista, saida);
        break;
    // Caso o comando seja 3, pesquisa o número que está abaixo dele na lista e retorna no arquivo de saída
    case 3:
        // Guardando o elemento inicial da lista em um auxiliar
        aux = lista.inicio;
        // Verifica se o elemento a ser buscado está na lista ou não, se estiver, count é incrementado e é retornado no arquivo de saída
        do
        {
            if (aux->dados.idPaciente == buscaNum)
            {
                printf("{%d,%s,%c,%d,%s,%.2f,%s}\n", aux->dados.idPaciente, aux->dados.nomePaciente, aux->dados.sexoPaciente, aux->dados.idadePaciente, aux->dados.pesoPaciente, aux->dados.alturaPaciente, aux->dados.telefonePaciente);
                fprintf(saida, "{%d,%s,%c,%d,%s,%.2f,%s}\n", aux->dados.idPaciente, aux->dados.nomePaciente, aux->dados.sexoPaciente, aux->dados.idadePaciente, aux->dados.pesoPaciente, aux->dados.alturaPaciente, aux->dados.telefonePaciente);
                count++;
            }
            aux = aux->proximo;
        } while (aux != lista.fim->proximo);

        // Caso count não seja incrementado, o elemento a ser pesquisado não existe na lista
        if (count == 0)
        {
            printf("Elemento nao encontrado!");
            fprintf(saida, "Elemento nao encontrado!");
        }
        break;
    // Caso default
    default:
        printf("Arquivo Invalido!");
        fprintf(saida, "Arquivo Inválido!");
        break;
    }

    // Fechando os arquivos
    fclose(entrada);
    fclose(saida);

    return 0;
}