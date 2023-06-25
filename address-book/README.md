Address book / Contact book
This project is an address book program (console application) that has the capacity to store the first name, last name, and phone number of a person. For a simple user experience, it has a descriptive menu which will be the first landing page when the program is executed, and it will take user input to proceed to whatever the user wants to do (the user input must be based on the menu description). 
NB: data base is not implemented on this project, so any data stored is volatile.

Then based on what the user chooses different operations will be done. If the user chooses “Add contact” then he/she will be redirected to another page that will allow them to add a new contact (first name, last name, and phone number). 
The user can also edit an existing contact by choosing the second option and entering the first name of the person to whom he/she wants to edit their contact. Then according to the first name, the contact will be displayed (if it exists) and if the user wishes to proceed he/she can edit the contact. 
Another operation that can be done is deleting a contact. Which will take a person’s first name and then search and display the contact found. Then it asks the user to confirm, and if the user confirms contact will be deleted.
Then the other operation that can be done is to view all contacts. This option will display all the contacts stored in a readable manner using a tabular form.
Searching for a specific contact is also possible. It requires the user to know and provide at least the first name of the person. After taking the person’s first name it will search and display the full information (first name, last name, phone number).
In addition, This program will sort the contacts in alphabetical order. To sort out contacts we used “bubble sort” algorithm.
Then finally, the last option is exit button to terminate the program.

Abstract data type and data structures used
In this project, I used structures for storing the information of a node. which is able to contain all the needed building structures of a single-person contact.  Then I used class to implement the data structure (double linked list).
