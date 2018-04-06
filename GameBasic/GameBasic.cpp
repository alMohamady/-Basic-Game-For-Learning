
#include "stdafx.h"
#include <iostream>

using namespace std;

bool mainManue();
bool playGame();
void showStory();
void resetGame();
bool updateWorld();
void drawGraphics();
void getInput();
bool gameOverScreen();

int difficulty = 10; 
char input = 'n';
int lowerBound = 0;
int upperBound = difficulty + 1;
int myGess = 0; 
int lastGess = -1;

int main() {
	while (mainManue()){
		while (playGame());
	}
	return 0;
}

bool mainManue(){
	cout << "Welcom to the Basic Game :) " << endl;
	while (true){
		cout << "1. Play a Game  :) " << endl; 
		cout << "2. Exit the Game :( " << endl; 
		cout << "> "; 
		cin >> input; 

		if (input == '1') return true; 
		else if (input == '2') return false;
	}
}

bool playGame() {
	showStory();

	resetGame();

	while (input != 'y'){
		updateWorld();

		drawGraphics(); 

		getInput();
	}

	return gameOverScreen();
}

void showStory(){
	input = 'n';
	
	cout << "Once apoun a time ......" << endl;
	cout << "you thought a number btween 0 and " << difficulty << endl;

	while (input != 'y'){
		cout << "Have you got one (y/n) ?";
		cin >> input;

		if (input != 'y') cout << "Ok, I'll wait a bit ....." << endl;
	}

	cout << endl;
}

void resetGame(){
	lowerBound = 0;
	upperBound = difficulty + 1;
	input = 'n';
}

bool updateWorld(){
	myGess = (lowerBound + upperBound) / 2;

	if (lastGess == myGess) {
		cout << "You are cheat !!" << endl; 
		return false; 
	}

	lastGess = myGess; 
	return true;
}

void drawGraphics(){
	cout << " I think it's  " << myGess << " ! Am I right  ??" << endl; 
	cout << " l. Lower " << endl;
	cout << " h. higher " << endl;
	cout << " y. yes " << endl;
}

void getInput() {
	cin >> input;

	switch (input)
	{
	case 'l': upperBound = myGess; break;
	case 'h': lowerBound = myGess; break;
	case 'y': cout << " Yaaaaay" << endl; break;
	}
}

bool gameOverScreen() {

	cout << endl; 
	cout << "Game Over" << endl;
	cout << "Paly againe (y/n) ?? " << endl; 
	cin >> input;

	if (input == 'y') return true; 
	else return false;
}