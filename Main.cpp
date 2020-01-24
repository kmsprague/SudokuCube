/*
Name: Kyle Sprague
Program: SudokuCube
Headers: Cube.h
Running instructions: ran using a c++ compiler including the headerfile "cube.h" 
						program will prompt and wait when responses are needed from the user. 

*/

#include <iostream>
#include "Cube.h"

using namespace std; 


int main() {

	int n = 0; 
	Cube cube1;  
	
	cout << "Here is the cube in its solved state: " << endl; 

	cube1.printCube();
	
	cout << endl << "Each cubie has a number and the side it belongs to in the solved state" << endl; 
	cout << "and the cube is layed out as such: " << endl;
	cout << "           top(^)" << endl << "left(<)    front(f)    left(l)    back(b)" << endl;
	cout << "           bottom(~)" << endl;
	cout << endl << endl; 

	cout << "Enter the number of moves you want for the cube to be scrambled: "; 
	cin >> n; 
	cout << endl;

	cube1.scrambleCube(n);
	cout <<endl << endl<<  "Here is the scrambled layout of the cube: " << endl;
	cube1.printCube(); 

	cout << endl << "Here is the hueristic approximation for the fewest number of moves to solve: " << cube1.hueristic();

	cout << endl << endl;
	
	return 0; 
}