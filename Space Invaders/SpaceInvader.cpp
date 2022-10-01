//ANNS SHAHBAZ BSE19M007
#include<iostream>
#include "SpaceInvader.h"
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;			// to handle cursore postions

int MartianShip::Score = 0;				//Static Score
int FireBall::General_Size = 20;			//Genarl Fire Ball size
//GENERAL SIZES CAN BE CHANGED, ACCORDING TO THE NEED

SpaceShip::SpaceShip() {			//abstract class

	xloc = 0;							//initilaize variables to 0, non speciied
	yloc = 0;
	Restored_X = xloc;
	Restored_Y = yloc;
	destroyed = false;
	ShipPower = 0;
	Fxloc = 0;
	Fyloc = 0;

	Balls = new FireBall[FireBall::General_Size];		//Fira ball array of general size
	Balls->setSize(FireBall::General_Size);
}

void SpaceShip::fire(Rocket* r, MartianShip* m, StarShip* s) {

	if (destroyed == false && Balls->getSize() > 0 && r->getDestruction() == false) {		//Fire If the firing ship is not destroyed, and it has fires and the rocket is also not destroyed

		int z = Balls->getSize();		//decrement one after every fire
		z--;
		Balls->setSize(z);

		Fxloc = xloc + 1;		//set fire starting location according the the ship position
		Fyloc = yloc + 1;

		while (Fyloc <= r->getY()) {		//while fire has not reached to the rockter

			CursorPosition.X = Fxloc;
			CursorPosition.Y = Fyloc++;
			SetConsoleCursorPosition(console, CursorPosition);
			cout << "|";		//do fire
			system("cls");
			r->draw();
			//drawr side by side
			for (int i = 0; i < 2; i++) {
				m[i].draw();
				s[i].draw();

			}
			//check if fire has hit the rocket

			if (Fxloc >= r->getX() && Fxloc < r->getX() + 4 && Fyloc >= r->getY() && Fyloc < r->getY() + 4) {

				int a = r->getShipPower();			//decrease the ship power
				a -= 1;
				r->setShipPower(a);


				if (r->getShipPower() <= 0) {		// if ship is destroyed decrease one live

					int c = r->getLives();
					c -= 1;
					r->setLives(c);


					r->setShipPower(3);		//Restart the game with low lives and 0 score, As advised
					Score = 0;


					for (int i = 0; i < 2; i++) {

						m[i].setShipPower(50);
						m[i].setDestruction(false);


						s[i].setDestruction(false);
						s[i].setShipPower(30);


						s[i].setX(s[i].getRestoredX());
						s[i].setY(s[i].getRestoredY());


						m[i].setX(m[i].getRestoredX());
						m[i].setY(m[i].getRestoredY());


						m[i].Balls->setSize(FireBall::General_Size);
						s[i].Balls->setSize(FireBall::General_Size);
						r->Balls->setSize(FireBall::General_Size);



					}

				}
				if (r->getLives() <= 0) {		//if Rocket is destroyed and no more lives are left game is over

					r->setDestruction(true);

				}


				break;

			}

		}
	}

}

void SpaceShip::move(Rocket* r, MartianShip* m, StarShip* s) {		//Move function

	if (destroyed == false) {
		srand((unsigned)time(0));
		int RandomNumber;

		RandomNumber = (rand() % 5) + 1;		//randomly move sometimes

		if (RandomNumber % 2 == 0) {		//Move only from Top To Bottom (As advised)
			if (yloc < 20)		//allowed to move few steps DOWN
				++yloc;
		}
	}

	system("cls");          //CEALR SCREEN
	r->draw();             //DRAW BOUNDARY, ROCKET AND OTHER SHIPS
	for (int i = 0; i < 2; i++) {

		m[i].draw();
		s[i].draw();

	}

}

bool SpaceShip::getDestruction() {
	return this->destroyed;			//geting desrtroyed
}

void SpaceShip::setDestruction(bool b) {
	this->destroyed = b;		//setting destroyed
}

double SpaceShip::getShipPower() {
	return ShipPower;		//get ship power
}

void SpaceShip::setShipPower(double d) {
	this->ShipPower = d;		//set ship power
}

double SpaceShip::getX() {
	return xloc;		//GET X
}

double SpaceShip::getY() {
	return yloc;		//GET Y
}

double SpaceShip::getRestoredX() {
	return Restored_X;				//GET Original X
}

double SpaceShip::getRestoredY() {
	return Restored_Y;			//GET Original Y
}

void SpaceShip::setX(double X) {
	xloc = X;
	Restored_X = xloc;			//SET X
}

void SpaceShip::setY(double Y) {
	yloc = Y;
	Restored_Y = yloc;			//SET Y
}

MartianShip::MartianShip() {


	Balls = new FireBall[FireBall::General_Size];			//Containing fireBall as an array
	Balls->setSize(FireBall::General_Size);			//setting the sizes

	xloc = 3;				//default construction , x = 3 , y = 1 co ordinates
	yloc = 1;
	ShipPower = 50;			//ship power 
	destroyed = false;		//not destroyed
	Martian = "_\\/_";			//shaper
	Restored_X = xloc;		//orignal location
	Restored_Y = yloc;
	Fxloc = 0;			//fire location not specified yet
	Fyloc = 0;

}

MartianShip::MartianShip(double X, double Y) {

	Balls = new FireBall[FireBall::General_Size];			//Containing fireBall as an array
	Balls->setSize(FireBall::General_Size);			//setting the sizes

	xloc = X;				//default construction , x = 3 , y = 1 co ordinates
	yloc = Y;
	ShipPower = 50;			//ship power 
	destroyed = false;		//not destroyed
	Martian = "_\\/_";			//shaper
	Restored_X = xloc;		//orignal location
	Restored_Y = yloc;
	Fxloc = 0;			//fire location not specified yet
	Fyloc = 0;

}

void MartianShip::draw() {



	if (ShipPower > 0) {		//if ship is not destroyed yet

		CursorPosition.X = xloc;		//draw the ship
		CursorPosition.Y = yloc;
		SetConsoleCursorPosition(console, CursorPosition);

		cout << Martian;

	}

	else if (Score % 30 == 0) {		// else if all the opponents are destroyed then make them re appear
		ShipPower = 50;			//Appearing them from their original starting points
		destroyed = false;
		xloc = Restored_X;
		yloc = Restored_Y;
		Balls->setSize(FireBall::General_Size);

	}

	else {							//else if it is destroyed then 
		xloc = -100;
		yloc = -100;
		destroyed = true;
		Balls->setSize(0);
	}

}

StarShip::StarShip() {

	Balls = new FireBall[FireBall::General_Size];		//containng fire ball as an array
	Balls->setSize(FireBall::General_Size);		//setting size

	xloc = 9;			//deafult position of star ship
	yloc = 9;
	ShipPower = 30;			//power
	destroyed = false;
	Star = "\\/";		//shpae
	Restored_X = xloc;		//oringal locations
	Restored_Y = yloc;
	Fxloc = 0;			//fire not specifed yet
	Fyloc = 0;

}

StarShip::StarShip(double X, double Y) {

	Balls = new FireBall[FireBall::General_Size];		//containng fire ball as an array
	Balls->setSize(FireBall::General_Size);		//setting size

	xloc = X;			//deafult position of star ship
	yloc = Y;
	ShipPower = 30;			//power
	destroyed = false;
	Star = "\\/";		//shpae
	Restored_X = xloc;		//oringal locations
	Restored_Y = yloc;
	Fxloc = 0;			//fire not specifed yet
	Fyloc = 0;


}

void StarShip::draw() {

	if (ShipPower > 0) {		//if ship is not destroyed

		CursorPosition.X = xloc;		//draw it
		CursorPosition.Y = yloc;
		SetConsoleCursorPosition(console, CursorPosition);

		cout << Star;

	}

	else if (Score % 30 == 0) {		// else if all the opponents are destroyed then make them re appear

		ShipPower = 30;
		destroyed = false;
		xloc = Restored_X;
		yloc = Restored_Y;
		Balls->setSize(FireBall::General_Size);
	}


	else {		//if destroyed then

		xloc = -100;
		yloc = -100;
		destroyed = true;
		Balls->setSize(0);		

	}
}

Rocket::Rocket() {


	Balls = new FireBall[FireBall::General_Size];		//contatining a fire ball array
	Balls->setSize(FireBall::General_Size);

	lives = 3;			//lives
					//default location of Rocket
	xloc = 12;
	yloc = 28;
	ShipPower = 3;		//As it can bear 3 shots 

	Fxloc = xloc;
	Fyloc = yloc;

	player = "_^_";		//shape
	destroyed = false;		//not destroyed

}

void Rocket::draw() {


	if (lives > 0) {		//if there are still some lives

		for (int i = 0; i < 30; i++) {		//draw rocket and the game boundary, Game boundary can be drawn in main function too

			if (i == 0 || i == 29) {

				CursorPosition.X = 0;
				CursorPosition.Y = i;
				SetConsoleCursorPosition(console, CursorPosition);

				cout << "*****************************" << endl;

			}

			else {

				CursorPosition.X = 0;
				CursorPosition.Y = i;
				SetConsoleCursorPosition(console, CursorPosition);
				cout << "*";

				CursorPosition.X = 28;
				CursorPosition.Y = i;
				SetConsoleCursorPosition(console, CursorPosition);
				cout << "*";
			}
		}



		CursorPosition.X = xloc;
		CursorPosition.Y = yloc;
		SetConsoleCursorPosition(console, CursorPosition);

		cout << player;

	}


}

void Rocket::move(MartianShip *m, StarShip *s , char c) {

	
	switch (c) {		//depending on the input move the rocket

	case 72:
	case 'w': { //UP

		if (yloc > 22)		//allowed to move few steps UP
			--yloc;// key up
		break;
	}
	case 80:
	case 's': {	//DOWN

		if (yloc < 28)	//allowed to move few steps Down
			++yloc;// key downw
		break;
	}

	case 75:
	case 'a': {

		if (xloc > 1)	//allowed to move few steps LEFT
			--xloc;// key left
		break;
	}

	case 77:
	case 'd':
	{ //right

		if (xloc < 25)	//allowed to move few steps RIGHT
			++xloc;  // key right
		break;

	}


	default:
		break;
	}

	//draw after moving
	system("cls");
	Rocket::draw();

	for (int i = 0; i < 2; i++) {

		m[i].draw();
		s[i].draw();

	}

}

void Rocket::fire(MartianShip* m, StarShip* s) {


	bool doBreak = false;		//to help in breaking loop

	Fxloc = xloc + 1;		//setting fire postion
	Fyloc = yloc - 1;

	if (Balls->getSize() > 0 && destroyed == false) {		//if it has some fires left and is not destroyed yet

		int z = Balls->getSize();		//decrement by one after every fire
		z--;
		Balls->setSize(z);
		
		
		for (int i = 0; i < 27; i++) {

			//do fire 
			CursorPosition.X = Fxloc;
			CursorPosition.Y = Fyloc--;
			SetConsoleCursorPosition(console, CursorPosition);
			cout << "|";
			system("cls");
			Rocket::draw();

			for (int i = 0; i < 2; i++) {

				m[i].draw();
				s[i].draw();

			}


			for (int i = 0; i < 2; i++) {

						//check if it has hit the Martian ship
				if (Fxloc >= m[i].getX() && Fxloc < m[i].getX() + 4 && Fyloc == m[i].getY()) {

					double q = m[i].getShipPower();			//decreas ship power
					q -= 10;
					m[i].setShipPower(q);


					//increase score
					if (m[i].getShipPower() <= 0 && m[i].getDestruction() == false)
						m[i].Score += 10;

					doBreak = true;
					break;

				}

			}

			if (doBreak == true)	// break if it has hit the Martian Ship
				break;

			//check if it has hit the Star Ship
			for (int i = 0; i < 2; i++) {

				if (Fxloc >= s[i].getX() && Fxloc < s[i].getX() + 2 && Fyloc == s[i].getY()) {

					double w = s[i].getShipPower();		//decrease ship power
					w -= 10;
					s[i].setShipPower(w);

					
					//increase score
					if (s[i].getShipPower() <= 0 && s[i].getDestruction() == false)
						m[i].Score += 5;

					doBreak = true;
					break;

				}
			}

			if (doBreak == true)
				break;



		}
	}

}

double Rocket::getX() {

	return xloc;			//get X

}

double Rocket::getY() {

	return yloc;		//get Y

}

int Rocket::getLives() {

	return lives;		//Get lives
}

void Rocket::setLives(int l) {
	lives = l;		//set Lives
}

int Rocket::getShipPower() {
	return ShipPower;		//get Ship Power
}

void Rocket::setShipPower(int s)  {
	this->ShipPower = s;		//Set Ship Power
}


bool Rocket::getDestruction() {
	return this->destroyed;			//geting desrtroyed
}

void Rocket::setDestruction(bool b) {
	this->destroyed = b;		//setting destroyed
}


FireBall::FireBall() {
	Size = 0;		//Fire Ball constructore
}

int FireBall::getSize() {
	return this->Size;		//GET Size
}

void FireBall::setSize(int s) {
	this->Size = s;		//SET size
}
