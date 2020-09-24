#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <fstream>
#include <curses.h>
#include <assert.h> 
#include "coord.h"  
#include <string>

//#include "amgui.h"
using namespace std;

class loginclass {
	private:
		fstream uname, upass;
		string password; 
		string temp1, temp2;
		string username;
		int movement;
		enum movement {ebox,pbox,obox,cbox};
		coord frontcursorloc[4]={coord(22,4),coord(22,7),coord(20,13),coord(38,13)}; 
		void cycletab();
		void nxtbox();
		void displayLogin();
		void displayEmail();
		void displayPassword();
		void displayOkCancel();
		void resetpass();
		int verifypass();
		int verifyboth();
		void finalout();
		int verifyusername();

	public:
		void displayloginpage(){
			initscr(); 
			noecho();
			cbreak();
			displayLogin();
			displayEmail();
			displayPassword(); 
			resetpass();
			displayOkCancel();
			nxtbox();
			getch();
			//endwin();
			finalout();
			erase();
			refresh();
		}
};

#endif