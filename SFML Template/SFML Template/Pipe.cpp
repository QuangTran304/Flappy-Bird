//
//  Pipe.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "Pipe.hpp"

namespace QT {

    Pipe::Pipe( GameDataRef data ): _data(data) {
        
    }

    void Pipe::drawPipes() {
        for (unsigned short int i = 0; i < pipeSprites.size(); ++i) {
            _data->window.draw( pipeSprites.at(i) );
        }
    }
    
    void Pipe::spawnBottomPipe() {
        sf::Sprite sprite( _data->assets.getTexture( "Pipe Up" ));
        sprite.setPosition( _data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height );
        pipeSprites.push_back( sprite );
    }

    void Pipe::spawnTopPipe() {
        sf::Sprite sprite( _data->assets.getTexture( "Pipe Down" ));
        sprite.setPosition( _data->window.getSize().x, 0 );             // Set y position to 0
        pipeSprites.push_back( sprite );
    }

    void Pipe::spawnInvisiblePipe() {
        sf::Sprite sprite( _data->assets.getTexture( "Pipe Up" ));
        sprite.setPosition( _data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height );
        
        sprite.setColor( sf::Color( 0,0,0,0 ));
        pipeSprites.push_back( sprite );
    }

    void Pipe::movePipes( float dt ) {
        for ( unsigned short int i = 0; i < pipeSprites.size(); ++i) {
            sf::Vector2f position = pipeSprites.at(i).getPosition();
            float movement = PIPE_MOVEMENT_SPEED * dt;
            pipeSprites.at(i).move( -movement, 0 );
        }
    }


}
