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
        
    };
}

