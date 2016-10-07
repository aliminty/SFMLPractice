//
//  Game.h
//  Pang
//
//  Created by Ali Minty on 9/30/16.
//  Copyright © 2016 Ali Minty. All rights reserved.
//

#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


class Game
{
    
public:
    static void Start();
    
private:
    static bool IsExiting();
    static void GameLoop();
    
    enum GameState { Uninitialized, ShowingSplash, Paused,
        ShowingMenu, Playing, Exiting };
    
    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
};
