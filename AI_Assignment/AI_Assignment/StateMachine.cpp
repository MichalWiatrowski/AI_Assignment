#include "StateMachine.h"


//Init the pointers to the indicators texts
StateMachine::StateMachine(sf::Text* left, sf::Text* straight, sf::Text* right)
{
	driveLeft = left;
	driveStraight = straight;
	driveRight = right;
}


StateMachine::~StateMachine()
{
}

//When the states are being switched, do something with the new state
void StateMachine::onEnter(FSM state)
{
	//sets text to green if driving left, right of straight
	if (state == DrivingLeft)
		driveLeft->setFillColor(sf::Color::Green);
	else if (state == DrivingStraight)
		driveStraight->setFillColor(sf::Color::Green);
	else if (state == DrivingRight)
		driveRight->setFillColor(sf::Color::Green);
}

float StateMachine::update(float carPosition, float raceLinePosition, float deltaTime)
{
	//reset values and calculate distance
	velocity = 0.0f;
	distance = raceLinePosition - carPosition;
	
	//Switch statement to cycle through state
	switch (States)
	{	
		//if going straight
		case FSM::DrivingStraight:
		{
			//if car is right and race line is left, change the switch to driving left
			//if the car is left and race line is right, change the switch to driving right
			//if non, break and use the return outside the case statement
			if (carPosition > raceLinePosition && distance <= -marginalDistance)
			{
				stateChange(FSM::DrivingLeft);
			}
			else if (carPosition < raceLinePosition && distance >= marginalDistance)
			{
				stateChange(FSM::DrivingRight);
			}
			break;
		}
		//if driving left
		case FSM::DrivingLeft:
		{
			//if the car is still left, return new velocity
			if (carPosition > raceLinePosition && distance <= -marginalDistance)
			{
				velocity = distance * deltaTime;
				return velocity;
			}
			//otherwise switch states
			else if (carPosition < raceLinePosition)
			{
				stateChange(FSM::DrivingRight);
			}
			else if ((raceLinePosition - carPosition) >= -marginalDistance)
			{
				stateChange(FSM::DrivingStraight);
			}
			break;
		}
		//if driving right
		case FSM::DrivingRight:
		{
			//if the car is still right, return new velocity
			if (carPosition < raceLinePosition && distance >= marginalDistance)
			{
				velocity = distance * deltaTime;
				return velocity;
			}
			//otherwise switch states
			else if (carPosition > raceLinePosition)
			{
				stateChange(FSM::DrivingLeft);
			}
			else if ((raceLinePosition - carPosition) <= marginalDistance)
			{
				stateChange(FSM::DrivingStraight);
			}
			break;
		}
	}
	//if going straight return velocity of 0
	return velocity;
}
//When the states are being switched, do something with the old state
void StateMachine::onExit(FSM state)
{
	//sets text to red if driving left, right of straight
	if (state == DrivingLeft)
		driveLeft->setFillColor(sf::Color::Red);
	else if (state == DrivingStraight)
		driveStraight->setFillColor(sf::Color::Red);
	else if (state == DrivingRight)
		driveRight->setFillColor(sf::Color::Red);
}

//Main function for switching states
void StateMachine::stateChange(FSM state)
{
	onExit(States);
	States = state;
	onEnter(state);
}
