#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

const std::string computerChoices[3] = { "Rock", "Paper", "Scissors" };

// Function to check the user input if it's valid
std::string validateInput ()
{
	std::string userChoice;
	do
	{
		std::cout << "Enter your choice [Rock, Paper, Scissors]: ";
		std::cin >> userChoice;
		userChoice[0] = toupper(userChoice[0]);
		for (int i = 1; i < userChoice.length(); i++)
		{
			userChoice[i] = tolower(userChoice[i]);
		}

	} while (userChoice != computerChoices[0] && userChoice != computerChoices[1] && userChoice != computerChoices[2]);

	return userChoice;
}

// Function to determine the winner
std::string determineWinner(std::string userChoice, std::string computerChoice)
{
	if ((userChoice == computerChoices[0] && computerChoice == computerChoices[2]) || (userChoice == computerChoices[2] && computerChoice == computerChoices[0]))
	{
		return "Rock win!";
	}
	else if ((userChoice == computerChoices[0] && computerChoice == computerChoices[1]) || (userChoice == computerChoices[1] && computerChoice == computerChoices[0]))
	{
		return "Paper win!";
	}
	else if ((userChoice == computerChoices[1] && computerChoice == computerChoices[2]) || (userChoice == computerChoices[2] && computerChoice == computerChoices[1]))
	{
		return "Scissors win!";
	}
	else
	{
		return "Draw!";
	}
}

// Function to random computer choice
std::string computerRandom()
{
	int random = rand() % 3;
	std::string computerChoice = computerChoices[random];
	return computerChoice;
}

int main()
{
	srand(time(NULL));
	std::string userChoice = validateInput();
	std::string computerChoice = computerRandom();

	std::cout << "You chose: " << userChoice << std::endl;
	std::cout << "Computer chose: " << computerChoice << std::endl;

	std::cout << determineWinner(userChoice, computerChoice) << std::endl;
}