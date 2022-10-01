//ANNS SHAHBAZ BSE19M007
#include<iostream>
#include "SpaceInvader.h"
#include <string>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;


//I HAVE SET WINNING SCORE 15, IT CAN BE CHANGED FROM HERE
#define Winning_Score 15    //WINNING SCORE, CAN BE CHANGED ACCORDING TO THE NEED 

HANDLE console1 = GetStdHandle(STD_OUTPUT_HANDLE);      
COORD CursorPositionMain;                   //TO HANDLE CURSOR POSITION

HWND hWnd = GetConsoleWindow();     //CONSOLE HANDLER I USED IT SO THAT THE CONSOLE ALWAYS OPENS MAXIMIZED

void Welcome();         //WELCOME FUNCTION
void Won();             //WON FUNCTION
void Lost();        //LOST FUNCTION

int main() {

    
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);     //SHOW MAXIMIZED, to show console maximized always
    srand((unsigned)time(0));               //RANDOM NUMBER
    int randomNumber;

    Welcome();          //WELCOME FUNCTION



    Rocket r;                   //CREATING ROCKET
    MartianShip m[2];           //CRATING MARTIAN SHIPS
    m[1].setX(15);               //SETTING IT'S POSITIONS
    m[1].setY(3);
   
    StarShip s[2];              //CREATING START SHIPS
    s[1].setX(24);               //SETTING IT'S POSITIONS
    s[1].setY(6);
    
    bool GameOver = false;      //TO CHECK IF GAME IS OVER
   

    while (GameOver == false) {     //WHILE GAMME IS NOT OVER


        
        if (m[0].Score >= Winning_Score) {   //CHECK SCORE IF GAME SHOULD BE CONTINUED OR NOT

            system("cls");          //clear screen
            GameOver = true;
            break;                  //get out from loop
        }

        if (r.getLives() <= 0) {        //if lives < 0, game lost

            system("cls");
            GameOver = true;
            break;
        }
        
            
        //if player and all enemies have 0 fire balls game is lost
        if (r.Balls->getSize() == 0 && m[0].Balls->getSize() == 0 && m[1].Balls->getSize() == 0 && s[0].Balls->getSize() == 0 && s[1].Balls->getSize() == 0) {
            GameOver = true;
            system("cls");
            break;
        }


        randomNumber = (rand() % 35) + 1;   //GENERATE A RANDOM NUMBER
        ShowWindow(hWnd, SW_SHOWMAXIMIZED);     //MAXIMIZE WINDOW
        system("cls");      //CLEAR SCREEN

        r.draw();                               //DRAW BOUNDARY, ROCKET AND OTHER SHIPS
        for (int i = 0; i < 2; i++) {

            m[i].draw();
            s[i].draw();

        }


        for (int i = 0; i < 2; i++) {           //MOVE THE OTHER SHIPS RANDOMLY

            m[i].move(&r, m, s);
            s[i].move(&r, m, s);

        }

       

            

      

        //SHOW SCORECARD, and other things
        CursorPositionMain.X = 0;
        CursorPositionMain.Y = 31;
        SetConsoleCursorPosition(console1, CursorPositionMain);

        cout << "=> Score:: " << m->Score << "  " << endl;
        cout << "=> Lives::" << r.getLives() << "   " << endl;
        cout << "=> Rocket Power::" << r.getShipPower() << "   " << endl;
        cout << "=> Rocket Balls::-------------" << r.Balls->getSize() << "   " << endl;

        for (int i = 0; i < 2; i++) {

            cout << "=> Martian " << i + 1 << " Power: " << m[i].getShipPower() << endl;
            cout << "=> Star " << i + 1 << " Power: " << s[i].getShipPower() << endl;
            cout << "=> MARTIAN " << i + 1 << " BALLS:---------------- " << m[i].Balls->getSize() << endl;
            cout << "=> Star " << i + 1 << " BALLS:---------- " << s[i].Balls->getSize() << endl;
        }

        //TAKE INPUT FOR USER ROCKET
       
        char c = '0';
        c = _getch();

        switch ((c)) {
            //IF HE WANTS TO MOVE,detect UP,DOWN,LEFT,RIGHT arrow keys or WASD keys
        case 72:        //UP
        case 77:        //right
        case 75:        //left
        case 80:        //down
        case 'w':
        case 'W':
        case 'a':
        case 'A':
        case 's':
        case 'S':
        case 'd':
        case 'D':
            r.move(m, s, c);
            break;
        case 102:       //IF HE WANTS TO FIRE, detect f
        case 70: {
            r.fire(m, s);
            break;
        }
        case -32:       //sometimes _getch causes issues and read -32 then continute to read the correct input
            continue;
        default:
            break;
        }
      

        //OPPONENT RANDOMLY FIRES
        if (randomNumber % 2 == 0)      
             m[0].fire(&r,m,s);

        if (randomNumber % 5 == 0)
           m[1].fire(&r, m, s);

        if (randomNumber % 9 == 0)
          s[0].fire(&r,m,s);

       if (randomNumber % 11 == 0)
          s[1].fire(&r,m,s);
        
       
    }

    //IF game is won call the Won function
    if (GameOver == true && m[0].Score >= Winning_Score)
        Won();
    //IF LOST, call the lost function
   else 
        Lost();
       
    return 0;
}

void Won() {

    cout << "=> Congratulations, YOU DID IT.\n => You WON";

}

void Lost() {
    cout << "=> Better luck next time. YOU LOST";
}

void Welcome() {

    int c = 0;

    cout << endl << "\t\t\t\t\t       /\\ " << endl;
    cout << "\t\t\t\t\t      /  \\" << endl;
    cout << "\t\t\t\t\t     /    \\" << endl;
    cout << "\t\t\t\t\t    /      \\" << endl;
    cout << "\t\t\t\t\t    |   A  |" << endl;
    cout << "\t\t\t\t\t    |   N  |" << endl;
    cout << "\t\t\t\t\t  / |   S  | \\" << endl;
    cout << "\t\t\t\t\t /  |   I  |  \\" << endl;
    cout << "\t\t\t\t\t \\  |      |  /" << endl;
    cout << "\t\t\t\t\t  \\ |      | /" << endl;
    cout << "\t\t\t\t\t    |      |" << endl;
    cout << "\t\t\t\t\t    |      |" << endl;
    cout << "\t\t\t\t\t    |      |" << endl;
    cout << "\t\t\t\t\t    --------" << endl;
    cout << "\t\t\t\t\t    ||||||||" << endl;

    cout << "\t\t\t\t_____   _____   _____   _____   _____" << endl;
    cout << "\t\t\t\t|         |     |   |   |   /     |  " << endl;
    cout << "\t\t\t\t|____     |     |___|   |  /      |  " << endl;
    cout << "\t\t\t\t    |     |     |   |   | \\       |" << endl;
    cout << "\t\t\t\t____|     |     |   |   |  \\      |" << endl;

    cout << "\n\t\t\t\t\t Press S To Start" << endl;

    while (1) {
        c = _getch();       //START IF S IS PRESSED
        if (c == 115 || c == 83)
            break;
    }

    system("cls");

    cout << "=> INSTRUCTIONS FOR THE GAME " << endl;
    cout << "=> CONTROLS: " << endl;
    cout << "=> USE ARROW KEYS / WASD TO MOVE YOUR ROCKET. " << endl;
    cout << "=> PRESS 'F' TO FIRE. " << endl;
    cout << "=> Instructions:" << endl;
    cout << "=> There are two types of enemies, shooting each enemy reward you with 10 points." << endl;
    cout << "=> 5 hits will destroy Martian Ship and 3 hits will destroy the smaller Star Ship." << endl;
    cout << "=> Score " << Winning_Score << " points to win." << endl;
    cout << "=> You have 3 lives to play." << endl;
    cout << "=> Each live is lost by 3 consecutive shots." << endl;
    cout << "=> AFTER READING THE INSTRUCTIONS CAREFULLY." << endl;
    system("pause");
}

