#include "sudoku.h"

class play {
public:
	sudoku s;

	play() {
		int x, y;
		s.autoFill();

		while(!s.checkWin()){
			s.display();
			std::cin>>x>>y;
			s.replace(s.tabla, x, y);
		}
	}

};

