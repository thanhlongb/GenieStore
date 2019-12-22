//
// Created by longb on 12/19/19.
//

#include "Game.h"

Game::Game(string id, string title, string loan_type, int copies, float rental_fee, string rental_status) {
    this->id = id;
    this->title = title;
    this->loan_type = loan_type;
    this->copies = copies;
    this->rental_fee = rental_fee;
    this->rental_status = rental_status;
}

string Game::to_string() {
    return  this->get_id() + "," +
            this->get_title() + "," +
            "Game," +
            this->get_loan_type() + "," +
            this->get_copies() + "," +
            this->get_rental_fee;
}

