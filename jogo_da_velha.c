#include <stdio.h>

char tabuleiro[3][3];
char jogadorAtual = 'X';

// Inicializa o tabuleiro
void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Mostra o tabuleiro na tela
void mostrarTabuleiro() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Verifica se alguém ganhou
int verificarVitoria() {
    for (int i = 0; i < 3; i++) {
        // Linhas e colunas
        if ((tabuleiro[i][0] == jogadorAtual &&
             tabuleiro[i][1] == jogadorAtual &&
             tabuleiro[i][2] == jogadorAtual) ||
            (tabuleiro[0][i] == jogadorAtual &&
             tabuleiro[1][i] == jogadorAtual &&
             tabuleiro[2][i] == jogadorAtual)) {
            return 1;
        }
    }

    // Diagonais
    if ((tabuleiro[0][0] == jogadorAtual &&
         tabuleiro[1][1] == jogadorAtual &&
         tabuleiro[2][2] == jogadorAtual) ||
        (tabuleiro[0][2] == jogadorAtual &&
         tabuleiro[1][1] == jogadorAtual &&
         tabuleiro[2][0] == jogadorAtual)) {
        return 1;
    }

    return 0;
}

// Verifica empate
int verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Alterna o jogador
void trocarJogador() {
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

int main() {
    int linha, coluna;

    inicializarTabuleiro();

    printf("=== JOGO DA VELHA ===\n");

    while (1) {
        mostrarTabuleiro();
        printf("Jogador %c, escolha linha e coluna (0 a 2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Posição inválida! Tente novamente.\n");
            continue;
        }

        if (tabuleiro[linha][coluna] != ' ') {
            printf("Posição já ocupada! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        if (verificarVitoria()) {
            mostrarTabuleiro();
            printf("🎉 Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        if (verificarEmpate()) {
            mostrarTabuleiro();
            printf("🤝 O jogo empatou!\n");
            break;
        }

        trocarJogador();
    }

    return 0;
}
