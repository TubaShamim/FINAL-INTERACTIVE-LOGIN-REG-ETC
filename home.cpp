

#include "home.h"
#include "forgotpass.h"
#include "login.h"
#include "register.h" 

void homeclass:: cycletab(){
    int i=movement++%3;
    move(frontcursorloc[i].my,frontcursorloc[i].mx);
} 

void homeclass:: nxtbox(){
noecho();
keypad(stdscr, TRUE);  
cycletab();

while (int c=getch()){
int tab=(movement%3==0)?2:movement%3-1;
assert(tab >= 0 && tab < 3);
switch (c){ 

	case 10:
  case -53:
			if(tab==inbox){choice=login;return;}
			if(tab==upbox){choice=reg;return;}
			if(tab==fpbox){choice=reset;return;}
      break;


	case KEY_DOWN:
		cycletab();
		break;

}
}
}

 
void homeclass:: home(){  
	initscr(); 
	int x=0, y=1, w=60, h=15;
	WINDOW *win = newwin(h,w,y,x);
	refresh();
	move(4, 27);
	attron(A_BOLD);
	printw("HOME");
	wrefresh(win);
}

void homeclass:: signin(){
	mvprintw(5,26,"sign in");
	refresh();
}

void homeclass:: signup(){
	mvprintw(6,26,"sign up");
	refresh();
}

void homeclass:: resetPassword(){
	mvprintw(7, 25, "reset pass");
	refresh();
}