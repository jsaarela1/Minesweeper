#include "Space.h"
#include "TextureManager.h"
/*
Space::Space()
{
	count = 0;
	faceup.setTexture(TextureManager::GetTexture("tile_revealed"));
	facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
	isFaceup = true;
}
*/

Space::Space(int value)
{
	count = value;
	if (value == 0)
	{
		faceup.setTexture(TextureManager::GetTexture("tile_revealed"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 1)
	{
		faceup.setTexture(TextureManager::GetTexture("number_1"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 2)
	{
		faceup.setTexture(TextureManager::GetTexture("number_2"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 3)
	{
		faceup.setTexture(TextureManager::GetTexture("number_3"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 4)
	{
		faceup.setTexture(TextureManager::GetTexture("number_4"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 5)
	{
		faceup.setTexture(TextureManager::GetTexture("number_5"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 6)
	{
		faceup.setTexture(TextureManager::GetTexture("number_6"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 7)
	{
		faceup.setTexture(TextureManager::GetTexture("number_7"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 8)
	{
		faceup.setTexture(TextureManager::GetTexture("number_8"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 9)
	{
		faceup.setTexture(TextureManager::GetTexture("mine"));
		facedown.setTexture(TextureManager::GetTexture("tile_hidden"));
		flag.setTexture(TextureManager::GetTexture("flag"));
		showMine.setTexture(TextureManager::GetTexture("mine"));
		isFaceup = false;
		mineDebugShowing = false;
		isFlagged = false;
	}
	else if (value == 10)
	{
		inProgress.setTexture(TextureManager::GetTexture("face_happy"));
		gameLost.setTexture(TextureManager::GetTexture("face_lose"));
		gameWon.setTexture(TextureManager::GetTexture("face_win"));
		isGameWon = false;
		isGameLost = false;
		isFlagged = false;
	}
	else if (value == 11)
	{
		testButton1.setTexture(TextureManager::GetTexture("test_1"));
	}
	else if (value == 12)
	{
		testButton2.setTexture(TextureManager::GetTexture("test_2"));
	}
	else if (value == 13)
	{
		testButton3.setTexture(TextureManager::GetTexture("test_3"));
	}
	else if (value == 14)
	{
		debugButton.setTexture(TextureManager::GetTexture("debug"));
	}
	else if (value == 15)
	{
		negativeNumber.setTexture(TextureManager::GetTexture("digits"));
		numberOne.setTexture(TextureManager::GetTexture("digits"));
		numberTwo.setTexture(TextureManager::GetTexture("digits"));
		numberThree.setTexture(TextureManager::GetTexture("digits"));
	}
}

int Space::GetCount()
{
	return count;
}

void Space::SetPosition(float xPosition, float yPosition)
{
	faceup.setPosition(xPosition, yPosition);
	facedown.setPosition(xPosition, yPosition);
	flag.setPosition(xPosition, yPosition);
	if (GetCount() == 9)
		showMine.setPosition(xPosition, yPosition);
}

void Space::ButtonSetPosition(float xPosition, float yPosition)
{
	if (GetCount() == 10)
	{
		inProgress.setPosition(xPosition, yPosition);
		gameWon.setPosition(xPosition, yPosition);
		gameLost.setPosition(xPosition, yPosition);
	}
	else if (GetCount() == 11)
		testButton1.setPosition(xPosition, yPosition);
	else if (GetCount() == 12)
		testButton2.setPosition(xPosition, yPosition);
	else if (GetCount() == 13)
		testButton3.setPosition(xPosition, yPosition);
	else if (GetCount() == 14)
		debugButton.setPosition(xPosition, yPosition);
	else if (GetCount() == 15)
	{
		negativeNumber.setPosition(xPosition, yPosition);
		numberThree.setPosition(xPosition + 20, yPosition);
		numberTwo.setPosition(xPosition + 40, yPosition);
		numberOne.setPosition(xPosition + 60, yPosition);

	}
}

void Space::Draw(sf::RenderWindow& window)
{
	if (isFlagged)
		window.draw(flag);
	else
	{
		if (isFaceup)
			window.draw(faceup);
		else
			window.draw(facedown);
	}
}

void Space::DrawUnrevealed(sf::RenderWindow& window)
{
	window.draw(facedown);
}

void Space::DrawMine(sf::RenderWindow& window)
{
	window.draw(showMine);
}

void Space::DrawButton(sf::RenderWindow& window)
{
	if (GetCount() == 10)
	{
		if (isGameLost)
			window.draw(gameLost);
		else if (isGameWon)
			window.draw(gameWon);
		else
			window.draw(inProgress);
	}
	else if (GetCount() == 11)
		window.draw(testButton1);
	else if (GetCount() == 12)
		window.draw(testButton2);
	else if (GetCount() == 13)
		window.draw(testButton3);
	else if (GetCount() == 14)
		window.draw(debugButton);
	else if (GetCount() == 15)
	{
		window.draw(numberThree);
		window.draw(numberTwo);
		window.draw(numberOne);
		if (negativeNum == true)
			window.draw(negativeNumber);
	}
}

sf::FloatRect Space::GetBounds()
{
	return faceup.getGlobalBounds();
}

sf::FloatRect Space::GetTestBoardBounds(int testNum)
{
	if (testNum == 0)
		return inProgress.getGlobalBounds(); 
	else if (testNum == 1)
		return testButton1.getGlobalBounds();
	else if (testNum == 2)
		return testButton2.getGlobalBounds();
	else if (testNum == 3)
		return testButton3.getGlobalBounds();
	else if (testNum == 4)
		return debugButton.getGlobalBounds();
}

void Space::FlipSpace()
{
	if (isFaceup == false)
		isFaceup = !isFaceup;
}

void Space::FlipBack()
{
	if (isFaceup == true)
		isFaceup = false;
}

void Space::MarkFlagged()
{
	isFlagged = !isFlagged;
}

bool Space::GetBool()
{
	return isFaceup;
}

bool Space::CheckIfFlagged()
{
	return isFlagged;
}

void Space::CheckIfGameWon()
{
	isGameWon = true;
}

void Space::HitMine()
{
	isGameLost = true;
}

void Space::makeMineFalse()
{
	isGameLost = false;
	isGameWon = false;
}

void Space::DrawMineCounter(int numberToDisplay, sf::RenderWindow& window)
{
	if (numberToDisplay < 0)
	{
		negativeNum = true;
		numberToDisplay *= -1;
		negativeNumber.setTextureRect(sf::IntRect(210, 0, 21, 32));
		window.draw(negativeNumber);
	}
	int ones = numberToDisplay % 10;
	numberToDisplay /= 10;
	int tens = numberToDisplay % 10;
	numberToDisplay /= 10;
	int hundreds = numberToDisplay % 10;
	numberThree.setTextureRect(sf::IntRect(hundreds * 21, 0, 21, 32));
	numberTwo.setTextureRect(sf::IntRect(tens * 21, 0, 21, 32));
	numberOne.setTextureRect(sf::IntRect(ones * 21, 0, 21, 32));
}
