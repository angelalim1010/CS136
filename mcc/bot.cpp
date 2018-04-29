
#include <cstdlib>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROBOT_NUM = 50;

int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions

/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;

	log << "Start!" << endl;
}

 

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) {
	int row = loc.r; // current row and column
	int col = loc.c;
	int pre_move;
	//int pre_col;
	//for loop with a 3 by 3 row < 3
	if (area.inspect(row, col) == DEBRIS){
				return COLLECT;
	}
	/*
	for (int row; row <ROWS; row++){
		for (int col; col < COLS; col++){
			if (area.inspect(row , col) == DEBRIS){
				return COLLECT;
			}
			else if (area.inspect(row+2, col+2) == DEBRIS)
			{
				return COLLECT;
			}
		}
	}	

	else {
		// if not at a debris field, move randomly:
		switch(rand() % 4) {
		case 0:
		if(pre_move == 1){
			return LEFT;
		}
		else{
			return RIGHT;
		}
		pre_move =0;
		case 1:
		if (pre_move == 0){
			return RIGHT;
		}
		else{
			return LEFT;
		}
		pre_move = 1;
		case 2:
		if(pre_move == 3){
			return UP;
		}
		else{
			return DOWN;
		}
		pre_move = 2
		default:
		if (pre_move == 2){
			return DOWN;
		}
		else{
			return UP;
		}
		pre_move = 3
		}
	}
*/

	if(area.inspect(row-1,col)==DEBRIS){
		return UP;
	}
	else if(area.inspect(row+1,col) == DEBRIS){
		return DOWN;
	}
	if(area.inspect(row,col-1) == DEBRIS){
		return LEFT;
	}
	else if (area.inspect(row,col+1) == DEBRIS){
		return RIGHT;
	}

	
//check reach row/column if there is debris.if there is collect it
//if there is debris most likely around that row/column there will be debris too
//idea 1: partition the robots so that they're only in certain parts 



	else {
		// if not at a debris field, move randomly:
		switch(rand() % 4) {
		case 0:
			return LEFT;
		case 1:
			return RIGHT;
		case 2:
			return UP;
		default:
			return DOWN;
		}
	}
}


void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) {
	log << "Robot " << id << " is damaged." << endl;
}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}


