//
//  Collision.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-10.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Collision.hpp"

namespace QT {

    Collision::Collision() {
        
    }

    bool Collision::checkSpriteCollision( sf::Sprite sprite1, sf::Sprite sprite2 ) {
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();      // Rectangle around the sprite
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();
        
        if ( rect1.intersects( rect2 )) {
            return true;
        }
        return false;
    }

}
