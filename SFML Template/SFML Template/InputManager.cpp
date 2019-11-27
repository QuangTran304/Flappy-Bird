//
//  InputManager.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-27.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "InputManager.hpp"

namespace QT {
    bool InputManager::isSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window ) {
        if ( sf::Mouse::isButtonPressed( button )) {
            sf::IntRect tempRect( object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height );
            
            if ( tempRect.contains( sf::Mouse::getPosition( window )) ) {
                return true;
            }
        }
        
        return false;
    }
    
    sf::Vector2i InputManager::getMousePosition( sf::RenderWindow& window ) {
        return sf::Mouse::getPosition( window );
    }
}
