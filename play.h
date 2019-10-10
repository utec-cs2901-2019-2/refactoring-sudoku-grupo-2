#include "sudoku.h"

class play{
public:
	sudoku s;

	play(){
		int x, y;
		while(!s.checkWin()){
			s.autoFill();
			s.display();
			std::cin>>s.x>>s.y;
			s.replace(s.tabla, x, y);
		}
	}

}

