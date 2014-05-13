#include <cstdio>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
using namespace std;

int main()
{
/*    int status;
    char* args[] = {"-l"};
    if (fork() != 0)
    {
        waitpid(-1, &status, 0);
    }
    else
    {
        system("ls -l");
    }
    */
    printf("%d\n", access("/root/wangpan", F_OK));
}
