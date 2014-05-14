#include <cstdio>
#include <cstring>
using namespace std;

/*
 * getLastDir(char* fullDir, char* lastDir, int lastDirLen)
 *   从指定的目录路径上获取最深层的目录名 
 *   输入参数：fullDir: 目录的绝对路径
 *             lastDirLen: lastDir的长度
 *   输出参数：lastDir: 目录名
 *   返回值: 无
 */
void getLastDir(char* fullDir, char* lastDir, int lastDirLen)
{
	int len = strlen(fullDir);
	int idx = 0;
	
	len --;
	while (len >= 0 && fullDir[len] != '/')
	{
		len --;
	}
	idx = len + 1;
	strncpy(lastDir, &fullDir[idx], lastDirLen);
}
