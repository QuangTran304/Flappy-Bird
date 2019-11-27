//
//  State.h
//  SFML Template
//
//  Created by Quang Tran on 2019-11-25.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once

namespace QT {
    class State {
    public:
        virtual void init() = 0;
        virtual void handleInput() = 0;
        virtual void update( float dt ) = 0;
        virtual void draw( float dt ) = 0;
        
        virtual void pause() { }
        virtual void resume() { }
    };
}
