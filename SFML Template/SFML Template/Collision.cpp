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


    // The two "scale" variables are used to scale up/down the rectangle around the sprite we want to use
    // for the 'perfect' collision detection (that looks real)
    bool Collision::checkSpriteCollision( sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2 ) {
        sprite1.setScale( scale1, scale1 );                     // The sprites are scaled in both directions
        sprite2.setScale( scale2, scale2 );
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();      // Find the rectangle bound around the sprite after scaling.
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();
       
        if ( rect1.intersects( rect2 )) {
            return true;
        }
        return false;
   }

}
