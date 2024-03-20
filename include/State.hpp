#pragma once

#include <SFML/System/Time.hpp>

namespace Engine {

    class State {
    public:
        State(){};
        virtual ~State(){};

        virtual void Init() = 0;
        virtual void ProccessInput() = 0;
        virtual void Update(sf::Time deltaTime) = 0;
    };

}  // namespace Engine