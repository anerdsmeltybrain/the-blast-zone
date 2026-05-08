#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    // Goal: 
    // 1. Create a child process using fork().
    // 2. Child should print "I am the child (PID: ...)" and exit.
    // 3. Parent should print "I am the parent", WAIT for the child, 
    //    and then print "Child process has finished."

    pid_t pid = fork();

    // Bug 1: No error checking! (If fork fails, pid is -1)
    
    // Bug 2: Both processes are running the EXACT SAME code below.
    // You need to use 'if (pid == 0)' to separate them.
    
    printf("I am process %d. My parent is %d.\n", getpid(), getppid());

    // Bug 3: The parent is not waiting for the child. 
    // This can lead to "Zombie" processes or the parent finishing too early.

    return 0;
}
