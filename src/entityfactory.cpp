#include "entityfactory.h"

#include <iostream>

EntityFactory::EntityFactory() {
    entityFlyweight = std::make_shared<EntityFlyweight>();
}
EntityFactory::~EntityFactory() {

}
std::unique_ptr<Entity> EntityFactory::createEntity(int entity_type){
    std::unique_ptr<Entity> newEntity = std::make_unique<Entity>(entity_type, entityFlyweight);
    return std::move(newEntity);
}