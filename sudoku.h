#include <iostream>
#include <vector>
#include <random>

#define vvint std::vector<vector<int>>
#define SZ 9

using namespace std;

class sudoku{
public:
	vvint tabla;
	sudoku(){
		for (int i = 0; i < 9; ++i) {
		    tabla.resize(9);
			for (int j = 0; j < 9; ++j)
			    tabla[i].resize(9);
		}
		
	}

	void autoFill(){
		srand (time(NULL));
		for(size_t i=0; i<SZ; i++){
			for(size_t j=0; j<SZ; j++){
				if (rand()%3 == 0) tabla[i][j] = rand()%9;
			}
		}
	}

	void replace (int x, int y, int value) {
	    tabla[y][x] = value;
	}

	void display () {
	    for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
		    cout << tabla[i][j] << " ";
		    if (j % 3 == 2) cout << "\t|\t";
		}
		cout << endl;
	    }
	}

	bool checkWin () {
	    vector<int> check;
	    for (int i = 0; i < 9; ++i) {
		check.clear();
		check.resize(9);
		for (int j = 0; j < 9; ++j) {
		    if (tabla[i][j] == 0) return false;			
		    if (check[tabla[i][j] - 1] == 1) return false;
		    check[tabla[i][j] - 1] = 1;
		}
		for (int j = 0; j < 9; ++j)
		    if (check[j] != 1) return false;
	    }

	    for (int i = 0; i < 9; ++i) {
		check.clear();
		check.resize(9);
		for (int j = 0; j < 9; ++j) {
		    if (tabla[i][j] == 0) return false;	
		    if (check[tabla[j][i] - 1] == 1) return false;
		    check[tabla[j][i] - 1] = 1;
		}
		for (int j = 0; j < 9; ++j)
		    if (check[j] != 1) return false;
	    }

	    int x_s, y_s;
	    for (int k = 0; k < 9; k++) {
		check.empty();
		check.resize(9);
		x_s = 0;
		y_s = 0;
		if (k % 3 == 0) 
		    x_s = 3;
		if (k % 3 == 1)
		    x_s = 6;
		if (k > 2)
		    y_s = 3;
		if (k > 5)
		    y_s = 6;

		for (int i = 0; i < 3; i++){
		    for (int j = 0; j < 3; j++) {
		    if (tabla[i][j] == 0) return false;	
		        if (check[tabla[i + y_s][j + x_s] - 1] == 1) return false;
		        check[tabla[i+ y_s][j + x_s] - 1] = 1;
		    }
		}
	    }
	    return true;
	}

};
