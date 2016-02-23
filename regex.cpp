#include <iostream>

using namespace std;

int matchhere(char * ,char *);

int matchstar(char c, char *re, char *text)
{
	do 
	{
		if (matchhere(re, text))
			return 1;
		text++;
	}while(c == *text || c == '.');
	
	return 0;
	
}

int matchhere(char *re, char * text)
{
	if (re[1] == '*')
	{
		return matchstar(re[0], re + 2, text);
	}
	if (*re == '\0')
	{
		return 1;
	}
	if (*re == *text || *re == '.')
	{
		return matchhere(re + 1, text + 1);
	}
	
	return 0;
}

int match(char * re, char * text)
{
	do 
	{	
		if (matchhere(re, text))
		{
			return 1;
		}
	}while(*text++ != '\0');
}



int main()
{
	char *re = "isme*ail", *text = "adbismeeabaildc";
	if (match(re, text))
	{
		cout << "Match found";
	}
	else
	{
		cout << "No match found";
	}
	
	return 1;
}
