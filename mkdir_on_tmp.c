//Numero 7 

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_USERID_LENGTH 32

struct stat st = {0};
char newDirName[10];
char home[] = "/home/";

int main() {
    char *username = getlogin();
    char *pathInit = strcat(home, username);
    char *path = strcat(pathInit, "/tmp/");

    printf("Digite o nome do diretório a ser criado: ");
    scanf("%s", newDirName);

    printf("Nome do novo repo: %s \n", newDirName);

    char *completePath = strcat(path, newDirName);

    printf("Caminho completo: %s \n", completePath);

    if (stat(completePath, &st) == -1) {
        mkdir(completePath, 0700);

        return 0;
    } else {
        return -1;
    }
}