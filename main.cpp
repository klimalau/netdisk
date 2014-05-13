#include <iostream>
#include <string>
using namespace std;

#include "shell.h"
#include "nshell.h"

int main(int argc, char* argv[])
{
    string cmd;
    cout << "netdisk >>";

    // 给pwd赋值，值等于当前工作目录
    getcwd(pwd, MAX_PATH_LENGTH - 1);

    while (getline(cin, cmd))
    {
        // 如果是一个网络命令
        if (cmd[0] == 'n')
        {

        }
        else // 本地命令
        {
            executeLocalCommand(cmd); 
        }
        cout << "pwd: " << pwd << endl;
        cout << "netdisk >>";
    }
}
