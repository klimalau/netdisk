#include <iostream>
#include <string>
using namespace std;

#include "util.h"
#include "shell.h"
#include "nshell.h"

int main(int argc, char* argv[])
{
    string cmd;
	char currDirName[MAX_PATH_LENGTH];
	getcwd(pwd, MAX_PATH_LENGTH);
	getLastDir(pwd, currDirName, MAX_PATH_LENGTH);
	printf("[netdisk@localhost %s]", currDirName);

    // 给pwd赋值，值等于当前工作目录
	// assig pwd, which value is the current work dir
    getcwd(pwd, MAX_PATH_LENGTH - 1);

    while (getline(cin, cmd))
    {
        // 如果是一个网络命令
        if (cmd[0] == 'n')
        {

        }
        else // 本地命令
        {
			if (cmd == "exit" || cmd == "quit")
			{
				exit (0);
			}
			else
			{
				executeLocalCommand(cmd); 
			}
        }
        //cout << "pwd: " << pwd << endl;
		getLastDir(pwd, currDirName, MAX_PATH_LENGTH);
        printf("[netdisk@localhost %s]", currDirName);
    }
}
