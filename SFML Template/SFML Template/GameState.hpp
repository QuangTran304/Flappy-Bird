//
//  GameState.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"
#include <SFML/Audio.hpp>
#include <memory>

namespace QT {
    class GameState: public State {
    public:
        GameState( GameDataRef data );
        
        void init();
        void handleInput();
        void update( float dt );
        void draw( float dt );
        
    private:
        GameDataRef _data;
        sf::Sprite _background;
        
        std::unique_ptr<Pipe> pipe;
        std::unique_ptr<Land> land;
        std::unique_ptr<Bird> bird;
        Collision collision;    // Not a pointer because we don't need to re-construct it afterwards.
        std::unique_ptr<Flash> flash;
        std::unique_ptr<HUD> hud;
        
        sf::Clock clock;
        int _gameState;
        int _score;             // Keep track of the user scores
        
        sf::SoundBuffer _hitSoundBuffer;
        sf::SoundBuffer _wingSoundBuffer;
        sf::SoundBuffer _pointSoundBuffer;
        
        sf::Sound _hitSound;
        sf::Sound _wingSound;
        sf::Sound _pointSound;
    };
}

