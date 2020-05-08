#include  "game.h"
#include <unistd.h>
#include <ctime>
using namespace std;

Game :: Game()
{
			  teamA.name = "Team-A";
			  teamB.name = "Team-B";

			  maxBalls = 6;
			//  playersPerTeam = 4;
			  totalPlayers = 11;

			  players[0] = "Virat";
			  players[1] = "Rohit";
			  players[2] = "Dhavan";
			  players[3] = "Rahul";
			  players[4] = "Hardik";
			  players[5] = "Dhoni";
			  players[6] = "Pant";
			  players[7] = "Jadeja";
			  players[8] = "Bumrah";
			  players[9] = "B.Kumar";
			  players[10] = "Aswin";

			 *battingTeam;
			 *bowlingTeam;
			 *batsman, *bowler;
			 isFirstinning = false;

}
//=================================================================================================================================================================
//Welcome message for the Teams
void Game :: welcome()
{
	cout<<""<<endl;
	cout <<"\t\t--------------------------------------------------------"<<endl;
	cout <<"\t\t========================================================"<<endl;
	cout <<"\t\t|                                                      |"<<endl;
	cout <<"\t\t     Welcome to The Virtual Cricket Game Application    "<<endl;
	cout <<"\t\t|                                                      |"<<endl;
	cout <<"\t\t--------------------------------------------------------"<<endl;
	cout <<"\t\t========================================================"<<endl;

	cout <<endl<<endl<<endl<<endl;

	cout <<"\t\t--------------------------------------------------------"<<endl;
	cout <<"\t\t===================Instructions========================="<<endl;
	cout <<"\t\t|                                                      |"<<endl;
	cout <<"\t\t  1. Create 2 Teams (Team-A , Team-B with 4"
			"\n\t\t\tPlayers each)from the pool of 11 players."<<endl;
	cout <<"\t\t  2. Lead the toss and decide the choice of Play."<<endl;
	cout<< "\t\t  3. Each innings will be of 6 Balls."<<endl;
	cout <<"\t\t|                                                      |"<<endl;
	cout <<"\t\t--------------------------------------------------------"<<endl;
	cout <<"\t\t========================================================"<<endl;
}
//=================================================================================================================================================================
//Showing  Poll Msg..
void Game :: poolmsg()
{
			cout <<"\t\t--------------------------------------------------------"<<endl;
			cout <<"\t\t================ : Pool Of Players : ==================="<<endl;
}
//=================================================================================================================================================================
//showing all Player Name with index function
void Game :: showAllPlayer()
		{
			for(int i = 0 ; i < totalPlayers ; i++)
			{
				cout << "\t\t" << "[" << i+1 << "]" << players[i] << endl;
			}

		}
//=================================================================================================================================================================
//Box Msg to Create Teams
void Game :: box_create()
{
	cout <<"\t\t|-------------------------------------------------------|"<<endl;
	cout <<"\t\t|=============Create Team-A And Team-B==================|"<<endl;
	cout <<"\t\t|-------------------------------------------------------|"<<endl;
}
//=================================================================================================================================================================
//Reference For function Validate()
bool Game :: Validate(int index)
{
	int n;
	vector <Player> players;
	//Team A check
	players = teamA.players;
	n = players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].index == index )
		{
			return false;
		}
	}

	//Team B Check
	players = teamB.players;
		n = players.size();
		for(int i=0;i<n;i++)
		{
			if(players[i].index == index )
			{
				return false;
			}

		 }
		return true;
}
//=================================================================================================================================================================
//Function to take user input for player selection
int Game :: takeInput()
{
	int n;
	while(!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize> :: max(),'\n');
		cout << "Invalid Input!  Try Again : ";
	}
	return n;
}
//=================================================================================================================================================================
//function for selection of players from the pool given
void Game  :: pselectA()		//Team A
{
	for(int i = 0; i < 4; i++)
	{
		//Team-A Input
		team:
		cout <<"\n"<< "Select Player" << i+1 << "of Team-A : ";
		int playerIndexTeam_A = takeInput();

		if(playerIndexTeam_A < 0 || playerIndexTeam_A >11 )
		{
			cout << endl<< "Enter Correct Player Index : " ;
			goto team;
		}
		else if( ! (Validate(playerIndexTeam_A)))
				{
					cout <<"Player Already Added! Please Select Another Player : ";
							goto team;
				}

		else
		{
					Player team_A_player;
					team_A_player.index = playerIndexTeam_A;
					team_A_player.name = players[playerIndexTeam_A];
					teamA.players.push_back(team_A_player);
		}
	}
}
//=================================================================================================================================================================

void Game :: pselectB()		//Team B
{
	for(int i = 0; i < 4; i++)
	{
		//Team-B Input
		team1:
		cout <<"\n"<< "Select Player" << i+1 << "of Team-B : ";
		int playerIndexTeam_B = takeInput();
		if(playerIndexTeam_B < 0 || playerIndexTeam_B >11 )
				{
					cout << endl<< "Enter Correct Player Index : " ;
					goto team1;
				}
		else if( ! (Validate(playerIndexTeam_B)))
				{
					cout <<"Player Already Added! Please Select Another Player : ";
							goto team1;
				}
				else
				{
					Player team_B_player;
					team_B_player.index = playerIndexTeam_B;
					team_B_player.name = players[playerIndexTeam_B];
					teamA.players.push_back(team_B_player);
				}
	}
}
//=================================================================================================================================================================
//Function to display the selected players from the pool selection
void Game :: displayselection()			//TODO
{
	vector <Player> displayA = teamA.players;
	vector <Player> displayB = teamB.players;

	cout <<"------------------------"<< endl;
	cout <<"=======TEAM-A==========="<< endl;
	cout <<"------------------------"<< endl;

	for(int i = 0; i < 4; i++)
	{
		cout <<"|"<<"[" << i+1 << "]" << displayA[i].name <<"|"<<endl;
	}

	cout <<"\t\t------------------------"<< endl;
	cout <<"\t\t=======TEAM-B==========="<< endl;
	cout <<"\t\t------------------------"<< endl;

	for(int i = 0; i < 4; i++)
	{
		cout <<"|"<<"[" << i+1 << "]" << displayB[i].name <<"|"<<endl;
	}
}
//=================================================================================================================================================================
//Function for display the  toss message
void Game :: tossmsg()
{
	cout << "-----------------------------"<<endl;
	cout << "|========Let's Toss=========|"<<endl;
	cout << "-----------------------------"<<endl;

	cout <<"Tossing The Coin..." <<endl;
	sleep(3.2);
}
//=================================================================================================================================================================
//Function to Toss For the Selection Of who will Bat or Bowl
void Game :: toss()
{
	srand(time(NULL));
	int A = (rand()%2)+1;

	switch(A)
	{
	case 1:
		cout << "Team-A Win the Toss" <<endl;
		tossChoice(teamA);
		break;

	case 2:
		cout << "Team-A Win the Toss" << endl;
		tossChoice(teamB);
		break;
	}
}
//=================================================================================================================================================================
//Function to Toss and choice for the Baaing or either Bowling
void Game :: tossChoice(Team tosswiner)

{
	cout << "Enter \n 1.Bat \n2.Bowl";
	int tosschoice = takeInput();
	cin.ignore(numeric_limits<streamsize> :: max(),'\n');
	switch(tosschoice)
	{
	case 1:
			cout << tosswiner.name <<"Won the Toss and Elected to Bat First"<<endl;
			//If Team A Won the Toss
			if(tosswiner.name.compare("Team-A") == 0)
			{
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}
			else
			{
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			break;

	case 2:
		cout << tosswiner.name <<"Won the Toss and Elected to Bowl First" <<endl;
		//If Team B Won the Toss
		if(tosswiner.name.compare("Team-A") == 0)
		{
			battingTeam = &teamB;
			bowlingTeam = &teamA;
		}
		else
		{
			battingTeam = &teamA;
			bowlingTeam = &teamB;
		}
		break;

	default:
		cout << "Invalid Input Try Again ";
		tossChoice(tosswiner);
	}
}
//===================================================================================================================================================================
//Function to start the First Inings
void Game :: firstIning()
{
	cout <<"\t\t================================"<<endl;
	cout <<"\t\t=====First Innings Starts======="<<endl;
	cout <<"\t\t================================"<<endl;
	isFirstinning = true;
	INT_Player();
}
//=================================================================================================================================================================
//Initialize the  Players in a team
void Game :: INT_Player()
{
	batsman =&battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " " << batsman->name <<"is Batting" <<endl;
	cout << bowlingTeam->name << " " << bowler->name  <<"is Bowling" <<endl;
}
//=================================================================================================================================================================
//Function call for a Innings start
void Game ::  playinings()
{
	for(int i=0; i<6; i++)
	{
		 cout <<"Press Enter To Bowl...";
		cin.ignore();

		 cout <<"Bowling..."<<endl;
		  bat();

		  if(!validateInings())
		  {
			  break;
		  }
	}
}
//=================================================================================================================================================================
//Function to call for the battings
void Game :: bat()
{
	srand(time(NULL));
	int runScored = rand() % 7;
	//Updatation for batsman Details
	batsman->runsScored = batsman->runsScored + runScored;
	battingTeam->totalRuns = battingTeam->totalRuns + runScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

//Updatation of Bowler Details
	bowler->ballsbowled = bowler->ballsbowled +1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven +runScored;

		if(runScored != 0)
		{
			cout << endl << bowler->name <<" to" << batsman->name << runScored << " runs!" <<endl <<endl;
			showscorecard();
		}
		else
		{
			cout << bowler->name << " to " << batsman->name << " OUT!" <<endl <<endl;
			battingTeam->wicketLost = battingTeam->wicketLost +1;
			bowler->wicketTaken = bowler->wicketTaken +1;

			showscorecard();

		int nextPlayer = battingTeam->wicketLost;
		batsman = &battingTeam->players[nextPlayer];
		}
}
//=================================================================================================================================================================
//Function to validate that the current  Innings is over or not
bool Game :: validateInings()
{
	if(!isFirstinning)
	{
		if(battingTeam->wicketLost == 4 || bowlingTeam->totalBallsBowled == 6)
		{
			cout << "\t\t||===First Innings End===||"<<endl<<endl;
			cout << battingTeam->name<< " " <<battingTeam->totalRuns<<" -"<<battingTeam->wicketLost << "{"<<bowlingTeam->totalBallsBowled<<"}"<<endl;
			cout<< bowlingTeam->name << "needs" << battingTeam->totalRuns +1 <<"Runs To Win The Match" <<endl<<endl;
			 return false;
		}
	}
	else
	{
		if(battingTeam->totalRuns > bowlingTeam->totalRuns )
			{
			cout << "\t\t||===Second Innings End===||"<<endl<<endl;
			cout << battingTeam->name<< " " <<battingTeam->totalRuns<<" -"<<battingTeam->wicketLost << "{"<<bowlingTeam->totalBallsBowled<<"}"<<endl;
			cout<< bowlingTeam->name << "Scored" << battingTeam->totalRuns <<endl<<endl;
			cout <<endl<<endl<<battingTeam<<"Won the Match"<<endl;
			}
		if((battingTeam->wicketLost == 4 || bowlingTeam->totalBallsBowled == 6))
		{
			cout << battingTeam->name<< " " <<battingTeam->totalRuns<<" -"<<battingTeam->wicketLost << "{"<<bowlingTeam->totalBallsBowled<<"}"<<endl;
			cout<< bowlingTeam->name << "needs" << battingTeam->totalRuns +1  <<endl<<endl;
			cout << bowlingTeam <<"Won The Match"<<endl;
		}
	}
	return true;
}

//=================================================================================================================================================================
//After Each Match Score Must be Shown The work Of the Function
void Game :: showscorecard()
{
	cout << "==========================================================="<<endl;

	cout << "\t"<<battingTeam->name << " "<<battingTeam->totalRuns<<" "
			<<battingTeam->wicketLost<< " " <<  "{"<<bowlingTeam->totalBallsBowled
			<<"} |" <<batsman->name <<batsman->runsScored<<"{"<<batsman->ballsPlayed
			<<"}\t" << bowler->name <<" "<< bowler->ballsbowled <<"-" << bowler->runsGiven
			<<"-"<<bowler->wicketTaken<<"\t"<<endl;

	cout << "==========================================================="<<endl;
}
//=================================================================================================================================================================
//Function to swap the Players
void Game :: swap()
	{
		bowler =&battingTeam->players[0];
		batsman = &bowlingTeam->players[0];

		cout << battingTeam->name << " " << batsman->name <<"is Batting" <<endl;
		cout << bowlingTeam->name << " " << bowler->name  <<"is Bowling" <<endl;
	}
//=================================================================================================================================================================
//Second Innings Play Function
void Game :: secondinnings()
	{
		cout <<"\t\t================================"<<endl;
		cout <<"\t\t=====Second Innings Starts======="<<endl;
		cout <<"\t\t================================"<<endl;
		isFirstinning = false;
		swap();
		playinings();
		validateInings();

	}


//=================================================================================================================================================================
//Function to show the Summary Of the Match
void Game :: summary()
{
	batsman =&battingTeam->players[0];
	bowler = &bowlingTeam->players[0];
	cout << "Team-A" <<battingTeam->totalRuns << battingTeam->wicketLost << bowlingTeam->totalBallsBowled <<endl;
	cout <<"\t\t==============================================="<<endl;
	cout <<"\t\t| " <<" Player" <<"\t Batting" << "\t Bowling"<<endl;
	cout <<"\t\t-----------------------------------------------"<<endl;

		for(int i=0; i<4;i++)
		{
			cout <<"\t\t| " << "[" <<i+1 <<"]" << players[i] << battingTeam->totalRuns << bowlingTeam->totalBallsBowled << "\t|"<<endl;
			cout <<"-----------------------------------------------"<<endl;
		}
							cout <<endl<<endl;
	//=============================================================================================================================================================
			bowler =&battingTeam->players[0];
			batsman = &bowlingTeam->players[0];

			cout << "Team-A" <<battingTeam->totalRuns << battingTeam->wicketLost << bowlingTeam->totalBallsBowled <<endl;
			cout <<"\t\t==============================================="<<endl;
			cout <<"\t\t| " <<" Player" <<"\t Batting" << "\t Bowling"<<endl;
			cout <<"\t\t-----------------------------------------------"<<endl;

			for(int i=0; i<4;i++)
			{
				cout <<"\t\t| " << "[" <<i+1 <<"]" << players[i] << battingTeam->totalRuns << bowlingTeam->totalBallsBowled << "\t|"<<endl;
				cout <<"\t\t-----------------------------------------------"<<endl;
			}
}


/*int pSwap = *battman;
			*battman = *bowwlman;
			*bowwlman = pSwap;
			return;
			*/

