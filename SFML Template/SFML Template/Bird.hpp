//
//  Bird.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-07.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace QT {

    class Bird {
    public:
        Bird( GameDataRef data );
        void draw();
        
    private:
        GameDataRef _data;
        sf::Sprite _birdSprite;
    };
}
