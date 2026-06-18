#include "Header.h"

//extern unsigned short XSpots[];
//extern unsigned short YSpots[];

extern unsigned short Spots[];

int t_t_t(int Player) {
	unsigned char A, B;

	short XSelect = 0;
	short YSelect = 0;

	int SelectedSpace = 0;

	do {
		system("cls");
		//std::cout << "Player #" << Player << "\'s turn\n";
		printf("Player #%d\'s turn\n", Player);
		draw_board(XSelect, YSelect, 0);

		A = getch();
		switch (A)
		{
			case 224:
				B = getch();
	
				switch(B)
				{
					case 72: 
						//cout << "up\n";
						(YSelect <= 0) ? YSelect = 2 : --YSelect;
						break;
					case 80: 
						//cout << "down\n";
						(YSelect >= 2) ? YSelect = 0 : ++YSelect;
						break;
					case 75: 
						//cout << "left\n";
						(XSelect <= 0) ? XSelect = 2 : --XSelect;
						break;
					case 77: 
						//cout << "right\n";
						(XSelect >= 2) ? XSelect = 0 : ++XSelect;
						break;
					}
				break;
			case 13:
				SelectedSpace = set_mark(Player, XSelect, YSelect);
				if (SelectedSpace) {
					//std::cout << "Player #" << SelectedSpace << " is already there\n"
					//	"(press space to choose a different spot)\n";
					printf("Player #%d is already there\n(press space to choose a different spot)\n", SelectedSpace);
					do { A = getch(); } while (A != 32);
				}
				break;
			case 27:
				printf("%d %d\n", A, B);
				return 7;
				break;
		}
		
		if (check_winner()) 
			return Player;
		if (check_cat(0))
			return 9;

	} while (A != 13);
	
	return 0;
}

int draw_board(unsigned short XSelect, unsigned short YSelect, int Last) {
/*
	unsigned char Walls = '³';
	unsigned char Middle[] = "Ä´ÃÄ´ÃÄ";
	unsigned char Select = '±';
	unsigned char Space = ' ';
*/

	unsigned char Walls = 186;
	unsigned char Middle[] = {205, 206, 205, 206, 205};
	unsigned char Select = 178;
	unsigned char Space = WHITESPACE;

	int j = 0;

	for (int i = 0; i < 6; ++i) {
		spaces(&Space, Select, XSelect, YSelect, i, j, Last);
		
		printf("%c%c", Space, Walls);
		Space = WHITESPACE;
		
		if (!((i + 1) % 2)) {
			spaces(&Space, Select, XSelect, YSelect, i + 1, j, Last);

			if (i == 5) printf("%c\n", Space);
			else printf("%c\n%c%c%c%c%c\n", 
					Space, 
					Middle[0],
					Middle[1],
					Middle[2],
					Middle[3],
					Middle[4]);

			Space = WHITESPACE;

			++j;
		}
	}

	return 0;
}

int spaces(unsigned char * Space, unsigned char Select, short XSelect, short YSelect, int i, int j, int Last) {
	if (Spots[i + j] == 1) {
		(*Space) = PLR1;
	}
	if (Spots[i + j] == 2) {
		(*Space) = PLR2;
	}
	
	if (XSelect == (i - (j * 2)) && !Last) {
		if (YSelect == j)
			(*Space) = Select;
	}
	
	return 0;
}

int set_mark(int Player, unsigned short XSelect, unsigned short YSelect) {
	unsigned short SpaceSelected = XSelect + ((YSelect) * 3);

	if (Spots[SpaceSelected]) 
		return Spots[SpaceSelected]; 
	else 
		Spots[SpaceSelected] = Player;

	return 0;
}
		
int check_winner() {
	int Winner = 0;

	h_check_winner(&Winner, 0);
	if (!Winner) {
		v_check_winner(&Winner, 0);
		if (!Winner)
			d_check_winner(&Winner);

	}

	return Winner;
}

int h_check_winner(int * Winner, int Index) {
	if (!(Index % 3) && Spots[Index])
		h_check_winner(Winner, Index + 1);
	else if (Spots[Index] && Spots[Index] == Spots[Index - 1]) {
		if (Index % 3 == 2) return (*Winner) = Spots[Index];
		
		h_check_winner(Winner, Index + 1);
	}
	if (*Winner) return *Winner;

	if (Index < 3) h_check_winner(Winner, 3);
	if (*Winner) return *Winner;
	
	if (Index < 6) h_check_winner(Winner, 6);
	if (*Winner) return *Winner;
	return *Winner = 0;

	/*
	if ((Index + 1) % 3 == 0)
		return Winner;
	
	if (!Index && Spots[Index]) {
		Winner = Spots[Index];
		h_check_winner(Winner, Index + 1);
	}
	else if (Winner == Spots[Index])
		h_check_winner(Winner, Index + 1);
	else {
		Winner = 0;
		return Winner;
	}
	*/
}
int v_check_winner(int * Winner, int Index) {
	if (Index < 3 && Spots[Index])
		v_check_winner(Winner, Index + 3);
	else if (Spots[Index] && Spots[Index] == Spots[Index - 3]) {
		if (Index > 5) return (*Winner) = Spots[Index];
		
		v_check_winner(Winner, Index + 3);
	}
	if (*Winner) return *Winner;

	if (!(Index % 3)) v_check_winner(Winner, 1);
	if (*Winner) return *Winner;
	
	if (Index % 3 == 1) v_check_winner(Winner, 2);
	if (*Winner) return *Winner;
	return (*Winner) = 0;
}
int d_check_winner(int * Winner) {
	int Middle = Spots[4];

	if (Spots[0] == Middle && Spots[8] == Middle)
		return (*Winner) = Middle;
	if (Spots[2] == Middle && Spots[6] == Middle)
		return (*Winner) = Middle;

	return (*Winner) = 0;
}

int check_cat(int Index) {
	if (Index == 9)
		return 1;
	if (Spots[Index])
		return check_cat(Index + 1);
	return 0;
}

		/* Old new line formatting
		if (!((i + 1) % 2) && i != 5) {
			Check_Space(Space, Select, XSelect, YSelect, i + 1, j);

			printf("%c\n%s\n", Space, Middle);
			Space = WhiteSpace;
			++j;
		}
		else if (i == 5) {
			Check_Space(Space, Select, XSelect, YSelect, i + 1, j);

			printf("%c\n", Space);
			Space = WhiteSpace;
			++j;
		}
		*/

	/*
	if (XSpots[(i - (j * 2))] == 2) {
		if (YSpots[j] == 2)
			Space = PLR2;
	}
	if (XSpots[(i - (j * 2))] == 2) {
		if (YSpots[j] == 2)
			Space = PLR2;
	}
	*/
