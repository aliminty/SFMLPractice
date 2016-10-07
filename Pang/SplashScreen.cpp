//
//  SplashScreen.cpp
//  Pang
//
//  Created by Ali Minty on 9/30/16.
//  Copyright © 2016 Ali Minty. All rights reserved.
//

#include "stdafx.h"
#include "ResourcePath.hpp"
#include "SplashScreen.h"


void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
    sf::Texture texture;
    std::string texturePath = resourcePath();
    texturePath.append("SplashScreen.png");
    if(texture.loadFromFile(texturePath) != true)
    {
        return;
    }
    
    sf::Sprite sprite(texture);
    
    renderWindow.draw(sprite);
    renderWindow.display();
    
    sf::Event event;
    while(true)
    {
        while(renderWindow.pollEvent(event))
        {
            if(event.type == sf::Event::EventType::KeyPressed
               || event.type == sf::Event::EventType::MouseButtonPressed
               || event.type == sf::Event::EventType::Closed )
            {
                return;
            }
        }
    }
}
