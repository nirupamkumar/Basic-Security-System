#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() 
{
	int a;
	int i = 0;
	string text, old, password1, password2, word, word1;
	string name, loginPassword, age;
	string user, pwd;
	string credentials[2], changePassword[2];

	cout << "        Security System         " << endl << endl;
	cout << "--------------------------------" << endl;
	cout << "|        1. Register           |" << endl;
	cout << "|        2. Login              |" << endl;
	cout << "|        3. Change password    |" << endl;
	cout << "|        4. End program        |" << endl;
	cout << "--------------------------------" << endl << endl;

	do 
	{
		cout << endl;
		cout << " Enter your choice: ";
		cin >> a;

		switch (a)
		{
			case 1:
			{
				//Registration code here
				cout << "------------------------" << endl;
				cout << "        Register        " << endl;
				cout << "------------------------" << endl;

				cout << "Please create your user name: ";
				cin >> name;
				cout << "Please create password: ";
				cin >> loginPassword;
				cout << "Please enter age: ";
				cin >> age;

				ofstream oFStream1;
				oFStream1.open("file.txt");

				if (oFStream1.is_open())
				{
					oFStream1 << name << "\n";
					oFStream1 << loginPassword;
					cout << "Registeration successfull" << endl;
				}

				break;
			}
				

			case 2: 
			{
				//Login code here
				i = 0;

				cout << "------------------------" << endl;
				cout << "         Login          " << endl;
				cout << "------------------------" << endl;

				ifstream iFStream1;
				iFStream1.open("file.txt");

				cout << "Enter user name: ";
				cin >> user;
				cout << "Enter password: ";
				cin >> pwd;

				if (iFStream1.is_open()) 
				{
					while (!iFStream1.eof())
					{
						while (getline(iFStream1, text)) 
						{
							istringstream iss(text);
							iss >> word;

							credentials[i] = word;
							i++;
						}

						if (user == credentials[0] && pwd == credentials[1])
						{
							cout << "-------Login Successfull-------" << endl << endl;

							cout << "Details: " << endl;
							cout << "Username: " + name << endl;
							cout << "Password: " + loginPassword << endl;
							cout << "Age: " + age << endl;
						}
						else
						{
							cout << endl << endl;
							cout << "Incorrect credentials" << endl;
							cout << "|          2. Login                  |" << endl;
							cout << "|          3. Change password        |" << endl;

							break;
						}
					}
				}

				break;
			}
				
			
			case 3: 
			{
				//Password change code here
				i = 0;

				cout << "-----------------Change Password---------------" << endl;

				ifstream iFStream0;
				iFStream0.open("file.txt");
				cout << "Enter old password: ";
				cin >> old;

				if (iFStream0.is_open())
				{
					while (iFStream0.eof()) 
					{
						while (getline(iFStream0, text))
						{
							istringstream iss(text);
							iss >> word1;
							changePassword[i] = word1;
							i++;
						}

						if (old == changePassword[1])
						{
							iFStream0.close();

							ofstream oFStream1;

							if (oFStream1.is_open())
							{
								cout << "Enter your new password: ";
								cin >> password1;
								cout << "Enter password again: ";
								cin >> password2;

								if (password1 == password2)
								{
									oFStream1 << changePassword[0] << "\n";
									oFStream1 << password1;
									cout << "Password changed successfully" << endl;
								}
								else
								{
									oFStream1 << changePassword[0] << "\n";
									oFStream1 << old;
									cout << "Password do not match" << endl;
								}
							}
						}
						else
						{
							cout << "Please enter valid password" << endl;
							break;
						}
					}
				}

				break;
			}
				
			
			case 4: 
			{
				//end program
				cout << "------------Thank You!------------";
				break;
			}
				
			
			default:
				cout << "Enter valid choice";
		}

	} while (a != 4);

	return 0;
}