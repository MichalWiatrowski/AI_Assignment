#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class StateMachine
{
public:
	StateMachine(sf::Text* left, sf::Text* straight, sf::Text* right);
	~StateMachine();

	//Enum to indicate states
	enum FSM {DrivingStraight, DrivingLeft, DrivingRight} States = DrivingStraight;

	//main uodate function
	float update(float carPosition, float raceLinePosition, float deltaTime);

	//pointers for indicator texts
	sf::Text* driveLeft;
	sf::Text* driveStraight;
	sf::Text* driveRight;

private:
	void onEnter(FSM state);
	void onExit(FSM state);
	void stateChange(FSM state);

	//values for calculations 
	float velocity = 0.0f;
	float distance = 0.0f;
	//marginal distance value to enhance state switching
	float marginalDistance = 0.015;
};

