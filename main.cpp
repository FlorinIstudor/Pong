#define _USE_MATH_DEFINES

#include <iostream>
#include "StateMachine.h"

int main()
{
    float fixedUpdateTime = 1.f / 60.f;
    sf::RenderWindow window(sf::VideoMode(1024, 512),"Pong", sf::Style::Close);

    StateMachine Manager(&window);

    Manager.newScene = new MainMenu();

    sf::Clock Clock;
    sf::Time dt;

    window.setFramerateLimit(60.f);

    float fpassedTime = 0.f;

    while (window.isOpen())
    {
        dt = Clock.restart();
        fpassedTime += dt.asSeconds();

        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        Manager.Update(dt);      

        while (fpassedTime >= fixedUpdateTime)
        {
            Manager.FixedUpdate(sf::seconds(fixedUpdateTime));
            fpassedTime -= fixedUpdateTime;
        }

        Manager.Draw();

        std::cout << (int)(1.f / dt.asSeconds())<<'\n';
    }

    return 0;
}