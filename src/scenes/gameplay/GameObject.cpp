#include "GameObject.h"

SP::Scene::Gameplay::GameObject::GameObject(int renderDepth) : renderDepth(renderDepth) {

}

void SP::Scene::Gameplay::GameObject::SetPosition(sf::Vector2f pos) {
    this->position = pos;
}

sf::Vector2f SP::Scene::Gameplay::GameObject::GetPosition() {
    return this->position;
}

int SP::Scene::Gameplay::GameObject::GetRenderDepth() const {
    return this->renderDepth;
}

void SP::Scene::Gameplay::GameObject::Update(float deltaUTime) {

}

void SP::Scene::Gameplay::GameObject::Render(sf::RenderWindow &window, float deltaRTime) {

}
