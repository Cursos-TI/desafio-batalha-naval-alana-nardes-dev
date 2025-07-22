#include <stdio.h>

#define TAMANHO_TABULEIRO 10 // Constante utilizada para definir o valor padrão das Linhas e Colunas do Tabuleiro. 
#define TAMANHO_NAVIO 3 // Constante utilizada para definir o valor padrão do tamanho dos Navios. 
#define TAMANHO_LINHA 3 // Constante utilizada para definir o valor padrão das Linhas das Matrizes de Habilidades.
#define TAMANHO_COLUNA 5 // Constante utilizada para definir o valor padrão das Colunas das Matrizes de Habilidades.

int main() {

    // Construindo o Jogo de Batalha Naval

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Vetor do tipo char para declarar e inicializar a identificação com letras, representando as Colunas do Tabuleiro.
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Declaração da Matriz do tipo inteiro, representando o tabuleiro, mas sem determinar o valor dos índices, pois já está sendo referenciada a sua respectiva Constante.
    int navioHorizontal[TAMANHO_NAVIO] = {3, 3, 3}; // Declaração (referenciada ao valor da sua respectiva Constante (índice)) e Inicialização do Vetor de tipo inteiro, para implementar o Navio em posição Horizontal em uma linha do Tabuleiro.
    int navioVertical[TAMANHO_NAVIO] = {3, 3, 3}; // Declaração (referenciada ao valor da sua respectiva Constante (índice)) e Inicialização do Vetor de tipo inteiro para implementar o Navio em posição Vertical em uma coluna do Tabuleiro.
    int navioDiagonal1[TAMANHO_NAVIO] = {3, 3, 3}; // Declaração (referenciada ao valor da sua respectiva Constante (índice)) e Inicialização do Vetor de tipo inteiro para implementar o 1º Navio em posição Diagonal Principal em uma diagonal do Tabuleiro.
    int navioDiagonal2[TAMANHO_NAVIO] = {3, 3, 3}; // Declaração (referenciada ao valor da sua respectiva Constante (índice)) e Inicialização do Vetor de tipo inteiro para implementar o 2º Navio em posição Diagonal Secundária em uma diagonal do Tabuleiro.

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) { // Loop Aninhado (for-for) referenciando o valor da condição à sua respectiva Constante, para inicializar os índices da Matriz do Tabuleiro, onde o valor 0 estará representando a água no Tabuleiro.
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) { // Loop for referenciando o valor da condição à sua respectiva Constante, para posicionar o Navio Horizontal no endereçamento dos índices [8][5], [8][6] e [8][7], ocupando 3 posições na horizontal a partir da coordenada 9 x F do Tabuleiro.
        tabuleiro[8][5 + i] = navioHorizontal[i];
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) { // Loop for referenciando o valor da condição à sua respectiva Constante, para posicionar o Navio Vertical no endereçamento dos índices [7][2], [8][2] e [9][2], ocupando 3 posições na vertical a partir da coordenada C x 8 do Tabuleiro.
        tabuleiro[7 + i][2] = navioVertical[i];
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) { // Loop for referenciando o valor da condição à sua respectiva Constante, para posicionar o 1º Navio Diagonal no endereçamento dos índices [1][2], [2][3] e [3][4], ocupando 3 posições na diagonal padrão a partir da coordenada 2 x C do Tabuleiro.
        tabuleiro[1 + i][2 + i] = navioDiagonal1[i];
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++){ // Loop for referenciando o valor da condição à sua respectiva Constante, para posicionar o 2º Navio Diagonal(Secundária) no endereçamento dos índices [3][8], [4][7] e [5][6], ocupando 3 posições na diagonal inversa a partir da coordenada 4 x I do Tabuleiro.
        tabuleiro[3 + i][8 - i] = navioDiagonal2[i];
    }

    // Matriz da Habilidade "CONE"
    int habilidadeCone[TAMANHO_LINHA][TAMANHO_COLUNA] = { // Declaração e Inicialização da Matriz do tipo inteiro, representando a habilidade "CONE", mas sem determinar o valor dos índices, pois já está sendo referenciada as suas respectivas Constantes.
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // Ponto de origem da habilidade (Topo do Cone [0][2])
    int origemLinha1 = 3; // Variável do tipo inteira para a coordenada da Linha do Tabuleiro onde acontecerá a sobreposição do ponto de origem do Cone.
    int origemColuna1 = 2; // Variável do tipo inteira para a coordenada da Coluna do Tabuleiro onde acontecerá a sobreposição do ponto de origem do Cone.
    int validacao1 = 1; // Variável de controle de valor booleano (1 = True) para a validação da sobreposição da habilidade, respeitando as posições já ocupadas pelos Navios e os limites das bordas do Tabuleiro.

    // Aplicando a habilidade CONE ao tabuleiro (Representado pelo valor 5)
    for (int i = 0; i < TAMANHO_LINHA; i++) { // Loop Aninhado (for-for) referenciando o valor das condições às suas respectivas Constantes, para sobrepor a habilidade nas coordenadas / índices da Matriz do Tabuleiro, desde que a aplicação da habilidade esteja dentro dos limites das bordas do Tabuleiro e que a coordenada que seria sobreposta pela ocupação completa da Habilidade, já não esteja sendo ocupada por um Navio.
        for (int j = 0; j < TAMANHO_COLUNA; j++) {
            if (habilidadeCone[i][j] == 1) { // Condicional: Quando o Elemento percorrido na Matriz da habilidade for = 1 em cada loop (interno e externo), a condição retorna VERDADEIRA e o bloco "if" é executado, sobrepondo o ponto de origem da habilidade na respectiva coordenada escolhida do Tabuleiro.
                int linhaTabuleiro = origemLinha1 + i; // Sobreposição da Habilidade na Linha do Tabuleiro = Índice de Linha escolhida no Tabuleiro + Retorno da Condicional "i" = 1, nesse caso, não sendo necessário uma função matemática para alinhar a linha da matriz da habilidade, pois o Ponto de Origem é o Topo do Cone (Índice[0]).
                int colunaTabuleiro = origemColuna1 - 2 + j; // Sobreposição da Habilidade na Coluna do Tabuleiro = Índice de Coluna escolhida no Tabuleiro + Retorno da Condicional "j" = 1, integrada com uma operação aritimética para centralizar o Ponto de Origem da Habilidade no centro das Colunas da respectiva Matriz (Habilidade).

                // Verificando se a aplicação da Habilidade está dentro dos limites do tabuleiro 10x10
                if (linhaTabuleiro < 0 || linhaTabuleiro >= TAMANHO_TABULEIRO ||
                    colunaTabuleiro < 0 || colunaTabuleiro >= TAMANHO_TABULEIRO) { // Estrutura de Decisão "if" para verificar se a aplicação completa da habilidade no tabuleiro, não excede as bordas limite (linha x Coluna) da Matriz.
                    validacao1 = 0; // Variável de Controle de valor Booleano que, caso a condição do if em questão seja verdadeira, a variável é zerada (0) se tornando "falsa" e bloqueando a aplicação da Habilidade no Tabuleiro.
                    break; // Encerra o Loop interno (j), se a validação se tornar 0 e bloquear a aplicação da Habilidade.
                } 

                // Verificando se a aplicação da Habilidade não está sobrepondo um Navio (valor 3) 
                if (validacao1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == 3) { // Estrutura de Decisão "if" para verificar se a aplicação completa da habilidade no tabuleiro, não sobreponha a localização que já esteja sendo ocupada por um Navio.
                    validacao1 = 0; // Variável de Controle de valor Booleano que, caso a condição do if em questão seja verdadeira, a variável é zerada (0) se tornando "falsa" e bloqueando a aplicação da Habilidade no tabuleiro.
                    break; // Encerra o Loop interno (j), se a validação se tornar 0 e bloquear a aplicação da Habilidade.
                }
            }
        }
        if (validacao1 == 0) break; // Encerra o Loop externo (i) se uma das duas validações se tornar 0 e bloquear a aplicação da Habilidade.
    }

    if (validacao1) { // Validação em Duas Etapas: Estrutura de Decisão "if" (integrada com Loop Aninhado (for-for)) a ser executada, após todas as validações anteriores serem aprovadas (validacao == 1). Somente com essas aprovações, será aplicado a habilidade no tabuleiro.
        for (int i = 0; i < TAMANHO_LINHA; i++) { // Mesma estrutura de loop aninhado do bloco anterior, porém com uma nova função na ultima linha do if, responsável de fato pela aplicação da habilidade no tabuleiro.
            for (int j = 0; j < TAMANHO_COLUNA; j++) {
                if (habilidadeCone[i][j] == 1) {
                    int linhaTabuleiro = origemLinha1 + i;
                    int colunaTabuleiro = origemColuna1 - 2 + j;
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Comando da função de sobreposição da Habilidade no Tabuleiro, representada pelo valor 5.
                }
            }
        }
    } else { // Bloco a ser executado caso alguma das validações anteriores tenha falhado (validacao == 0). Então, a habilidade NÃO será aplicada e a mensagem de erro será impressa no terminal. 
        printf("\n⚠️  Habilidade *CONE* NÃO aplicada: Ultrapassa os limites do Tabuleiro ou sobrepõe um Navio!\n");
    }

    // Matriz da Habilidade "CRUZ"
    int habilidadeCruz[TAMANHO_LINHA][TAMANHO_COLUNA] = { // Declaração e Inicialização da Matriz do tipo inteiro, representando a habilidade "CRUZ", mas sem determinar o valor dos índices, pois já está sendo referenciada as suas respectivas Constantes.
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    // Ponto de origem da habilidade (Centro da Cruz [1][2])
    int origemLinha2 = 1; // Variável do tipo inteira para a coordenada da Linha do Tabuleiro onde acontecerá a sobreposição do ponto de origem da Cruz.
    int origemColuna2 = 6; // Variável do tipo inteira para a coordenada da Coluna do Tabuleiro onde acontecerá a sobreposição do ponto de origem da Cruz.
    int validacao2 = 1; // Variável de controle de valor booleano (1 = True) para a validação da sobreposição da habilidade, respeitando as posições já ocupadas pelos Navios e os limites das bordas do Tabuleiro.

    // Aplicando a habilidade CRUZ ao tabuleiro (Representado pelo valor 5)
    for (int i = 0; i < TAMANHO_LINHA; i++) { // Loop Aninhado (for-for) referenciando o valor das condições às suas respectivas Constantes, para sobrepor a habilidade nas coordenadas / índices da Matriz do Tabuleiro, desde que a aplicação da habilidade esteja dentro dos limites das bordas do Tabuleiro e que a coordenada que seria sobreposta pela ocupação completa da Habilidade, já não esteja sendo ocupada por um Navio.
        for (int j = 0; j < TAMANHO_COLUNA; j++) {
            if (habilidadeCruz[i][j] == 1) { // Condicional: Quando o Elemento percorrido na Matriz da habilidade for = 1 em cada loop (interno e externo), a condição retorna VERDADEIRA e o bloco "if" é executado, sobrepondo o ponto de origem da habilidade na respectiva coordenada escolhida do Tabuleiro.
                int linhaTabuleiro = origemLinha2 - 1 + i; // Sobreposição da Habilidade na Linha do Tabuleiro = Índice de Linha escolhida no Tabuleiro + Retorno da Condicional "i" = 1, integrada com uma operação aritimética para centralizar o Ponto de Origem da Habilidade no centro das Linhas da respectiva Matriz (Habilidade).
                int colunaTabuleiro = origemColuna2 - 2 + j; // Sobreposição da Habilidade na Coluna do Tabuleiro = Índice de Coluna escolhida no Tabuleiro + Retorno da Condicional "j" = 1, integrada com uma operação aritimética para centralizar o Ponto de Origem da Habilidade no centro das Colunas da respectiva Matriz (Habilidade).

                // Verificando se a aplicação da Habilidade está dentro dos limites do tabuleiro 10x10
                if (linhaTabuleiro < 0 || linhaTabuleiro >= TAMANHO_TABULEIRO ||
                    colunaTabuleiro < 0 || colunaTabuleiro >= TAMANHO_TABULEIRO) { // Estrutura de Decisão "if" para verificar se a aplicação completa da habilidade no tabuleiro, não excede as bordas limite (linha x Coluna) da Matriz.
                    validacao2 = 0; // Variável de Controle de valor Booleano que, caso a condição do if em questão seja verdadeira, a variável é zerada (0) se tornando "falsa" e bloqueando a aplicação da Habilidade no Tabuleiro.
                    break; // Encerra o Loop interno (j), se a validação se tornar 0 e bloquear a aplicação da Habilidade.
                }

                // Verificando se a aplicação da Habilidade não está sobrepondo um Navio (valor 3) 
                if (validacao2 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == 3) { // Estrutura de Decisão "if" para verificar se a aplicação completa da habilidade no tabuleiro, não sobreponha a localização que já esteja sendo ocupada por um Navio.
                    validacao2 = 0; // Variável de Controle de valor Booleano que, caso a condição do if em questão seja verdadeira, a variável é zerada (0) se tornando "falsa" e bloqueando a aplicação da Habilidade no Tabuleiro.
                    break; // Encerra o Loop interno (j), se a validação se tornar 0 e bloquear a aplicação da Habilidade.
                }
            }
        }
        if (validacao2 == 0) break; // Encerra o Loop externo (i) se uma das duas validações se tornar 0 e bloquear a aplicação da Habilidade.
    }

    if (validacao2) { // Validação em Duas Etapas: Estrutura de Decisão "if" (integrada com Loop Aninhado (for-for)) a ser executada, após todas as validações anteriores serem aprovadas (validacao == 1). Somente com essas aprovações, será aplicado a habilidade no tabuleiro.
        for (int i = 0; i < TAMANHO_LINHA; i++) { // Mesma estrutura de loop aninhado do bloco anterior, porém com uma nova função na ultima linha do if, responsável de fato pela aplicação da habilidade no tabuleiro.
            for (int j = 0; j < TAMANHO_COLUNA; j++) {
                if (habilidadeCruz[i][j] == 1) {
                    int linhaTabuleiro = origemLinha2 - 1 + i;
                    int colunaTabuleiro = origemColuna2 - 2 + j;
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Comando da função de sobreposição da Habilidade no Tabuleiro, representada pelo valor 5.
                }
            }
        }
    } else { // Bloco a ser executado caso alguma das validações anteriores tenha falhado (validacao == 0). Então, a habilidade NÃO será aplicada e a mensagem de erro será impressa no terminal. 
        printf("\n⚠️  Habilidade *CRUZ* NÃO aplicada: Ultrapassa os limites do Tabuleiro ou sobrepõe um Navio!\n");
    }

    // Matriz da Habilidade "OCTAEDRO"
    int habilidadeOcta[TAMANHO_LINHA][TAMANHO_COLUNA] = { // Declaração e Inicialização da Matriz do tipo inteiro, representando a habilidade "OCTAEDRO", mas sem determinar o valor dos índices, pois já está sendo referenciada as suas respectivas Constantes.
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Ponto de origem da habilidade (Centro do Octaedro [1][2])
    int origemLinha3 = 6; // Variável do tipo inteira para a coordenada da Linha do Tabuleiro onde acontecerá a sobreposição do ponto de origem do Octaedro.
    int origemColuna3 = 8; // Variável do tipo inteira para a coordenada da Coluna do Tabuleiro onde acontecerá a sobreposição do ponto de origem do Octaedro.
    int validacao3 = 1; // Variável de controle de valor booleano (1 = True) para a validação da sobreposição da habilidade, respeitando as posições já ocupadas pelos Navios e os limites das bordas do Tabuleiro.

    // Aplicando a habilidade OCTAEDRO ao tabuleiro (Representado pelo valor 5)
    for (int i = 0; i < TAMANHO_LINHA; i++) { // Loop Aninhado (for-for) referenciando o valor das condições às suas respectivas Constantes, para sobrepor a habilidade nas coordenadas / índices da Matriz do Tabuleiro, desde que a aplicação da habilidade esteja dentro dos limites das bordas do Tabuleiro e que a coordenada que seria sobreposta pela ocupação completa da Habilidade, já não esteja sendo ocupada por um Navio.
        for (int j = 0; j < TAMANHO_COLUNA; j++) {
            if (habilidadeOcta[i][j] == 1) { // Condicional: Quando o Elemento percorrido na Matriz da habilidade for = 1 em cada loop (interno e externo), a condição retorna VERDADEIRA e o bloco "if" é executado, sobrepondo o ponto de origem da habilidade na respectiva coordenada escolhida do Tabuleiro.
                int linhaTabuleiro = origemLinha3 - 1 + i; // Sobreposição da Habilidade na Linha do Tabuleiro = Índice de Linha escolhida no Tabuleiro + Retorno da Condicional "i" = 1, integrada com uma operação aritimética para centralizar o Ponto de Origem da Habilidade no centro das Linhas da respectiva Matriz (Habilidade).
                int colunaTabuleiro = origemColuna3 - 2 + j; // Sobreposição da Habilidade na Coluna do Tabuleiro = Índice de Coluna escolhida no Tabuleiro + Retorno da Condicional "j" = 1, integrada com uma operação aritimética para centralizar o Ponto de Origem da Habilidade no centro das Colunas da respectiva Matriz (Habilidade).

                // Verificando se a aplicação da Habilidade está dentro dos limites do tabuleiro 10x10
                if (linhaTabuleiro < 0 || linhaTabuleiro >= TAMANHO_TABULEIRO ||
                    colunaTabuleiro < 0 || colunaTabuleiro >= TAMANHO_TABULEIRO) { // Estrutura de Decisão "if" para verificar se a aplicação completa da habilidade no tabuleiro, não excede as bordas limite (linha x Coluna) da Matriz.
                    validacao3 = 0; // Variável de Controle de valor Booleano que, caso a condição do if em questão seja verdadeira, a variável é zerada (0) se tornando "falsa" e bloqueando a aplicação da Habilidade no Tabuleiro.
                    break; // Encerra o Loop interno (j), se a validação se tornar 0 e bloquear a aplicação da Habilidade.
                }

                // Verificando se a aplicação da Habilidade não está sobrepondo um Navio (valor 3) 
                if (validacao3 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == 3) { // Estrutura de Decisão "if" para verificar se a aplicação completa da habilidade no tabuleiro, não sobreponha a localização que já esteja sendo ocupada por um Navio.
                    validacao3 = 0; // Variável de Controle de valor Booleano que, caso a condição do if em questão seja verdadeira, a variável é zerada (0) se tornando "falsa" e bloqueando a aplicação da Habilidade no Tabuleiro.
                    break; // Encerra o Loop interno (j), se a validação se tornar 0 e bloquear a aplicação da Habilidade.
                }
            }
        }
        if (validacao3 == 0) break; // Encerra o Loop externo (i) se uma das duas validações se tornar 0 e bloquear a aplicação da Habilidade.
    }

    if (validacao3) { // Validação em Duas Etapas: Estrutura de Decisão "if" (integrada com Loop Aninhado (for-for)) a ser executada, após todas as validações anteriores serem aprovadas (validacao == 1). Somente com essas aprovações, será aplicado a habilidade no tabuleiro.
        for (int i = 0; i < TAMANHO_LINHA; i++) { // Mesma estrutura de loop aninhado do bloco anterior, porém com uma nova função na ultima linha do if, responsável de fato pela aplicação da habilidade no tabuleiro.
            for (int j = 0; j < TAMANHO_COLUNA; j++) {
                if (habilidadeOcta[i][j] == 1) {
                    int linhaTabuleiro = origemLinha3 - 1 + i;
                    int colunaTabuleiro = origemColuna3 - 2 + j;
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Comando da função de sobreposição da Habilidade no Tabuleiro, representada pelo valor 5.
                }
            }
        }
    } else { // Bloco a ser executado caso alguma das validações anteriores tenha falhado (validacao == 0). Então, a habilidade NÃO será aplicada e a mensagem de erro será impressa no terminal. 
        printf("\n⚠️  Habilidade *OCTAEDRO* NÃO aplicada: Ultrapassa os limites do Tabuleiro ou sobrepõe um Navio!\n");
    }

    printf("\n\n*** TABULEIRO BATALHA NAVAL ***\n\n");

    printf("   "); // Espaço impresso apena para o alinhamento das Letras x Colunas do Tabuleiro.
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) { // Loop for referenciando o valor da condição à sua respectiva Constante, para a impressão do Vetor de identificação com letras, representando as Colunas do Tabuleiro.
        printf(" %c", linha[j]);
    }

    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) { // Estrutura externa do Loop Aninhado (for-for) referenciando o valor da condição à sua respectiva Constante, para a impressão da identicação das linhas de 1 à 10, do lado esquerdo do Tabuleiro.
        printf("%2d ", i + 1); // "%2d" - Encaixa os elementos de um numero na 2º casa decimal, para alinhar a Coluna de identificação Númerica do Tabuleiro. "i + 1" - Começa a sequencia de impressão a partir do nº 1 e não pelo nº 0.
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) { // Estrutura interna do Loop Aninhado (for-for) referenciando o valor da condição à sua respectiva Constante, para a impressão da Matriz, representando o Tabuleiro.
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n"); // Impressão apenas para quebra de linha a cada Loop. 
    }

    printf("\n");

    return 0;
}