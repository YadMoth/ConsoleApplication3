int main() {
    ContactManager manager;
    int choice;
    std::string name, phone, email;

    do {
        std::cout << "1. Add Contact\n";
        std::cout << "2. Delete Contact\n";
        std::cout << "3. Find Contact\n";
        std::cout << "4. Change Contact\n";
        std::cout << "5. Save to File\n";
        std::cout << "6. Display Contacts\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter name, phone, email: ";
                std::cin >> name >> phone >> email;
                manager.addContact(name, phone, email);
                break;
            case 2:
                std::cout << "Enter name to delete: ";
                std::cin >> name;
                manager.deleteContact(name);
                break;
            case 3:
                std::cout << "Enter name to find: ";
                std::cin >> name;
                if (Contact* contact = manager.findContact(name)) {
                    contact->display();
                } else {
                    std::cout << "Contact not found.\n";
                }
                break;
            case 4:
                std::cout << "Enter name to change: ";
                std::cin >> name;
                std::cout << "Enter new phone and email: ";
                std::cin >> phone >> email;
                manager.changeContact(name, phone, email);
                break;
            case 5:
                manager.saveToFile("contacts.txt");
                std::cout << "Contacts saved to file.\n";
                break;
            case 6:
                manager.displayContacts();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
