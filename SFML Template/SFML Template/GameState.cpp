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
        _data->assets.loadTexture( "Land", LAND_FILEPATH );
        _data->assets.loadTexture( "Bird Frame 1", BIRD_FRAME_1_FILEPATH );
        _data->assets.loadTexture( "Bird Frame 2", BIRD_FRAME_2_FILEPATH );
        _data->assets.loadTexture( "Bird Frame 3", BIRD_FRAME_3_FILEPATH );
        _data->assets.loadTexture( "Bird Frame 4", BIRD_FRAME_4_FILEPATH );
        
        pipe = new Pipe( _data );
        land = new Land( _data );
        bird = new Bird( _data );
        
        _background.setTexture( this->_data->assets.getTexture( "Game Background" ));
    }

    void GameState::handleInput() {
        sf::Event event;
        
        while ( _data->window.pollEvent( event )) {
            if ( sf::Event::Closed == event.type ) {
                _data->window.close();
            }
            
            // If user clicks on the sprite, ... (i.e. The Background - because the background covered the entire screen)
            if ( _data->input.isSpriteClicked( _background, sf::Mouse::Left, _data->window ) ) {
                bird->tap();
            }
        }
    }

    void GameState::update( float dt ) {
        pipe->movePipes( dt );
        land->moveLand( dt );
        
        if ( clock.getElapsedTime().asSeconds()  >  PIPE_SPAWN_FREQUENCY ) {
            pipe->randomisePipeOffset();
            
            pipe->spawnInvisiblePipe();
            pipe->spawnBottomPipe();
            pipe->spawnTopPipe();
            
            clock.restart();
        }
        
        bird->animate( dt );
        bird->update( dt );
    }

    void GameState::draw( float dt ) {
        _data->window.clear();
        _data->window.draw( _background );
        
        pipe->drawPipes();          // Draw pipes after drawing the background
        land->drawLand();
        bird->draw();
        
        _data->window.display();
    }
}
