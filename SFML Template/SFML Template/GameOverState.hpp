//
//  GameOverState.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace QT {
    class GameOverState: public State {
    public:
        GameOverState( GameDataRef data, int score );
        
        void init();
        void handleInput();
        void update( float dt );
        void draw( float dt );
        
    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;
        
        sf::Text _scoreText;
        sf::Text _highScoreText;
        int _score;
        int _highScore;
        
    };
}

