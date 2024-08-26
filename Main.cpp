#include "Chat.h"//подключение заголовочного файла
int main() {
	Chat chat;//сам чат
	locale::global(locale(""));
	User* currentUser = nullptr;//указатель для идентификации пользователя, использующего чат в данный момент
	int option = 1;
	while (option) {//реализация взаимодействия пользователя с чатом с помощью switch case
		cout << "WARNING!!! YOU CAN'T USE MORE THAN 60 SYMBOLS IN LOGIN, PASSWORD OR NAME!!!!\n";
		cout << "1. Register" << endl;
		cout << "2. Login" << endl;
		cout << "3. Send message to user" << endl;
		cout << "4. Send message for all" << endl;
		cout << "5. Get out of the account" << endl;
		cout << "6. Show list of users" << endl;
		cout << "7. Show private messages" << endl;
		cout << "8. Show messages for all" << endl;
		cout << "9. Exit" << endl;
		cout << "Choose 1 of the options " << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			string login, password;
			cout << "Enter login: ";
			cin >> login;
			cout << "Enter password: ";
			cin >> password;
			try {
				chat.registerUser(login, password);
			}
			catch (const char* exception) 
			{
				cout << "This login is unavailabe\n";
				break;
			}
			catch (const int& exception)
			{
				cout << "length of ur login or password or name is longer than 60 symbols!\n";
				break;
			}
			cout << "Registration successful!" << endl;
			break;
		}

		case 2:
		{
			if (currentUser == nullptr)
			{
				string login, password;
				cout << "Enter login: ";
				cin >> login;
				cout << "Enter password: ";
				cin >> password;
				currentUser = chat.loginUser(login, password);
				if (currentUser) {
					cout << "Login successful!" << endl;
				}
				else {
					cout << "Invalid login or password!" << endl;
				}
				break;
			}
			else {
				cout << "You need to logout\n";
				break;
			}
		}

		case 3: {

			if (currentUser != nullptr) {
				string recipientLogin;
				cout << "Enter recipient login: ";
				cin >> recipientLogin;
				chat.lsMessage(currentUser, recipientLogin);
				break;
			}
			cout << "You aren't logged in\n";
			break;
		}

		case 4: {
			if (currentUser != nullptr) {
				string message;
				cout << "Enter message: ";
				cin >> message;
				chat.broadcastMessage(currentUser, message);
				break;
			}
			cout << "You aren't logged in\n";
			break;
		}

		case 5: {
			if (currentUser != nullptr) {
				chat.logout(currentUser);
				break;
			}
			cout << "You aren't logged in\n";
			break;
		}

		case 6: {
			if (currentUser != nullptr) {
				chat.showListOfUsers();
				break;
			}
			cout << "You aren't logged in\n";
			break;
		}

		case 7: {
			if (currentUser != nullptr) {
				chat.showLsMessage(currentUser->getLogin());
				break;
			}
			cout << "You aren't logged in\n";
			break;
		}

		case 8: {
			if (currentUser != nullptr) {
				chat.showMessageForAll();
				break;
			}
			cout << "You aren't logged in\n";
			break;
		}

		case 9: {
			option = 0;
			cout << "Goodbye!";
			chat.end();
			break;
		}

		default: {
			cout << "Invalid choice!" << endl;
			break;
		}
		}
	}
	return 0;
}