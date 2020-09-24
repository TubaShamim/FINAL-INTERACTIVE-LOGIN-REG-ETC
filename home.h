#ifndef HOME_H
#define HOME_H

#include <iostream>
#include <fstream>
#include <curses.h>
#include <assert.h> 
#include "coord.h"  
#include <string>
using namespace std;

class homeclass {
	private:
		void cycletab();
		void nxtbox();
		void home();
		void signin();
		void signup();
		void resetPassword();
		int movement;
		enum movement {upbox,inbox,fpbox};
		coord frontcursorloc[3]={coord(28,5),coord(28,6),coord(28,7)}; 
	public:
	string choices [3] = {"sign up", "sign in", "forgot pass"};
enum  scr {login,reg,reset};
int choice;

		void display(){
			initscr();
			noecho();
			cbreak();
			home();
			signup();
			signin(); 
			resetPassword(); 
			nxtbox();
			//getch();
			erase();
			refresh();
		}

};

#endif