#include <stdlib.h> 
#include <stdio.h>
#include <conio.h>

# define PLR1 'x'
# define PLR2 'o'

# define WHITESPACE ' '
# define VERT 186
# define HORI 205
# define CROS 206
# define CURS 178 // 176, 177

int t_t_t(int Player);
int draw_board(unsigned short XSelect, unsigned short YSelect, int Last);
int set_mark(int Player, unsigned short XSelect, unsigned short YSelect);
int spaces(unsigned char * Space, unsigned char Select, short XSelect, short YSelect, int i, int j, int Last);

int check_winner();
int h_check_winner(int * Winner, int Index);
int v_check_winner(int * Winner, int Index);
int d_check_winner(int * Winner);

int check_cat(int Index);
