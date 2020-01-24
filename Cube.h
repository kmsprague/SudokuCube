#pragma once

#include <iostream>
#include <time.h> 

using namespace std; 

class Cube {

public: 

	int front[3][3] = { {1, 4, 2}, {8, 7, 3}, {6, 9, 5} }, left[3][3] = { {3, 9, 7}, {6, 1, 5}, {8, 2, 4} }, right[3][3] = { {5, 2, 3}, {6, 1, 8}, {4, 9, 7} },
		back[3][3] = { {9, 7, 1}, {2, 4, 8}, {5, 3, 6} }, top[3][3] = { {4, 3, 6}, {7, 5, 1}, {9, 2, 8} }, bottom[3][3] = { {9, 8, 7}, {3, 6, 4}, {2 , 5, 1} };
	char frontOr[3][3] = { {'f', 'f', 'f'}, {'f', 'f', 'f'},{'f', 'f', 'f'} }, leftOr[3][3] = { {'<', '<', '<'},{'<', '<', '<'},{'<', '<', '<'} },
		rightOr[3][3] = { {'>', '>', '>'},{'>', '>', '>'}, {'>', '>', '>'} }, backOr[3][3] = { {'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'} }, 
		topOr[3][3] = { {'^', '^', '^'}, {'^', '^', '^'}, {'^', '^', '^'} }, bottomOr[3][3] = { {'~', '~', '~'}, {'~', '~', '~'}, {'~', '~', '~'} };

	//Default constructor
	//Each Matrix is a face and they are all in solved order
	Cube() {

	}

	//Prints out the current state of the cube in this format
	//		top
	//
	//left  front  right  back
	//
	//		bottom
	//
	void printCube() {
		cout << endl; 
		for (int i = 0; i < 3; i++) {
			cout << "              "; 
			for (int j = 0; j < 3; j++) {
				cout << top[i][j] << topOr[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl; 
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << left[i][j] << leftOr[i][j] << "  "; 
			}
			cout << "  "; 
			for (int j = 0; j < 3; j++) {
				cout << front[i][j] << frontOr[i][j] << "  ";
			}
			cout << "  ";
			for (int j = 0; j < 3; j++) {
				cout << right[i][j] << rightOr[i][j] << "  ";
			}
			cout << "  ";
			for (int j = 0; j < 3; j++) {
				cout << back[i][j] << backOr[i][j] << "  ";
			}
			cout << endl; 
		}
		cout << endl; 
		for (int i = 0; i < 3; i++) {
			cout << "              ";
			for (int j = 0; j < 3; j++) {
				cout << bottom[i][j] << bottomOr[i][j] << "  ";
			}
			cout << endl;
		}
	}

	//Moves are completed by storing positions in temporary
	//varriables and then swapped accordingly, moves are named
	//using the orentation of looking at the front 
	void topLeft(){

		int temp1[3], temp2[3], temp3[3], temp4[3]; 
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[0][i];
			temp2[i] = left[0][i];
			temp3[i] = back[0][i];
			temp4[i] = right[0][i];
			front[0][i] = temp4[i]; 
			left[0][i] = temp1[i]; 
		}
		
		back[0][0] = temp2[2]; 
		back[0][1] = temp2[1]; 
		back[0][2] = temp2[0]; 

		right[0][0] = temp3[2]; 
		right[0][1] = temp3[1]; 
		right[0][2] = temp3[0]; 

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[0][i];
			tempOr2[i] = leftOr[0][i];
			tempOr3[i] = backOr[0][i];
			tempOr4[i] = rightOr[0][i];
			frontOr[0][i] = tempOr4[i];
			leftOr[0][i] = tempOr1[i];
		}

		backOr[0][0] = tempOr2[2];
		backOr[0][1] = tempOr2[1];
		backOr[0][2] = tempOr2[0];

		rightOr[0][0] = tempOr3[2];
		rightOr[0][1] = tempOr3[1];
		rightOr[0][2] = tempOr3[0];


		int top1 = top[0][0]; 
		int top2 = top[0][1];
		int top3 = top[0][2];
		int top4 = top[1][0];
		int top5 = top[1][1];
		int top6 = top[1][2];
		int top7 = top[2][0]; 
		int top8 = top[2][1];
		int top9 = top[2][2];

		top[0][0] = top7; 
		top[0][1] = top4; 
		top[0][2] = top1; 
		top[1][0] = top8; 
		top[1][1] = top5; 
		top[1][2] = top2; 
		top[2][0] = top9; 
		top[2][1] = top6; 
		top[2][2] = top3; 

		char topOr1 = topOr[0][0];
		char topOr2 = topOr[0][1];
		char topOr3 = topOr[0][2];
		char topOr4 = topOr[1][0];
		char topOr5 = topOr[1][1];
		char topOr6 = topOr[1][2];
		char topOr7 = topOr[2][0];
		char topOr8 = topOr[2][1];
		char topOr9 = topOr[2][2];

		topOr[0][0] = topOr7;
		topOr[0][1] = topOr4;
		topOr[0][2] = topOr1;
		topOr[1][0] = topOr8;
		topOr[1][1] = topOr5;
		topOr[1][2] = topOr2;
		topOr[2][0] = topOr9;
		topOr[2][1] = topOr6;
		topOr[2][2] = topOr3;

		printCube();

	}

	void topRight() {
		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[0][i];
			temp2[i] = left[0][i];
			temp3[i] = back[0][i];
			temp4[i] = right[0][i];
			front[0][i] = temp2[i];
			right[0][i] = temp1[i];
		}

		back[0][0] = temp4[2]; 
		back[0][1] = temp4[1]; 
		back[0][2] = temp4[0]; 

		left[0][0] = temp3[2]; 
		left[0][1] = temp3[1]; 
		left[0][2] = temp3[0]; 

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[0][i];
			tempOr2[i] = leftOr[0][i];
			tempOr3[i] = backOr[0][i];
			tempOr4[i] = rightOr[0][i];
			frontOr[0][i] = tempOr2[i];
			rightOr[0][i] = tempOr1[i];
		}

		backOr[0][0] = tempOr4[2];
		backOr[0][1] = tempOr4[1];
		backOr[0][2] = tempOr4[0];

		leftOr[0][0] = tempOr3[2];
		leftOr[0][1] = tempOr3[1];
		leftOr[0][2] = tempOr3[0];

		int top1 = top[0][0];
		int top2 = top[0][1];
		int top3 = top[0][2];
		int top4 = top[1][0];
		int top5 = top[1][1];
		int top6 = top[1][2];
		int top7 = top[2][0];
		int top8 = top[2][1];
		int top9 = top[2][2];

		top[0][0] = top3;
		top[0][1] = top6;
		top[0][2] = top9;
		top[1][0] = top2;
		top[1][1] = top5;
		top[1][2] = top8;
		top[2][0] = top1;
		top[2][1] = top4;
		top[2][2] = top7;

		char topOr1 = topOr[0][0];
		char topOr2 = topOr[0][1];
		char topOr3 = topOr[0][2];
		char topOr4 = topOr[1][0];
		char topOr5 = topOr[1][1];
		char topOr6 = topOr[1][2];
		char topOr7 = topOr[2][0];
		char topOr8 = topOr[2][1];
		char topOr9 = topOr[2][2];

		topOr[0][0] = topOr3;
		topOr[0][1] = topOr6;
		topOr[0][2] = topOr9;
		topOr[1][0] = topOr2;
		topOr[1][1] = topOr5;
		topOr[1][2] = topOr8;
		topOr[2][0] = topOr1;
		topOr[2][1] = topOr4;
		topOr[2][2] = topOr7;
		printCube();
	}

	void middleLeft() {
		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[1][i];
			temp2[i] = left[1][i];
			temp3[i] = back[1][i];
			temp4[i] = right[1][i];
			front[1][i] = temp4[i];
			left[1][i] = temp1[i];
		}
		back[1][0] = temp2[2];
		back[1][1] = temp2[1];
		back[1][2] = temp2[0];

		right[1][0] = temp3[2];
		right[1][1] = temp3[1];
		right[1][2] = temp3[0];

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[1][i];
			tempOr2[i] = leftOr[1][i];
			tempOr3[i] = backOr[1][i];
			tempOr4[i] = rightOr[1][i];
			frontOr[1][i] = tempOr4[i];
			leftOr[1][i] = tempOr1[i];
		}


		backOr[1][0] = tempOr2[2];
		backOr[1][1] = tempOr2[1];
		backOr[1][2] = tempOr2[0];

		rightOr[1][0] = tempOr3[2];
		rightOr[1][1] = tempOr3[1];
		rightOr[1][2] = tempOr3[0];
		printCube();
	}

	void middleRight() {
		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[1][i];
			temp2[i] = left[1][i];
			temp3[i] = back[1][i];
			temp4[i] = right[1][i];
			front[1][i] = temp2[i];
			right[1][i] = temp1[i];
		}

		back[1][0] = temp4[2];
		back[1][1] = temp4[1];
		back[1][2] = temp4[0];

		left[1][0] = temp3[2];
		left[1][1] = temp3[1];
		left[1][2] = temp3[0];

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[1][i];
			tempOr2[i] = leftOr[1][i];
			tempOr3[i] = backOr[1][i];
			tempOr4[i] = rightOr[1][i];
			frontOr[1][i] = tempOr2[i];
			rightOr[1][i] = tempOr1[i];
		}
		backOr[1][0] = tempOr4[2];
		backOr[1][1] = tempOr4[1];
		backOr[1][2] = tempOr4[0];

		leftOr[1][0] = tempOr3[2];
		leftOr[1][1] = tempOr3[1];
		leftOr[1][2] = tempOr3[0];
		printCube();
	}

	void bottomLeft() {
		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[2][i];
			temp2[i] = left[2][i];
			temp3[i] = back[2][i];
			temp4[i] = right[2][i];
			front[2][i] = temp4[i];
			left[2][i] = temp1[i];
		}

		back[2][0] = temp2[2];
		back[2][1] = temp2[1];
		back[2][2] = temp2[0];

		right[2][0] = temp3[2];
		right[2][1] = temp3[1];
		right[2][2] = temp3[0];


		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[2][i];
			tempOr2[i] = leftOr[2][i];
			tempOr3[i] = backOr[2][i];
			tempOr4[i] = rightOr[2][i];
			frontOr[2][i] = tempOr4[i];
			leftOr[2][i] = tempOr1[i];
			backOr[2][i] = tempOr2[i];
			rightOr[2][i] = tempOr3[i];
		}

		backOr[2][0] = tempOr2[2];
		backOr[2][1] = tempOr2[1];
		backOr[2][2] = tempOr2[0];

		rightOr[2][0] = tempOr3[2];
		rightOr[2][1] = tempOr3[1];
		rightOr[2][2] = tempOr3[0];

		int bottom1 = bottom[0][0];
		int bottom2 = bottom[0][1];
		int bottom3 = bottom[0][2];
		int bottom4 = bottom[1][0];
		int bottom5 = bottom[1][1];
		int bottom6 = bottom[1][2];
		int bottom7 = bottom[2][0];
		int bottom8 = bottom[2][1];
		int bottom9 = bottom[2][2];

		bottom[0][0] = bottom3;
		bottom[0][1] = bottom6;
		bottom[0][2] = bottom9;
		bottom[1][0] = bottom2;
		bottom[1][1] = bottom5;
		bottom[1][2] = bottom8;
		bottom[2][0] = bottom1;
		bottom[2][1] = bottom4;
		bottom[2][2] = bottom7;

		char bottomOr1 = bottomOr[0][0];
		char bottomOr2 = bottomOr[0][1];
		char bottomOr3 = bottomOr[0][2];
		char bottomOr4 = bottomOr[1][0];
		char bottomOr5 = bottomOr[1][1];
		char bottomOr6 = bottomOr[1][2];
		char bottomOr7 = bottomOr[2][0];
		char bottomOr8 = bottomOr[2][1];
		char bottomOr9 = bottomOr[2][2];

		bottomOr[0][0] = bottomOr3;
		bottomOr[0][1] = bottomOr6;
		bottomOr[0][2] = bottomOr9;
		bottomOr[1][0] = bottomOr2;
		bottomOr[1][1] = bottomOr5;
		bottomOr[1][2] = bottomOr8;
		bottomOr[2][0] = bottomOr1;
		bottomOr[2][1] = bottomOr4;
		bottomOr[2][2] = bottomOr7;
		printCube();
	}

	void bottomRight() {
		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[2][i];
			temp2[i] = left[2][i];
			temp3[i] = back[2][i];
			temp4[i] = right[2][i];
			front[2][i] = temp2[i];
			right[2][i] = temp1[i];
		}

		back[2][0] = temp4[2];
		back[2][1] = temp4[1];
		back[2][2] = temp4[0];

		left[2][0] = temp3[2];
		left[2][1] = temp3[1];
		left[2][2] = temp3[0];

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[2][i];
			tempOr2[i] = leftOr[2][i];
			tempOr3[i] = backOr[2][i];
			tempOr4[i] = rightOr[2][i];
			frontOr[2][i] = tempOr2[i];
			leftOr[2][i] = tempOr3[i];
			backOr[2][i] = tempOr4[i];
			rightOr[2][i] = tempOr1[i];
		}

		backOr[2][0] = tempOr4[2];
		backOr[2][1] = tempOr4[1];
		backOr[2][2] = tempOr4[0];

		leftOr[2][0] = tempOr3[2];
		leftOr[2][1] = tempOr3[1];
		leftOr[2][2] = tempOr3[0];

		int bottom1 = bottom[0][0];
		int bottom2 = bottom[0][1];
		int bottom3 = bottom[0][2];
		int bottom4 = bottom[1][0];
		int bottom5 = bottom[1][1];
		int bottom6 = bottom[1][2];
		int bottom7 = bottom[2][0];
		int bottom8 = bottom[2][1];
		int bottom9 = bottom[2][2];

		bottom[0][0] = bottom7;
		bottom[0][1] = bottom4;
		bottom[0][2] = bottom1;
		bottom[1][0] = bottom8;
		bottom[1][1] = bottom5;
		bottom[1][2] = bottom2;
		bottom[2][0] = bottom9;
		bottom[2][1] = bottom6;
		bottom[2][2] = bottom3;

		char bottomOr1 = bottomOr[0][0];
		char bottomOr2 = bottomOr[0][1];
		char bottomOr3 = bottomOr[0][2];
		char bottomOr4 = bottomOr[1][0];
		char bottomOr5 = bottomOr[1][1];
		char bottomOr6 = bottomOr[1][2];
		char bottomOr7 = bottomOr[2][0];
		char bottomOr8 = bottomOr[2][1];
		char bottomOr9 = bottomOr[2][2];

		bottomOr[0][0] = bottomOr7;
		bottomOr[0][1] = bottomOr4;
		bottomOr[0][2] = bottomOr1;
		bottomOr[1][0] = bottomOr8;
		bottomOr[1][1] = bottomOr5;
		bottomOr[1][2] = bottomOr2;
		bottomOr[2][0] = bottomOr9;
		bottomOr[2][1] = bottomOr6;
		bottomOr[2][2] = bottomOr3;
		printCube();
	}

	void rightUp() {
		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[i][2];
			temp2[i] = top[i][2];
			temp3[i] = back[i][0];
			temp4[i] = bottom[i][2];
			front[i][2] = temp4[i];
			top[i][2] = temp1[i];
		}

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[i][2];
			tempOr2[i] = topOr[i][2];
			tempOr3[i] = backOr[i][0];
			tempOr4[i] = bottomOr[i][2];
			frontOr[i][2] = tempOr4[i]; 
			topOr[i][2] = tempOr1[i]; 
		}

		back[0][0] = temp2[2]; 
		back[1][0] = temp2[1];
		back[2][0] = temp2[0]; 

		bottom[0][2] = temp3[2];
		bottom[1][2] = temp3[1]; 
		bottom[2][2] = temp3[0]; 

		backOr[0][0] = tempOr2[2];
		backOr[1][0] = tempOr2[1];
		backOr[2][0] = tempOr2[0];

		bottomOr[0][2] = tempOr3[2];
		bottomOr[1][2] = tempOr3[1];
		bottomOr[2][2] = tempOr3[0];

		int right1 = right[0][0];
		int right2 = right[0][1];
		int right3 = right[0][2];
		int right4 = right[1][0];
		int right5 = right[1][1];
		int right6 = right[1][2];
		int right7 = right[2][0];
		int right8 = right[2][1];
		int right9 = right[2][2];

		right[0][0] = right7;
		right[0][1] = right4;
		right[0][2] = right1;
		right[1][0] = right8;
		right[1][1] = right5;
		right[1][2] = right2;
		right[2][0] = right9;
		right[2][1] = right6;
		right[2][2] = right3;


		char rightOr1 = rightOr[0][0];
		char rightOr2 = rightOr[0][1];
		char rightOr3 = rightOr[0][2];
		char rightOr4 = rightOr[1][0];
		char rightOr5 = rightOr[1][1];
		char rightOr6 = rightOr[1][2];
		char rightOr7 = rightOr[2][0];
		char rightOr8 = rightOr[2][1];
		char rightOr9 = rightOr[2][2];

		rightOr[0][0] = rightOr7;
		rightOr[0][1] = rightOr4;
		rightOr[0][2] = rightOr1;
		rightOr[1][0] = rightOr8;
		rightOr[1][1] = rightOr5;
		rightOr[1][2] = rightOr2;
		rightOr[2][0] = rightOr9;
		rightOr[2][1] = rightOr6;
		rightOr[2][2] = rightOr3;
		printCube();
	}

	void middleUp() {
		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[i][1];
			temp2[i] = top[i][1];
			temp3[i] = back[i][1];
			temp4[i] = bottom[i][1];
			front[i][1] = temp4[i];
			top[i][1] = temp1[i];
		}

		back[0][1] = temp2[2];
		back[1][1] = temp2[1];
		back[2][1] = temp2[0];

		bottom[0][1] = temp3[2];
		bottom[1][1] = temp3[1];
		bottom[2][1] = temp3[0];



		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[i][1];
			tempOr2[i] = topOr[i][1];
			tempOr3[i] = backOr[i][1];
			tempOr4[i] = bottomOr[i][1];
			frontOr[i][1] = tempOr4[i];
			topOr[i][1] = tempOr1[i];
		}

		backOr[0][1] = tempOr2[2];
		backOr[1][1] = tempOr2[1];
		backOr[2][1] = tempOr2[0];

		bottomOr[0][1] = tempOr3[2];
		bottomOr[1][1] = tempOr3[1];
		bottomOr[2][1] = tempOr3[0];
		printCube();
	}

	void leftUp() {
		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[i][0];
			temp2[i] = top[i][0];
			temp3[i] = back[i][2];
			temp4[i] = bottom[i][0];
			front[i][0] = temp4[i];
			top[i][0] = temp1[i];
		}

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[i][0];
			tempOr2[i] = topOr[i][0];
			tempOr3[i] = backOr[i][2];
			tempOr4[i] = bottomOr[i][0];
			frontOr[i][0] = tempOr4[i];
			topOr[i][0] = tempOr1[i];
		}

		back[0][2] = temp2[2];
		back[1][2] = temp2[1];
		back[2][2] = temp2[0];

		bottom[0][0] = temp3[2];
		bottom[1][0] = temp3[1];
		bottom[2][0] = temp3[0];

		backOr[0][2] = tempOr2[2];
		backOr[1][2] = tempOr2[1];
		backOr[2][2] = tempOr2[0];

		bottomOr[0][0] = tempOr3[2];
		bottomOr[1][0] = tempOr3[1];
		bottomOr[2][0] = tempOr3[0];

		int left1 = left[0][0];
		int left2 = left[0][1];
		int left3 = left[0][2];
		int left4 = left[1][0];
		int left5 = left[1][1];
		int left6 = left[1][2];
		int left7 = left[2][0];
		int left8 = left[2][1];
		int left9 = left[2][2];

		left[0][0] = left3;
		left[0][1] = left6;
		left[0][2] = left9;
		left[1][0] = left2;
		left[1][1] = left5;
		left[1][2] = left8;
		left[2][0] = left1;
		left[2][1] = left4;
		left[2][2] = left7;

		char leftOr1 = leftOr[0][0];
		char leftOr2 = leftOr[0][1];
		char leftOr3 = leftOr[0][2];
		char leftOr4 = leftOr[1][0];
		char leftOr5 = leftOr[1][1];
		char leftOr6 = leftOr[1][2];
		char leftOr7 = leftOr[2][0];
		char leftOr8 = leftOr[2][1];
		char leftOr9 = leftOr[2][2];

		leftOr[0][0] = leftOr3;
		leftOr[0][1] = leftOr6;
		leftOr[0][2] = leftOr9;
		leftOr[1][0] = leftOr2;
		leftOr[1][1] = leftOr5;
		leftOr[1][2] = leftOr8;
		leftOr[2][0] = leftOr1;
		leftOr[2][1] = leftOr4;
		leftOr[2][2] = leftOr7;
		printCube();
	}
	
	void rightDown() {

		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[i][2];
			temp2[i] = top[i][2];
			temp3[i] = back[i][0];
			temp4[i] = bottom[i][2];
			front[i][2] = temp2[i];
			bottom[i][2] = temp1[i];
		}

		back[0][0] = temp4[2];
		back[1][0] = temp4[1]; 
		back[2][0] = temp4[0]; 
		
		top[0][2] = temp3[2]; 
		top[1][2] = temp3[1]; 
		top[2][2] = temp3[0]; 

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[i][2];
			tempOr2[i] = topOr[i][2];
			tempOr3[i] = backOr[i][0];
			tempOr4[i] = bottomOr[i][2];
			frontOr[i][2] = tempOr2[i];
			bottomOr[i][2] = tempOr1[i];
		}

		backOr[0][0] = tempOr4[2];
		backOr[1][0] = tempOr4[1];
		backOr[2][0] = tempOr4[0];

		topOr[0][2] = tempOr3[2];
		topOr[1][2] = tempOr3[1];
		topOr[2][2] = tempOr3[0];

		int right1 = right[0][0];
		int right2 = right[0][1];
		int right3 = right[0][2];
		int right4 = right[1][0];
		int right5 = right[1][1];
		int right6 = right[1][2];
		int right7 = right[2][0];
		int right8 = right[2][1];
		int right9 = right[2][2];

		right[0][0] = right3;
		right[0][1] = right6;
		right[0][2] = right9;
		right[1][0] = right2;
		right[1][1] = right5;
		right[1][2] = right8;
		right[2][0] = right1;
		right[2][1] = right4;
		right[2][2] = right7;

		char rightOr1 = rightOr[0][0];
		char rightOr2 = rightOr[0][1];
		char rightOr3 = rightOr[0][2];
		char rightOr4 = rightOr[1][0];
		char rightOr5 = rightOr[1][1];
		char rightOr6 = rightOr[1][2];
		char rightOr7 = rightOr[2][0];
		char rightOr8 = rightOr[2][1];
		char rightOr9 = rightOr[2][2];

		rightOr[0][0] = rightOr3;
		rightOr[0][1] = rightOr6;
		rightOr[0][2] = rightOr9;
		rightOr[1][0] = rightOr2;
		rightOr[1][1] = rightOr5;
		rightOr[1][2] = rightOr8;
		rightOr[2][0] = rightOr1;
		rightOr[2][1] = rightOr4;
		rightOr[2][2] = rightOr7;
		printCube();
	}
	
	void middleDown() {

		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[i][1];
			temp2[i] = top[i][1];
			temp3[i] = back[i][1];
			temp4[i] = bottom[i][1];
			front[i][1] = temp2[i];
			bottom[i][1] = temp1[i];
		}

		back[0][1] = temp4[2];
		back[1][1] = temp4[1];
		back[2][1] = temp4[0];

		top[0][1] = temp3[2];
		top[1][1] = temp3[1];
		top[2][1] = temp3[0];

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[i][1];
			tempOr2[i] = topOr[i][1];
			tempOr3[i] = backOr[i][1];
			tempOr4[i] = bottomOr[i][1];
			frontOr[i][1] = tempOr2[i];
			bottomOr[i][1] = tempOr1[i];
		}

		backOr[0][1] = tempOr4[2];
		backOr[1][1] = tempOr4[1];
		backOr[2][1] = tempOr4[0];

		topOr[0][1] = tempOr3[2];
		topOr[1][1] = tempOr3[1];
		topOr[2][1] = tempOr3[0];
		printCube();
	}

	void leftDown() {

		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = front[i][0];
			temp2[i] = top[i][0];
			temp3[i] = back[i][2];
			temp4[i] = bottom[i][0];
			front[i][0] = temp2[i];
			bottom[i][0] = temp1[i];
		}
		
		back[0][2] = temp4[2];
		back[1][2] = temp4[1];
		back[2][2] = temp4[0];

		top[0][0] = temp3[2];
		top[1][0] = temp3[1];
		top[2][0] = temp3[0];

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = frontOr[i][0];
			tempOr2[i] = topOr[i][0];
			tempOr3[i] = backOr[i][2];
			tempOr4[i] = bottomOr[i][0];
			frontOr[i][0] = tempOr2[i];
			bottomOr[i][0] = tempOr1[i];
		}

		backOr[0][2] = tempOr4[2];
		backOr[1][2] = tempOr4[1];
		backOr[2][2] = tempOr4[0];

		topOr[0][0] = tempOr3[2];
		topOr[1][0] = tempOr3[1];
		topOr[2][0] = tempOr3[0];

		int left1 = left[0][0];
		int left2 = left[0][1];
		int left3 = left[0][2];
		int left4 = left[1][0];
		int left5 = left[1][1];
		int left6 = left[1][2];
		int left7 = left[2][0];
		int left8 = left[2][1];
		int left9 = left[2][2];

		left[0][0] = left1;
		left[0][1] = left4;
		left[0][2] = left7;
		left[1][0] = left8;
		left[1][1] = left5;
		left[1][2] = left2;
		left[2][0] = left9;
		left[2][1] = left6;
		left[2][2] = left3;

		char leftOr1 = leftOr[0][0];
		char leftOr2 = leftOr[0][1];
		char leftOr3 = leftOr[0][2];
		char leftOr4 = leftOr[1][0];
		char leftOr5 = leftOr[1][1];
		char leftOr6 = leftOr[1][2];
		char leftOr7 = leftOr[2][0];
		char leftOr8 = leftOr[2][1];
		char leftOr9 = leftOr[2][2];

		leftOr[0][0] = leftOr1;
		leftOr[0][1] = leftOr4;
		leftOr[0][2] = leftOr7;
		leftOr[1][0] = leftOr8;
		leftOr[1][1] = leftOr5;
		leftOr[1][2] = leftOr2;
		leftOr[2][0] = leftOr9;
		leftOr[2][1] = leftOr6;
		leftOr[2][2] = leftOr3;
		printCube();
	}

	void frontCW() {

		int temp1[3], temp2[3], temp3[3], temp4[3]; 
		for (int i = 0; i < 3; i++) {
			temp1[i] = left[i][2]; 
			temp2[i] = top[2][i]; 
			temp3[i] = right[i][0];
			temp4[i] = bottom[0][i]; 
		}
		top[2][2] = temp1[0];
		top[2][1] = temp1[1];
		top[2][0] = temp1[2];

		right[0][0] = temp2[0];
		right[1][0] = temp2[1];
		right[2][0] = temp2[2]; 

		bottom[0][0] = temp3[2]; 
		bottom[0][1] = temp3[1];
		bottom[0][2] = temp3[0]; 

		left[0][2] = temp4[0]; 
		left[1][2] = temp4[1]; 
		left[2][2] = temp4[2]; 

		char tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = leftOr[i][2];
			tempOr2[i] = topOr[2][i];
			tempOr3[i] = rightOr[i][0];
			tempOr4[i] = bottomOr[0][i];
		}
		topOr[2][2] = tempOr1[0];
		topOr[2][1] = tempOr1[1];
		topOr[2][0] = tempOr1[2];

		rightOr[0][0] = tempOr2[0];
		rightOr[1][0] = tempOr2[1];
		rightOr[2][0] = tempOr2[2];

		bottomOr[0][0] = tempOr3[2];
		bottomOr[0][1] = tempOr3[1];
		bottomOr[0][2] = tempOr3[0];

		leftOr[0][2] = tempOr4[0];
		leftOr[1][2] = tempOr4[1];
		leftOr[2][2] = tempOr4[2];

		int front1 = front[0][0];
		int front2 = front[0][1];
		int front3 = front[0][2];
		int front4 = front[1][0];
		int front5 = front[1][1];
		int front6 = front[1][2];
		int front7 = front[2][0];
		int front8 = front[2][1];
		int front9 = front[2][2];

		front[0][0] = front7;
		front[0][1] = front4;
		front[0][2] = front1;
		front[1][0] = front8;
		front[1][1] = front5;
		front[1][2] = front2;
		front[2][0] = front9;
		front[2][1] = front6;
		front[2][2] = front3;

		char frontOr1 = frontOr[0][0];
		char frontOr2 = frontOr[0][1];
		char frontOr3 = frontOr[0][2];
		char frontOr4 = frontOr[1][0];
		char frontOr5 = frontOr[1][1];
		char frontOr6 = frontOr[1][2];
		char frontOr7 = frontOr[2][0];
		char frontOr8 = frontOr[2][1];
		char frontOr9 = frontOr[2][2];

		frontOr[0][0] = frontOr7;
		frontOr[0][1] = frontOr4;
		frontOr[0][2] = frontOr1;
		frontOr[1][0] = frontOr8;
		frontOr[1][1] = frontOr5;
		frontOr[1][2] = frontOr2;
		frontOr[2][0] = frontOr9;
		frontOr[2][1] = frontOr6;
		frontOr[2][2] = frontOr3;
		printCube();
	}

	void middleCW() {

		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = left[i][1];
			temp2[i] = top[1][i];
			temp3[i] = right[i][1];
			temp4[i] = bottom[1][i] ;
			left[i][1] = temp4[i];
			right[i][1] = temp2[i];
		}

		top[1][0] = temp1[2]; 
		top[1][1] = temp1[1]; 
		top[1][2] = temp1[0]; 

		bottom[1][0] = temp3[2]; 
		bottom[1][1] = temp3[1]; 
		bottom[1][2] = temp3[0]; 

		char tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = leftOr[i][1];
			tempOr2[i] = topOr[1][i];
			tempOr3[i] = rightOr[i][1];
			tempOr4[i] = bottomOr[1][i];
			leftOr[i][1] = tempOr4[i];
			rightOr[i][1] = tempOr2[i];
		}

		topOr[1][0] = tempOr1[2];
		topOr[1][1] = tempOr1[1];
		topOr[1][2] = tempOr1[0];

		bottomOr[1][0] = tempOr3[2];
		bottomOr[1][1] = tempOr3[1];
		bottomOr[1][2] = tempOr3[0];
		printCube();
	}

	void backCW() {

		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = left[i][0];
			temp2[i] = top[0][i];
			temp3[i] = right[i][2];
			temp4[i] = bottom[2][i];
			left[i][0] = temp4[i];
			right[i][2] = temp2[i];
		}

		top[0][0] = temp1[2];
		top[0][1] = temp1[1];
		top[0][2] = temp1[0];

		bottom[2][0] = temp3[2];
		bottom[2][1] = temp3[1];
		bottom[2][2] = temp3[0];

		int back1 = back[0][0];
		int back2 = back[0][1];
		int back3 = back[0][2];
		int back4 = back[1][0];
		int back5 = back[1][1];
		int back6 = back[1][2];
		int back7 = back[2][0];
		int back8 = back[2][1];
		int back9 = back[2][2];

		back[0][0] = back3;
		back[0][1] = back6;
		back[0][2] = back9;
		back[1][0] = back2;
		back[1][1] = back5;
		back[1][2] = back8;
		back[2][0] = back1;
		back[2][1] = back4;
		back[2][2] = back7;

		int tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = leftOr[i][0];
			tempOr2[i] = topOr[0][i];
			tempOr3[i] = rightOr[i][2];
			tempOr4[i] = bottomOr[2][i];
			leftOr[i][0] = tempOr4[i];
			rightOr[i][2] = tempOr2[i];
		}

		topOr[0][0] = tempOr1[2];
		topOr[0][1] = tempOr1[1];
		topOr[0][2] = tempOr1[0];

		bottomOr[2][0] = tempOr3[2];
		bottomOr[2][1] = tempOr3[1];
		bottomOr[2][2] = tempOr3[0];

		char backOr1 = backOr[0][0];
		char backOr2 = backOr[0][1];
		char backOr3 = backOr[0][2];
		char backOr4 = backOr[1][0];
		char backOr5 = backOr[1][1];
		char backOr6 = backOr[1][2];
		char backOr7 = backOr[2][0];
		char backOr8 = backOr[2][1];
		char backOr9 = backOr[2][2];

		backOr[0][0] = backOr3;
		backOr[0][1] = backOr6;
		backOr[0][2] = backOr9;
		backOr[1][0] = backOr2;
		backOr[1][1] = backOr5;
		backOr[1][2] = backOr8;
		backOr[2][0] = backOr1;
		backOr[2][1] = backOr4;
		backOr[2][2] = backOr7;
		printCube();
	}

	void frontCCW(){

		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = left[i][2];
			temp2[i] = top[2][i];
			temp3[i] = right[i][0];
			temp4[i] = bottom[0][i];
			top[2][i] = temp3[i];
			bottom[0][i] = temp1[i];
		}
		left[0][2] = temp2[2];
		left[1][2] = temp2[1];
		left[2][2] = temp2[0];

		right[0][0] = temp4[2];
		right[1][0] = temp4[1];
		right[2][0] = temp4[0];

		char tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = leftOr[i][2];
			tempOr2[i] = topOr[2][i];
			tempOr3[i] = rightOr[i][0];
			tempOr4[i] = bottomOr[0][i];
			topOr[2][i] = tempOr3[i];
			bottomOr[0][i] = tempOr1[i];
		}
		leftOr[0][2] = tempOr2[2];
		leftOr[1][2] = tempOr2[1];
		leftOr[2][2] = tempOr2[0];

		rightOr[0][0] = tempOr4[2];
		rightOr[1][0] = tempOr4[1];
		rightOr[2][0] = tempOr4[0];

		int front1 = front[0][0];
		int front2 = front[0][1];
		int front3 = front[0][2];
		int front4 = front[1][0];
		int front5 = front[1][1];
		int front6 = front[1][2];
		int front7 = front[2][0];
		int front8 = front[2][1];
		int front9 = front[2][2];

		front[0][0] = front3;
		front[0][1] = front6;
		front[0][2] = front9;
		front[1][0] = front2;
		front[1][1] = front5;
		front[1][2] = front8;
		front[2][0] = front1;
		front[2][1] = front4;
		front[2][2] = front7;

		char frontOr1 = frontOr[0][0];
		char frontOr2 = frontOr[0][1];
		char frontOr3 = frontOr[0][2];
		char frontOr4 = frontOr[1][0];
		char frontOr5 = frontOr[1][1];
		char frontOr6 = frontOr[1][2];
		char frontOr7 = frontOr[2][0];
		char frontOr8 = frontOr[2][1];
		char frontOr9 = frontOr[2][2];

		frontOr[0][0] = frontOr3;
		frontOr[0][1] = frontOr6;
		frontOr[0][2] = frontOr9;
		frontOr[1][0] = frontOr2;
		frontOr[1][1] = frontOr5;
		frontOr[1][2] = frontOr8;
		frontOr[2][0] = frontOr1;
		frontOr[2][1] = frontOr4;
		frontOr[2][2] = frontOr7;
		printCube();
	}

	void middleCCW() {

		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = left[i][1];
			temp2[i] = top[1][i];
			temp3[i] = right[i][1];
			temp4[i] = bottom[1][i];
			top[1][i] = temp3[i];
			bottom[1][i] = temp1[i];
		}

		left[0][1] = temp2[2];
		left[1][1] = temp2[1];
		left[2][1] = temp2[0];

		right[0][1] = temp4[2];
		right[1][1] = temp4[1];
		right[2][1] = temp4[0];

		char tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = leftOr[i][1];
			tempOr2[i] = topOr[1][i];
			tempOr3[i] = rightOr[i][1];
			tempOr4[i] = bottomOr[1][i];
			topOr[1][i] = tempOr3[i];
			bottomOr[1][i] = tempOr1[i];
		}

		leftOr[0][1] = tempOr2[2];
		leftOr[1][1] = tempOr2[1];
		leftOr[2][1] = tempOr2[0];

		rightOr[0][1] = tempOr4[2];
		rightOr[1][1] = tempOr4[1];
		rightOr[2][1] = tempOr4[0];
		printCube();
	}

	void backCCW() {

		int temp1[3], temp2[3], temp3[3], temp4[3];
		for (int i = 0; i < 3; i++) {
			temp1[i] = left[i][0];
			temp2[i] = top[0][i];
			temp3[i] = right[i][2];
			temp4[i] = bottom[2][i];
			top[0][i] = temp3[i];
			bottom[2][i] = temp1[i];
		}

		right[0][2] = temp4[2];
		right[1][2] = temp4[1];
		right[2][2] = temp4[0];

		left[0][0] = temp2[2];
		left[1][0] = temp2[1];
		left[2][0] = temp2[0];

		char tempOr1[3], tempOr2[3], tempOr3[3], tempOr4[3];
		for (int i = 0; i < 3; i++) {
			tempOr1[i] = leftOr[i][0];
			tempOr2[i] = topOr[0][i];
			tempOr3[i] = rightOr[i][2];
			tempOr4[i] = bottomOr[2][i];
			topOr[0][i] = tempOr3[i];
			bottomOr[2][i] = tempOr1[i];
		}

		rightOr[0][2] = tempOr4[2];
		rightOr[1][2] = tempOr4[1];
		rightOr[2][2] = tempOr4[0];

		leftOr[0][0] = tempOr2[2];
		leftOr[1][0] = tempOr2[1];
		leftOr[2][0] = tempOr2[0];

		int back1 = back[0][0];
		int back2 = back[0][1];
		int back3 = back[0][2];
		int back4 = back[1][0];
		int back5 = back[1][1];
		int back6 = back[1][2];
		int back7 = back[2][0];
		int back8 = back[2][1];
		int back9 = back[2][2];

		back[0][0] = back7;
		back[0][1] = back4;
		back[0][2] = back1;
		back[1][0] = back8;
		back[1][1] = back5;
		back[1][2] = back2;
		back[2][0] = back9;
		back[2][1] = back6;
		back[2][2] = back3;

		char backOr1 = backOr[0][0];
		char backOr2 = backOr[0][1];
		char backOr3 = backOr[0][2];
		char backOr4 = backOr[1][0];
		char backOr5 = backOr[1][1];
		char backOr6 = backOr[1][2];
		char backOr7 = backOr[2][0];
		char backOr8 = backOr[2][1];
		char backOr9 = backOr[2][2];

		backOr[0][0] = backOr7;
		backOr[0][1] = backOr4;
		backOr[0][2] = backOr1;
		backOr[1][0] = backOr8;
		backOr[1][1] = backOr5;
		backOr[1][2] = backOr2;
		backOr[2][0] = backOr1;
		backOr[2][1] = backOr6;
		backOr[2][2] = backOr3;
		printCube();
	}

	void scrambleCube(int r) {
		srand(time(NULL));
		cout << "Here are the moves preformed: " << endl;
		for (int i = 0; i < r; i++) {

			int s = rand() % 17;
			if (s == 0) {
				topLeft();
				cout << "top row turned left" << endl;
			}

			else if (s == 1) {
				topRight();
				cout << "top row turned right" << endl; 
			}

			else if (s == 2) {
				middleLeft();
				cout << "middle row turned left" << endl; 
			}

			else if (s == 3) {
				middleRight();
				cout << "middle row turned right" << endl; 
			}

			else if (s == 4) {
				bottomLeft();
				cout << "bottom row turned left" << endl;
			}

			else if (s == 5) {
				bottomRight();
				cout << "bottom row turned right" << endl; 
			}

			else if (s == 6) {
				rightUp();
				cout << "right collumn turned up" << endl;
			}

			else if (s == 7) {
				middleUp();
				cout << "middle collumn turned up" << endl; 
			}

			else if (s == 8) {
				leftUp(); 
				cout << "left collumn turned up" << endl;
			}

			else if (s == 9) {
				rightDown(); 
				cout << "right collumn turned down" << endl; 
			}

			else if (s == 10) {
				middleDown();
				cout << "middle collumn turned down" << endl;
			}

			else if (s == 11) {
				leftDown();
				cout << "left collumn turned down" << endl; 
			}

			else if (s == 12) {
				frontCW();
				cout << "front face turned clockwise" << endl;
			}

			else if (s == 13) {
				middleCW();
				cout << "middle face turned clockwise" << endl; 
			}

			else if (s == 14) {
				backCW();
				cout << "back face turned clockwise" << endl;
			}

			else if (s == 15) {
				frontCCW();
				cout << "front face turned counterclockwise" << endl;
			}

			else if (s == 16) {
				middleCCW();
				cout << "middle face turned coutnerclockwise" << endl;
			}

			else if (s == 17) {
				backCCW();
				cout << "back face turned couterclockwise" << endl; 
			}
			cout << "----------------------------------------------------------" << endl;
		}

	}

	int hueristic() {
		int h = 0; 
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (frontOr[i][j] == '>' || frontOr[i][j] == '<' || frontOr[i][j] == '^' || frontOr[i][j] == '~') {
					h++; 
				}
				if (frontOr[i][j] == 'b') {
					h = h + 2; 
				}
				if (leftOr[i][j] == 'b' || leftOr[i][j] == 'f' || leftOr[i][j] == '^' || leftOr[i][j] == '~') {
					h++;
				}
				if (leftOr[i][j] == '>') {
					h = h + 2; 
				}
				if (rightOr[i][j] == 'b' || rightOr[i][j] == 'f' || rightOr[i][j] == '^' || rightOr[i][j] == '~') {
					h++;
				}
				if (rightOr[i][j] == '<') {
					h = h + 2; 
				}
				if (bottomOr[i][j] == '<' || bottomOr[i][j] == 'f' || bottomOr[i][j] == '>' || bottomOr[i][j] == 'b') {
					h++;
				}
				if (bottom[i][j] == '^') {
					h = h + 2; 
				}
				if (topOr[i][j] == '<' || topOr[i][j] == 'f' || topOr[i][j] == '>' || topOr[i][j] == 'b') {
					h++;
				}
				if (topOr[i][j] == '~') {
					h = h + 2; 
				}
				if (backOr[i][j] == '<' || backOr[i][j] == '^' || backOr[i][j] == '>' || backOr[i][j] == '~') {
					h++;
				}
				if (backOr[i][j] == 'f') {
					h = h + 2; 
				}
			}
		}
		return h/12; 
	}
};