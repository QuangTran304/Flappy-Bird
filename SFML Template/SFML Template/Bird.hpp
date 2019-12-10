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
#include <vector>

namespace QT {

    class Bird {
    public:
        Bird( GameDataRef data );
        void draw();
        void animate( float dt );
        void update( float dt );
        void tap();
        const sf::Sprite& getSprite() const;
        
    private:
        GameDataRef _data;
        sf::Sprite _birdSprite;         // We're not going to have 4 different sprites. Just need to swap the textures to animate the bird.
        std::vector<sf::Texture> _animationFrames;
        unsigned _animationIterator;    // Current frame that is being displayed
        
        sf::Clock _clock;
        sf::Clock _movementClock;       // To track the movement -> We could reset the time -> allow user to tap multiple times.
    
        int _birdState;                 // Either STILL, FALLING or FLYING
        float _rotation;                // Rotationn angle for the bird sprite
    };
}
