/************************************************************************
 * File Name:	checkmacro.c
 * Author:		DennisGao
 * Mail:		DennisGao 
 * Created Time:	2017/01/16 16:06:25
 * Last modified:	2017/01/16 16:06:25
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

void ut_abort(char *file, int ln, char *line, int rc, int exp) 
{
	fprintf(stderr, "%s line %d\n'%s': expected %d, got %d\n", file, ln, line, exp, rc);
	exit(1);
}

#define CHECK(LINE, EXPECTED) \
{ \
	int rc = LINE; \
	if (rc != EXPECTED) \
		ut_abort(__FILE__, __LINE__, #LINE, rc, EXPECTED); \
}

int main(int argc, char** argv)
{
	CHECK(23, 22);
	//CHECK("real", "expected"); // error
	return 0;
}

