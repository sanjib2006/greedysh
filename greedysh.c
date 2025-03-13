#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//greedysh.c
//command declarations
void echo_cmd(char *args);
void ls_cmd(char *args);
void exit_cmd(char *args);
void nfound_cmd(char *args);

//structure for command lookup
typedef struct {
    char *name;
    void (*func)(char *args);
} cmd;

cmd commands[] = {
    {"echo", echo_cmd},
    {"ls", ls_cmd},
    {"exit", exit_cmd},
    {NULL, nfound_cmd}
};

//commands------------------

//echo
void echo_cmd(char *args){
    printf("%s\n", args ? args : "");
    return;
}

//ls
void ls_cmd(char *args){
    system("ls");
    return;
}

//exit
void exit_cmd(char *args){
    printf("Exiting GreedySH...\n");
    exit(0);
}

//unknown
void nfound_cmd(char *args){
    printf("Command not found.\n");
    return;
}



//------------------------------
//to seperate the input into tokens
void greedysh() {
    char input[1024];
    printf("greedysh> ");
    fflush(stdout);
    
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    
    char *command = strtok(input, " ");
    if (command == NULL) {
        return;
    }
    char *args = strtok(NULL, "");
    
    for (int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(command, commands[i].name) == 0) {
            commands[i].func(args);
            return;
        }
    }
    nfound_cmd(args);
    return;
}

int main() {
    printf("\n🔥 Welcome to GreedySH 🔥\n");
    printf("   Developed by sanjib2006\n");
    printf("   Type 'help' for available commands\n");
    printf("-------------------------------------\n");

    while (1) {
        greedysh();
    }
    return 0;
}