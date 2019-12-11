//
//  Collision.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-10.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

namespace QT {

    class Collision {
    public:
        Collision();
        bool checkSpriteCollision( sf::Sprite sprite1, sf::Sprite sprite2 );
        bool checkSpriteCollision( sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2 );
    };

}
