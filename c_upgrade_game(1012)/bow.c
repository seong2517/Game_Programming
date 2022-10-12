#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define COLOR(A) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),A);

void intro_game(char name[][20], int* n, int* level, int* horseno);
float result_game(int num, int r_count, char* check);
void horizontal_slide(int x, int y, char* c2, int n, int level);
void draw_rectangle(int r, int c);
void display_text(int count, int r_count,char b_name[][20],float* b_score);
void game_control(int* r_c, int rnd, int level, int horseno);
void gotoxy(int x, int y);
void cursor(int n);

int main(void)
{	
	int rnd, num, level, count, r_count, horseno;
	char name[1][20];
    char b_name[1][20] = {"None"};
    float score;
    float b_score = 0.0;
    char *target = "��";
    char check = 'y';
    srand(time(NULL));
    while(check == 'y')
    {
    	system("cls");
    	num = 0;
    	count = 0;
    	r_count = 0;
    	score = 0.0;
  		intro_game(name, &num, &level, &horseno);
    	cursor(0);	
    	do
    	{
  			system("cls");
     		draw_rectangle(20, 20);
      		rnd=rand()%35+4;
      		gotoxy(rnd, 2);
      		printf("%s", target);
      		count++;
      		display_text(count, r_count, b_name, &b_score);
      		game_control(&r_count, rnd, level, horseno);
	    }while(count < num);
	    score = result_game(num, r_count, &check);
	    if(b_score <= score)
	    {
	    	b_score = score;
	    	strcpy(b_name[0], name[0]);
		} 
	}
    return 0;
}

void intro_game(char name[][20], int* n, int* level, int* horseno)
{
 	printf("�� ��Ÿ�� ȭ���� ��\n\n");
  	printf("���� Ÿ�� ��ǥ��(��)�� ���ߴ� �����Դϴ�.\n");
 	printf("ȭ���� �����̽�Ű�� �߻��մϴ�. \n\n");
 	printf("- ������ �̸��� �Է��ϰ� ENTER > ");
	scanf("%s", name[0]);
	printf("\n- ���� ���� Ƚ���� �Է��ϰ� ENTER > ");
	scanf("%d", n);
	printf("\n- ���� ���̵�(1~3) �Է��ϰ� ENTER > ");
	scanf("%d", level);
	while(*level < 1 || *level > 3)
	{
		printf("�ùٸ� ���̵��� �Է����ּ���(1~3) > ");
		scanf("%d", level);
	}
	if(*level == 1) *level = 40;
	else if(*level == 2) *level = 20;
	else *level = 10;
	printf("\n- ���� ���(1=��|2=��|3=��|4=��)�� ���ϰ� ENTER > ");
	scanf("%d", horseno);
	while(*horseno < 1 || *horseno > 4)
	{
		printf("�ùٸ� ��ȣ�� �Է����ּ���(1=��|2=��|3=��|4=��) > ");
		scanf("%d", horseno);
	}
}

float result_game(int num, int r_count, char* check)
{
	system("cls");
	draw_rectangle(20, 20);
	gotoxy(14, 8);
	printf("�� �� �� �� �� ��");
	gotoxy(14, 10);
	printf(" - �õ� : %dȸ", num);
	gotoxy(14, 12);
	printf(" - ���� : %dȸ", r_count);
	gotoxy(14, 14);
	printf(" - ���߷� : %.0lf%%", (float)r_count/(float)num*100.0);
	gotoxy(8, 20);
	printf("����ȭ������ ���ư���(Y/N) > ");
	scanf(" %c", check);
	gotoxy(1, 24);
	return (float)r_count/(float)num*100.0;
}

void horizontal_slide(int x, int y, char* c2, int n, int level)
{
		gotoxy(x, y);
		printf("%s", c2);
		Sleep(level);
		gotoxy(x, y);
		if(n == 0)
		{
			printf("  ");
			printf("\b ");
		}
}

void draw_rectangle(int r, int c)
{
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[7]; 
    for(i=1;i<7;i++)
   	b[i]=0xa0+i;

    printf("%c%c",a, b[3]);
    for(i=0;i<c+22;i++) printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r;i++)
    {
	printf("%c%c", a, b[2]);
	for(j=0;j<=c;j++)
		printf("  ");
	printf("%c%c",a, b[2]);
	printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c + 22;i++) printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}

void display_text(int count, int r_count, char b_name[][20], float* b_score)
{
	gotoxy(46, 2);
	printf("�����̽��ٸ� ������\n");
	gotoxy(46, 3);
	printf("ȭ���� �߻�˴ϴ�.");
	gotoxy(46, 6);
	printf("�� Ƚ�� : %d", count);
	gotoxy(46, 7);
	printf("�� ���� : %d", r_count);
	gotoxy(46, 20);
	printf("�� ���� : %s", b_name[0]);
	gotoxy(46, 21);
	printf("�� �ְ���߷� : %.0lf%%", *b_score);
}

void game_control(int* r_c, int rnd, int level, int horseno)
{
	int i=1, k=1, y;
	char* horse = "��";
	if(horseno == 1) horse="��";
	else if(horseno == 2) horse="��";
	else if(horseno == 3) horse="��";
	char *chr;
	do
	{
		i+=k;
		if (i>39)
			k=-1;
		else if (i<3)
			k=+1;
		horizontal_slide(i+1, 21, horse, 0, level);
	}while(!kbhit());
	horizontal_slide(i+1, 21, horse, 1, level);
	chr=getch();
	y=21;
	if (chr==32)
	{
		while(y>2)
		{
			y-=1;
			gotoxy(i+1, y);
			printf("��");
			Sleep(40);
			gotoxy(i+1, y);
			printf("  ");
			printf("\b	");
		}
		if ((rnd<=i+2) && (i<(rnd+1)))
		{
			gotoxy(rnd, 2);
			printf("��");
			Beep(1046.502, 200);
			gotoxy(46, 10);
			COLOR(2);
			printf("������ϴ�!");
			COLOR(7);
			gotoxy(46, 12);
			printf("�����̽��� ������ ���...");
			Sleep(50);
			*r_c=*r_c+1;
		}
		else
		{
			COLOR(4);
			gotoxy(46, 10);
			printf("������ ���߽��ϴ�.");
			COLOR(7);
			gotoxy(46, 12);
			printf("�����̽��� ������ ���...");
		}
		getch();
	}
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void cursor(int n)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = n;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
