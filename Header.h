
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <conio.h>

#if defined(_WIN32) || defined(_WIN64)
	#define WIN_SYS
	#include <windows.h>
#endif


# define PLR1 "x"
# define PLR2 "o"

# define WHITESPACE " "
# define VERT "\u2551"
# define HORI "\u2550"
# define CROS "\u256C" //206
# define CURS "\u2592" //178, 176, 177

int t_t_t(int Player);
int draw_board(unsigned short XSelect, unsigned short YSelect, int Last);
int set_mark(int Player, unsigned short XSelect, unsigned short YSelect);
int spaces(char * Space, const char * Select, short XSelect, short YSelect, int i, int j, int Last);

int check_winner();
int h_check_winner(int * Winner, int Index);
int v_check_winner(int * Winner, int Index);
int d_check_winner(int * Winner);

int check_cat(int Index);
