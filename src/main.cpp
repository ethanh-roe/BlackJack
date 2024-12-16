#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "include/Deck.h"

using namespace std;

sf::RectangleShape drawBackground(){
    sf::RectangleShape background(sf::Vector2f(120.f, 50.f));

    background.setSize(sf::Vector2f(800.f, 600.f));
    background.setFillColor(sf::Color(0, 105, 10));
    return background;
}

sf::Text drawFps(float fps, sf::Font font){
    sf::Text text;
    text.setFont(font);

    stringstream ss;
    ss.precision(2);
    ss << fixed << fps;

    text.setString("FPS: " + ss.str());
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    sf::FloatRect bounds = text.getLocalBounds();

    float x = 800 - bounds.width - 1;
    float y = 0;

    text.setPosition(x, y);

    return text;
}

void renderingThread(sf::RenderWindow* window)
{
    window->setActive(true);
    window->setFramerateLimit(60);
    sf::Clock clock;

    sf::Font font;

    if(!font.loadFromFile("res/fonts/calibri.ttf")){
        cerr << "error loading font" << endl;
    }

    while(window->isOpen())
    {

        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f / currentTime;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // clear the window with black color
        window->clear(sf::Color::Black);

        window->draw(drawBackground());

        window->draw(drawFps(fps, font));
        // end the current frame
        window->display();
    }
}


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Black Jack - Ethan Roe");
    window.setFramerateLimit(60);

    window.setActive(false);
    
    sf::Thread thread(&renderingThread, &window);
    thread.launch();

    Deck* deck = new Deck();
    deck->initDeck();
    // run the program as long as the window is open
    while (window.isOpen())
    {
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            deck->shuffle();
            cout << "shuffled" << endl;
        }
        
    }

    return 0;
}

