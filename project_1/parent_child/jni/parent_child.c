#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
 *     CS356 Operating System Project 1: Problem 3
 * This is a simple program which calls pstree in the child
 * process, showing the relationship between the parent and 
 * child process.
 *          anthor: Ma Yesheng 5140209064
 */
 
 
int main(void) 
{
    printf("test parent and child process relation\n");
    pid_t pid;
    
    pid = fork();
    if (pid == -1) {
        printf("fork error\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("5140209064-child is %d\n", getpid());
        // use execl to call the pstree program
        execl("/data/project/pstree", "2", "100", (char *) 0);
        _exit(EXIT_SUCCESS);
    } else {
        waitpid(pid, NULL, 0);
        printf("5140209064-parent is %d\n", getpid());
    }
    wait(1); // wait for 1ms for pretty print
    return EXIT_SUCCESS;
}

