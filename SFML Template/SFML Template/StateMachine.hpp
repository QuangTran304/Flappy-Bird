//
//  StateMachine.hpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-25.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#pragma once
#include <memory>
#include <stack>
#include "State.hpp"

namespace QT {
    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
    public:
        StateMachine() { }
        ~StateMachine() { }
        void addState(StateRef newState, bool isReplacing = true);
        void removeState();
        
        void processStateChanges();
        StateRef& getActiveState();
        
    private:
        std::stack<StateRef> _states;
        StateRef _newState;
        
        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}

