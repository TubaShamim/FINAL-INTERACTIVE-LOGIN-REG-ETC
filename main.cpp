#include <iostream> 
#include "forgotpass.h"
#include "login.h"
#include "register.h"  
#include "home.h"
using namespace std;    
  
int main (){ 

loginclass login; 
forgotpass forgot;
registerclass regi;
 

homeclass temp4;
temp4.display();

if (temp4.choice==temp4.login){
login.displayloginpage(); 
}

else if (temp4.choice==temp4.reg){
regi.displayregisterpage();
}

else if (temp4.choice==temp4.reset){
forgot.display();
}


}











