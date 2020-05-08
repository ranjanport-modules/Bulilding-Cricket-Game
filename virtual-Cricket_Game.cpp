//============================================================================
// Name        : virtual-Cricket_Game.cpp
// Author      : Aman Ranjan
// Version     :v1.0
// Copyright   : This code is free and can be used without prior notice.
// Description : This is a virtual cricket Game.
//============================================================================

#include "game.h"
using namespace std;



int main()
{
	setbuf(stdout,NULL);
	Game gamewelcome , cont_msg,pollmessage,playmsg,selectionview,Tossmsg;
	Game playerlist,takeinput,TossWin;
	Game Inningcall,Summary;

	gamewelcome.welcome();		//Show Welcome message For Players With Instruction

	cout<<endl;

	//cont_msg.showAllPlayer();

	cout << "Press Enter to Continue..."<<endl;
		cin.ignore();

	pollmessage.poolmsg();			//Poll Message display function

	playerlist.showAllPlayer(); 		//Shows the Available Players

	cout << "Press Enter to Continue..."<<endl;		//Enter to Continue Display Tag
			cin.ignore();

	//cin.ignore(numeric_limits <streamsize> :: max(),'\n');  //Clr buffer

	playmsg.box_create();		//Print Create Team Message

//	cin.ignore(numeric_limits <streamsize> :: max(),'\n');		//Clr buffer


	takeinput.pselectA();		//Team Create Function A

	//cin.ignore(numeric_limits <streamsize> :: max(),'\n');	//Clr buffer

	takeinput.pselectB();		//Team Create Function B

	cin.ignore(numeric_limits <streamsize> :: max(),'\n');	//Clr buffer

	selectionview.displayselection();

	cout << "Press Enter to Toss..."<<endl;
				cin.ignore();

	Tossmsg.tossmsg();		//Toss message

	cin.ignore(numeric_limits <streamsize> :: max(),'\n');	//Clr buffer

	TossWin.toss();			//Do the toss

	cin.ignore(numeric_limits <streamsize> :: max(),'\n');	//Clr buffer

	Inningcall.firstIning();			//First Inning Match

	cout << "Press Enter to Toss..."<<endl;
					cin.ignore();

	Inningcall.secondinnings();			//Second Inning Match

	Summary. summary();				//Summary of the Match

	return 0;
}

