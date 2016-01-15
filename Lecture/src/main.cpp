#include <SFML/Graphics.hpp>
#include "ResourcePath.h"
#include <iostream>

using namespace std;

enum gameScene {
    start,
    mid,
    lose,
    win
};

struct GameState {
    GameState() {
        resetTouches();
        scene = start;
    }
    
    void resetTouches() {
        touch1 = touch2 = touch3 = touch4 = touch5 = 0;
    }
    
    sf::Clock clock;
    bool touch1, touch2, touch3, touch4, touch5;
    gameScene scene;
};

int main()
{
    // Initialization: everything before main loop
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML Works!");
    
    sf::RectangleShape shape1(sf::Vector2f(100, 100));
    sf::CircleShape shape2(75.f);
    sf::RectangleShape shape3(sf::Vector2f(100, 100));
    sf::RectangleShape shape4(sf::Vector2f(100, 100));
    sf::RectangleShape shape5(sf::Vector2f(100, 100));
    
    shape1.setPosition(100, 100);
    shape2.setPosition(300, 100);
    shape3.setPosition(200, 400);
    shape4.setPosition(200, 400);
    shape5.setPosition(300, 100);
    
    shape1.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Blue);
    shape3.setFillColor(sf::Color::Red);
    shape4.setFillColor(sf::Color::Cyan);
    shape5.setFillColor(sf::Color::Yellow);
    
    sf::Font font;
    font.loadFromFile("/Library/Fonts/arial.ttf");

    sf::Text introText("Press space to start game", font, 20);
    sf::Text loseText("You lose", font, 50);
    sf::Text winText("You win", font, 50);

    // Game state: values inside variables
    GameState state;
    
    // Main loop
    while (window.isOpen())
    {
        float secondsPast = state.clock.getElapsedTime().asSeconds();
        
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (state.scene == start){
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space) {
                        state.resetTouches();
                        state.scene = mid;
                    }
                }
            }
            
            if (state.scene == mid){
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        int x = sf::Mouse::getPosition(window).x;
                        int y = sf::Mouse::getPosition(window).y;
                        
                        if (x >= 100 && y <= 200 &&
                            y >= 100 && y <= 200 &&
                            secondsPast > 1 ) {
                            state.touch1 = true;
                        }
                        if (x >= 300 && x <= 450 &&
                            y >= 100 && y <= 250 &&
                            secondsPast > (2) ){
                            state.touch2 = true;
                        }
                        if (x >= 200 && x <= 300 &&
                            y >= 400 && y <= 500 &&
                            secondsPast > (3) ){
                            state.touch3 = true;
                        }
                        if (x >= 200 && x <= 300 &&
                            y >= 400 && y <= 500 &&
                            secondsPast > (6) ){
                            state.touch4 = true;
                        }
                        if (x >= 300 && x <= 400 &&
                            y >= 100 && y <= 200 &&
                            secondsPast > (6) ){
                            state.touch5 = true;
                        }
                    }
                }
                
            }
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // Simulate world: Update the world by 16.7 milliseconds.
        if (state.scene == start) {
            state.clock.restart();
        }

        if (state.scene == mid) {
            if ( secondsPast > (1) && !state.touch1){
                if (secondsPast > 4){
                    state.scene = lose;
                }
            }
            if ( secondsPast > (2) && !state.touch2){
                if (secondsPast > 5){
                    state.scene = lose;
                }
            }
            if ( secondsPast > (3) && !state.touch3){
                if (secondsPast > 6){
                    state.scene = lose;
                }
            }
            if ( secondsPast > (6) && !state.touch4){
                if (secondsPast > 9){
                    state.scene = lose;
                }
            }
            if ( secondsPast > (6) && !state.touch5){
                if (secondsPast > 9){
                    state.scene = lose;
                }
            }
            if (state.touch5 && state.touch4){
                state.clock.restart();
                secondsPast = 0.0;
                state.scene = win;
            }
        }
        
        if (state.scene == lose){
            if ( secondsPast > 12.5){
                state.scene = start;
            }
        }
        
        if (state.scene == win){
            if ( secondsPast > 2.5){
                state.scene = start;
            }
        }
        
        // Render: draw your game state to the screen
        window.clear();
        
        if (state.scene == start) {
            window.draw(introText);
        }
        
        if (state.scene == mid) {
            if ( secondsPast > (1) && !state.touch1){
                window.draw(shape1);
            }
            if ( secondsPast > (2) && !state.touch2){
                window.draw(shape2);
            }
            if ( secondsPast > (3) && !state.touch3){
                window.draw(shape3);
            }
            if ( secondsPast > (6) && !state.touch4){
                window.draw(shape4);
            }
            if ( secondsPast > (6) && !state.touch5){
                window.draw(shape5);
            }
        }
        
        if (state.scene == lose) {
            window.draw(loseText);
        }
        
        if (state.scene == win) {
            window.draw(winText);
        }
        
        window.display();
        
        
    }
    
    return 0;
}