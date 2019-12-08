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
        
        _birdSprite.setTexture( _data->assets.getTexture( "Bird Frame 1" ));
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
}
