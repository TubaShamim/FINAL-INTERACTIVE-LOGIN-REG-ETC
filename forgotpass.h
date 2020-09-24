#ifndef FORGOTPASS_H
#define FORGOTPASS_H

#include <iostream>
#include <curses.h> 
#include <assert.h>   
#include "coord.h"  
#include <string> 
#include <fstream>
using namespace std;


class forgotpass{ 
private:
  fstream pass;
  string newpassword; 
  string confpassword;
  int movement;
  enum movement {ebox,pbox,obox,cbox};
  coord frontcursorloc[4]={coord(22,4),coord(22,7),coord(20,11),coord(38,11)}; 
	void cycletab();
	void nxtbox();
	void displayresetpass();
	void displaynewpass();
	void displayconfPassword();
	void displayOkCancel();
	void comparepass(string newpassword, string confpassword);
	void finalout();
public:
	void display(){
		initscr();
		noecho();
		cbreak();
		displayresetpass();
		displaynewpass(); 
		displayconfPassword(); 
		displayOkCancel();
		nxtbox();
		getch();
		endwin();
		finalout();
	}
};

#endif