#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
    //ctor
}

GameObjectManager::~GameObjectManager()
{
    for(auto &it : _gameObjects)
    {
        delete it.second;
    }
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
    _gameObjects.insert(std::make_pair(name,gameObject));
}
void GameObjectManager::Remove(std::string name)
{
    auto searchResult = _gameObjects.find(name);
    if (searchResult!=_gameObjects.end()) {
        delete  searchResult->second;
        _gameObjects.erase(searchResult);
    }
}

VisibleGameObject* GameObjectManager::Get(std::string name)
{
    auto searchResult = _gameObjects.find(name);
    if (searchResult!=_gameObjects.end()) {
        return searchResult->second;
    }
    return NULL;
}

int GameObjectManager::GetObjectCount() {
        return _gameObjects.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& window)
{
    for (auto& obj : _gameObjects)
    {
        obj.second->Draw(window);
    }
}
void GameObjectManager::UpdateAll() {
    float elapsedTime = clock.restart().asSeconds();
    for (auto& pairDenObj : _gameObjects)
    {
        pairDenObj.second->Update(elapsedTime,this);
    }
}

