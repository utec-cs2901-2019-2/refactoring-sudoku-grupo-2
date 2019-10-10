#include "sudoku.h"

class play {
public:
	sudoku s;

	play() {
		int x, y, value;
		s.autoFill();

		while(!s.checkWin()){
			s.display();
			std::cin>>x>>y>> value;
			s.replace(x, y, value);
		}
	}

};

