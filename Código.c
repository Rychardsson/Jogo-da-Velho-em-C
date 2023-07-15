#include <stdio.h>

// Função para imprimir o tabuleiro do jogo da velha
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n--- Tabuleiro ---\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Função para verificar se o jogo terminou (vitória ou empate)
int verificarFimDeJogo(char tabuleiro[3][3]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return 1;
        }
    }
    
    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return 1;
        }
    }
    
    // Verificar diagonais
    if ((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) ||
        (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])) {
        return 1;
    }
    
    // Verificar empate
    int empate = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                empate = 0;
                break;
            }
        }
    }
    if (empate == 1) {
        return -1;
    }
    
    return 0;
}

// Função principal
int main() {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int jogador = 1; // jogador 1 = X, jogador 2 = O
    int linha, coluna;
    int fimDeJogo = 0;
    
    printf("=== Jogo da Velha ===\n\n");
    
    while (!fimDeJogo) {
        imprimirTabuleiro(tabuleiro);
        
        printf("Jogador %d, digite a linha (0-2): ", jogador);
        scanf("%d", &linha);
        printf("Jogador %d, digite a coluna (0-2): ", jogador);
        scanf("%d", &coluna);
        
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }
        
        if (jogador == 1) {
            tabuleiro[linha][coluna] = 'X';
            jogador = 2;
        } else {
            tabuleiro[linha][coluna] = 'O';
            jogador = 1;
        }
        
        fimDeJogo = verificarFimDeJogo(tabuleiro);
    }
    
    imprimirTabuleiro(tabuleiro);
    
    if (fimDeJogo == 1) {
        printf("Jogador %d venceu!\n", jogador);
    } else {
        printf("Empate!\n");
    }
    
    return 0;
}
