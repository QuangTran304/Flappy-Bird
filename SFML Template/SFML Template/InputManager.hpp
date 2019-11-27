//
//  InputManager.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-27.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>

namespace QT {
    class InputManager {
    public:
        InputManager() { }
        ~InputManager() { }
        
        bool isSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window );
        sf::Vector2i getMousePosition( sf::RenderWindow& window );
        
    };

}
