#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Contact {
public:
    std::string name;
    std::string phone;
    std::string email;

    Contact(const std::string& n, const std::string& p, const std::string& e)
        : name(n), phone(p), email(e) {}

    void display() const {
        std::cout << "Name: " << name << ", Phone: " << phone << ", Email: " << email << std::endl;
    }
};

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string& name, const std::string& phone, const std::string& email) {
        contacts.emplace_back(name, phone, email);
    }

    void deleteContact(const std::string& name) {
        contacts.erase(std::remove_if(contacts.begin(), contacts.end(),
                                       [&name](const Contact& c) { return c.name == name; }), contacts.end());
    }

    Contact* findContact(const std::string& name) {
        for (auto& contact : contacts) {
            if (contact.name == name) {
                return &contact;
            }
        }
        return nullptr;
    }

    void changeContact(const std::string& name, const std::string& newPhone, const std::string& newEmail) {
        Contact* contact = findContact(name);
        if (contact) {
            contact->phone = newPhone;
            contact->email = newEmail;
        }
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& contact : contacts) {
            file << contact.name << "," << contact.phone << "," << contact.email << std::endl;
        }
    }

    void displayContacts() const {
        for (const auto& contact : contacts) {
            contact.display();
        }
    }
};
