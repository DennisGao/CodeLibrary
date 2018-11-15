/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:

输入: "abab"

输出: True

解释: 可由子字符串 "ab" 重复两次构成。
示例 2:

输入: "aba"

输出: False
示例 3:

输入: "abcabcabcabc"

输出: True

解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
*/

#include <stdio.h>
#include <string.h>

typedef enum {
	false,
   	true
} bool;

bool repeatedSubstringPattern(char* s) {

	int slen = strlen(s);
	int hslen = slen/2;
	int mididx = 0;

	if (slen < 2)
		return false;
	if (strlen(s)>10000)
		return false;

	if (slen%2) {
		mididx = hslen+1;
		if (s[hslen] != s[0])
			return false;
	}
	else
		mididx = hslen;

	for (int i=0; i<hslen; i++) {
		if (s[i] != s[i+mididx])
			return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	char tmp[20][20] = {
//		"a",					/* False */
//		"aba",					/* False */
//		"abc",					/* False */
//		"abab",					/* True */
		"ababab",				/* True */
//		"abcabcabcabc"			/* True */
	};

	char* p = tmp[0];
	 //int (*p)[4] = a
	int i = 0;
	while (i<20 && tmp[i][0])
	{
		printf("%s\n", repeatedSubstringPattern(tmp[i])==true?"True":"False");
		i++;
	}
}

