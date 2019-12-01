/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** ShooterSystem
*/

#include "ShooterSystem.hpp"

ShooterSystem::ShooterSystem() : ASystem(), _clock(), _objet(std::make_unique<Shooter>()), _size(1), _counter(0), _spawn(0), _y(0)
{
}

ShooterSystem::~ShooterSystem()
{
}


void ShooterSystem::init()
{
    Signature sign;
    sign.set(gameEngine->getComponentID<shooterComponent>());
    setSignature(sign);
    _objet->setGameEngine(gameEngine);
    _activate = false;
}

void ShooterSystem::activate(bool isActivated)
{
    if (isActivated) {
        _clock = std::chrono::system_clock::now();
        _size = 1;
        _activate = true;
    } else
        _activate = false;
}

void ShooterSystem::shoot(std::pair<int,int> pos, std::pair<int,int> cible)
{
    Entity missile = gameEngine->createEntity();
    Signature signmis;
    signmis.set(gameEngine->getComponentID<rendering>());
    signmis.set(gameEngine->getComponentID<destroyable>());
    signmis.set(gameEngine->getComponentID<boundingBox>());
    signmis.set(gameEngine->getComponentID<speed>());
    signmis.set(gameEngine->getComponentID<Effect>());
    gameEngine->addComponent(missile,rendering {
        Asset::ENNEMYSHOOT0,
        std::to_string(missile),
        {pos.first + 4, pos.second - 3},
        {2, 1}
    });
    gameEngine->addComponent(missile, boundingBox {
        CIRCLE,
        {{pos.first + 4, pos.second - 3},
        {2, 0}},
        collisionType::COLLIDE_ENEMY
    });
    gameEngine->addComponent(missile, speed {
        -2,
        [pos, cible] (int x) {
            return 0;
            // return (cible.second - pos.second) / (cible.first - pos.first) * x;
            }
    });
    gameEngine->addComponent(missile, destroyable {
        true, false
    });
    gameEngine->addComponent(missile, Effect {
        Type::DAMMAGE,
        20
    });
    gameEngine->setEntitySystem(missile, signmis);
}

void ShooterSystem::update(const std::chrono::time_point<std::chrono::system_clock>& now)
{
    if (!_activate)
        return;
    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-_clock).count();
    if (elapsed > (1000 / 60)) {
        _clock = now;
        _counter++;
        if (_counter % 100 == 0) {
            _y = rand() % 100 + 75;
            _spawn++;
            _objet->createObjet({_y, MAX_WINDOW});
            _counter = 0;
        }
        if (_spawn && _counter % (_objet->getSize().first * 2 + 3) == 0) {
            _counter = 0;
            _objet->createObjet({_y, MAX_WINDOW});
            _spawn++;
        }
        if (_spawn > 3)
            _spawn = 0;

        for (auto&x : _entities) {
            auto& cible = gameEngine->getComponent<shooterComponent>(x);
            auto& pos = gameEngine->getComponent<boundingBox>(x);
            auto& speedy = gameEngine->getComponent<speed>(x);
            if (!gameEngine->isEntityHave<boundingBox>(cible.cible))
                cible.cible = gameEngine->getRandomComponent<playerComponent>();
            else {
                auto& posCible = gameEngine->getComponent<boundingBox>(cible.cible).pos[LOWERRIGHT];
                if (rand() % 200 == 0)
                    shoot(pos.pos[UPPERLEFT], posCible);
            }
            if (pos.pos[UPPERLEFT].first < 70) {
                speedy.calc = [] (int) {return 1;};
            }
            if (pos.pos[UPPERLEFT].first > 180) {
                speedy.calc = [] (int) {return -1;};
            }
        }
    }
}