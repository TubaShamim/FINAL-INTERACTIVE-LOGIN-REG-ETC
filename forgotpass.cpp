#include "forgotpass.h"

void forgotpass::cycletab(){
    int i=movement++%4;
    move(frontcursorloc[i].my,frontcursorloc[i].mx);
    cout << frontcursorloc[i].my;
} 

void forgotpass::nxtbox(){
noecho();
keypad(stdscr, TRUE);  
cycletab();

while (int c=getch()){
int tab=(movement%4==0)?3:movement%4-1;
//assert(tab > 0);
switch (c){ 

	case 10:
  case -53:
		//if (c==' '){ 
			if(tab==obox)return;
			if(tab==cbox){
   	 	    	newpassword="<no input>"; 
					confpassword="<no input>";
			return;
			}
      break;
		//}

	case KEY_RIGHT:
		cycletab();
		break;
 
	default:
    switch(tab){ 
      case ebox:
      if(int(c)!=127)printw("%c",'*');
       newpassword.append(1,c);
      break;
			case pbox:
       if(int(c)!=127)printw("%c",'*');
       confpassword.append(1,c);
      break;
        }

}
}
}

void forgotpass::displayresetpass(){  
		initscr(); 
		int x=0, y=1, w=60, h=13;
		WINDOW *win = newwin(h,w,y,x);
		refresh();
	move(1, 24);
	attron(A_BOLD);
	printw("RESET PASS");
	box(win, 0, 0);
	wrefresh(win);
}

void forgotpass::displaynewpass(){
	mvprintw(4,4,"new pass");
	WINDOW* ebox = newwin(3, 35, 3, 20);
	refresh();
	box(ebox, 0, 0); 
	wrefresh(ebox);
}

void forgotpass::displayconfPassword(){
	mvprintw(7, 4, "confirm new pass");
	WINDOW* pbox = newwin(3, 35, 6, 20);
	refresh();
	box(pbox, 0, 0);
	wrefresh(pbox);
}

void forgotpass::displayOkCancel(){
	WINDOW*  obox = newwin(3, 10, 10, 14);
	refresh();
	box(obox, 0, 0);
	attron(A_BOLD);
	mvwprintw(obox, 1, 1, "   OK");
	attron(A_BOLD);
	wrefresh(obox);


	WINDOW* cbox = newwin(3, 10, 10, 34);
	refresh();
	box(cbox, 0, 0);
	attron(A_BOLD); 
	mvwprintw(cbox,1, 1, " CANCEL");
	attron(A_BOLD);
	wrefresh(cbox);
} 

void forgotpass::comparepass(string newpassword, string confpassword){
	if (newpassword != confpassword) 
    cout << "error: passwords do not match";
	else if (newpassword == confpassword) {
    cout << "passwords match. pass has been reset.";
			pass.open("newpass.txt");
			pass<<confpassword;
			pass.close();
	}
	else
		cout<<"error";
}

void forgotpass::finalout(){
	cout << "\n\nnew-passw received was : " << newpassword << endl;
	cout << "confirmed-passw obtained was : " << confpassword << endl;
	comparepass(newpassword, confpassword);
} 
