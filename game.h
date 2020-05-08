#include <iostream>
#include <ctime>
#include <limits>
#include <cstdlib>
#include "team.h"
class Game {

 public:

	Game();
		Team teamA, teamB;
		Team *battingTeam;
		Team *bowlingTeam;
		Player *batsman, *bowler;
		bool isFirstinning;

		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		string players[11];

		void welcome();
		void showAllPlayer();
		void poolmsg();
		int takeInput();
		void box_create();
		bool Validate(int);
		void pselectA();
		void pselectB();
		void displayselection();
		void tossmsg();
		void toss();
		void tossChoice(Team);
		void firstIning();
		void INT_Player();
		void playinings();
		void bat();
		bool validateInings();
		void showscorecard();
		void secondinnings();
		void swap();
		void  summary();


};


