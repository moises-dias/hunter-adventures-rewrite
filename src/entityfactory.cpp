#include "entityfactory.h"

#include <iostream>

EntityFactory::EntityFactory() {
    entityFlyweight = std::make_shared<EntityFlyweight>();
}
EntityFactory::~EntityFactory() {

}
std::unique_ptr<Entity> EntityFactory::createEntity(int entity_type){
    std::cout << "created a entity of type " << entity_type << "\n";
    std::unique_ptr<Entity> newEntity = std::make_unique<Entity>(entity_type, entityFlyweight);
    return std::move(newEntity);
}