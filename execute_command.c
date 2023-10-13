#include "shell.h"

int execute_command(char **command) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        if (execvp(command[0], command) == -1) {
            perror("Execution error");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(child_pid, &status, 0);
    }

    return WEXITSTATUS(status);
}
