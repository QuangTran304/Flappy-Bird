//
//  Game.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-27.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace QT {
    struct GameData {
        StateMachine machine;
        sf::RenderWindow window;            // The window of our game
        AssetManager assets;
        InputManager input;
    };

    using GameDataRef = std::shared_ptr<GameData>;

    class Game {
    public:
        Game( int width, int height, std::string title );
        
    private:
        const float dt = 1.0f / 60.0f;      // Frame rate: 60 times/ sec    (https://en.wikipedia.org/wiki/Frame_rate)
        sf::Clock _clock;                   // Measure the elapsed time. Handle the frame rate.
        GameDataRef _data = std::make_shared<GameData>();
        
        void run();
    };
}


