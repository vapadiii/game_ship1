#include<stdio.h>
#include<windows.h>
#include<conio.h>

int main() {
	char ch = ' ';
	int x = 38, y = 20;
	int j;
	/*for(j=0; j<80; j++) {
		printf("%d",j%10);
	}*/
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = getch();
			if (ch == 'a') {
				if (x > 0) {
					erase_ship(x, y);
					draw_ship(--x, y);
				}

			}
			if (ch == 'd') {
				if (x < 75) {
					erase_ship(x, y);
					draw_ship(++x, y);
				}
			}
			if (ch == 'w') {
				if (y > 0) {
					erase_ship(x, y);
					draw_ship(x, --y);
				}

			}
			if (ch == 's') {
				erase_ship(x, y);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}

void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
	gotoxy(x, y);
	printf("<-0->");
}

void erase_ship(int x, int y) {
	gotoxy(x, y);
	printf("     ");
}