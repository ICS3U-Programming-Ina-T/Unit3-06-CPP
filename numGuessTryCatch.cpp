// Copyright (c) 2021 Ina Tolo All rights reserved.
//
// Created by: Ina Tolo
// Created on: Dec. 14, 2021
// This program generates a random
// number and uses a try catch statement
// to determine if a user has
// guessed correctly.


#include <iostream>
#include <random>
#include <string>

int main() {
    // declares variables
    std::string userNumberString;
    int userNumberInt;
    int randomNumber;

    std::random_device rseed;

    // mersenne_twister
    std::mt19937 rgen(rseed());

    // [0, 9]
    std::uniform_int_distribution<int> idist(0, 9);

    randomNumber = idist(rgen);

    // displays opening message
    std::cout << "Today you will try to guess the random number!";
    std::cout << std::endl;
    std::cout << std::endl;

    // collects input from user
    std::cout << "Enter an integer number: ";
    std::cin >> userNumberString;

    // checks if the user has entered the correct number
    try {
        // convert the user's guess to an int
        userNumberInt = std::stoi(userNumberString);

        if (userNumberInt == randomNumber) {
            // output
            std::cout << "You are correct!";
            std::cout << std::endl;
            std::cout << "Thank you for playing!";
        } else if (userNumberInt > 9) {
            std::cout << "Please enter a valid number.";
        } else if (userNumberInt < 0) {
            std::cout << "Please enter a valid number.";
        } else {
            std::cout << "Sorry, you are incorrect. The correct answer is ";
            std::cout << randomNumber;
        }
    // determines if the the answer is a number
    } catch (std::invalid_argument) {
    // The user did not enter a number.
    std::cout << userNumberString << " is not a number.\n";
    }
}
