#include <iostream>
#include <vector>
#include <random>

#define vvint std::vector<vector<int>>
#define SZ 9

class sudoku{
private:
	vvint tabla;

public:

	sudoku(vvint tabla){
		this->tabla = tabla
	}

	void autoFill(vvint table){
		srand (time(NULL));
		for(size_t i=0; i<SZ; i++){
			for(size_t j=0; j<SZ; j++){
				if (rand()%3 == 0) table[i][j] = rand()%9;
			}
		}
	}

	void display(){}

	void replace(vvint table, int x, int y){}

	bool checkWin(){}

}
