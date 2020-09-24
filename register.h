#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <fstream>
#include <curses.h>
#include <assert.h> 
//#include "amgui.h"
#include "coord.h"  
#include <string>
using namespace std;

class registerclass {
	private:
		fstream usernames;
		fstream mmn;
		fstream pass;
		string newpassword;
		string username;
		string MMN; 
		string confpassword;
		int movement;
		enum movement {abox,cbox,dbox,ebox,fbox,gbox};
		coord frontcursorloc[6]={coord(26,4),coord(26,7),coord(26,10),coord(26,13),coord(22,17),coord(43,17)}; 
		void cycletab();
		void nxtbox();
		void name();
		void MMName();
		void registration();
		void displayPassword();
		void displayPassword2();
		void displayOkCancel();
		void comparepass(string newpassword, string confpassword);
		void finalout();
	public:
		void displayregisterpage(){
			initscr();
			noecho();
			cbreak();
			registration();
			name();
			MMName();
			displayPassword();
			displayPassword2();
			displayOkCancel();
			nxtbox();
			getch();
			endwin();
			finalout();
		}
};

#endif