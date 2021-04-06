#include "IGameObject.h"

SP::Scene::Gameplay::IGameObject::IGameObject(int renderDepth) : renderDepth(renderDepth) {

}

void SP::Scene::Gameplay::IGameObject::SetPosition(sf::Vector2f pos) {
    this->position = pos;
}

sf::Vector2f SP::Scene::Gameplay::IGameObject::GetPosition() {
    return this->position;
}

int SP::Scene::Gameplay::IGameObject::GetRenderDepth() const {
    return this->renderDepth;
}

void SP::Scene::Gameplay::IGameObject::Update(float deltaUTime) {

}

void SP::Scene::Gameplay::IGameObject::Render(float deltaRTime, sf::Transform viewTransform) {

}
