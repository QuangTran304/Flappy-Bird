//
//  StateMachine.cpp
//  SFML Template
//
//  Created by Quang Tran on 2019-11-25.
//  Copyright © 2019 Quang Tran. All rights reserved.
//

#include "StateMachine.hpp"

namespace QT {

    void StateMachine::addState( StateRef newState, bool isReplacing ) {
        _isAdding = true;
        _isReplacing = isReplacing;
        
        _newState = std::move( newState );
    }


    void StateMachine::removeState() {
        _isRemoving = true;
    }


    void StateMachine::processStateChanges() {
        if ( _isRemoving  &&  !_states.empty() ) {
            _states.pop();
            _isRemoving = false;
        }
        
        if ( _isAdding ) {
            if ( !_states.empty()  &&  _isReplacing ) {
                _states.pop();
            }
            
            _states.push( std::move( _newState ) );
            _states.top()->init();
            _isAdding = false;
        }
    }


    StateRef& StateMachine::getActiveState() {
        return _states.top();
    }
}
