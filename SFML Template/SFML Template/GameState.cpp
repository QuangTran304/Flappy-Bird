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
        flash = new Flash( _data );
        
        _background.setTexture( this->_data->assets.getTexture( "Game Background" ));
        
        _gameState = GameStates::eREADY;
    }

    void GameState::handleInput() {
        sf::Event event;
        
        while ( _data->window.pollEvent( event )) {
            if ( sf::Event::Closed == event.type ) {
                _data->window.close();
            }
            
            // If user clicks on the sprite, ... (i.e. The Background - because the background covered the entire screen)
            if ( _data->input.isSpriteClicked( _background, sf::Mouse::Left, _data->window ) ) {
                if ( _gameState  !=  GameStates::eGAMEOVER ) {
                    _gameState = GameStates::ePLAYING;
                    bird->tap();
                }
            }
        }
    }

    void GameState::update( float dt ) {
        if ( _gameState  !=  GameStates::eGAMEOVER ) {
            bird->animate( dt );
            land->moveLand( dt );
        }
        
        if ( _gameState  ==  GameStates::ePLAYING ) {
            pipe->movePipes( dt );
            
            if ( clock.getElapsedTime().asSeconds()  >  PIPE_SPAWN_FREQUENCY ) {
                pipe->randomisePipeOffset();
                
                pipe->spawnInvisiblePipe();
                pipe->spawnBottomPipe();
                pipe->spawnTopPipe();
                
                clock.restart();
            }
            
            bird->update( dt );
            
//            // Land collision detection
//            std::vector<sf::Sprite> landSprites = land->getSprites();
//            for ( int i = 0; i < landSprites.size(); ++i ) {
//                if ( collision.checkSpriteCollision( bird->getSprite(), landSprites.at(i) )) {
//                    _gameState = GameStates::eGAMEOVER;
//                }
//            }
            
            // Land collision detection
            std::vector<sf::Sprite> landSprites = land->getSprites();
            for ( int i = 0; i < landSprites.size(); ++i ) {
                if ( collision.checkSpriteCollision( bird->getSprite(), 0.7f, landSprites.at(i), 1.0f )) {
                    _gameState = GameStates::eGAMEOVER;
                }
            }
            
            
//            // Pipe collision detection
//            std::vector<sf::Sprite> pipeSprites = pipe->getSprites();
//            for ( int i = 0; i < pipeSprites.size(); ++i ) {
//                if ( collision.checkSpriteCollision( bird->getSprite(), pipeSprites.at(i) )) {
//                    _gameState = GameStates::eGAMEOVER;
//                }
//            }
            
            // Pipe collision detection
            std::vector<sf::Sprite> pipeSprites = pipe->getSprites();
            for ( int i = 0; i < pipeSprites.size(); ++i ) {
                if ( collision.checkSpriteCollision( bird->getSprite(), 0.625f, pipeSprites.at(i), 1.0f )) {
                    _gameState = GameStates::eGAMEOVER;
                }
            }
        }
        
        
        // Show the white flash if GAME OVER
        if ( _gameState  ==  GameStates::eGAMEOVER ) {
            flash->show( dt );
        }
    }


    void GameState::draw( float dt ) {
        _data->window.clear();
        _data->window.draw( _background );
        
        pipe->drawPipes();          // Draw pipes after drawing the background
        land->drawLand();
        bird->draw();
        flash->draw();              // By default, there will be a clear flash drawing constantly (alpha/opacity = 0).
        
        _data->window.display();
    }
}
