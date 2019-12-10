//
//  Bird.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-07.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Bird.hpp"

namespace QT {
    Bird::Bird( GameDataRef data ) : _data(data) {
        _animationIterator = 0;
        
        _animationFrames.push_back( _data->assets.getTexture( "Bird Frame 1" ));
        _animationFrames.push_back( _data->assets.getTexture( "Bird Frame 2" ));
        _animationFrames.push_back( _data->assets.getTexture( "Bird Frame 3" ));
        _animationFrames.push_back( _data->assets.getTexture( "Bird Frame 4" ));
        
        _birdSprite.setTexture( _animationFrames.at( _animationIterator ));
        
        // Set the bird's x-position at 25% of the screen to the left, y-position at 50% of the screen.
        // " - (_birdSprite.getGlobalBounds().width / 2)" because the origins of the bird sprite is on the left of the graphic. We want to align to the center of the sprite.
        _birdSprite.setPosition( (_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2)  ,  (_data->window.getSize().x / 2) - (_birdSprite.getGlobalBounds().width / 2 ));
        
        _birdState = BIRD_STATE_STILL;
        
        // Get the origin at the center of the bird sprite -> so that we could rotate the bird
        sf::Vector2f birdOrigin = sf::Vector2f( _birdSprite.getGlobalBounds().width / 2  , _birdSprite.getGlobalBounds().height / 2  );
        _birdSprite.setOrigin( birdOrigin );
        
        _rotation = 0;      // Init the rotation angle to 0
    }

    void Bird::draw() {
        _data->window.draw( _birdSprite );
    }


    void Bird::animate( float dt ) {
        // Animate/ change frame every 0.1 second: duration 0.4s / 4 frames
        if ( _clock.getElapsedTime().asSeconds()  >  BIRD_ANIMATION_DURATION / _animationFrames.size()) {       // Better to use _animationFrames.size() if we change the frames later
            
            if ( _animationIterator  <  _animationFrames.size() - 1 ) {     // If not the last animation frame
                ++_animationIterator;                                        // keep moving to the next frame
            } else {
                _animationIterator = 0;                                      // If reach the last frame, come back to the begining.
            }
            
            _birdSprite.setTexture( _animationFrames.at( _animationIterator ));
            _clock.restart();
        }
    }


    void Bird::update( float dt ) {
        if ( _birdState  ==  BIRD_STATE_FALLING ) {
            // We don't need to move the bird on the x-axis because everything else is still moving.
            // We need to " * dt" to make it frame-rate independent.
            _birdSprite.move( 0, GRAVITY * dt );
            
            // Rotate the bird
            _rotation += ROTATION_SPEED * dt;
            if ( _rotation  >  25.0f ) {    // If the rotation angle is > than 25 deg.
                _rotation = 25.0f;
            }
            _birdSprite.setRotation( _rotation );
            
        } else if ( _birdState  ==  BIRD_STATE_FLYING ) {
            // "-FLYING_SPEED" because positive value move the bird down
            _birdSprite.move( 0, -FLYING_SPEED * dt );
        
            // Rotate the bird
            _rotation -= ROTATION_SPEED * dt;
            if ( _rotation  <  -25.0f ) {
                _rotation = -25.0f;
            }
            _birdSprite.setRotation( _rotation );
        }
        
        
        if ( _movementClock.getElapsedTime().asSeconds()  >  FLYING_DURATION ) {
            // If the current flying time of the bird (_movementClock) > than the flying duration...
            _movementClock.restart();
            _birdState = BIRD_STATE_FALLING;
        }
    }

    void Bird::tap() {
        _movementClock.restart();   // Need to restart the clock to 0 because we don't know how long the user wait to press on the screen.
        _birdState = BIRD_STATE_FLYING;
    }

    const sf::Sprite& Bird::getSprite() const {
        return _birdSprite;
    }
}
