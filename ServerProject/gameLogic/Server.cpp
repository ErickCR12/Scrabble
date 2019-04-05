//
// Created by Erick Barrantes y Esteban Alvarado on 25/03/19.
//

#include "Server.hpp"

// Constructor default
Server::Server() {}

// Crea una nueva instancia del juego
void Server::new_game() {
    Game* gm = new Game();
    matches.push_back(gm);
}

// Se encarga de añadir los jugadores y comenzar el juego
void Server::launch_game() {
    for(int i= 0; i < matches.size();i++)
        matches[i]->add_players();
}