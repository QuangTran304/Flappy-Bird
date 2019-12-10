//
//  Land.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-07.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace QT {
    class Land {
    public:
        Land ( GameDataRef data );
        void moveLand( float dt );
        void drawLand();
        const std::vector<sf::Sprite>& getSprites() const;
        
    private:
        GameDataRef _data;
        
        // We need multiple "land objects" in order to make the land "move" during the game.
        std::vector<sf::Sprite> _landSprites;
    };
}
