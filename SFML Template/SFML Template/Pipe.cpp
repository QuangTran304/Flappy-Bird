//
//  Pipe.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Pipe.hpp"
#include <iostream>

namespace QT {

    Pipe::Pipe( GameDataRef data ): _data(data) {
        
    }

    void Pipe::drawPipes() {
        for (unsigned short int i = 0; i < pipeSprites.size(); ++i) {
            _data->window.draw( pipeSprites.at(i) );
        }
    }
    
    void Pipe::spawnBottomPipe() {
        // Create a sprite called "Pipe Up" (get it from the textures inside "assets" i.e. map<string, texture>)
        sf::Sprite sprite( _data->assets.getTexture( "Pipe Up" ));
        
        // On the X-axis, set the pipe outside of the window, then spawn it into the game screen.
        // On the Y-axis, "_data->window.getSize().y" put the Pipe all the way down, so we need the formula.
        // Imagine the x-y axis is located at the upper-left corner.
        sprite.setPosition( _data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height );
        
        pipeSprites.push_back( sprite );
    }

    void Pipe::spawnTopPipe() {
        sf::Sprite sprite( _data->assets.getTexture( "Pipe Down" ));
        sprite.setPosition( _data->window.getSize().x, 0 );             // Set y position to 0
        pipeSprites.push_back( sprite );
    }

    void Pipe::spawnInvisiblePipe() {
        // These invisible pipes are used to fix a screen problem: lag issue or movement issue
        sf::Sprite sprite( _data->assets.getTexture( "Pipe Up" ));      // Doesn't matter which pipe
        sprite.setPosition( _data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height );
        
        sprite.setColor( sf::Color( 0,0,0,0 ));
        pipeSprites.push_back( sprite );
    }

    void Pipe::movePipes( float dt ) {
        for ( unsigned short int i = 0; i < pipeSprites.size(); ++i) {
            
            // Delete the pipes when they go off the screen. If we only keep the condition as "... < 0", the pipes will be deleted right before the edge of the screen.
            if ( pipeSprites.at(i).getPosition().x  <  0 - pipeSprites.at(i).getGlobalBounds().width ) {
                
                pipeSprites.erase( pipeSprites.begin() + i );
                
            } else {    // If that's not the case, move the pipes as normal
                
                float movement = PIPE_MOVEMENT_SPEED * dt;
                pipeSprites.at(i).move( -movement, 0 );         // -movement because we're gonna move pipe to the left of the x-axis
            }
        }
    }


}
