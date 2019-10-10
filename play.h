#include "sudoku.h"

class play {
public:
	sudoku *s;

	play() {
		s =  new sudoku();
		s->autoFill();

	
	}


	void execute () {
	int x, y, value;
	while(1){
			s->display();
			std::cin>>x>>y>> value;
			s->replace(x, y, value);

		}
	}	

};

