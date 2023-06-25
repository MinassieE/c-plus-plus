#include <iostream>
#include <iomanip>
using namespace std;

//GROUP MEMBERS
//SECTION: G
//1.	Minassie ephrem === RCD/3324/2013
//2.	Mohammed Seid === RCD/3326/2013
//3.	Tsega Zenebe ====== RCD/3338/2013
//4.	Urael Alemayehu === RCD/3336/2013

//structure to define the blue print of a single person contact
struct Node {
	string Fname;
	string Lname;
	int id, phone;
	Node *next, *prev;
}*head = NULL; //create a structure variable head of type Node pointer with a NULL value

//create Address class for all the linked list implementation
class Address{
	//static variable to keep count of the number of contact stored
	static int counter;
	//methode to create a node
	Node* createNode(string Fname, string Lname, int phone){
			Node *node = new Node;
			node->Fname = Fname;
			node->Lname = Lname;
			node->phone = phone;
			node->next = NULL;
			node->prev = NULL;
			return node;
		}
	public:
		//declaration methods for different operations on the linked list
		//method definition is implemented below
		void addContact(string Fname, string Lname, int phone);
		void searchContact(string key);
		void editContact(string key);
		void deleteContact(string key);
		void sortContact(Node *head);
		void viewContact(Node *head);
};
//initializing the static variable counter of class Address
int Address::counter = 0;

int main(){
	//variables to store first name, last name, phone number
	//and key, which is basically first name of a person that we use for searching
	string fname, lname, key;
	int phone;
	
	//creating an object of class Address
	Address address;
	
	//	contacts for test, initial starting contact lists
	address.addContact("abebe", "kasa", 911111111);
	address.addContact("minassie", "ephrem", 977777777);
	address.addContact("biniyam", "solomon", 944444444);
	address.addContact("zaki", "teshome", 933333333);
	address.addContact("yabsera", "dereje", 988888888);
	address.addContact("kenean", "kibru", 966666666);
	address.addContact("efrata", "mulgeta", 955555555);
	
	//clear the command line
	system("cls");
	
	//flag that we use to run the menu until the user exit
	bool run=true;
	
	//do while loop for the menu
	do{
		//variable to store the user choice from the menu
		int Option;
		
		//display the menu
		cout << "-----------------User Address Book------------------------" << endl;
		cout << "\n";
		cout << "What would you like to do?" << endl;
		cout << "1.) Add Contact" << endl;
		cout << "2.) Edit Contact" << endl;
		cout << "3.) Delete Contact" << endl;
		cout << "4.) View All Contacts" << endl;
		cout << "5.) Search Address Book" << endl;
		cout << "6.) sort contacts" << endl;
		cout << "7.) Exit" << endl << endl;
		cout << "Choose an option: ";
		
		//accept the user input
		cin >> Option;
		
		system("cls");
		
		//switch to execute specific operations based on the users input 
		switch (Option){
			case 1:
				//accept the required informations to create a new contact
				cout << "====================================" <<endl;
				cout << "||         ADDING CONTACT         ||" << endl;
				cout << "====================================" <<endl;
				cout << "Enter first name: ";
				cin >> fname;
				cout << "Enter last name: ";
				cin >> lname;
				cout << "Enter new phone nubmer (format = '912121212', don't start with 0): ";
				cin >> phone;
				
				//calling the addContact method in the address object passing on the data that the user provided
				address.addContact(fname, lname, phone);
				break;
			case 2:
				cout << "====================================" <<endl;
				cout << "||         EDITING CONTACT        ||" << endl;
				cout << "====================================" <<endl;
				//asking the user to enter the first name of the person which will be used to find a specific contact
				cout << "Enter the first name of the person: ";
				cin >> key;
				//calling the editContact method in the address object passing on the data(key) that the user provided
				address.editContact(key);
				break;
			case 3:
				cout << "====================================" <<endl;
				cout << "||        DELETING CONTACT        ||" << endl;
				cout << "====================================" <<endl;
				//asking the user to enter the first name of the person which will be used to delete a specific contact
				cout << "Enter the first name of the person: ";
				cin >> key;
				//calling the deleteContact method in the address object passing on the data(key) that the user provided
				address.deleteContact(key);
				break;
			case 4:
				cout << "====================================" <<endl;
				cout << "||         DISPLAY CONTACT        ||" << endl;
				cout << "====================================" <<endl;
				//calling the viewContact method in the address object passing on the first node of our linked list
				address.viewContact(head);
				break;
			case 5:
				cout << "====================================" <<endl;
				cout << "||       SEARCHING CONTACT        ||" << endl;
				cout << "====================================" <<endl;
				//asking the user to enter the first name of the person which will be used to find a specific contact
				cout << "Enter the first name of the person: ";
				cin >> key;
				//calling the searchContact method in the address object passing on the data(key) that the user provided
				address.searchContact(key);
				break;
			case 6:
				//calling the sortContact method in the address object passing on the first node of the linked list
				address.sortContact(head);
				cout << "====================================" <<endl;
				cout << "||         CONTACT SORTED         ||" << endl;
				cout << "====================================" <<endl;
				break;
			case 7:
				//if the user enters 7 then our flag (run variable) will be false, which will stop the do-while loop
				run = false;
				break;
			default:
				//if the user enters any other value than the avilable inputs discribed in the menu this will be executed
				cout << "Please Choose between 1 to 7" <<endl;
				int main();
		}
	} while(run);
	//when the user enters 7 which is Exit option this message will be displayed
	cout << "Program Terminated";
}


//method definitions

//defining addContact method
//it takes 3 arguments
void Address::addContact(string Fname, string Lname, int phone){
	//creating pointer variables of type Node
	Node *newNode, *temp;
	//calling createNode function and saving the returned node in newNode variable
	newNode = createNode(Fname, Lname, phone);
	//incrementing the number of node
	counter++;
	//seting id to the created node based on the number of node
	newNode->id = counter;
	
	//adding the new node to an empty linked list 
	if(head == NULL){
		head = newNode;
		head->next = NULL;
		head->prev = NULL;
	}
	//adding the new node to non empty linked list
	else{
		temp = head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
}

//defining the method searchContact
//if takes an argument key for the search
void Address::searchContact(string key){
	//creating new Node pointer variable and assigning it to head
	Node *temp = head;
	
	//iterating through all nodes of the linked list until we find the last node
	while(temp){
		//checking if the first name of a contact matches with a key in eavery eteration
		if(key == temp->Fname){
			//display the contact if a match is found with the key
			cout << "---------------------------------------------------------------------------" <<endl;
			cout << "| Entry #" << setw(20)<<"First Name" << setw(20)<< "Last Name" << setw(20) <<"Contact" << setw(6)<< " |"<< endl;
			cout << "|-------------------------------------------------------------------------|" <<endl;
			cout << "| "<<setw(3) << temp->id << setw(23) <<temp->Fname << setw(20) << temp->Lname << setw(16) << "+251-"<<temp->phone << " |"<< endl;
			cout << "---------------------------------------------------------------------------" <<endl;
			return;
		}
		//go to the next node if the current node is not the one wanted
		temp = temp->next;
	}
	//display this if their is no mathc for the key 
	cout << "NAME: '" << key << "'\n"; 
	cout << "Contact not found \n";
}

//difining editContact method
void Address::editContact(string key){
	//creating new Node pointer variable and assigning it to head
	Node *temp = head;
	
	//create a new int variable for using is as a flag of user's confirmation
	int confirmEdit;
	//iterating through the list until their is match for the key or until we reach the end of the list
	while(temp){
		//checking if the first name of a contact matches with a key in eavery eteration
		if(key == temp->Fname){
			//display the contact if a match is found with the key
			cout << "---------------------------------------------------------------------------" <<endl;
			cout << "| Entry #" << setw(20)<<"First Name" << setw(20)<< "Last Name" << setw(20) <<"Contact" << setw(6)<< " |"<< endl;
			cout << "|-------------------------------------------------------------------------|" <<endl;
			cout << "| "<<setw(3) << temp->id << setw(23) <<temp->Fname << setw(20) << temp->Lname << setw(16) << "+251-"<<temp->phone << " |"<< endl;
			cout << "---------------------------------------------------------------------------" <<endl << endl;
			
			//ask the user for confirmation
			cout << "Is this the contact that you want to edit? (1- yes, 2-no): ";
			cin >> confirmEdit;
			
			//if confirmed proceed to editing the found contact
			if(confirmEdit == 1){
				//create new variables to receive data to edit the existing contact
				string fname, lname;
				int phone;
				//ask user to enter the new data
				cout << "Enter new first name: " <<endl;
				cin >>fname;
				cout << "Enter new last name: " << endl;
				cin >> lname;
				cout << "Enter new phone nubmer (format = '912121212', don't start with 0): " << endl;
				cin >> phone;
				
				//overright the old data in that specific node
				temp->Fname = fname;
				temp->Lname = lname;
				temp->phone = phone;
				
				//display the new edited contact
				cout << "contact updated succesfully!!!" << endl;
				cout << "---------------------------------------------------------------------------" <<endl;
				cout << "| Entry #" << setw(20)<<"First Name" << setw(20)<< "Last Name" << setw(20) <<"Contact" << setw(6)<< " |"<< endl;
				cout << "|-------------------------------------------------------------------------|" <<endl;
				cout << "| "<<setw(3) << temp->id << setw(23) <<temp->Fname << setw(20) << temp->Lname << setw(16) << "+251-"<<temp->phone << " |"<< endl;
				cout << "---------------------------------------------------------------------------" <<endl << endl;
				return;
			}
			else return;
		}
		temp = temp->next;
	}
	cout << "NAME: '" << key << "'\n"; 
	cout << "Contact not found \n";
}

void Address::deleteContact(string key){
	//creating new Node pointer variable and assigning it to head
	Node *temp = head;
	//create a new int variable for using is as a flag of user's confirmation
	int deletionConfirmation;
	
	//iterating through the linked list until key is found of the list is over
	while(temp){
		if(key == temp->Fname){
			//display the contact if key is found 
			cout << "---------------------------------------------------------------------------" <<endl;
			cout << "| Entry #" << setw(20)<<"First Name" << setw(20)<< "Last Name" << setw(20) <<"Contact" << setw(6)<< " |"<< endl;
			cout << "|-------------------------------------------------------------------------|" <<endl;
			cout << "| "<<setw(3) << temp->id << setw(23) <<temp->Fname << setw(20) << temp->Lname << setw(16) << "+251-"<<temp->phone << " |"<< endl;
			cout << "---------------------------------------------------------------------------" <<endl << endl;
			
			//ask for confirmation to delete
			cout << "Is this the contact you want to delete? (press 1 to confirm and any number to abort): ";
			cin >> deletionConfirmation;
			//proceed deletion process if user approved
			if(deletionConfirmation==1){
				//code to delete the first element of the linded list
				if(temp==head){
					head = temp->next;
					temp->next->prev = NULL;
					temp->next = NULL;
				}
				//code to delete the last element of the linked list
				else if(temp->next == NULL){
					temp->prev->next = NULL;
					temp->prev = NULL;
				}
				//code to delete a node from the middle of the linked list
				else{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					temp->next = NULL;
					temp->prev= NULL;
						
				}
				return;
			}
			else return;
		}
		//go to the next node if the current node does not match with key
		temp = temp->next;
	}
	//notify user if the key (name to be deleted) is not found
	cout << "NAME: '" << key << "'\n"; 
	cout << "Contact not found \n";
}

//difining sortContact method
void Address::sortContact(Node *head){
	//creating new Node pointer variable and assigning it to head
	Node *temp = head;
	//create a new variables which are used to swap nodes
	string fname, lname;
	//counter is a variable to count how many nodes are there in the linked list
	int phone, counter = 0;
	//check if the list is empty
	if(head == NULL){
		cout << "empty list \n";
	}
	else{
		//if not start counting how many elements are their
		while(temp){
			//increament counter every time new node is found
			counter++;
			temp = temp->next;
		}
		//reseting temp to head to iterate through the linked list
		temp = head;
		
		//this is bubble sort implementation
		//for loop to iterate through the linked list 
		for(int i=0; i<counter-1; i++){
			//for loop to compare every element with its imediate right element
			for(int j=0; j<counter-1-i; j++){
				//swaping the element if the first element is greater than the second
				if(temp->Fname > temp->next->Fname){
					fname = temp->Fname;
					temp->Fname = temp->next->Fname;
					temp->next->Fname = fname;
					
					lname = temp->Lname;
					temp->Lname = temp->next->Lname;
					temp->next->Lname = lname;
					
					phone = temp->phone;
					temp->phone = temp->next->phone;
					temp->next->phone = phone;
				}
				temp = temp->next;
			}
			//reseting temp to head for second iteration
			temp = head;
		}
		
	}
}

//difining viewContact method
//it taked a Node pointer as an arguement
void Address::viewContact(Node *head){
	//creating new Node pointer variable and assigning it to head
	Node *temp = head;
	//check if the link is empty
	if(head==NULL){
		cout << "empty list;";
	}
	//if the list is not empty display the data 
	else{
		cout << "---------------------------------------------------------------------------" <<endl;
		cout <<"| Entry #" << setw(20)<<"First Name" << setw(20)<< "Last Name" << setw(20) <<"Contact" << setw(6)<< " |"<< endl;
		cout << "|-------------------------------------------------------------------------|" <<endl;
		//display the data inside each exixting node
		while(temp){
			cout << "| "<<setw(3) << temp->id << setw(23) <<temp->Fname << setw(20) << temp->Lname << setw(16) << "+251-"<<temp->phone << " |"<< endl;
			temp = temp->next;
		}
		cout << "---------------------------------------------------------------------------" <<endl;
	}	
}
