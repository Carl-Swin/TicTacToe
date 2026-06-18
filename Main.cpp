#include "Header.h"
using namespace std;

//NOT ENOUGH DATA FOR ALL SPACES -- FIX
//unsigned short XSpots[3] = {0};
//unsigned short YSpots[3] = {0};

unsigned short Spots[9] = {0};

int main() {
	int Player = 0;
	int Winner = 0;

	while (!Winner && Winner != 9) {
		//system("cls");
		//std::cout << "Player #" << Player + 1 << "\'s turn\n";

		Winner = t_t_t(Player + 1);
		Player ? Player = 0 : ++Player;
	}

	system("cls");
	cout << "\n";
	draw_board(0, 0, 1);

	if (Winner == 9) cout << "Cat won the game!\n";
	else cout << "Player #" << Winner << " Wins!\n";
	cout << "(press space to exit)\n";

	do { Player = getch(); } while (Player != 32);

	return Winner;
}
