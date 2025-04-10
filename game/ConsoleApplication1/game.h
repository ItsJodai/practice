#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iomanip>

void Update();
void Start();
void Draw();
float deltaTime;
float maxwidth;
float textwidth;

using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1680, 1050), "SFML works!");
Font font;
Event event;
Sprite  bigbox, close, smallbox, arrowleft, arrowright, button, textbox, truebut, playersscreen, close2, add, finalplayer;
Texture texclose, texbigbox, player1, player2, texsmallbox, arrowr, arrowl, texbutton, TexTextbox, textrue, texplayerscreen, texadd;

string select = "Select";
Text buttonsel;
bool firstone = false;
bool sselectingisdone = false;
bool isplayersel = false;
bool deletname = false;
bool isentered = false;
bool istextboxsel = false;
bool keyisdown = false;
bool truebutton = false;
bool addplayer = false;
bool menubutton = true;
bool closeexit = false;
bool addexist = false;
int playerindex = 0;
int addcounter = 0;

struct player
{
    Sprite process[4];
    Texture playertex[2];
    Text playername;
    string username = "";
    string namedone = "";
    Text name;
    RectangleShape namebox;
    RectangleShape playerbox;

};
player myplayer[2];

int numofplayer = 1;








void playercut(player myplayer[], int x);

void chooseplayer(Vector2i mouse);

void cinname(Vector2i mouse, int&);


void closebut(Vector2i mouse);

void seltextbox(Vector2i mouse);

void doneselect(Vector2i mouse);


void closebut2(Vector2i mouse);


void startadd(Vector2i mouse, int&);

void finalchoose(Vector2i mouse);


