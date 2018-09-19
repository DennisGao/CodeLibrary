/************************************************************************
 * File Name:	toLowerCase.c
 * Author:		DennisGao
 * Mail:		DennisGao 
 * Created Time:	2018/07/17 20:23:26
 * Last modified:	2018/07/17 20:23:26
 ***********************************************************************/

/*
 * 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
 */

#include <stdio.h>

char* toLowerCase(char* str) {
	int i = 0;
	int len = strlen(str);
	int gap = 'a'-'A';

	for (; i<len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += gap;
		}
	}
	return str;
}
	

int main(int argc, char* argv[])
{
	char b[32];
	strcpy(b, "aBCde");
	toLowerCase(b);
	printf("%s\n", b);
	return 0;
}

