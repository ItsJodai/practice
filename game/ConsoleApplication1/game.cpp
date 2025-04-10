#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iomanip>
#include"game.h"
using namespace std;
using namespace sf;

int main()
{

    Start();
    Clock clock;
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();


        Update();
        Draw();
    }

    return 0;
}
void Start()
{

    menubutton = true;


    texadd.loadFromFile("menu\\add.png");
    texplayerscreen.loadFromFile("menu\\big.png");
    textrue.loadFromFile("menu\\true.png");
    texclose.loadFromFile("menu\\close.png");
    font.loadFromFile("ani\\font.ttf");
    texbigbox.loadFromFile("menu\\big.png");
    texbutton.loadFromFile("menu\\b3.png");
    arrowr.loadFromFile("menu\\right.png");
    arrowl.loadFromFile("menu\\left.png");
    texsmallbox.loadFromFile("menu\\small.png");
    myplayer[0].playertex[1].loadFromFile("ani\\spellcast1.png");
    myplayer[0].playertex[0].loadFromFile("ani\\spellcast.png");
    myplayer[1].playertex[1].loadFromFile("ani\\spellcast1.png");
    myplayer[1].playertex[0].loadFromFile("ani\\spellcast.png");
    TexTextbox.loadFromFile("menu\\b1.png");//edit

    bigbox.setTexture(texbigbox);
    bigbox.setPosition(90, 230);

    arrowright.setTexture(arrowr);
    arrowright.setPosition(356, 430);
    arrowright.setScale(0.13, 0.13);


    arrowleft.setTexture(arrowl);
    arrowleft.setPosition(160, 440);
    arrowleft.setScale(0.097, 0.097);



    button.setTexture(texbutton);
    button.setPosition(235, 510);
    button.setScale(0.65, 0.65);


    select = "Select";
    buttonsel.setString(select);
    buttonsel.setFont(font);
    buttonsel.setCharacterSize(24);
    buttonsel.setFillColor(Color::Black);
    buttonsel.setPosition(button.getPosition().x + 29, button.getPosition().y + 28);


    smallbox.setTexture(texsmallbox);
    smallbox.setPosition(150, 300);


    textbox.setTexture(TexTextbox);
    textbox.setPosition(bigbox.getPosition().x + 125, bigbox.getPosition().y + 240);
    textbox.setScale(2.5, 1);

    maxwidth = 3.3 * (TexTextbox.getSize().x - 60);



    myplayer[0].name.setPosition(textbox.getPosition().x + 45, textbox.getPosition().y + 25);
    myplayer[0].name.setFont(font);
    myplayer[0].name.setCharacterSize(34);
    myplayer[0].name.setFillColor(Color::Black);

    myplayer[1].name.setPosition(textbox.getPosition().x + 45, textbox.getPosition().y + 25);
    myplayer[1].name.setFont(font);
    myplayer[1].name.setCharacterSize(34);
    myplayer[1].name.setFillColor(Color::Black);


    close.setPosition(bigbox.getPosition().x + 400, bigbox.getPosition().y + 44);
    close.setTexture(texclose);
    close.setScale(0.5, 0.5);



    close2.setTexture(texclose);
    close2.setScale(0.5, 0.5);
    close2.setPosition(playersscreen.getPosition().x + 650, playersscreen.getPosition().y + 270);


    truebut.setPosition(bigbox.getPosition().x + 380, bigbox.getPosition().y + 260);
    truebut.setTexture(textrue);
    truebut.setScale(0.5, 0.5);



    playersscreen.setPosition(50, 200);
    playersscreen.setTexture(texplayerscreen);
    playersscreen.setScale(1.4, 1.3);

    add.setPosition(playersscreen.getPosition().x + 190, playersscreen.getPosition().y + 220);
    add.setTexture(texadd);
    add.setScale(0.14, 0.14);

    myplayer[0].playername.setFont(font);
    myplayer[0].playername.setCharacterSize(28);
    myplayer[0].playername.setFillColor(Color::Black);


    myplayer[0].playerbox.setFillColor(sf::Color(255, 255, 255, 150));
    myplayer[0].playerbox.setOutlineColor(sf::Color(139, 69, 19));
    myplayer[0].playerbox.setOrigin(myplayer[0].namebox.getGlobalBounds().width / 2, myplayer[0].namebox.getGlobalBounds().height / 2);
    myplayer[0].playerbox.setOutlineThickness(3);


    myplayer[0].namebox.setFillColor(sf::Color(255, 255, 255, 150));
    myplayer[0].namebox.setOutlineColor(sf::Color(139, 69, 19));
    myplayer[0].namebox.setOutlineThickness(3);
    myplayer[0].namebox.setOrigin(myplayer[0].namebox.getGlobalBounds().width / 2, myplayer[0].namebox.getGlobalBounds().height / 2);

    myplayer[0].process[0].setPosition((smallbox.getGlobalBounds().height) / 2 + 50, (smallbox.getGlobalBounds().width / 2) + 180);
    myplayer[0].process[0].setTexture(myplayer[0].playertex[0]);




    myplayer[1].playername.setFont(font);
    myplayer[1].playername.setCharacterSize(28);
    myplayer[1].playername.setFillColor(Color::Black);


    myplayer[1].playerbox.setFillColor(sf::Color(255, 255, 255, 150));
    myplayer[1].playerbox.setOutlineColor(sf::Color(139, 69, 19));
    myplayer[1].playerbox.setOrigin(myplayer[1].namebox.getGlobalBounds().width / 2, myplayer[1].namebox.getGlobalBounds().height / 2);
    myplayer[1].playerbox.setOutlineThickness(3);


    myplayer[1].namebox.setFillColor(sf::Color(255, 255, 255, 150));
    myplayer[1].namebox.setOutlineColor(sf::Color(139, 69, 19));
    myplayer[1].namebox.setOutlineThickness(3);
    myplayer[1].namebox.setOrigin(myplayer[1].namebox.getGlobalBounds().width / 2, myplayer[1].namebox.getGlobalBounds().height / 2);

    myplayer[1].process[0].setPosition((smallbox.getGlobalBounds().height) / 2 + 50, (smallbox.getGlobalBounds().width / 2) + 180);
    myplayer[1].process[0].setTexture(myplayer[1].playertex[0]);
    // cout << playerindex<<endl;


    IntRect rectplayer1(70, 128, 70, 64);
    myplayer[1].process[0].setTexture(myplayer[playerindex].playertex[0]);
    myplayer[1].process[0].setTextureRect(rectplayer1);
    myplayer[1].process[0].setScale(3.2, 3.2);

    playercut(myplayer, 0);
}


void Update()
{
    addexist = true;
    closeexit = false;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        Vector2i mouse = Mouse::getPosition(window);

        //menubutton = true;


        if (event.type == sf::Event::MouseButtonPressed) {

            chooseplayer(mouse);

            finalchoose(mouse);

            seltextbox(mouse);


            closebut(mouse);

            doneselect(mouse);

            closebut2(mouse);
            //if(addcounter<=2)
            startadd(mouse, playerindex);
        }


        if (istextboxsel)
            cinname(mouse, playerindex);



    }



}



void playercut(player myplayer[], int x) {


    IntRect rectplayer1(70, 128, 70, 64);
    myplayer[playerindex].process[0].setTexture(myplayer[playerindex].playertex[x]);
    myplayer[playerindex].process[0].setTextureRect(rectplayer1);
    myplayer[playerindex].process[0].setScale(3.2, 3.2);



}

void chooseplayer(Vector2i mouse) {

    if (!isplayersel) {



        if (arrowright.getGlobalBounds().contains(Vector2f(mouse)))
        {
            playercut(myplayer, 1);
        }
        else if (arrowleft.getGlobalBounds().contains(Vector2f(mouse))) {
            playercut(myplayer, 0);
        }


        if (button.getGlobalBounds().contains(Vector2f(mouse)) && !isplayersel)
        {

            isplayersel = true;
            myplayer[playerindex].process[1] = myplayer[playerindex].process[0];
            myplayer[playerindex].process[1].setPosition((bigbox.getGlobalBounds().height / 2) - 80, (bigbox.getGlobalBounds().width / 2) + 20);
        }



    }
}


void cinname(Vector2i mouse, int& ind) {




    if (istextboxsel && !isentered && event.type == Event::TextEntered) {
        textwidth = myplayer[ind].name.getLocalBounds().width;




        cout << "Key Pressed: " << event.text.unicode << endl;
        if (!keyisdown)
        {

            if (event.text.unicode == 8) {
                if (!myplayer[ind].username.empty()) {
                    myplayer[ind].username.pop_back();
                }
            }
            else if (event.text.unicode >= 32 && event.text.unicode < 127)
            {
                cout << textwidth << "  " << maxwidth << endl;
                if (textwidth < maxwidth)
                    myplayer[ind].username += static_cast<char>(event.text.unicode);

            }
            keyisdown = true;
        }
    }

    if (event.type == Event::KeyReleased)
    {
        keyisdown = false;
    }


    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
    {
        isentered = true;
        myplayer[ind].name.setString(myplayer[ind].username);
    }

    if (!isentered)
        myplayer[ind].name.setString(myplayer[ind].username + "_");
    else
        myplayer[ind].name.setString(myplayer[ind].username);


}

void closebut(Vector2i mouse) {

    if (close.getGlobalBounds().contains(Vector2f(mouse))) {

        isplayersel = false;
        istextboxsel = false;
        isentered = false;
        myplayer[playerindex].username = "";
        myplayer[playerindex].name.setString(myplayer[playerindex].username);
    }


}

void seltextbox(Vector2i mouse) {

    if (textbox.getGlobalBounds().contains(Vector2f(mouse)))
    {
        istextboxsel = true;


    }
    else
        istextboxsel = false;


}

void doneselect(Vector2i mouse) {
    int  x;

    if (truebut.getGlobalBounds().contains(Vector2f(mouse)))
    {
        if (playerindex == 1) {
            x = 200;

            add.setScale(0, 0);
        }
        else
            x = 0;
        menubutton = true;
        truebutton = true;
        istextboxsel = false;
        isentered = false;
        add.setPosition((myplayer[playerindex].process[2].getGlobalBounds().width) + 535, myplayer[playerindex].process[2].getPosition().y + 410);
        textwidth = myplayer[playerindex].name.getLocalBounds().width + 20;
        myplayer[playerindex].namebox.setSize(sf::Vector2f(textwidth, 30));
        myplayer[playerindex].playerbox.setSize(sf::Vector2f(3 * 64, 3 * 72));
        myplayer[playerindex].playerbox.setPosition(myplayer[playerindex].process[2].getPosition().x + 200 + x, myplayer[playerindex].process[2].getPosition().y + 360);
        myplayer[playerindex].namedone = myplayer[playerindex].username;
        myplayer[playerindex].playername.setString(myplayer[playerindex].namedone);
        myplayer[playerindex].namebox.setPosition(playersscreen.getPosition().x + 200 + x, playersscreen.getPosition().y + 390);
        myplayer[playerindex].playername.setPosition(myplayer[playerindex].namebox.getPosition().x + 15, myplayer[playerindex].namebox.getPosition().y);
        myplayer[playerindex].process[2] = myplayer[playerindex].process[1];
        myplayer[playerindex].process[2].setScale(3.7, 3.7);
        myplayer[playerindex].process[2].setPosition((myplayer[playerindex].playername.getGlobalBounds().height / 2) + 190 + x, (playersscreen.getGlobalBounds().width / 2) - 30);

    }
}

void closebut2(Vector2i mouse) {


    if (close2.getGlobalBounds().contains(Vector2f(mouse)))
    {
        truebutton = false;

        menubutton = false;
        addplayer = false;
    }



}

void startadd(Vector2i mouse, int& playerind) {


    if (add.getGlobalBounds().contains(Vector2f(mouse)))
    {
        addexist = true;
        addcounter++;
        if (addcounter == 2) {









            playerind++;
            isplayersel = false;
            if (istextboxsel && !isentered && event.type == Event::TextEntered) {
                textwidth = myplayer[1].name.getLocalBounds().width;




                cout << "Key Pressed: " << event.text.unicode << endl;
                if (!keyisdown)
                {

                    if (event.text.unicode == 8) {
                        if (!myplayer[1].username.empty()) {
                            myplayer[1].username.pop_back();
                        }
                    }
                    else if (event.text.unicode >= 32 && event.text.unicode < 127)
                    {
                        cout << textwidth << "  " << maxwidth << endl;
                        if (textwidth < maxwidth)
                            myplayer[1].username += static_cast<char>(event.text.unicode);

                    }
                    keyisdown = true;
                }
            }

            if (event.type == Event::KeyReleased)
            {
                keyisdown = false;
            }


            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
            {
                isentered = true;
                myplayer[1].name.setString(myplayer[1].username);
            }

            if (!isentered)
                myplayer[1].name.setString(myplayer[1].username + "_");
            else
                myplayer[1].name.setString(myplayer[1].username);


        }


        addplayer = true;
        menubutton = false;
        truebutton = false;
    }



}


void finalchoose(Vector2i mouse) {
    if (addcounter == 2 && truebutton) {

        if (myplayer[1].playerbox.getGlobalBounds().contains(Vector2f(mouse))) {

            finalplayer = myplayer[1].process[2];
            myplayer[1].playerbox.setFillColor(sf::Color(255, 255, 255, 150));
            finalplayer.setScale(6, 6);
            finalplayer.setPosition(400, 200);

            // playersscreen.setScale(0, 0);
            // close2.setScale(0, 0);
            truebutton = false;
            addplayer = false;
            sselectingisdone = true;


        }
        else   if (myplayer[0].playerbox.getGlobalBounds().contains(Vector2f(mouse))) {


            finalplayer = myplayer[0].process[2];
            myplayer[0].playerbox.setFillColor(sf::Color(255, 255, 255, 150));
            finalplayer.setScale(6, 6);
            finalplayer.setPosition(400, 200);

            truebutton = false;
            addplayer = false;
            sselectingisdone = true;


        }
    }
}



void Draw()
{


    window.clear();
    if (!sselectingisdone && menubutton || truebutton) {
        window.draw(playersscreen);
        window.draw(add);
        window.draw(close2);
    }


    if (addplayer && !menubutton && !sselectingisdone) {

        window.draw(smallbox);
        window.draw(arrowright);
        window.draw(arrowleft);
        if (addcounter == 1)
            window.draw(myplayer[0].process[0]);
        if (addcounter == 2)
            window.draw(myplayer[1].process[0]);
        window.draw(button);
        window.draw(buttonsel);
    }
    if (!sselectingisdone && isplayersel && addplayer && !menubutton) {
        window.draw(bigbox);
        window.draw(textbox);
        if (addcounter == 1)
            window.draw(myplayer[0].name);
        if (addcounter == 2)
            window.draw(myplayer[1].name);

        window.draw(truebut);
        window.draw(close);

        if (addcounter == 1)
            window.draw(myplayer[0].process[1]);
        if (addcounter == 2)
            window.draw(myplayer[1].process[1]);
    }

    if (truebutton && !sselectingisdone) {


        window.draw(myplayer[0].playerbox);
        window.draw(myplayer[0].process[2]);
        window.draw(myplayer[0].namebox);
        window.draw(myplayer[0].playername);

        window.draw(myplayer[1].playerbox);
        window.draw(myplayer[1].process[2]);
        window.draw(myplayer[1].namebox);
        window.draw(myplayer[1].playername);

    }


    if (sselectingisdone)
        window.draw(finalplayer);


    window.display();
}
