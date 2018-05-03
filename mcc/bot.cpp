/*
Author: Angela Lim
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Project 3
This project will be able to find debris in a game and collect it.
It will also be able to repair a robot in the game
*/
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "bot.h"
using namespace std;
const int MAX_ROBOT_NUM = 50;
int NUM;          // to remember number or robots
int ROWS, COLS;   // map dimensions
int health[50];	//global array that represents each potential bot
int debris_coord[40][40]; //global 2D arrary that represents each point in coord
double distances[40][40]; //find the distance between the debris and the robot
/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,
             Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;
	//for loop to intialize the healthy robot array
	for (int i = 0; i < 50; i++){
		health[i] = 1;
	}
	//for loop to intialize the coordinates of debris
	for(int h = 0; h < 40; h++){
		for(int w = 0; w < 40; w++){
			debris_coord[h][w] = 0;
		}
	}

	for(int l = 0; l < 40; l++){
		for(int u = 0; u < 40; u++){
			distances[l][u] = 60;
		}
	}
	log << "Start!" << endl;
}

bool broken(int id){
	//if onRobotMalfunction is true
	if (health[id] == 0){
		return true;
	}
	else{
		return false;
	}
}

 //Deciding robot's next move 
Action onRobotAction(int id, Loc loc, Area &area, ostream &log) {
	int row = loc.r; // current row and column
	int col = loc.c;
	for(int x = 0; x < NUM; x++){
			if(broken(x)){
				// if the location of the robot is in the same col but 1 row away then repair
				if((area.locate(x).c == col) && (area.locate(x).r == row-1)){
					health[x] = 1;
					return REPAIR_UP;
				}
				// if the location of the robot is in the same col but 1 row away then repair
				if (area.locate(x).c == col && (area.locate(x).r == row+1)){
					health[x] = 1;
					return REPAIR_DOWN;
				}
				// if the location of the robot is in the same row but 1 col away then repair
				if ((area.locate(x).c == col-1) && area.locate(x).r == row){
					
					health[x] = 1;
					return REPAIR_LEFT;	
				}
				// if the location of the robot is in the same row but 1 col away then repair
				if ((area.locate(x).c == col+1) && (area.locate(x).r == row)){
					
					health[x] = 1;
					return REPAIR_RIGHT;
					
				}
				else if((area.locate(x).c == col) && (area.locate(x).r < row)){
					//if the broken robot is in the same col but diff row move it so it's only 1 row away
					return UP; 
					if((area.locate(x).c == col) && (area.locate(x).r == row-1)){
					health[x] = 1;
					return REPAIR_UP;
					}
				}
				else if ((area.locate(x).c == col) && (area.locate(x).r > row)){
					//if the broken robot is in the same col but diff row move it so it's only 1 row away
					return DOWN;
					if (area.locate(x).c == col && (area.locate(x).r == row+1)){
				
					health[x] = 1;
					return REPAIR_DOWN;
					}
				}
				else if ((area.locate(x).c > col) && area.locate(x).r == row)
				{
					//if the broken robot is in the same row but diff col move it so it's only 1 col away
					return RIGHT;
					if ((area.locate(x).c == col+1) && area.locate(x).r == row){
					
					health[x] = 1;
					return REPAIR_RIGHT;	
					}			
				}
				else if ((area.locate(x).c < col) && (area.locate(x).r == row))
				{
					//if the broken robot is in the same row but diff col move it so it's only 1 col away
					return LEFT;
					if ((area.locate(x).c == col-1) && (area.locate(x).r == row)){
					
					health[x] = 1;
					return REPAIR_LEFT;
					
					}
				}
			}
	}
	if (area.inspect(row, col) == DEBRIS){
				return COLLECT;
	}
	//intializing the distance array
	for(int l = 0; l < 40; l++){
		for(int u = 0; u < 40; u++){
			distances[l][u] = 60;
		}
	}
	for(int h = 0; h < 40; h++){
		for(int w = 0; w < 40; w++){
			debris_coord[h][w] = 0;
		}
	}
	//initializing the debris array to 1
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 40; j++){
			if ( area.inspect(i,j) == DEBRIS){
				debris_coord[i][j] = 1;
			}
		}
	}
	//finding the distance for each coord
	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 40; j++){
			int distx;
			int disty;
			if(debris_coord[i][j] == 1){
				double mindistances;
				mindistances = (abs(i - row) + abs(j - col));
				//distx = ((i-row) * (i-row));
				//disty = ((j-col)* (j-col));
				//mindistances = sqrt(distx + disty);
				distances[i][j] = mindistances;
			}
		}
	}	
	double mindistance = distances[0][0];
	int debris_col = 0;
	int debris_row = 0;
	for (int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(mindistance > distances[i][j]){
				mindistance=distances[i][j];
				debris_col = j;
				debris_row = i;
			}
		}
	}
	//directing the robot to that debris' row and col
	log << "me: " << "x: " << row << " y: " << col << " | t: x: " << debris_row << " y: " << debris_col << "\n";
	if(col == debris_col && (row < debris_row)){
		log << id << " debris down" << "\n";
		return DOWN;
	}

	else if(col == debris_col && (row > debris_row)){
		log << id << " debris up" << "\n";
		return UP;
	}

	else if (col < debris_col && (row == debris_row)){
		log << id << " debris right" << "\n";
			return RIGHT;
	}
	else if (col > debris_col && (row == debris_row)){
		log << id << " debris left" << "\n";
			return LEFT;
	}
	
	//prioritize x axis for some reason..
	else if (col < debris_col && row < debris_row) { return RIGHT; }
	else if (col > debris_col && row > debris_row) { return UP; }
	else if (col > debris_col && row < debris_row) { return DOWN; }
	else if (col < debris_col && row > debris_row) { return RIGHT; }
	
	else if(area.inspect(row-1,col)==DEBRIS){
		log << id << " debris straight up" << "\n";
		return UP;
	}

	else if(area.inspect(row+1,col) == DEBRIS){
		log << id << " debris straight down" << "\n";
		return DOWN;
	}
	else if(area.inspect(row,col-1) == DEBRIS){
		log << id << " debris straight left" << "\n";
		return LEFT;
	}
	else if (area.inspect(row,col+1) == DEBRIS){
		log << id << " debris straight right" << "\n";
		return RIGHT;
	}
//check reach row/column if there is debris.if there is collect it
//if there is debris most likely around that row/column there will be debris too
//idea 1: partition the robots so that they're only in certain parts 

	else {
		// if not at a debris field, move randomly:
		log << id << " goin random..." << "\n";
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
	int row = loc.r; // current row and column
	int col = loc.c;
	health[id] = 0;
	log << "Robot " << id << " is damaged." << endl;

}

void onClockTick(int time, ostream &log) {
	if (time % 100 == 0) log << time << " ";
}




