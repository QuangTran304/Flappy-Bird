//
//  Pipe.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-12-02.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <vector>

namespace QT {

    class Pipe {
    public:
        Pipe( GameDataRef data );
        void drawPipes();
        void spawnBottomPipe();
        void spawnTopPipe();
        void spawnInvisiblePipe();
        void spawnScoringPipe();       // Used to detect if the bird has gone between 2 pipes (earn scores)
        void movePipes( float dt );
        void randomisePipeOffset();
        
        const std::vector<sf::Sprite>& getSprites() const;
        std::vector<sf::Sprite>& getScoringSprites();
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprites;
        std::vector<sf::Sprite> scoringPipes;
        
        int _landHeight;            // Height of the land sprite
        int _pipeSpawnY_offSet;     // How much the next set of pipes will move (up/down)
    };

}
