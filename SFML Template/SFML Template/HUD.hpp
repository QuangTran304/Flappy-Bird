//
//  HUD.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-13.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace QT {

    class HUD {
    public:
        HUD( GameDataRef data );
        void draw();
        void updateScore( int score );
        
    private:
        GameDataRef _data;
        sf::Text _scoreText;
    };

}
