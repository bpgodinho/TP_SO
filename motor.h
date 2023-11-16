#include <stdio.h>
#include <ncurses.h>

#define MAX_LINHAS 16
#define MAX_COLUNAS 40
void mostraLabirinto(char labirinto[MAX_LINHAS][MAX_COLUNAS], int linhas, int colunas, WINDOW *window);