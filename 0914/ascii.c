#include <stdio.h>
#include <conio.h>

int main(void)
{
	int chr;
	do
	{
		chr = _getch();
		if (chr == 0 || chr == 0xe0)
		{
			chr = _getch();
			printf("확장키 code=%d\n", chr);
		}
		else
			printf("아스키 code=%d\n", chr);
	} while (1);

	return 0;
}
