#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
	Textbox(int size, sf::Color color, bool sel, bool isPassword = false) {
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		isSelected = sel;
		this->isPassword = isPassword;

		// Check if the textbox is selected upon creation and display it accordingly:
		if (isSelected)
			textbox.setString("_");
		else
			textbox.setString("");
	}

	// Make sure font is passed by reference:
	void setFont(sf::Font& fonts) {
		textbox.setFont(fonts);
	}

	void setPosition(sf::Vector2f point) {
		textbox.setPosition(point);
	}

	// Set char limits:
	void setLimit(bool ToF) {
		hasLimit = ToF;
	}

	void setLimit(bool ToF, int lim) {
		hasLimit = ToF;
		limit = lim - 1;
	}

	// Change selected state:
	void setSelected(bool sel) {
		isSelected = sel;

		// If not selected, remove the '_' at the end:
		if (!sel) {
			textbox.setString(maskedText);
		}
	}

	std::string getText() {
		return text.str();
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(textbox);
	}

	// Function for event loop:
	void typedOn(sf::Event input) {
		if (isSelected) {
			int charTyped = input.text.unicode;

			// Only allow normal inputs:
			if (charTyped < 128) {
				if (hasLimit) {
					// If there's a limit, don't go over it:
					if (static_cast <int>(text.str().length()) <= limit) {
						inputLogic(charTyped);
					}
					// But allow for char deletions:
					else if (static_cast<int>(text.str().length()) > limit && charTyped == DELETE_KEY) {
						deleteLastChar();
					}
				}
				// If no limit exists, just run the function:
				else {
					inputLogic(charTyped);
				}
			}
		}
	}
private:
	sf::Text textbox;
	std::ostringstream text;
	std::string maskedText;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;
	bool isPassword = false;

	// Delete the last character of the text:
	void deleteLastChar() {
		std::string t = text.str();
		if (!t.empty()) {
			t.pop_back(); // Remove last character from actual text
			maskedText.pop_back(); // Remove last character from masked text
		}
		text.str("");
		text << t;
		textbox.setString(maskedText + "_");
	}

	// Get user input:
	void inputLogic(int charTyped) {
		// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
			text << static_cast<char>(charTyped);
			maskedText += (isPassword ? '*' : static_cast<char>(charTyped));
		}
		// If the key is delete, then delete the char:
		else if (charTyped == DELETE_KEY) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
		}
		// Set the textbox text:
		textbox.setString(maskedText + "_");
	}
};
