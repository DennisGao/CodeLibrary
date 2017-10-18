/************************************************************************
 * File Name:	Unicode2HZ.c
 * Author:		DennisGao
 * Mail:		DennisGao 
 * Created Time:	2016/12/14 11:21:16
 * Last modified:	2016/12/14 11:21:16
***********************************************************************/
// easy example:
//	char str[12];
//	wchar_t wstr[]={0x6570,0x636e,0x5e93, 0};
//	setlocale(LC_ALL,"");
//	wcstombs(str,wstr,sizeof(str)/sizeof(char));
//	printf("%s", str);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int main(int argc, char** argv)
{
	char local1[100] = "d@6570@636e@5e93abc";
	char local2[100] = "@6570@636e@5e93";
	char local3[100] = "d@6570@636e@5e93";
	char local4[100] = "@6570@636e@5e93aaa";
	char local5[100] = "5e93aaa";
	char local6[100] = "5e9_3aaa";
	char* p = local6;
	wchar_t wstr[100] = {0};
	char tmp[5];
	char str[12];
	char to[100];
	memset(to, 0,100);
	int cnt = 0;
	int i = 0;

    while(*p!='\0') {
		// iterate string
		if(*p == '@')	{
			strncpy(tmp, p+1, 4);
			tmp[4] = '\0';
			p = p+5;
			// string to hex
			int x;
			x = strtol(tmp, NULL, 16);
			wstr[0] = x;
			wstr[0+1] = 0;
			setlocale(LC_ALL,"");
			wcstombs(str, wstr, sizeof(str)/sizeof(char));
			printf("%d: %s\n", i ,str);
			strncat(to, str, strlen(str));
			cnt = cnt + strlen(str);
			i++;
		}
		else {
			to[cnt] = *p;
			cnt++;
			p++;
		}
	}

	printf("Total length %d, string is %s\n", cnt, to);
	return 0;
}

