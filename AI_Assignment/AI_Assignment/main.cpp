#include "Game.h"

int main()
{
	//Init the fuzzy lite engine
	fl::Engine* engine = fl::FisImporter().fromFile("final.fis");

	//declare string used for user input
	std::string userInput = "";

	//declare the sfml window
	sf::RenderWindow window(sf::VideoMode(800, 600), "AI Fuzzy Logic");
	//Create the game class and pass the window refernce
	Game game(&window);
	//Create the input class
	Input input;

	//Clock and float for calculating delta time
	sf::Clock clock;
	float deltaTime;

	//Ask the user if they would want to start the app in test mode or not
	std::cout << "Would you like to launch the application in test mode (y/n)" << std::endl;

	std::cin >> userInput;

	//if not testing, run the app in fuzzy logic
	if (userInput == "N" || userInput == "n")
	{
		userInput.clear(); // clear the string
		game.appState = game.ApplicationFuzzyLogic; //set the appstate to fuzzy logic
		system("CLS"); //clears the console
		std::cout << "////////// Running in application mode! //////////" << std::endl;
		std::cout << "Please switch over to the other window (do not close this one!)" << std::endl;
		std::cout << "To return to testing, press T/t while having the sfml window selected" << std::endl;
	}


	//main game loop; while the sfml window is open
	while (window.isOpen())
	{
		//handle basic events such as moving the window, resizing, closing and input
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
				break;
			case sf::Event::KeyPressed:
				input.setKeyDown(event.key.code);
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				input.setKeyUp(event.key.code);
				input.setKeyUp(event.key.code);
				break;
			default:
				// don't handle other events
				break;
			}
		}


		deltaTime = clock.restart().asSeconds(); //calculate deltaTime

		//if the states are for either test, run the testing function
		if (game.appState == game.TestingFuzzy || game.appState == game.TestingFSM)
		{
			game.testing(engine, deltaTime);
		}
		//otherwise run the sfml game loop
		else if (game.appState == game.ApplicationFuzzyLogic || game.appState == game.ApplicationFSM)
		{
			game.handleInput(&input, deltaTime);
			game.application(engine, deltaTime);
			game.render();
		}	
	}

	system("PAUSE");
	return 0;
}

