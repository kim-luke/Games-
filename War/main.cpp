#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

class player {
	private:
		int number;
		int score;

	public:

	player() {
		number = 0;
		score = 0;
	}

	int getScore() {
		return score;
	}
	
	// Generates numbers between 1 to 10 for the player
	int generateNumber() {
		int number = rand() % 10 + 1;
		return number;
	}

	void assignPointUser(player user, int increment) {
		user.score += increment;
		cout << "\nYour score has increased by 1! It is now: " << user.getScore() << endl;
	}

	void assignPointDealer(player dealer, int increment) {
		dealer.score += increment;
		cout << "\nThe dealer's score has increased by 1! It is now: " << dealer.getScore() << endl;
	}

	// Takes in inputs for both the user and the dealer's number and compares them
	void compareNumbers(int userNumber, int dealerNumber, player user, player dealer) {

		// If the numbers are equal, generate new numbers and call the function (recursively) until two satisfactory numbers are assigned
		if (userNumber == dealerNumber) {
			cout << "Both numbers are equal! Re-assigning numbers..." << endl;
			userNumber = generateNumber();
			dealerNumber = generateNumber();
			cout << "\nYour new number is: " << userNumber << endl;
			cout << "The dealer's new number is: " << dealerNumber << endl;
			return compareNumbers(userNumber, dealerNumber, user, dealer);
		}

		else if (userNumber > dealerNumber) {
			user.assignPointUser(user, 1);
			return;
		}

		else {
			dealer.assignPointDealer(dealer, 1);
			return;
		}
	}

};

void War(player user, player dealer) {
	int userNumber;
	int dealerNumber;
	cout << "\nAssigning numbers for both players! ---------------------------------------" << endl;

	userNumber = user.generateNumber();
	cout << "\nYour number is: " << userNumber << endl;

	dealerNumber = dealer.generateNumber();
	cout << "The dealer's number is " << dealerNumber << endl;

	user.compareNumbers(userNumber, dealerNumber, user, dealer);
}

int main() {

	srand(time(nullptr));

	player user;
	player dealer;
	bool cont = true;
	char confirm;
	cout << "Let's start a round of War!" << endl;
	War(user, dealer);
	
	while (cont) {
		cout << "Would you like to continue playing? Typing 'y' or 'Y' will continue the game, anything else will stop the game." << endl;
		cin >> confirm;
		
		switch (confirm) {
			case 'y':
			case 'Y':
				War(user, dealer);
				cont = true;
				break;

			default:
				cont = false;
				break;
		}
		
	}	

	system("pause");
	return 0;
}