#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Space
{
	sf::Sprite faceup;
	sf::Sprite facedown;
	sf::Sprite inProgress;
	sf::Sprite showMine;
	sf::Sprite gameWon;
	sf::Sprite gameLost;
	sf::Sprite testButton1;
	sf::Sprite testButton2;
	sf::Sprite testButton3;
	sf::Sprite debugButton;
	sf::Sprite flag;
	sf::Sprite negativeNumber;
	sf::Sprite numberOne;
	sf::Sprite numberTwo;
	sf::Sprite numberThree;
	sf::Texture texture;

	bool isFaceup;
	bool isGameLost;
	bool isFlagged;
	bool gameInProgress;
	bool mineDebugShowing;
	bool isGameWon;
	bool negativeNum;

public:
	int count;

	// Constructors
	//Space();
	Space(int value);

	// Accessors
	int GetCount();

	// Behaviors
	void SetPosition(float xPosition, float yPosition);	
	void ButtonSetPosition(float xPosition, float yPosition);
	void Draw(sf::RenderWindow& window);
	void DrawUnrevealed(sf::RenderWindow& window);
	void DrawMine(sf::RenderWindow& window);
	void DrawButton(sf::RenderWindow& window);
	void DrawMineCounter(int numberToDisplay, sf::RenderWindow& window);
	
	sf::FloatRect GetBounds();
	sf::FloatRect GetTestBoardBounds(int testNum);

	bool GetBool();
	bool CheckIfFlagged();
	void CheckIfGameWon();

	void FlipSpace();
	void FlipBack();
	void MarkFlagged();
	void HitMine();
	void makeMineFalse();
};
