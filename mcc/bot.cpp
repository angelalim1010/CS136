
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

extern int health[50] = 1;
 

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

	for(int r = 0; r < NUM; r++){
		//if array is 0 then repair 
			if(broken(r)){
				//if at r is broken take the nearest bot to repair it
				//save the location
				//robot id -1 to go and repair it
				if(area.locate(r-1).r == (area.locate(r).r-1)){
					return REPAIR_UP;
				}
				else if (area.locate(r-1).r == (area.locate(r).r+1)){
					return REPAIR_DOWN;
				}
				else if (area.locate(r-1).c == (area.locate(r).c-1)){
					return REPAIR_LEFT;
				}
				else if (area.locate(r-1).c == (area.locate(r).c+1)){
					return REPAIR_RIGHT;
				}
			}
	}
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

bool broken(int id){
	//if onRobotMalfunction is true
	if (health[id] == 0){
		return false;
	}
	else{
		return true;
	}
}



void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log) {
	log << "Robot " << id << " is damaged." << endl;
	health[id] == 0;
}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}


