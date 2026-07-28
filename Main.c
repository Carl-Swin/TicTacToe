#include "Header.h"

unsigned short Spots[9] = {0};

int main() {
#ifdef WIN_SYS
	SetConsoleOutputCP(65001);
#endif


	int Player = 0;
	int Winner = 0;

	while (!Winner && Winner != 9) {
		Winner = t_t_t(Player + 1);
		Player ? Player = 0 : ++Player;
	}

	system("cls");
	printf("\n");
	draw_board(0, 0, 1);

	if (Winner == 9) printf("Cat won the game!\n");
	else if (Winner == 7) printf("You have ended the game!\n");
	else printf("Player #%d Wins!\n", Winner);
	printf("(press space to exit)\n");

	do { Player = getch(); } while (Player != 32);


#ifdef WIN_SYS
	SetConsoleOutputCP(437);
#endif
	return Winner;
}
