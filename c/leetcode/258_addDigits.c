/************************************************************************
 * File Name:	addDigits.c
 * Author:		DennisGao
 * Mail:		DennisGao 
 * Created Time:	2018/07/28 16:12:03
 * Last modified:	2018/07/28 16:12:03
 ***********************************************************************/

#include <stdio.h>

int addDigits(int num) {
	int sum = num%10;

	while ((num /=10 )>0)
	{
		sum += num%10;
	}
	if (sum > 9)
		sum = addDigits(sum);
	return sum;
}

int main(int argc, char** argv)
{
	printf("%d\n", addDigits(19));
	printf("%d\n", addDigits(38));
	printf("%d\n", addDigits(11));
	printf("%d\n", addDigits(123));
	printf("%d\n", addDigits(10));
	return 0;
}

