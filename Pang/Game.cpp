//
//  Game.cpp
//  Pang
//
//  Created by Ali Minty on 9/30/16.
//  Copyright © 2016 Ali Minty. All rights reserved.
//

#include "stdafx.h"
#include "Game.h"

void Game::Start(void)
{
    if(_gameState != Uninitialized)
        return;
    
    _mainWindow.create(sf::VideoMode(1024,768,32),"Pang!");
    _gameState = Game::Playing;
    
    while(!IsExiting())
    {
        GameLoop();
    }
    
    _mainWindow.close();
}

bool Game::IsExiting()
{
    if(_gameState == Game::Exiting)
        return true;
    else
        return false;
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent))
    {
        
        switch(_gameState)
        {
            case Game::Playing:
            {
                _mainWindow.clear(sf::Color(10,100,200));
                _mainWindow.display();
                
                if(currentEvent.type == sf::Event::Closed)
                {
                    _gameState = Game::Exiting;
                }
                break;
            }
            default:
                break;
        }
    }
}


Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
