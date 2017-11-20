#include <iostream>
#include "Game.h"

using namespace Gradius;

const int Game::SCREEN_W = 1280;
const int Game::SCREEN_H = 720;

Game::Game(): window {sf::VideoMode(this->SCREEN_W, this->SCREEN_H), "GRADIUS"}
{
    srand(time(nullptr));
    this->bg = new BackGround(&this->window, this->SCREEN_W);
    this->input = new Input(&this->window);
    this->state = Gamestate::RUNNING;
    this->player = new Player(&this->window, this->SCREEN_H, this->SCREEN_W);
    this->enemyManager= new EnemyManager(&this->window);
    //this->enemy = new Enemy(&this->window, this->SCREEN_H, this->SCREEN_W, 100, 5.0f, 0.5f);
    this->window.setFramerateLimit(60);
}

void Game::Draw()
{
    this->window.clear();
    this->bg->Draw();
    this->player->Draw();
    this->enemyManager->Draw();
    this->window.display();
}

void Game::Update(float deltaTime)
{
    this->bg->Update(deltaTime);
    this->player->Update(deltaTime, this->input->getdir());
    this->enemyManager->Update(deltaTime);
}

void Game::Run()
{
    float deltaTime = 0;
    while(this->state != Gamestate::EXIT && this->input->getInputState() != Inputs::ESCAPE)
    {
        this->InputListen();
        this->Update(deltaTime);
        this->Draw();
        this->input->Reset();
        deltaTime = this->clock.getElapsedTime().asSeconds();
        this->clock.restart();
    }
}

void Game::InputListen()
{
    this->input->EventListener();

    if(this->input->getInputState() == Inputs::ESCAPE)
    {
        this->window.close();
    }
    if(this->input->getInputState() == Inputs::FIRE)
    {
        this->player->Fire();
    }
}

Game::~Game()
{
    if(this->bg != nullptr)
        delete this->bg;

    if(this->input != nullptr)
        delete this->input;

    if(this->player != nullptr)
        delete this->player;

}
