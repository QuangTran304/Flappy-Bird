//
//  GameOverState.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "GameOverState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>

namespace QT {
    GameOverState::GameOverState( GameDataRef data): _data(data) {
        
    }

    /*
        Loading the texture using AssetManager
    */
    void GameOverState::init() {
        std::cout << "Game-over State" << std::endl;
        
        _data->assets.loadTexture( "Game Over Background", GAME_OVER_BACKGROUND_FILEPATH );
        
        _background.setTexture( this->_data->assets.getTexture( "Game Over Background" ));
    }

    void GameOverState::handleInput() {
        sf::Event event;
        
        while ( _data->window.pollEvent( event )) {
            if ( sf::Event::Closed == event.type ) {
                _data->window.close();
            }
        }
    }

    void GameOverState::update( float dt ) {

    }

    void GameOverState::draw( float dt ) {
        _data->window.clear();
        _data->window.draw( _background );
        _data->window.display();
    }
}
