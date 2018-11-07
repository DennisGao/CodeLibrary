/************************************************************************
 * File Name:	b.c
 * Author:		DennisGao
 * Mail:		DennisGao 
 * Created Time:	2018/03/31 10:30:04
 * Last modified:	2018/03/31 10:30:04
 ***********************************************************************/

/*
 *
 * 1. 由至少6个，至多20个字符组成。
 * 2. 至少包含一个小写字母，一个大写字母，和一个数字。
 * 3. 同一字符不能连续出现三次 (比如 "...aaa..." 是不允许的, 但是 "...aa...a..." 是可以的)。
 *
 * 编写函数 strongPasswordChecker(s)，s 代表输入字符串，如果 s 已经符合强密码条件，则返回0；否则返回要将 s 修改为满足强密码条件的字符串所需要进行修改的最小步数。
 *
 * 插入、删除、替换任一字符都算作一次修改。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXLEN 20
#define MINLEN 6

#define CFLAGUPPER	0x0001
#define CFLAGLOWER	0x0010
#define CFLAGNUM	0x0100


/*
 * 1. 由至少6个，至多20个字符组成。
 */
int checkLens(int slen){
	    if (slen > MAXLEN)
			return slen - MAXLEN;
		if (slen < MINLEN)
			return slen - MINLEN;
		return 0;
}

void checkCharactor(char b, int* cflag)
{
	if ( b >= 'a' && b <= 'z') {
		*cflag |= CFLAGLOWER;
		return ;
	}
	if ( b >= 'A' && b <= 'Z') {
		*cflag |= CFLAGUPPER;
		return ;
	}
	if ( b >= '0' && b <= '9') {
		*cflag |= CFLAGNUM;
		return ;
	}
}

int checkRepChar(char *b, int slen)
{
	char *ptr = b;
	int repCharCnt = 0;
	slen -= 2;
	while (slen > 0 ) {
		if (( *ptr >= 'a' && *ptr <= 'z')
		|| ( *ptr >= 'A' && *ptr <= 'Z')
		|| ( *ptr >= '0' && *ptr <= '9')) {
			if (*ptr==*(ptr+1) && *ptr==*(ptr+2)) {
				repCharCnt++;
				ptr += 3;
				slen -= 3;
			}
			else {
				ptr++;
				slen--;
			}
		}
		else {
			ptr++;
			slen--;
			}
	}
	return repCharCnt;
}

int strongPasswordChecker(char* s) {
	int i = 0;
	int slen = strlen(s);
	int charisfull = 3;	// 大小写、数字缺少的个数
	int lenbet = 0;
	int cflag = 0;
	int repcnt = 0;

	// 获取长度差
	lenbet = checkLens(slen);

	// 获取重复子串数量
	if (slen > 2)
		repcnt = checkRepChar(s, slen);

	// 0. 长度不足，且至少需要补足3个的，直接返回缺少的长度
	//if (lenbet <= -3)
	if (lenbet <0)
		return repcnt-lenbet;


	// 记录字符大小写、数字的情况
	for (i=0; i<slen; i++) {
		checkCharactor(s[i], &cflag);
		if ((cflag & CFLAGUPPER)
			&& (cflag & CFLAGLOWER)
			&& (cflag & CFLAGNUM)){
			charisfull = 0;
			break;
		}
	}

	if (charisfull){
		if (cflag & CFLAGUPPER)
			charisfull--;
		if (cflag & CFLAGLOWER)
			charisfull--;
		if (cflag & CFLAGNUM)
			charisfull--;
	}


	// 分情况判断最终结果
	// 1. 比规定要长
	if (lenbet > 0) {
		if (repcnt*3 < lenbet)
			return lenbet + charisfull;
		else
		{
			int tmp = (repcnt*3-lenbet)/3+1;
			int tmp2 = lenbet + charisfull;
			return tmp > tmp2 ? tmp:tmp2;
		}
	}
	
	// 2. 比规定短
	if (lenbet < 0)
		return (abs(lenbet)<charisfull ? charisfull: abs(lenbet))+repcnt;

	// 3. 在规定长度内
	return charisfull>repcnt ? charisfull : repcnt;
}

int main(int argc, char** argv)
{
//	printf("%d\n", strongPasswordChecker(""));	// 6
//	printf("%d\n", strongPasswordChecker("..."));	// 3
//	printf("%d\n", strongPasswordChecker("a"));	// 5
//	printf("%d\n", strongPasswordChecker("aaaaa"));	// 2
//	printf("%d\n", strongPasswordChecker("aaa111"));	// 2
//	printf("%d\n", strongPasswordChecker("Aa1aclsdwegsadkjfasgAAAAAAA"));	// 7
//	
//	printf("%d\n", strongPasswordChecker("Ab1acc"));	// 0
//	printf("%d\n", strongPasswordChecker("Abaacc"));	// 1
//	printf("%d\n", strongPasswordChecker("abaacc"));	// 2
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaa"));	// 6
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaa"));	// 6
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaA"));	// 6
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaa3A"));	// 6
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaa"));	// 5
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaA"));	// 5
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaa3A"));	// 5
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaa"));	// 7
	
	printf("%d\n", strongPasswordChecker("1234567890123456Baaaaa"));	// 3

//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaa"));	// 3
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaA"));	// 2
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaa3A"));	// 1
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaaaaa"));	// 6
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaaaaA"));	// 5
//	printf("%d\n", strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaaa3A"));	// 4

//	printf("%d\n", strongPasswordChecker("Abc"));	// 3
//	printf("%d\n", strongPasswordChecker("Ab1"));	// 3
//	printf("%d\n", strongPasswordChecker("abc"));	// 3
//	printf("%d\n", strongPasswordChecker("a"));		// 5

//	printf("%d\n", strongPasswordChecker("Ab1c"));	// 2
//	printf("%d\n", strongPasswordChecker("Abcc"));	// 2
//	printf("%d\n", strongPasswordChecker("aabc"));	// 2
//	printf("%d\n", strongPasswordChecker("aaaaa"));		// 2
//	printf("%d\n", strongPasswordChecker("Aaaaa"));		// 1
//	printf("%d\n", strongPasswordChecker("Aa1aa"));		// 1

	return 0;
}

