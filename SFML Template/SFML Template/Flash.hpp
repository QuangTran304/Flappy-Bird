//
//  Flash.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-12.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace QT {

    class Flash {
    public:
        Flash( GameDataRef data );
        void show( float dt );
        void draw();
        
    private:
        GameDataRef _data;
        sf::RectangleShape _shape;      // Used to set the FILL color later.
        bool _flashOn;                  // Check if the white screen is flashed
    };

}
