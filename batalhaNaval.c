#include <stdio.h>

int main() {

    // Construindo o Jogo de Batalha Naval

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Vetor do Tipo char para declarar e inicializar a identificação com letras, representando as Colunas do Tabuleiro.
    int tabuleiro[10][10]; // Declaração da Matriz do tipo inteiro, de tamanho 10x10 [linha]x[coluna], representando o tabuleiro.
    int navioHorizontal[3] = {3, 3, 3}; // Declaração e inicialização do Vetor de tipo inteiro para implementar o Navio em posição Horizontal, que ocupará 3 posições em uma linha do Tabuleiro.
    int navioVertical[4]= {3, 3, 3, 3}; // Declaração e inicialização do Vetor de tipo inteiro para implementar o Navio em posição Vertical, que ocupará 4 posições em uma coluna do Tabuleiro.
    

    for (int i = 0; i < 10; i++) { // Loop Aninhado (for-for) para inicializar os índices da Matriz de linha[i] e coluna[j] com valor 0, representando a água no Tabuleiro.
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) { // Loop for para posicionar o Navio Horizontal nos índices [5][5], [5][6] e [5][7], ocupando 3 posições na linha 6 x F do Tabuleiro.
        tabuleiro[5][5 + i] = navioHorizontal[i];
    }

    for (int i = 0; i < 4; i++) { // Loop for para posicionar o Navio Vertical nos índices [6][2], [7][2], [8][2] e [9][2], ocupando 4 posições na coluna C x 7 do Tabuleiro.
        tabuleiro[6 + i][2] = navioVertical[i];
    }

    printf("\n\n*** TABULEIRO BATALHA NAVAL ***\n\n");

    printf("   "); // Espaço impresso apena para o alinhamento das Letras x Colunas do Tabuleiro.
    for (int j = 0; j < 10; j++) { // Loop for para a impressão do Vetor de identificação com letras, representando as Colunas do Tabuleiro.
        printf(" %c", linha[j]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++) { // Estrutura externa do Loop Aninhado (for-for), para a impressão da identicação das linhas de 1 à 10, do lado esquerdo do Tabuleiro.
        printf("%2d ", i + 1); // "%2d" - Insere um pequeno espaço na frente dos numeros, para alinhar a Coluna de identificação Númerica do Tabuleiro. "i + 1" - Começa a sequencia de impressão a partir do nº 1 e não pelo nº 0.
        for (int j = 0; j < 10; j++) { // Estrutura interna do Loop Aninhado (for-for), para a impressão da Matriz [i=10] x [j=10], representando o Tabuleiro.
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n"); // Impressão apenas para quebra de linha a cada Loop. 
    }

    printf("\n");

    return 0;
}