//ANNS SHAHBAZ BSE19M007
#pragma once
using namespace std;
class Fireball;		//fwd declartations
class MartianShip;
class StarShip;
class Rocket;

//FIRE BALL CLASS THAT MAINTAINS THE NUMBER OF FIRES
class FireBall {
protected:
	int Size;	//SPECIFIC SIZE OF ROCKETS
public:
	static int General_Size;		//GENEARL FIRE SIZE
	FireBall();			//DEFAULT CONSTRUCTOR
	int getSize();		//to get the size
	void setSize(int);		//to set the size
};

class SpaceShip {

protected:
	double xloc, yloc;			//X AND Y POSITIONS
	double Restored_X, Restored_Y;		//TO HAVE A RECORD OF ORIGINAL POSITIONS
	bool destroyed;			//IF SHIP IS DESTROYED OR NOT
	double ShipPower;		//SHIP POWER
	double Fxloc, Fyloc;		//it's fire location
public:
	SpaceShip();			//default constructor
	FireBall* Balls;			//FireBall contained in Rocket as an array
	static int Score;		//SCORE
	virtual void draw() = 0;		//DRAW FUNCTIONS
	virtual void fire(Rocket*, MartianShip*, StarShip*);		//FIRE function
	virtual void move(Rocket*, MartianShip*, StarShip*);		//MOVE function
	bool getDestruction();		//to get Boolean variable destroyed
	void setDestruction(bool);	//to Set Boolean variable destroyed
	double getShipPower();		//get ship power
	void setShipPower(double);		//set power
	double getX();			//get X
	double getY();			//get Y
	double getRestoredX();		//get Original starting X
	double getRestoredY();		//get Original Starting Y
	void setX(double);		//set X
	void setY(double);		//set Y
};


class MartianShip : public SpaceShip {

private:
	string Martian;				//Martian ROcket Shape	
public:
	MartianShip();				//deafault constructor
	MartianShip(double, double);		//parameterize
	void draw();			//draw function
};

class StarShip : public SpaceShip {

private:
	string Star;			//star Rocket Shape
public:
	StarShip();			//default constructor
	StarShip(double, double);		//parameterize
	void draw();		//draw functions

};

class Rocket {		//player rocket class

private:
	double xloc, yloc;			//X and Y co ordinates
	double Fxloc, Fyloc;					//it's fire co ordinates
	string player;			//player shape
	int lives;		//its lives
	int ShipPower;		//its power
	bool destroyed;
public:
	FireBall* Balls;		//FireBall contained in Rocket as an array
	Rocket();			//Default Construcot
	void draw();		//draw functions
	void move(MartianShip*, StarShip*, char);		//move function
	void fire(MartianShip*, StarShip*);		//fire functions
	double getX();		//get X
	double getY();		//get Y
	int getLives();			//get Lives
	void setLives(int);		// set Lives
	int getShipPower();		//get SHip power
	void setShipPower(int);	// set ship power
	bool getDestruction();		//to get Boolean variable destroyed
	void setDestruction(bool);	//to Set Boolean variable destroyed

};


