#include <stdio.h>
//#include <string.h>
//判断字符是否被包含在字符串中，被包含了返回1，否则返回0
int Contained(char c, char *delim)
{
	while(*delim)
	{
		if(*delim == c)
			return 1;
		++delim;
	}
	return 0;
}
//
char *Strtok(char *s, char *delim)
{
	static char * pSave = NULL;//静态字符指针变量
	if(s)
	{
		//不为空,第一次查找
		//去掉前面的符合条件的字符
		while(*s && Contained(*s, delim))
			++s;
		pSave = s + 1;//保存要查找字符的首位置
		while(*pSave)
		{
			if(Contained(*pSave, delim))//如果是分隔字符
			{
				*pSave = '\0';
				++pSave;
				break;
			}
			//如果不是分隔字符
			++pSave;
		}
		return s;
	}
	else
	{
		//为空,不是第一次查找
		if(pSave && *pSave)
		{
			while(*pSave && Contained(*pSave, delim))
				++pSave;
			s = pSave ++;//保存子串的起始位置
			while(*pSave)
			{
				if(Contained(*pSave, delim))//如果是分隔字符
				{
					*pSave = '\0';
					++pSave;
					break;
				}
				//如果不是分隔字符
				++pSave;//让静态指针变量指向下一个字符
			}			
		}
		return s;		
	}
	
	
}
int main()
{
	char ip[] = "19#2.168.1.101";
	char *pstr = NULL;
	pstr = Strtok(ip, ".#");
	do
	{
		printf("%s\n", pstr);
	}while(pstr = Strtok(NULL, ".#"));
	
	return 0;
}
