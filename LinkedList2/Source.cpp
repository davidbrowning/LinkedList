#include "list.hpp"

void chooser(int);
void NoUI();
void UI();

int main(){
	std::cout << "linked list demonstration" << std::endl; //Opening bit.
	std::cout << "-David Browning" << std::endl << std::endl;
	std::cout << "1) No UI, just show me you know how to code a linked list" << std::endl;
	std::cout << "2) UI, walking through the lists, picking typenames" << std::endl;

	int choice = 0;
	std::cout << " input: ";
	if (std::cin >> choice){ //Check user input, if valid continue, else run w/o User interface
	chooser(choice);
	}
	else{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	NoUI();
	}
	return EXIT_SUCCESS;
}

void chooser(int c){ // Validate selection.
	if (c == 1){
		NoUI();
	}
	else if (c == 2){
		UI();
	}
	else {
		NoUI();
	}
}

void NoUI(){ // Print the three linked lists. 

	std::fstream fin("numbers.txt"); //Data Stored in three text files (numbers.txt, letters.txt, and strings.txt)
	linkedlist L1; //Initialize the integer list.
	if (fin.fail()){ //assure the file opens properly.
		std::cout << "Error Opening File" << std::endl;
		return;
	}
	else{
		int i;
		fin >> i;
		while (fin.eof() == false){ //Insert all elements into list.
			L1.insert(i);
			fin >> i;
		}
	}
	L1.print(1);
	fin.close(); //Close the file.

	fin.open("letters.txt"); //Repeat.
	linkedlist L2;
	if (fin.fail()){
		std::cout << "Error Opening File" << std::endl;
		return;
	}
	else{
		char i;
		fin >> i;
		while (fin.eof() == false){
			L2.insert(i);
			fin >> i;
		}
	}
	L2.print(2);
	fin.close();

	fin.open("strings.txt");
	linkedlist L3;
	if (fin.fail()){
		std::cout << "Error Opening File" << std::endl;
		return;
	}
	else{
		std::string i;
		fin >> i;
		while (fin.eof() == false){
			L3.insert(i);
			fin >> i;
		}
	}
	L3.print(3);
}
void writeToFile(std::shared_ptr<linkedlist> l){
	std::fstream fout;
	fout.open("numbers.txt");
	auto n = l->headInt;
	fout << n->value << std::endl;
	while (n->next != nullptr){
		fout << n->value << std::endl;
		n = n->next;
	}
	fout.close();
}

void UI(){ //This part is a bit messy, but it boils down to the event loop, and the main switch statement. 
	//The user chooses between integer, character, and strings after which they have the option
	//to follow the list piece by piece or to simply display the entire thing. 
	//The lists are stored in individual text files. 
	char input = '1';
	std::fstream fin;
	do {
		std::cout << "You've entered the user interface, type 'q' then hit 'enter' at any time to quit." << std::endl;
		std::cout << "Three lists are available: \n \t a) integers \n \t b) characters \n \t c) strings " << std::endl;
		std::cout << "Selection: ";
		if (std::cin >> input){ //Selecting which list to work with.
			switch (input){
			case('a') : {std::cout << "Integers: \n \t d) Display \n \t s) step through" << std::endl << "input:"; //Print the list or step through it.
				fin.open("numbers.txt");
				linkedlist L1;
				if (fin.fail()){
					std::cout << "Error Opening File" << std::endl;
					return;
				}
				else{
					int i;
					fin >> i;
					while (fin.eof() == false){
						L1.insert(i); //Create list.
						fin >> i;
					}
				}
				fin.close();
				if (std::cin >> input){ // Check user input.
					if (input == 'd'){
						L1.print(1);
					}
					else if (input == 'i'){
						std::cout << "which number?";
						int num;
						if (std::cin >> num){
							L1.insert(num);
							writeToFile(std::make_shared<linkedlist>(L1));
						}
						else break;
					}
					else if (input == 'r'){
						std::cout << "which one?" << std::endl;
						auto toDelete = 0;
						if (std::cin >> toDelete){
							L1.delNode(toDelete);
							L1.print(1);
							writeToFile(std::make_shared<linkedlist>(L1));
						}
						else{
							break;
						}
					}
					else if (input == 's'){
						std::cout << "\t n) next " << std::endl;
						auto n = L1.headInt;
						std::cout << "Head:" << n->value << std::endl << "input:";
						if (std::cin >> input){
							while (input == 'n'){
								if (n->next != nullptr){
									n = n->next;
								}
								else break;

								std::cout <<"Next: "<< n->value << std::endl << "input:";
								if (std::cin >> input){
								}
								else break;
							}
						}
						else break;
					}
				}
				else break;
				
			}
						break;
			case('b') : {std::cout << "Characters \n \t d) Display \n \t s) step through" << std::endl << "input:";
				fin.open("letters.txt");
				linkedlist L2;
				if (fin.fail()){
					std::cout << "Error Opening File" << std::endl;
					return;
				}
				else{
					char i;
					fin >> i;
					while (fin.eof() == false){
						L2.insert(i);
						//std::cout << i << std::endl;
						fin >> i;
					}
				}
				fin.close();
				if (std::cin >> input){
					if (input == 'd'){
						L2.print(2);
					}
					else if (input == 's'){
						std::cout << "\t n) next " << std::endl;
						auto n = L2.headChar;
						std::cout << "Head:" << n->value << std::endl << "input: ";
						if (std::cin >> input){
							while (input == 'n'){
								if (n->next != nullptr){
									n = n->next;
								}
								else break;

								std::cout << "Next: " << n->value << std::endl << "input:";
								if (std::cin >> input){
								}
								else break;
							}
						}
						else break;
					}
				}
				else break;

			}
						break;
			case('c') : {std::cout << "Strings \n \t d) Display \n \t s) step through" << std::endl << "input"; 
				fin.open("strings.txt");
				linkedlist L3;
				if (fin.fail()){
					std::cout << "Error Opening File" << std::endl;
					return;
				}
				else{
					std::string i;
					fin >> i;
					while (fin.eof() == false){
						L3.insert(i);
						//std::cout << i << std::endl;
						fin >> i;
					}
				}
				fin.close();
				if (std::cin >> input){
					if (input == 'd'){
						L3.print(3);
					}
					else if (input == 's'){
						std::cout << "\t n) next " << std::endl;
						auto n = L3.headString;
						std::cout << "Head:" << n->value << std::endl << "input: ";
						if (std::cin >> input){
							while (input == 'n'){
								if (n->next != nullptr){
									n = n->next;
								}
								else break;

								std::cout << "Next: " << n->value << std::endl << "input:";
								if (std::cin >> input){
								}
								else break;
							}
						}
						else break;
					}
				}
				else break;

			}
						break;
			case('q') : {std::cout << "Terminating Linked List" << std::endl; }
						break;
			default: std::cout << "Invalid Selection" << std::endl; 
			}
		}
		else break;
		

	} while (input != 'q');
}