#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <error.h>

#define MAX_LINHAS 16
#define MAX_COLUNAS 43
#define SERVER_FIFO "SERVERFIFO"

void mostrarLabirinto(char labirinto[MAX_LINHAS][MAX_COLUNAS], int linhas, int colunas);


