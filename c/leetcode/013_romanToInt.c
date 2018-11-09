/************************************************************************
 * File Name:	romanToInt.c
 * Author:		DennisGao
 * Mail:		DennisGao 
 * Created Time:	2018/07/17 19:51:01
 * Last modified:	2018/07/17 19:51:01
 ***********************************************************************/

/*
 * 罗马数字包含以下七种字符：I， V， X， L，C，D 和 M。
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 *
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 *
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 */

#include <stdio.h>
#include <string.h>

int getValue(char c, char prec)
{
	switch(c)
	{
		case 'I':
			return 1;
		case 'V':
			if(prec == 'I')
				return 3;
			return 5;
		case 'X':
			if(prec == 'I')
				return 8;
			return 10;
		case 'L':
			if(prec == 'X')
				return 30;
			return 50;
		case 'C':
			if(prec == 'X')
				return 80;
			return 100;
		case 'D':
			if(prec == 'C')
				return 300;
			return 500;
		case 'M':
			if(prec == 'C')
				return 800;
			return 1000;
		default:
			return 0;
	}
}

int romanToInt(char* s)
{
	int i = 0;
	int len = strlen(s);
	char* p = s;
	int retval = 0;
	int tmp = 0;
	
	for (; i<len; p++, i++)
	{
		if (tmp=getValue(*p, (i==0)?0:*(p-1)))
			retval += tmp;
		else
			return -1;
	}
	return retval;
}

int main(int argc, char** argv)
{
	char* s = "III";
	printf("%d\n", romanToInt(s));	// 3
	s = "IV";
	printf("%d\n", romanToInt(s));	// 4
	s = "IX";
	printf("%d\n", romanToInt(s));	// 9
	s = "LVIII";
	printf("%d\n", romanToInt(s));	// 58
	s = "MCMXCIV";
	printf("%d\n", romanToInt(s));	// 1994
	return 0;
}

