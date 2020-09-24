#include "login.h"

void loginclass:: cycletab(){
    int i=movement++%4;
    move(frontcursorloc[i].my,frontcursorloc[i].mx);
    cout << frontcursorloc[i].my;
} 
 
void loginclass:: nxtbox(){
noecho();
keypad(stdscr, TRUE);  
cycletab();

while (int c=getch()){
int tab=(movement%4==0)?3:movement%4-1;
//assert(tab >= 0);
switch (c){ 

	case 10:
  case -53:
		//if (c==' '){ 
			if(tab==obox)return;
			if(tab==cbox){
   	 	username="<no input>";
    	password="<no input>"; 
			break;
			}
      break;
		//}

	case KEY_RIGHT:
		cycletab();
		break;

	/*case KEY_LEFT:
			backcycletab1();
	break;*/
 
	default:
    switch(tab){ 
      case ebox:
      if(int(c)!=127)printw("%c",c);
       username.append(1,c);
      break;
			case pbox:
       if(int(c)!=127)printw("%c",'*');
       password.append(1,c);
      break;
        }

}
}
}
 
void loginclass:: displayLogin(){  
	initscr();
	int x=0, y=1, w=60, h=15;
	WINDOW *win = newwin(h,w,y,x);
	refresh();
	move(1, 27);
	attron(A_BOLD);
	printw("LOGIN");
	box(win, 0, 0);
	wrefresh(win);
}

void loginclass:: displayEmail(){
	mvprintw(4,4,"Username");
	WINDOW* ebox = newwin(3, 35, 3, 20);
	refresh();
	box(ebox, 0, 0); 
	wrefresh(ebox);
}

void loginclass:: displayPassword(){
	mvprintw(7, 4, "Password");
	WINDOW* pbox = newwin(3, 35, 6, 20);
	refresh();
	box(pbox, 0, 0);
	wrefresh(pbox);
}

void loginclass:: displayOkCancel(){
	WINDOW*  obox = newwin(3, 10, 12, 14);
	refresh();
	box(obox, 0, 0);
	attron(A_BOLD);
	mvwprintw(obox, 1, 1, "   OK");
	attron(A_BOLD);
	wrefresh(obox);


	WINDOW* cbox = newwin(3, 10, 12, 34);
	refresh();
	box(cbox, 0, 0);
	attron(A_BOLD); 
	mvwprintw(cbox,1, 1, " CANCEL");
	attron(A_BOLD);
	wrefresh(cbox);
}  
   
void loginclass:: resetpass(){
attron(A_UNDERLINE); 
mvprintw(10,21,"Reset password...");
attroff(A_UNDERLINE);
} 

int loginclass:: verifyusername(){  
		uname.open("names.txt"); 
			while (uname >> temp1) { 
				if (temp1.compare(username) == 0){
					cout<<"\n[ "<<username<<" ] has been found in the database.";	
					uname.close();
					return 1;
				}
				else{ 
					cout<<"\nACCESS DENIED [wrong username]";
					break;
				}
			}
		uname.close();
return 0; 
} 

int loginclass:: verifypass(){ 
			upass.open("pass.txt");
			while (upass >> temp2) { 
				if (temp2.compare(password) == 0){
					cout<<"\npass found.";
					upass.close();
					return 1;
				}
				else{
					cout<<"\nACCESS DENIED [wrong pass]";
					break; 
				} 
			}
			upass.close();
return 0; 
} 
  
int loginclass:: verifyboth(){
uname.open("names.txt"); 
upass.open("pass.txt");
	while ((upass >> temp2)&&(uname>>temp1)) {
		if (temp1.compare(username) ==0 && temp2.compare		(password) ==0){
			cout<<"\n\nyou can now login!!";
			uname.close();
			upass.close();
			return 1;
		}
		else {
			cout<<"\n\nyou can not login!!";
		break;
		}
	}
uname.close();
upass.close();
return 0;
}

void loginclass:: finalout(){
cout << "\n\nusername received was : " << username << endl;
cout << "passw obtained was : " << password << endl;
verifyusername();
verifypass();
verifyboth();
}