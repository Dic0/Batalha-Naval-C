#include <stdio.h>
#include <stdbool.h> // É um cabeçalho em C que define o tipo de dado bool e as constantes true e false;
#include <stdlib.h>  // Esta linha inclui a biblioteca padrão do C para funções de utilidade, como rand() e srand();
#include <time.h>    // É um cabeçalho em C que fornece funções e tipos relacionados ao tempo e data. Ele permite que você trabalhe com informações de data, hora e calendário em seus programas C;
#include <windows.h>

#define TAMANHO_TABULEIRO 5    // Define que o tamanho do tabuleiro vai ser de 5x5;
#define TAMANHO_PORTA_AVIOES 3 // Define que o tamanho do porta-avião é 3;
#define TAMANHO_SUBMARINO 2    // Define que o tamanho do submarino é 2;
#define NUMERO_NAVIOS 5        // Define que a quantidade de navios é 5;

typedef struct
{
    int x;
    int y;
} Posicao;

/* O typedef é usado para fornecer um nome alternativo (um "apelido") para a estrutura de dados definida pela struct.
Ele cria um tipo de dado novo e personalizado. Dessa forma, em vez de usar a forma completa struct NomeDaEstrutura,
podemos usar apenas o nome definido com typedef;

Por exemplo, a definição typedef struct { int x; int y; } Posicao; cria um novo tipo de dado chamado Posicao, que é uma estrutura contendo
dois membros do tipo int chamados x e y. Agora, podemos usar Posicao como um tipo de dado em nosso programa;
*/

typedef struct
{
    Posicao posicoes[TAMANHO_PORTA_AVIOES]; // Infoma q a variavel (posicoes) é do tipo Posicao com um parametro TAMANHO_PORTA_AVIOES que esta definido como o tamanho 3;
    bool atingido[TAMANHO_PORTA_AVIOES];    // Informa que se o Porta-avião foi atingido ou não;
} PortaAvioes;

typedef struct
{
    Posicao posicoes[TAMANHO_SUBMARINO];
    bool atingido[TAMANHO_SUBMARINO];
} Submarino;

// Mesma lógica que o PortaAvioes;

typedef struct
{
    Posicao posicao;
    bool atingido;
} Navio;

// Mesma lógica que o PortaAvioes, só que sem tamanho pré definido, por ser de tamanho 1;

typedef struct
{
    PortaAvioes portaAvioes;
    Submarino submarinos[2];
    Navio navios[NUMERO_NAVIOS];
} Tabuleiro;

/* A estrutura Tabuleiro é usada para representar um tabuleiro de jogo que contém um porta-aviões, dois submarinos e um número variável de navios. Cada um desses
elementos é armazenado dentro da estrutura Tabuleiro para facilitar o gerenciamento e manipulação
*/

void inicializarTabuleiro(Tabuleiro *tabuleiro) // A sintaxe void inicializarTabuleiro(Tabuleiro *tabuleiro) define uma função chamada inicializarTabuleiro que recebe um ponteiro para Tabuleiro comoargumento e não retorna nenhum valor (void).

/*  Void: É o tipo de retorno da função, indicando que ela não retorna nenhum valor.
    inicializarTabuleiro: É o nome da função.
    (Tabuleiro *tabuleiro): É a lista de parâmetros da função. Nesse caso, há um único parâmetro chamado tabuleiro, que é um ponteiro para a estrutura de dados Tabuleiro.
    Tabuleiro *: Indica que o parâmetro tabuleiro é um ponteiro para a estrutura Tabuleiro. Isso significa que ele irá armazenar o endereço de memória de um objeto do tipo Tabuleiro.
    A função inicializarTabuleiro é definida com void como tipo de retorno porque ela não retorna nenhum valor específico. Em vez disso, ela realiza uma ação, que é a inicialização do tabuleiro,
    modificando o objeto Tabuleiro original.
    Ao passar um ponteiro para Tabuleiro como argumento, a função inicializar pode acessar e modificar diretamente o objeto Tabuleiro original, em vez de criar uma cópia.
*/

{
    int i, j;

    // Inicializar porta-avioes;

    for (i = 0; i < TAMANHO_PORTA_AVIOES; i++)
    {
        tabuleiro->portaAvioes.posicoes[i].x = -1;

        /* A primeira linha dentro do loop atribui o valor -1 à coordenada x da posição atual do objeto portaAvioes no tabuleiro. Essa linha é equivalente a tabuleiro->portaAvioes.posicoes[i].x = -1;.
        O uso do -> indica que estamos acessando um membro de uma estrutura por meio de um ponteiro.
        */

        tabuleiro->portaAvioes.posicoes[i].y = -1;

        /* A segunda linha dentro do loop atribui o valor -1 à coordenada y da posição atual do objeto portaAvioes no tabuleiro.
         */

        tabuleiro->portaAvioes.atingido[i] = false;

        /* A terceira linha dentro do loop define o valor false para o elemento atingido[i] do array atingido do objeto portaAvioes. Essa linha é equivalente a tabuleiro->portaAvioes.atingido[i] = false;.
        Através dessa atribuição, estamos indicando que a posição atual do porta-aviões não foi atingida.
        */
    }

    // Inicializar submarinos;

    for (i = 0; i < 2; i++) // O código começa com um loop for externo que vai de 0 a 1 (2 iterações). A variável i é inicializada com 0.
    {
        for (j = 0; j < TAMANHO_SUBMARINO; j++) // Em seguida, há um loop for interno que itera de 0 a TAMANHO_SUBMARINO - 1. A variável j é inicializada com 0.
        {
            tabuleiro->submarinos[i].posicoes[j].x = -1;

            /* Dentro do loop interno, a linha tabuleiro->submarinos[i].posicoes[j].x = -1; atribui o valor -1 à coordenada x da posição atual do submarino i no tabuleiro.
            Isso define a coordenada x como -1.
            */

            tabuleiro->submarinos[i].posicoes[j].y = -1;

            /* A linha seguinte tabuleiro->submarinos[i].posicoes[j].y = -1; atribui o valor -1 à coordenada y da posição atual do submarino i no tabuleiro. Essa atribuição define a coordenada y como -1.*/

            tabuleiro->submarinos[i].atingido[j] = false;

            /* A última linha dentro do loop interno tabuleiro->submarinos[i].atingido[j] = false; define o valor false para o elemento atingido[j] do array atingido do submarino i.
            Isso indica que a posição atual do submarino não foi atingida.*/
        }
    }

    // Inicializar navios;

    for (i = 0; i < NUMERO_NAVIOS; i++)
    {
        tabuleiro->navios[i].posicao.x = -1;
        tabuleiro->navios[i].posicao.y = -1;
        tabuleiro->navios[i].atingido = false;

        /* Nesse trecho de código, um loop é usado para percorrer todos os navios no tabuleiro. O número total de navios é dado por NUMERO_NAVIOS.
        Dentro do loop, as posições dos navios são definidas como (-1, -1) e a flag atingido é definida como false.
        Isso significa que, inicialmente, os navios não têm uma posição atribuída no tabuleiro (pois (-1, -1) não é uma posição válida) e também não foram atingidos.
        Essa é uma configuração inicial comum, onde todos os navios são colocados fora do tabuleiro, aguardando a sua colocação posteriormente durante a inicialização
        do jogo ou a fase de posicionamento dos navios.
        À medida que os navios são colocados no tabuleiro, suas posições são atualizadas com valores válidos e a flag atingido é modificada conforme eles são atingidos durante o jogo.
        */
    }
}

bool posicaoValida(int x, int y) // A função posicaoValida verifica se uma posição (x, y) é válida dentro das dimensões do tabuleiro. Ela retorna um valor booleano indicando se a posição é válida ou não.
{
    return x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO;
}

bool posicaoDisponivel(Tabuleiro *tabuleiro, int x, int y)

/* A função posicaoDisponivel verifica se uma determinada posição (x, y) está disponível no tabuleiro. Ela recebe um ponteiro para a estrutura de dados Tabuleiro como parâmetro,
juntamente com as coordenadas (x, y) da posição a ser verificada.
A função percorre os diferentes tipos de navios no tabuleiro (porta-aviões, submarinos e outros navios) e verifica se a posição (x, y) coincide com alguma posição já ocupada por um navio.*/

{
    int i, j;

    for (i = 0; i < TAMANHO_PORTA_AVIOES; i++) // O loop for percorre o array de posições do porta-aviões, que tem tamanho TAMANHO_PORTA_AVIOES.
    {
        if (tabuleiro->portaAvioes.posicoes[i].x == x && tabuleiro->portaAvioes.posicoes[i].y == y)
        {
            return false;

            /* A expressão completa tabuleiro->portaAvioes.posicoes[i].x == x && tabuleiro->portaAvioes.posicoes[i].y == y verifica se as coordenadas (x, y) fornecidas são iguais às coordenadas da posição i
            do porta-aviões no tabuleiro. Se as coordenadas coincidirem, isso significa que a posição (x, y) está ocupada pelo porta-aviões e a condição será verdadeira. Caso contrário, se as coordenadas
            não coincidirem, a condição será falsa.
            */
        }
    }

    for (i = 0; i < 2; i++) // O primeiro loop for (i = 0; i < 2; i++) percorre os submarinos presentes no tabuleiro. No caso desse código, existem dois submarinos a serem verificados.
    {
        for (j = 0; j < TAMANHO_SUBMARINO; j++) // Em seguida, o segundo loop for (j = 0; j < TAMANHO_SUBMARINO; j++) percorre as posições de cada submarino. A constante TAMANHO_SUBMARINO indica o tamanho do submarino, ou seja, a quantidade de posições que ele ocupa no tabuleiro.
        {
            if (tabuleiro->submarinos[i].posicoes[j].x == x && tabuleiro->submarinos[i].posicoes[j].y == y)
            {
                return false;

                /* Se as coordenadas fornecidas (x, y) coincidirem com as coordenadas da posição atual do submarino, isso indica que a posição (x, y) está ocupada por um submarino. Nesse caso, a função
                retorna false, indicando que a posição não está disponível.
                */
            }
        }
    }

    for (i = 0; i < NUMERO_NAVIOS; i++) // O loop for (i = 0; i < NUMERO_NAVIOS; i++) percorre os navios presentes no tabuleiro. O valor de NUMERO_NAVIOS indica a quantidade de navios presentes no tabuleiro.
    {
        if (tabuleiro->navios[i].posicao.x == x && tabuleiro->navios[i].posicao.y == y)
        {
            return false;

            /* Se as coordenadas coincidirem com as coordenadas da posição do navio, isso indica que a posição (x, y) está ocupada por um navio. Nesse caso, a função retorna false, indicando que a posição
            não está disponível.
            Se as coordenadas não coincidirem com as coordenadas de nenhuma posição dos navios, o código continua a execução do loop, verificando outras posições dos navios.
            */
        }
    }

    return true;

    /* Após o loop, se nenhuma coincidência for encontrada em nenhum dos navios, a função retorna true, indicando que a posição (x, y) está disponível no tabuleiro. Isso significa que a posição está livre e
    pode ser ocupada por outro objeto ou ser utilizada conforme necessário.
    */
}

void posicionarEmbarcacoes(Tabuleiro *tabuleiro) // Essa função posicionarEmbarcacoes é responsável por posicionar as embarcações (porta-aviões, submarinos e navios) de forma aleatória no tabuleiro.
{
    int i;

    // Posicionar o porta-aviões
    int portaAvioesX = rand() % (TAMANHO_TABULEIRO - TAMANHO_PORTA_AVIOES + 1);

    /* (TAMANHO_TABULEIRO - TAMANHO_PORTA_AVIOES) calcula a diferença entre o tamanho do tabuleiro e o tamanho do porta-aviões. Essa diferença representa o espaço disponível no tabuleiro para posicionar o porta-aviões.
    + 1 é adicionado ao resultado para incluir o último índice disponível. Isso ocorre porque a função rand() retorna um número entre 0 e o valor máximo exclusivo.
    rand() % (TAMANHO_TABULEIRO - TAMANHO_PORTA_AVIOES + 1) calcula o resto da divisão do número aleatório gerado pela função rand() pelo valor máximo calculado. Isso garante que o resultado esteja dentro do intervalo desejado.

    Portanto, portaAvioesX receberá um valor aleatório entre 0 e a diferença de espaço disponível para posicionar o porta-aviões no tabuleiro. Essa fórmula é utilizada para posicionar o porta-aviões em uma linha
    aleatória, garantindo que ele caiba completamente dentro do tabuleiro.
    */

    int portaAvioesY = rand() % TAMANHO_TABULEIRO;

    /* A variável portaAvioesY receberá um número aleatório dentro do intervalo de posições verticais válidas no tabuleiro. Isso garante que o porta-aviões seja colocado em uma coluna válida dentro do tabuleiro.*/

    for (i = 0; i < TAMANHO_PORTA_AVIOES; i++) // Nesse trecho de código, o loop for está sendo usado para posicionar cada parte do porta-aviões no tabuleiro. O porta-aviões possui um tamanho definido por TAMANHO_PORTA_AVIOES.
    {
        tabuleiro->portaAvioes.posicoes[i].x = portaAvioesX + i;

        /* Dentro do loop, a posição horizontal (x) de cada parte do porta-aviões está sendo definida como portaAvioesX + i, onde portaAvioesX é a posição horizontal inicial gerada aleatoriamente e i é o
        índice atual do loop. Isso significa que cada parte do porta-aviões será colocada em uma linha consecutiva no tabuleiro.*/

        tabuleiro->portaAvioes.posicoes[i].y = portaAvioesY;

        /* A posição vertical (y) de todas as partes do porta-aviões é definida como portaAvioesY, que é a posição vertical gerada aleatoriamente. Isso significa que todas as partes do porta-aviões estarão na mesma coluna do tabuleiro.*/
    }

    // Posicionar os dois submarinos
    int submarino1X, submarino1Y, submarino2X, submarino2Y;

    do // É iniciado um laço de repetição do-while para posicionar o primeiro submarino. O do-while garante que as coordenadas geradas aleatoriamente sejam válidas e que o submarino não seja sobreposto a outras embarcações.
    {
        submarino1X = rand() % TAMANHO_TABULEIRO; // submarino1X é definido como um valor aleatório entre 0 e TAMANHO_TABULEIRO - 1, representando a posição horizontal do submarino.
        submarino1Y = rand() % (TAMANHO_TABULEIRO - TAMANHO_SUBMARINO + 1);

        /* submarino1Y é definido como um valor aleatório entre 0 e TAMANHO_TABULEIRO - TAMANHO_SUBMARINO, representando a posição vertical do submarino, considerando o seu tamanho. Isso garante que o
        submarino seja colocado dentro dos limites do tabuleiro.
        */

    } while (!posicaoDisponivel(tabuleiro, submarino1X, submarino1Y) ||
             !posicaoDisponivel(tabuleiro, submarino1X, submarino1Y + 1));

    /* Após gerar as coordenadas aleatórias, a função posicaoDisponivel é usada para verificar se as posições geradas estão disponíveis no tabuleiro. O do-while continua executando enquanto as coordenadas não forem válidas.*/

    for (i = 0; i < TAMANHO_SUBMARINO; i++)
    {
        tabuleiro->submarinos[0].posicoes[i].x = submarino1X;
        tabuleiro->submarinos[0].posicoes[i].y = submarino1Y + i;

        /* Após a saída do do-while, o primeiro submarino é posicionado no tabuleiro no loop for. Cada parte do submarino recebe as coordenadas submarino1X (posição horizontal fixa) e submarino1Y + i
        (posição vertical variando de acordo com o índice i do loop). O loop percorre de 0 a TAMANHO_SUBMARINO - 1, atribuindo as coordenadas para cada parte do submarino.
        */
    }

    do
    {
        submarino2X = rand() % (TAMANHO_TABULEIRO - TAMANHO_SUBMARINO + 1);
        submarino2Y = rand() % TAMANHO_TABULEIRO;

    } while (!posicaoDisponivel(tabuleiro, submarino2X, submarino2Y) ||
             !posicaoDisponivel(tabuleiro, submarino2X + 1, submarino2Y));

    /* Após a saída do segundo do-while, o segundo submarino é posicionado no tabuleiro usando um loop for semelhante ao anterior. Cada parte do submarino recebe as coordenadas submarino2X + i
    (posição horizontal variando de acordo com o índice i do loop) e submarino2Y (posição vertical fixa).
    */

    for (i = 0; i < TAMANHO_SUBMARINO; i++)
    {
        tabuleiro->submarinos[1].posicoes[i].x = submarino2X + i;
        tabuleiro->submarinos[1].posicoes[i].y = submarino2Y;

        // Mesma logica utilizada no primeiro submarino.
    }

    // Posicionar os navios
    for (i = 0; i < NUMERO_NAVIOS; i++) // É realizado um loop for para percorrer cada navio. Dentro do loop, são declaradas as variáveis navioX e navioY para armazenar as coordenadas do navio atual.
    {
        int navioX, navioY;

        do
        {
            navioX = rand() % TAMANHO_TABULEIRO;
            navioY = rand() % TAMANHO_TABULEIRO;

        } while (!posicaoDisponivel(tabuleiro, navioX, navioY));

        // É iniciado um do-while para gerar coordenadas aleatórias para o navio e verificar se essas coordenadas estão disponíveis no tabuleiro, utilizando a função posicaoDisponivel.

        tabuleiro->navios[i].posicao.x = navioX;
        tabuleiro->navios[i].posicao.y = navioY;

        /* Após a saída do do-while, as coordenadas válidas para o navio atual são armazenadas na estrutura posicao do navio no tabuleiro. A coordenada horizontal é atribuída a tabuleiro->navios[i].posicao.x
        e a coordenada vertical é atribuída a tabuleiro->navios[i].posicao.y.
        */
    }
}

void exibirTabuleiro(Tabuleiro *tabuleiro)
{
    int i, j, k, l;

    printf("\n\t    Tabuleiro\n\n");
    printf("\n\t    0 1 2 3 4\n");
    printf("\t   ___________\n");

    for (i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("\t%d | ", i);
        for (j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            bool atingido = false;
            char simbolo = '~';

            /* Essas linhas de cima iniciam um loop for externo que percorre as linhas do tabuleiro e um loop for interno que percorre as colunas do tabuleiro. A cada iteração, uma variável booleana atingido
             é inicializada como false e uma variável simbolo é inicializada com o caractere til (~). Essas variáveis serão usadas para determinar o símbolo a ser exibido na posição atual do tabuleiro.
            */

            for (k = 0; k < TAMANHO_PORTA_AVIOES; k++)
            {
                if (tabuleiro->portaAvioes.posicoes[k].x == i && tabuleiro->portaAvioes.posicoes[k].y == j)
                {
                    atingido = tabuleiro->portaAvioes.atingido[k];
                    simbolo = atingido ? 'P' : 'P';
                    break;
                }
            }

            /* Este trecho de código contém um loop for que percorre as posições do porta-aviões no tabuleiro. Se a posição atual corresponder à posição sendo verificada
            (tabuleiro->portaAvioes.posicoes[k].x == i && tabuleiro->portaAvioes.posicoes[k].y == j), o valor do membro atingido[k] é atribuído à variável atingido e o caractere 'P' é atribuído à variável
            simbolo se a posição foi atingida. A instrução break é usada para sair do loop interno.
            */

            for (k = 0; k < 2; k++) // Esse for (k = 0; k < 2; k++): Inicia um loop que itera sobre os submarinos no tabuleiro. O valor 2 é usado como limite superior, presumivelmente indicando que existem dois submarinos no jogo.
            {
                for (l = 0; l < TAMANHO_SUBMARINO; l++) // Inicia outro loop que percorre as posições individuais do submarino atual.
                {
                    if (tabuleiro->submarinos[k].posicoes[l].x == i && tabuleiro->submarinos[k].posicoes[l].y == j) // Verifica se a posição atual do submarino (identificada por k e l) corresponde à posição atual (i, j) no tabuleiro.
                    {
                        atingido = tabuleiro->submarinos[k].atingido[l]; // Se a posição atual do submarino corresponder à posição atual do tabuleiro, atribui o valor do indicador atingido para indicar se essa posição do submarino foi atingida.
                        simbolo = atingido ? 'S' : 'S';

                        /* Se a variável atingido for avaliada como verdadeira (ou seja, diferente de zero), o valor atribuído a simbolo será o caractere 'S'.
                        Caso contrário, se a variável atingido for avaliada como falsa (ou seja, igual a zero), o valor atribuído a simbolo será o caractere '~'.
                        */

                        break;
                    }
                }
            }

            for (k = 0; k < NUMERO_NAVIOS; k++) // Mesma lógica que o for de porta-aviões
            {
                if (tabuleiro->navios[k].posicao.x == i && tabuleiro->navios[k].posicao.y == j)
                {
                    atingido = tabuleiro->navios[k].atingido;
                    simbolo = atingido ? 'N' : 'N';
                    break;
                }
            }

            printf("%c ", simbolo);
        }

        printf("|\n");
    }
    printf("\t   -----------\n\n\n");
}

bool verificarFimJogo(Tabuleiro *tabuleiro) // A função verificarFimJogo tem como objetivo verificar se o jogo chegou ao fim, ou seja, se todos os navios foram atingidos no tabuleiro.
{
    int i, j;

    for (i = 0; i < TAMANHO_PORTA_AVIOES; i++)
    {
        if (!tabuleiro->portaAvioes.atingido[i])
        {
            return false;
        }
    }

    /* Nessa parte, o laço for percorre todas as posições do vetor atingido dentro da estrutura portaAvioes do tabuleiro. Se algum dos elementos não estiver marcado como atingido (ou seja, false),
    significa que o porta-aviões ainda não foi totalmente destruído, então a função retorna false.
    */

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < TAMANHO_SUBMARINO; j++)
        {
            if (!tabuleiro->submarinos[i].atingido[j])
            {
                return false;
            }
        }
    }

    /* Nesse trecho, dois laços for são usados para percorrer as posições dos submarinos no tabuleiro. Assim como antes, se algum dos elementos no vetor atingido do submarino não estiver marcado como
    atingido, a função retorna false, indicando que ainda há submarinos não destruídos.
    */

    for (i = 0; i < NUMERO_NAVIOS; i++)
    {
        if (!tabuleiro->navios[i].atingido)
        {
            return false;
        }
    }

    /* Por fim, outro laço for percorre as posições dos navios no tabuleiro. Se algum dos navios não estiver marcado como atingido, a função retorna false, indicando que ainda há navios não destruídos.
    Se o código chegar até esse ponto sem ter retornado false, significa que todos os navios foram atingidos e o jogo chegou ao fim. Portanto, a função retorna true.
    */

    return true;
}

void limparTela() // A função limparTela é responsável por limpar a tela do console, proporcionando uma interface mais limpa e organizada para o usuário.

// O código utiliza diretivas de pré-processamento (#ifdef, #else, #endif) para lidar com a diferença entre sistemas operacionais Windows e Linux na execução dos comandos para limpar a tela.

{
#ifdef _WIN32
    system("cls"); // Comando para limpar a tela no Windows

    // No caso do sistema operacional Windows (_WIN32), a função system("cls") é chamada. Esse comando executa o comando cls no prompt de comando do Windows, que limpa a tela.

#else
    system("clear"); // Comando para limpar a tela no Linux

    // Já no caso de outros sistemas operacionais, como Linux, a função system("clear") é chamada. Esse comando executa o comando clear no terminal do Linux, que também realiza a limpeza da tela.

#endif
}

int printSobre() // É responsável por abrir um arquivo chamado "sobreJogo.txt"
{
    FILE *arquivo;   // Declara um ponteiro de arquivo chamado arquivo. Esse ponteiro será usado para manipular o arquivo que será aberto.
    char linha[100]; // Declara uma matriz de caracteres chamada linha com tamanho 100. Essa matriz será usada para armazenar cada linha lida do arquivo.

    arquivo = fopen("sobreJogo.txt", "r");

    // A função fopen abre o arquivo chamado "sobreJogo.txt" no modo de leitura ("r"). Essa função retorna um ponteiro para o arquivo aberto, que é atribuído à variável arquivo.

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;

        /* Verifica se o ponteiro arquivo é nulo, o que indicaria que ocorreu um erro ao abrir o arquivo. Se o ponteiro for nulo, a mensagem "Erro ao abrir o arquivo." é impressa na tela e o valor 1 é
        retornado, indicando uma falha na execução do programa.
        */
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);
    }

    /* O loop while é usado para ler o conteúdo do arquivo linha por linha. A função fgets é utilizada para ler uma linha do arquivo apontado por arquivo e armazená-la na matriz linha. A função fgets lê
    no máximo sizeof(linha) caracteres de cada linha.
    A condição do loop while verifica se a função fgets não retornou nulo, o que indicaria o fim do arquivo. Enquanto houver linhas para serem lidas, o loop continua executando.
    Dentro do loop, a linha lida é impressa na tela usando printf com o formato "%s". Isso exibe a linha no console.
    */

    fclose(arquivo);
    return 0;

    /* Após o término do loop, a função fclose é utilizada para fechar o arquivo apontado por arquivo. Isso libera os recursos associados ao arquivo.
    Por fim, o valor 0 é retornado, indicando que o programa foi executado com sucesso.
    */
}

void printBanner() // Imprime o banner do menu
{
    printf("\t╔══════════════════════════════╗\n");
    printf("\t║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
    printf("\t║░░░░░░░╔═══════════════╗░░░░░░║\n");
    printf("\t║░░░░░░░║ BATALHA NAVAL ║░░░░░░║\n");
    printf("\t║░░░░░░░╚═══════════════╝░░░░░░║\n");
    printf("\t║░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░║\n");
    printf("\t╚══════════════════════════════╝\n");
}

bool verificarPortaAvioesTotalmenteAtingido(PortaAvioes *portaAvioes) // Essa função tem como objetivo verificar se todas as partes do porta-aviões foram atingidas.
{
    int i;
    for (i = 0; i < TAMANHO_PORTA_AVIOES; i++)
    {
        if (!portaAvioes->atingido[i]) // Verifica se a posição i do porta-aviões não foi atingida. A expressão portaAvioes->atingido[i] verifica se a parte do porta-aviões na posição i está marcada como atingida.
        {
            return false; //  Caso alguma parte do porta-aviões não tenha sido atingida, a função retorna false, indicando que o porta-aviões não foi totalmente atingido.
        }
    }
    return true;
}

int main() // A função main() é a função principal do programa, onde a execução do programa começa. Ela retorna um valor inteiro.
{
    srand(time(NULL));         // É uma chamada de função que inicializa a geração de números aleatórios usando a função rand(). Essa linha é importante para garantir que os números aleatórios gerados sejam diferentes em cada execução do programa.
    SetConsoleOutputCP(65001); // É uma chamada de função que configura a codificação de caracteres do console para suportar caracteres especiais em português, como acentos e caracteres UTF-8.

    char reiniciar;
    int escolha;

    Tabuleiro tabuleiro; // Declara uma variável tabuleiro do tipo Tabuleiro, que é uma estrutura que representa o tabuleiro do jogo.

    do
    {
        limparTela();
        printBanner();
        printf("\t\n\nMenu:\n\n");
        printf("\t1. Saber sobre o jogo\n");
        printf("\t2. Jogar\n\n");
        printf("\tEscolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) // Avalia o valor da variável escolha e executa o bloco de código correspondente ao caso escolhido.
        {
        case 1: // Representa o caso em que o jogador escolhe a opção "Sobre o jogo". As seguintes linhas chamam funções para limpar a tela, imprimir informações sobre o jogo.
            limparTela();
            printSobre();
            printf("\n\n");
            break;
        case 2: // Representa o caso em que o jogador escolheu a opção "Jogar". As seguintes linhas chamam funções para limpar a tela, inicializar o tabuleiro e posicionar as embarcações no tabuleiro.
            limparTela();
            inicializarTabuleiro(&tabuleiro);
            posicionarEmbarcacoes(&tabuleiro);

            int tiros = 0; // Declara e inicializa uma variável tiros com o valor 0. Essa variável será usada para contar o número de tiros realizados pelo jogador.

            while (true) // O loop while (true) é executado continuamente até que seja interrompido manualmente.
            {
                exibirTabuleiro(&tabuleiro); // É uma função que exibe o tabuleiro atualizado na tela, mostrando as embarcações, tiros disparados e seus resultados.

                int x, y, i, j;
                printf("\t\nDigite as coordenadas do tiro (x y): "); // Exibe uma mensagem solicitando ao jogador que digite as coordenadas do tiro.
                scanf("%d %d", &x, &y);                              // Lê as coordenadas do tiro digitadas pelo jogador e armazena os valores nas variáveis x e y.

                if (!posicaoValida(x, y))

                /* Verifica se as coordenadas do tiro não são válidas, chamando uma função posicaoValida() para realizar a verificação. Se as coordenadas não forem válidas, uma mensagem é exibida e o loop
                continua com a próxima iteração usando o comando continue;.
                */

                {
                    printf("\tCoordenadas inválidas! Tente novamente.\n");
                    continue;
                }

                bool acertou = false; // Declara e inicializa uma variável booleana acertou como false. Essa variável será usada para indicar se o tiro acertou alguma embarcação.

                for (i = 0; i < TAMANHO_PORTA_AVIOES; i++) // Percorre as posições do porta-aviões no tabuleiro e verifica se alguma delas corresponde às coordenadas do tiro do jogador.
                {
                    if (tabuleiro.portaAvioes.posicoes[i].x == x && tabuleiro.portaAvioes.posicoes[i].y == y) // Verifica se as coordenadas do tiro (x, y) correspondem às coordenadas da posição atual do porta-aviões no índice i.
                    {
                        if (!tabuleiro.portaAvioes.atingido[i]) // Verifica se a posição do porta-aviões no índice i ainda não foi atingida.
                        {

                            tabuleiro.portaAvioes.atingido[i] = true; // Marca a posição i do porta-aviões como atingida, definindo o valor correspondente no vetor tabuleiro.portaAvioes.atingido como true.
                            acertou = true;                           // Atribui o valor true à variável booleana acertou, indicando que o tiro acertou uma embarcação.

                            if (verificarPortaAvioesTotalmenteAtingido(&tabuleiro.portaAvioes))
                            {
                                printf("\nPorta-aviões totalmente destruído!\n\n");
                            }
                            else
                            {
                                printf("\nAcertou uma parte do porta-aviões!\n\n");
                            }
                        }
                        else // Executa se o usuário colocar a mesma coordenada já disparada antes que tenha acertado um porta-aviões.
                        {
                            printf("\n\nVocê já disparou nessa coordenada, era um porta-aviões!\n");
                            acertou = true;
                        }
                    }
                }

                for (i = 0; i < 2; i++) // É um loop externo que itera sobre os submarinos.
                {
                    for (j = 0; j < TAMANHO_SUBMARINO; j++) // É um loop interno que itera sobre as posições de cada submarino. TAMANHO_SUBMARINO é uma constante que representa o número de posições ocupadas por um submarino.
                    {
                        if (tabuleiro.submarinos[i].posicoes[j].x == x && tabuleiro.submarinos[i].posicoes[j].y == y) // Mesma lógica no do porta-aviões.
                        {
                            if (!tabuleiro.submarinos[i].atingido[j]) // Mesma lógica no do porta-aviões.
                            {
                                printf("\nAcertou uma parte do Submarino!\n\n");
                                tabuleiro.submarinos[i].atingido[j] = true;
                                acertou = true;
                            }
                            else // Executa se o usuário colocar a mesma coordenada já disparada antes que tenha acertado um submarino.
                            {
                                printf("\n\nVocê já disparou nessa coordenada, era um submarino!\n");
                                acertou = true;
                            }
                        }
                    }
                }

                for (i = 0; i < NUMERO_NAVIOS; i++) // Mesma lógica no do porta-aviões.
                {
                    if (tabuleiro.navios[i].posicao.x == x && tabuleiro.navios[i].posicao.y == y) // Mesma lógica no do porta-aviões.
                    {
                        if (!tabuleiro.navios[i].atingido) // Mesma lógica no do porta-aviões.
                        {
                            printf("Acertou um navio!\n");
                            tabuleiro.navios[i].atingido = true;
                            acertou = true;
                        }
                        else // Executa se o usuário colocar a mesma coordenada já disparada antes que tenha acertado um navio.
                        {
                            printf("Você já disparou nessa coordenada, era um navio!\n");
                            acertou = true;
                        }
                    }
                }

                if (!acertou) // Verifica se nenhuma embarcação foi atingida pelo tiro do jogador. Isso significa que o tiro acertou apenas água (mar).
                {
                    printf("Tiro no mar!\n"); // Exibe a mensagem indicando que o tiro atingiu apenas água, ou seja, não acertou nenhuma embarcação.
                }

                tiros++; // Incrementa o contador de tiros. Essa variável foi inicializada antes do loop principal e está sendo incrementada a cada tiro realizado pelo jogador.

                if (verificarFimJogo(&tabuleiro))

                /* Verifica se todas as embarcações no tabuleiro foram destruídas. A função verificarFimJogo recebe o endereço do tabuleiro como parâmetro e retorna true se todas as embarcações foram
                destruídas, ou false caso contrário.
                */

                {
                    exibirTabuleiro(&tabuleiro); // Exibe o tabuleiro final, mostrando a posição das embarcações e os tiros realizados pelo jogador.
                    printf("\n\nParabéns! Você destruiu todas as embarcações em %d tiros!\n\n", tiros);
                    break; // Interrompe o loop principal, encerrando o jogo.
                }
            }
        default:
            if (escolha > 2 || escolha < 1)
            {
                printf("Opção inválida!\n");
                break;
            }

            /* Essa parte do código trata a situação em que o jogador digita uma opção inválida no menu. Se o valor de escolha estiver fora do intervalo válido (1 ou 2), uma mensagem de "Opção inválida!"
            será exibida. Isso garante que o jogador seja notificado sobre a escolha inválida e possa realizar uma nova seleção válida.
            */
        }

        if (escolha == 1) // Verifica se a opção escolhida pelo jogador foi a opção 1, que corresponde a "Sobre o jogo".
        {
            printf("Deseja voltar ao menu? (S/N): ");
            scanf(" %c", &reiniciar);
        }
        else
        {
            printf("Deseja jogar novamente? (S/N): ");
            scanf(" %c", &reiniciar);
        }

    } while (reiniciar == 'S' || reiniciar == 's'); // O laço do-while é usado para repetir o processo até que o jogador decida não voltar ao menu ou não jogar novamente. O laço é executado enquanto a variável reiniciar for igual a 'S' ou 's'.

    printf("\nObrigado por jogar!\n\n");

    return 0;
}