#include <vector>
#include "player.h"

class Team {
	public:

	Team();
		string name;
		int totalRuns;
		int wicketLost;
		int totalBallsBowled;
		vector <Player> players;


};
