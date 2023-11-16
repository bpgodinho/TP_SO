#include "motor.h"

void mostrarLabirinto(char labirinto[MAX_LINHAS][MAX_COLUNAS], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c", labirinto[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char labirinto[MAX_LINHAS][MAX_COLUNAS];
    int linhas = 0, colunas = 0;
    FILE *file = fopen("labirinto.txt", "r");
    if (file == NULL) {
        perror("Erro a abrir o ficheiro");
        return 1;
    }
    while (fgets(labirinto[linhas], MAX_COLUNAS, file) != NULL) {
        labirinto[linhas][strcspn(labirinto[linhas], "\n")] = '\0';
        printf("Line %d length: %zu\n", linhas + 1, strlen(labirinto[linhas]));
        linhas++;
    }
    fclose(file);
    colunas = strlen(labirinto[0]);
    mostrarLabirinto(labirinto, linhas, colunas);
    return 0;
}