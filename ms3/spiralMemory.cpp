#include <iostream>
#include <string>
#include "../helperFunctions.h"

using namespace std;

#define input 347991
#define mSize 100

int calcSum(int m[][mSize], int y, int x);

int main(){
	/* yMax is set to 0 because it gets incremented right away in the x == xMax if statement */
	int yMax = 0, xMax = 1, y = 0, x = 0;
	bool moveX = true;
	/* Traverse x and y according to the rules of the matrix */
	for(int i = 1; i < input; i++){
		if(moveX){
			x++;
			if(x == xMax){
				moveX = false;
				y = 0;
				yMax++;
			}
		}
		else{
			y++;
			if(y == yMax){
				moveX = true;
				x = 0;
				xMax++;
			}
		}
	}

	/* Wherever x and y is from the max steps of the current iteration, they only need to travel to the middle */
	int yMiddle = yMax / 2;
	int xMiddle = xMax / 2;

	/* Distance from where x and y exist to the middle */
	int yDist = abs(yMiddle - y);
	int xDist = abs(xMiddle - x);

	/* Total distance */
	int steps = xDist + yDist;

	cout << "steps needed: " << steps << endl;

	/* Making a second loop with an actual matrix for 3b, mSize defined at the top */
	int m[mSize][mSize] = {{0}}; //init all elements to 0

	x = y = mSize/2;
	m[y][x] = 1;
	moveX = true;
	yMax = 0;
	xMax = 1;
	int xSteps = 0, ySteps = 0;
	int sum = 0;

	/*
	 * Fugly solution probably. Here x and y needs to be tracked in the array,
	 * but also how many steps has been taken in the x and y direction already
	 */
	while(1){
		if(moveX){
			xSteps++;
			/* if xMax is even it travels to the left, so reduce x, if odd, increment instead */
			isEven(xMax) ? x-- : x++;
			if(xSteps == xMax){
				yMax++;
				ySteps = 0;
				moveX = false;
			}
		}
		else{
			ySteps++;
			isEven(yMax) ? y++ : y--;
			if(ySteps == yMax){
				xMax++;
				xSteps = 0;
				moveX = true;
			}
		}
		/* Sum up adjacent values and set it into [y][x] */
		sum = calcSum(m, y, x);
		if(sum > input)
			break;
	}

	cout << "The first number larger than the input is: " << sum << endl;

	return 0;
}

int calcSum(int m[][mSize], int y, int x){
	int sum = 0;
	for(int i = y-1; i <= y+1; i++){
		for(int j = x-1; j <= x+1; j++){
			sum += m[i][j];
		}
	}
	m[y][x] = sum;
	return sum;
}
