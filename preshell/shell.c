#include "myshell.h"


/**
 *
 *
 *
 */


int main()
{
    char userprompt[1024];
    char fullprompt[1064];

    while (1)
    {
        printf("simple_shell> ");

        if (fgets(userprompt, sizeof(userprompt), stdin) == NULL) {
            break;
        }

        size_t len = strlen(userprompt);
        if (len > 0 && userprompt[len - 1] == '\n') {
            userprompt[len - 1] = '\0';
        }

        if (strcmp(userprompt, "exit") == 0) {
            break;
        }

        if (strcmp(userprompt, "./ppid") == 0) {
            printf("Parent PID: %d\n", getppid());
            continue;
        }

        snprintf(fullprompt, sizeof(fullprompt), "%s", userprompt);

        int result = system(fullprompt);
        if (result == -1) {
            printf("Error ejecutando el comando.\n");
        }
    }

    return 0;
}
