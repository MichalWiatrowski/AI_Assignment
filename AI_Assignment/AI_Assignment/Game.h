#pragma once
#include "Input.h"
#include "StateMachine.h"
#include "fl/Headers.h"
#include <string>
#include <stdlib.h>
#include <fstream>
class Game {
public:
	//Enums to control the states of the application
	enum AppStates { TestingFuzzy, TestingFSM, ApplicationFuzzyLogic, ApplicationFSM } appState = TestingFuzzy;

	Game(sf::RenderWindow* hwnd);
	~Game();
	void handleInput(Input* input, float deltaTime);
	void testing(fl::Engine* engine, float deltaTime);
	void application(fl::Engine* engine, float deltaTime);
	void render();

private:
	sf::RenderWindow* window;
	float update(fl::Engine* engine, float deltaTime, float vel, float dis);
	void beginDraw();
	void endDraw();

	void updateUI(float deltaTime);

	//background, car and race line sprites and textures
	sf::RectangleShape raceLineObject;
	sf::Texture raceLineTexture;

	sf::RectangleShape backgroundObject;
	sf::Texture backgroundTexture;

	sf::RectangleShape carCubeObject;
	sf::Texture carCubeTexture;

	//Texts and font for calculations and indicator texts
	sf::Font font;

	sf::Text modeText;
	sf::Text velocityText;
	sf::Text distanceText;
	sf::Text outputText;

	sf::Text goingLeftText;
	sf::Text goingStraightText;
	sf::Text goingRightText;

	//Variables holding velocities and distance for application mode
	float raceLineVelocity;
	float velocity;
	float distance;

	float calculatedOutput;
	float output;

	float marginalDistance = 0.0001;
	//Variables holding velocities and distance for testing mode
	float testVelocity;
	float testDistance;
	std::string ifTesting = ""; //used to check if the user wants to keep testing

	//variable to store the output for fuzzy logic
	fl::OutputVariable* outputVariable;

	//Pointer to FSM class
	StateMachine* carControlState;
};