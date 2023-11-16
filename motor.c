#include "motor.h"

void mostraLabirinto(char labirinto[MAX_LINHAS][MAX_COLUNAS], int linhas, int colunas, WINDOW *window) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            mvwaddch(window, labirinto[i][j]);
        }
        printf("\n");
    }
    addch(window, "refresh");
    refresh();
}

int main() {
    WINDOW *window;
    initscr();
    start_color();
    erase();
    noecho();
    cbreak();
    addch(window, "inicio");
    char labirinto[MAX_LINHAS][MAX_COLUNAS];
    int linhas = 0, colunas = 0;

    // Open the file for reading
    FILE *file = fopen("labirinto.txt", "r");
    if (file == NULL) {
        perror("Erro a abrir ficheiro");
        return 1;
    }

    // Read the labirinto from the file
    while (fgets(labirinto[linhas], MAX_COLUNAS, file) != NULL) {
        // Remove the newline character if present
        labirinto[linhas][strcspn(labirinto[linhas], "\n")] = '\0';
        linhas++;
    }

    // Close the file
    fclose(file);

    // Determine the number of columns
    colunas = strlen(labirinto[0]);

    // Print the labirinto
    mostraLabirinto(labirinto, linhas, colunas, window);

    while(1){
        printf("teste");
    }
    return 0;
}