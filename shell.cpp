#include "shell.h"

char pwd[MAX_PATH_LENGTH];
char npwd[MAX_PATH_LENGTH];
char ** cmdArgs;
int cmdArgc;

ACCESS_TYPE getAccessType(string cmd)
{
    int cmdLen = cmd.size();
    const char* strCmd = cmd.c_str();
    ACCESS_TYPE at = USAGE;

    if (cmdLen < 2)
    {
        at = USAGE;
    }
    else if (cmdLen == 2 || strCmd[2] == ' ')    //命令是2个字节的
    {
        if (!memcmp(strCmd, "ls", 2))
        {
            at = LS; 
        }
        else if (!memcmp(strCmd, "cd", 2))
        {
            at = CD;
        }
        else if (!memcmp(strCmd, "rm", 2))
        {
            at = RM;
        }
        else if (!memcmp(strCmd, "cp", 2))
        {
            at = CP;
        }
        else if (!memcmp(strCmd, "mv", 2))
        {
            at = MV;
        }
        else
        {
            at = USAGE;
        }
    }
    else if (cmdLen == 3 || strCmd[3] == ' ')   //命令是3个字节的
    {
        if (!memcmp(strCmd, "nls", 3))
        {
            at = NLS;
        }
        else if (!memcmp(strCmd, "pwd", 3))
        {
            at = PWD;
        }
        else if (!memcmp(strCmd, "put", 3))
        {
            at = PUT;
        }
        else if (!memcmp(strCmd, "get", 3))
        {
            at = GET;
        }
        else if (!memcmp(strCmd, "ncd", 3))
        {
            at = NCD;
        }
        else
        {
            at = USAGE;
        }
    }
    else if (cmdLen == 4 || strCmd[4] == ' ')   //命令是4个字节的
    {
        if (!memcmp(strCmd, "npwd", 4))
        {
            at = NPWD;
        }
        else
        {
            at = USAGE;
        }
    }
    else if (cmdLen == 5 || strCmd[5] == ' ')  //命令是5个字节的
    {
        if (!memcmp(strCmd, "mkdir", 5))
        {
            at = MKDIR;
        }
        else if (!memcmp(strCmd, "touch", 5))
        {
            at = TOUCH;
        }
        else
        {
            at = USAGE;
        }
    }
    else if (cmdLen == 6 || strCmd[6] == ' ')
    {
        if (!memcmp(strCmd, "nmkdir", 6))
        {
            at = NMKDIR;
        }
        else if (!memcmp(strCmd, "ntouch", 6))
        {
            at = NTOUCH;
        }
        else 
        {
            at = USAGE;
        }
    }
    else if (cmdLen == 7 && !memcmp(strCmd, "version", 7))
    {
        at = VERSION;
    }
    else    //其余全都默认为version，不做错误处理
    {
        at = USAGE;
    }

    return at;
}

int getArg(string cmd, char args[], int argsLen)
{
    int idx = 0;
    const char* strCmd = cmd.c_str();

    while (strCmd[idx] != '\0' && strCmd[idx] != ' ')
    {
        idx ++;
    }

    if (strCmd[idx] == '\0')
    {
        return 0;
    }
    else
    {
        strncpy(args, strCmd + idx + 1, argsLen);
        return strlen(strCmd + idx + 1);
    }
}

int getArgs(string cmd, string args[])
{
    
}

int executeCdCommand(char* arg, int argLen)
{
    char tempPath[MAX_PATH_LENGTH];

    if (argLen == 0)	//如果cd命令没有参数则失败
    {
        return 0;
    }
    else
    {
		if (chdir(arg))
		{
			printf("no such dir: %s", arg[0]);
			return 0;
		}
		
		getcwd( pwd, MAX_PATH_LENGTH);
		return 1;
    }
}

int executeLocalCommand(string cmd)
{
    char buff[BUFFSIZE];
    string executedCmd = cmd;
    ACCESS_TYPE at = getAccessType(cmd); 

    int argLen = getArg(cmd, buff, BUFFSIZE); 
    switch (at)
    {
        case LS:
            executedCmd = executedCmd + " " + pwd;
            return system(executedCmd.c_str());
        case CD:
            return executeCdCommand(buff, argLen);
        case RM:
            break;
    }
    return system(cmd.c_str());
}

void getPwd(char* buff, int buffLen)
{
    strncpy(buff, pwd, buffLen);
}
