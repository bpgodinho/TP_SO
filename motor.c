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
    char output[9];
    char command[26];
    char kickName[20];
    int exitFlag = 0;
    char labirinto[MAX_LINHAS][MAX_COLUNAS];
    int linhas = 0, colunas = 0;
    FILE *file = fopen("labirinto.txt", "r");
    if (file == NULL) {
        perror("Erro a abrir o ficheiro");
        return 1;
    }
    while (fgets(labirinto[linhas], MAX_COLUNAS, file) != NULL) {
        labirinto[linhas][MAX_COLUNAS] = '\0';
        linhas++;
    }
    linhas = MAX_LINHAS;
    fclose(file);
    colunas = MAX_COLUNAS;
    mostrarLabirinto(labirinto, linhas, colunas);
     while(exitFlag == 0){
        printf("\nInserir comando");
        fgets(command, 26, stdin);
        if(strncmp(command, "end", 3) == 0){
            printf("Acabar o jogo\n");
        }else if (strncmp(command, "rbm", 3) == 0){
            printf("Eliminar bloqueio movel\n");
        }else if(strncmp(command, "bmov", 4) == 0){
            printf("Insere bloqueio movel\n");
        }else if(strncmp(command, "bots", 4) == 0){
            printf("Lista bots\n");
        }else if(strncmp(command, "kick", 4) == 0){
            if(sscanf(command, "kick %20s", kickName) == 1){
                printf("Kickar: %s", kickName);
            }else{
                printf("Erro argumento de nome invalido\n");
            }
        }else if(strncmp(command, "test_bot", 8) == 0){
            if (mkfifo(SERVER_FIFO, 0666) == -1)
    {
        perror("Erro a abrir fifo ou programa recebeMSG está a correr");
        return -1;
    }
    
    int fd = open (SERVER_FIFO,O_RDONLY|O_NONBLOCK);
    if (fd == -1)
    {
        perror("Erro a abrir fifo ");
        return -1;
    }
    int a;
    int i=0;
    while (i <=5)
    {
        int size = read(fd, &output, 9);
        if (size > 0){
            printf("\nRECEBI: %s", output);
            i++;
            }
    }
    close(fd);
    unlink(SERVER_FIFO);
        }
    }
    return 0;
}