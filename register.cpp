#include "register.h"

void registerclass:: cycletab(){
    int i=movement++%6;
    move(frontcursorloc[i].my,frontcursorloc[i].mx);
    cout << frontcursorloc[i].my;
}  
 
void registerclass:: nxtbox(){
noecho();
keypad(stdscr, TRUE);  
cycletab();
 
while (int c=getch()){
int tab=(movement%6==0)?5:movement%6-1;
//assert(tab >= 0);
switch (c){

	case 10:
  case -53:
		//if (c==' '){ 
			if(tab==fbox)return; 
			if(tab==gbox){
   	 	username="<no input>";
			MMN="<no input>";
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
      case abox:
      if(int(c)!=127)printw("%c",c);
       username.append(1,c);
			usernames.open("newnames.txt");
			usernames<<username;
			usernames.close();
      break;
			case cbox:
       if(int(c)!=127)printw("%c",c);
       MMN.append(1,c);
			 mmn.open("maidennames.txt");
			 mmn<<MMN;
			 mmn.close();
      break;
			case dbox:
       if(int(c)!=127)printw("%c",'*');
       newpassword.append(1,c);
      break;
			case ebox:
       if(int(c)!=127)printw("%c",'*');
       confpassword.append(1,c);
      break;
        }

}
}
}

void registerclass:: name(){
	mvprintw(4,4,"Username");  

	WINDOW* abox = newwin(3, 36, 3, 25);
	refresh();
	box(abox, 0, 0);
	wrefresh(abox);
}
 
void registerclass:: MMName(){
	mvprintw(7,4,"Mother's maiden name");

	WINDOW* cbox = newwin(3, 36, 6, 25);
	refresh();
	box(cbox, 0, 0);
	wrefresh(cbox);
}

void registerclass:: registration(){ 
int x=0, y=1, w=66, h=20;

	WINDOW *win = newwin(h,w,y,x);

	refresh();
	move(1, 25);
	
	attron(A_BOLD);
	printw("REGISTRATION");
	attron(A_BOLD);

	box(win, 0, 0); 
	wrefresh(win);
} 
 
void registerclass:: displayPassword(){
	mvprintw(10, 4, "New Password");

	WINDOW* dbox = newwin(3, 36, 9, 25);
	refresh();
	box(dbox, 0, 0);
	wrefresh(dbox);
}
 
void registerclass:: displayPassword2(){
	mvprintw(13, 4, "Confirm New Password");
 
	WINDOW* ebox = newwin(3, 36, 12, 25);
	refresh();
	box(ebox, 0, 0);
	wrefresh(ebox);
}

void registerclass:: displayOkCancel(){
	WINDOW* fbox = newwin(3, 10, 16, 18);
	refresh();
	box(fbox, 0, 0);
	attron(A_BOLD);
	mvwprintw(fbox, 1, 1, "   OK");
	attron(A_BOLD);
	wrefresh(fbox);


	WINDOW* gbox = newwin(3, 10, 16, 39);
	refresh();
	box(gbox, 0, 0);
	attron(A_BOLD);
	mvwprintw(gbox,1, 1, " CANCEL");
	wrefresh(gbox);
}  

void registerclass:: comparepass(string newpassword, string confpassword){
	    if (newpassword != confpassword) 
        cout << "error: passwords do not match. unable to register.";
			else if (newpassword == confpassword) {
      	cout << "passwords match. you are now a registered user.";
				pass.open("newpass.txt");
				pass<<confpassword;
				pass.close();
			}
			else
			cout<<"error";
}

void registerclass:: finalout(){
	cout << "\n\nusername received was : " << username << endl;
	cout << "MMN received was : " << MMN << endl;
	cout << "passw obtained was : " << confpassword << endl;
	comparepass(newpassword, confpassword);
}