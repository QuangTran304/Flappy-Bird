//
//  Pipe.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace QT {

    class Pipe {
    public:
        Pipe( GameDataRef data );
        void DrawPipes();
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprites;
    };

}
