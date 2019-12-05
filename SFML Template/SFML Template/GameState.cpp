//
//  GameState.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>

namespace QT {
    GameState::GameState( GameDataRef data): _data(data) {
        
    }

    /*
        Loading the texture using AssetManager
    */
    void GameState::init() {
        std::cout << "Init() Game State" << std::endl;
        
        _data->assets.loadTexture( "Game Background", GAME_BACKGROUND_FILEPATH );
        _data->assets.loadTexture( "Pipe Up", PIPE_UP_FILEPATH );
        _data->assets.loadTexture( "Pipe Down", PIPE_DOWN_FILEPATH );
        
        pipe = new Pipe( _data );
        
        _background.setTexture( this->_data->assets.getTexture( "Game Background" ));
    }

    void GameState::handleInput() {
        sf::Event event;
        
        while ( _data->window.pollEvent( event )) {
            if ( sf::Event::Closed == event.type ) {
                _data->window.close();
            }
            
            // If user clicks on the sprite, ...
            if ( _data->input.isSpriteClicked( _background, sf::Mouse::Left, _data->window ) ) {
                // Do something
            }
        }
    }

    void GameState::update( float dt ) {
        pipe->movePipes( dt );
        
        if ( clock.getElapsedTime().asSeconds()  >  PIPE_SPAWN_FREQUENCY ) {
            pipe->spawnInvisiblePipe();
            pipe->spawnBottomPipe();
            pipe->spawnTopPipe();
            
            clock.restart();
        }
    }

    void GameState::draw( float dt ) {
        _data->window.clear();
        _data->window.draw( _background );
        pipe->drawPipes();          // Draw pipes after drawing the background
        _data->window.display();
    }
}
