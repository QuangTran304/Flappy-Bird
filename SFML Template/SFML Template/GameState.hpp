//
//  GameState.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"


namespace QT {
    class GameState: public State {
    public:
        GameState( GameDataRef data );
        
        void init();
        void handleInput();
        void update( float dt );
        void draw( float dt );
        
    private:
        GameDataRef _data;
        sf::Sprite _background;
        
        Pipe* pipe;
        Land* land;
        Bird* bird;
        Collision collision;    // Not a pointer because we don't need to re-construct it afterwards.
        Flash* flash;
        HUD* hud;
        
        sf::Clock clock;
        int _gameState;
        int _score;             // Keep track of the user scores
    };
}

