#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <error.h>
#define SERVER_FIFO "SERVERFIFO"
// objetivo é receber uma msg´s
void termina(int s, siginfo_t *i, void *v)
{
    unlink(SERVER_FIFO);
    printf("\nadeus\n");
    exit(1);
}
int main()
{
    struct sigaction sa;
    sa.sa_sigaction = termina;
    sigaction(SIGINT, &sa, NULL);
    char resposta[100];
    if (mkfifo(SERVER_FIFO, 0666) == -1)
    {
        perror("Erro a abrir fifo ou programa recebeMSG está a correr");
        return -1;
    }
    

    // int fd = open(SERVER_FIFO, O_RDONLY|O_NONBLOCK); // ABRIR O FIFO EM MODO DE LEITURA BLOQ.
    int fd = open (SERVER_FIFO,O_RDONLY|O_NONBLOCK);
    if (fd == -1)
    {
        perror("Erro a abrir fifo ");
        return -1;
    }
    while (1) // testarem se é a melhor opção
    {
        int size = read(fd, &resposta, sizeof(resposta));
        if (size > 0)
            printf("\nRecebi [%s] com o tamanho [%d]", resposta, size);
    }
    close(fd);
    unlink(SERVER_FIFO);
}