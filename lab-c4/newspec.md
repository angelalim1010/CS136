# GROUP: Quymbee, Angela, Myles, Anton

## Gameplay Overview

1-Player: input column because since there's "gravity" the rows are already predetermined
	  return where the piece is
	  check to see which row is next in column 
	 (if no available rows in board (column is full) then player can no longer input there 		 --return notification for such info)
	randomize computer's piece locations

State: start, playing, end
	start - one player vs computer
	playing - one player scenario --"makeMove()"
	end - checks after every move if a player gets four in a row --maybe "checkWin()"
	      asks to play again

## Functions Needed

buildGrid: creates board
	   should be made in a way that it can generate an updated board every turn

makeMove(int col): asks for user input, places that input into the board
		   in this function, you should include "checkAvail", "checkWin", and "buildGrid"

checkWin(bool): checks for four in a row, vertically, or diagonally

checkAvail(bool): check to see which row is available for the whole "gravity" concept
		   in the 2D array, check if row, col position in grid is empty or not
		   ex) if first move player chooses col 2 as input, then row 0 is first available.
		    if next move is col 2 again, then row 1 is first available. 
		   so checkAvail returns next avail row number or return if column is full

compMove(): includes "makeMove" where input is randomized

##Team Split-Up
Person 1 builds framework (i.e making the board)
Person 2 creating input/output (i.e making the input/output system for player 1 and comp)
Person 3 checking win (i.e checking each move to see if anyone won)

## UI

constant input/output per turn
input - always asking for player column
output - showing new grid after every turn 
	

## Representation

maybe "buildGrid()" to display the connect four board in like dashes and x/o piecces
2D array

## Idea(s)
The API should be made so that this "connect 4" could be turned into "tic tac toe"
So "buildGrid()" could have parameter to change size
and could have "buildPieces()" that allows for connect 4 or connect 3, etc


