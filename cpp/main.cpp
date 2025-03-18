#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iomanip>
using namespace std;
using namespace sf;
bool isPlayerSelected = false;

Sprite selplayer, finalplayer;
String playername;
Texture player1;
Texture player2;
Sprite box;
Texture texbox;
Sprite arrowleft;
Sprite arrowright;
Texture arr;
Sprite butt;
Texture butttex;
sf::RenderWindow window(sf::VideoMode(1680, 1050), "SFML works!");
sf::CircleShape shape(100.f);
void Update(Event event);
void Start();
void Draw();
float deltaTime;
int main()
{
    Start();
    Clock clock;
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Update(event);
        Draw();
    }
    return 0;
}
void Start()
{
    butttex.loadFromFile("ani\\selct.png");
    arr.loadFromFile("ani\\buttons-arrows-V2.png");
    texbox.loadFromFile("ani\\back.png");
    player1.loadFromFile("ani\\spellcast1.png"); //3-1
    player2.loadFromFile("ani\\spellcast.png"); //3-1
    box.setTexture(texbox);
    box.setPosition(400, 300);
    IntRect rightrwct(0, 48, 16, 16);
    arrowright.setTexture(arr);
    arrowright.setTextureRect(rightrwct);
    arrowright.setPosition(695, 500);
    arrowright.setScale(2, 2);

    IntRect lefttrwct(16, 48, 16, 16);
    arrowleft.setTexture(arr);
    arrowleft.setTextureRect(lefttrwct);
    arrowleft.setPosition(390, 500);
    arrowleft.setScale(2, 2);
    selplayer.setPosition((box.getGlobalBounds().height) / 2 + 260, (box.getGlobalBounds().width / 2) + 195);

    IntRect rectplayer1(70, 128, 70, 64);
    selplayer.setTexture(player1);
    selplayer.setTextureRect(rectplayer1);
    selplayer.setScale(3.5, 3.5);
    butt.setTexture(butttex);
    butt.setPosition(485, 600);
    butt.setScale(0.3, 0.3);

}
void Update(Event event)
{

    if (event.type == Event::MouseButtonPressed)
    {
        Vector2i mousePos = Mouse::getPosition(window);
        if (!isPlayerSelected) {




            if (arrowright.getGlobalBounds().contains(Vector2f(mousePos)))
            {
                IntRect rectplayer2(70, 128, 70, 64);
                selplayer.setTexture(player2);
                selplayer.setTextureRect(rectplayer2);
            }
            else if (arrowleft.getGlobalBounds().contains(Vector2f(mousePos))) {
                IntRect rectplayer1(70, 128, 70, 64);
                selplayer.setTexture(player1);
                selplayer.setTextureRect(rectplayer1);
            }
        }
        if (butt.getGlobalBounds().contains(Vector2f(mousePos)) && !isPlayerSelected)
        {

            isPlayerSelected = true;
            finalplayer = selplayer;
        }

    }

    finalplayer.setPosition(100, 100);



}
void Draw()
{


    window.clear();



    window.draw(box);
    window.draw(arrowright);
    window.draw(arrowleft);
    window.draw(selplayer);
    window.draw(butt);
    window.draw(finalplayer);
    window.display();
}