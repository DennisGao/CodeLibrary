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

int maxn(int p1, int p2)
{
	return p1>p2?p1:p2;
}

void bubble_sort(int a[], int n)
{
	int i, j, temp;
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - 1 - j; i++)
		{
			if(a[i] > a[i + 1] || a[i]==0)
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
}

int strongPasswordChecker(char* s) {
	int i = 0;
	int slen = strlen(s);
	int charisfull = 3;	// 大小写、数字缺少的个数
	int lenbet = 0;
	int cflag = 0;
	int repcnt = 0;
	int repblock[100] = {0};
	int blkcnt = 1;	// rep block length
	int j = 0;

	// 记录字符大小写、数字的情况
	for (i=0; i<slen; i++) {
		char b = s[i];
		if ( b >= 'a' && b <= 'z') {
			cflag |= CFLAGLOWER;
		}
		if ( b >= 'A' && b <= 'Z') {
			cflag |= CFLAGUPPER;
		}
		if ( b >= '0' && b <= '9') {
			cflag |= CFLAGNUM;
		}

		if (s[i] == s[i-1]) {
			blkcnt++;
		}
		else {
			if (blkcnt >= 3) {
				repcnt += blkcnt/3;
				repblock[j] = blkcnt;
				j++;
			}
			blkcnt = 1;
		}
	}
	if (blkcnt >= 3) {
		repcnt += blkcnt/3;
		repblock[j] = blkcnt;
		j++;
	}

	if (cflag & CFLAGUPPER)
		charisfull--;
	if (cflag & CFLAGLOWER)
		charisfull--;
	if (cflag & CFLAGNUM)
		charisfull--;

	if (slen < MINLEN) {
		return maxn(charisfull, maxn((MINLEN-slen), repcnt));
	}

	if (slen <= MAXLEN) {
		return maxn(charisfull, repcnt);
	}

	bubble_sort(repblock, j);

	int chgrep = 0;
	int overlen = slen-MAXLEN;
	for (int nn1 = 0; nn1<j+1; nn1++) {
		if (repblock[nn1] == 0 )
			break;
		if (repblock[nn1]%3 == 0 ) {
			int tempa = repblock[nn1]%3+1;
			if (overlen > tempa) {
				overlen -= tempa;
				repblock[nn1] -= tempa;
			}
			else {
				repblock[nn1] -= overlen;
				overlen = 0;
				break;
			}
		}
	}
	for (int nn1 = 0; nn1<j+1; nn1++) {
		if (repblock[nn1] == 0 )
			break;
		if (repblock[nn1]%3 == 1) {
			int tempa = repblock[nn1]%3+1;
			if (overlen > tempa) {
				overlen -= tempa;
				repblock[nn1] -= tempa;
			}
			else {
				repblock[nn1] -= overlen;
				overlen = 0;
				break;
			}
		}
	}

	for (int nn1 = 0; nn1<j+1; nn1++) {
		int tmp = ((repblock[nn1] - 2) / 3) * 3;
		if(overlen != 0 && overlen >= tmp) 
			overlen -= tmp;
		else {
			chgrep += (repblock[nn1] - overlen) / 3;
			overlen = 0;
		}
	}

	return slen - MAXLEN + maxn(charisfull, chgrep);
}

void printif(char* p1, int n2)
{
	int n1 = strongPasswordChecker(p1);
	if (n1 != n2)
		printf("%s, %d, %d\n", p1, n1, n2);
}

int main(int argc, char** argv)
{
	printif("",										 6);
	printif("...",									 3);
	printif("a",									 5);
	printif("aaaaa",								 2);
	printif("aaa111",								 2);
	printif("Aa1aclsdwegsadkjfasgAAAAAAA",			 7);
	printif("Ab1acc",								 0);
	printif("Abaacc",								 1);
	printif("abaacc",								 2);
	printif("aaaaaaaaaaaaaaaaaaaa",					 6);
	printif("aaaaaaaaaaaaaaaaaaaa",					 6);
	printif("aaaaaaaaaaaaaaaaaaaA",					 6);
	printif("aaaaaaaaaaaaaaaaaa3A",					 6);
	printif("aaaaaaaaaaaaaaaaa",					 5);
	printif("aaaaaaaaaaaaaaaaA",					 5);
	printif("aaaaaaaaaaaaaaa3A",					 5);
	printif("aaaaaaaaaaaaaaaaaaaaa",				 7);
	printif("1234567890123456Baaaaa",				 3);
	printif("aaaabbaaabbaaa123456A",				 3);
	printif("aaaaaa1234567890123Ubefg",				 4);
	
	printif("aaaabaaaaaa123456789F",				 3);


	return 0;
}

