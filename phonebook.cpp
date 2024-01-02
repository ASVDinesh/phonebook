#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;
    string address;
};

class TreeNode {
public:
    Contact contact;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Contact contact) : contact(contact), left(nullptr), right(nullptr) {}
};

class Phonebook {
public:
    Phonebook() : root(nullptr) {}
    ~Phonebook();

    void add_contact(Contact contact);
    void delete_contact(string phone);
    vector<Contact> search_contacts(string query);
    void display_all_contacts();

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, Contact contact);
    TreeNode* find_min(TreeNode* node);
    TreeNode* remove(TreeNode* node, string phone);
    vector<Contact> search(TreeNode* node, string query);
    void display_inorder(TreeNode* node);
    void destroy_tree(TreeNode* node);
    bool is_valid_email(const string& email);
};

// Destructor implementation
Phonebook::~Phonebook() {
    destroy_tree(root);
}

void Phonebook::add_contact(Contact contact) {
    if (!is_valid_email(contact.email)) {
        cout << "Invalid email format. Contact not added." << endl;

        return;
    }
    cout << "Contact added"<<endl;
    root = insert(root, contact);
}

TreeNode* Phonebook::insert(TreeNode* node, Contact contact) {
    if (node == nullptr) {
        return new TreeNode(contact);
    }

    if (contact.phone < node->contact.phone) {
        node->left = insert(node->left, contact);
    } else if (contact.phone > node->contact.phone) {
        node->right = insert(node->right, contact);
    }

    return node;
}

void Phonebook::delete_contact(string phone) {
    root = remove(root, phone);
}

TreeNode* Phonebook::remove(TreeNode* node, string phone) {
    if (node == nullptr) {
        return nullptr;
    }

    if (phone < node->contact.phone) {
        node->left = remove(node->left, phone);
    } else if (phone > node->contact.phone) {
        node->right = remove(node->right, phone);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        } else {
            TreeNode* min_right = find_min(node->right);
            node->contact = min_right->contact;
            node->right = remove(node->right, min_right->contact.phone);
        }
    }

    return node;
}

TreeNode* Phonebook::find_min(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

vector<Contact> Phonebook::search_contacts(string query) {
    return search(root, query);
}

vector<Contact> Phonebook::search(TreeNode* node, string query) {
    vector<Contact> results;

    if (node != nullptr) {
        if (node->contact.name.find(query) != string::npos ||
            node->contact.phone.find(query) != string::npos ||
            node->contact.email.find(query) != string::npos ||
            node->contact.address.find(query) != string::npos) {
            results.push_back(node->contact);
        }

        vector<Contact> left_results = search(node->left, query);
        vector<Contact> right_results = search(node->right, query);

        results.insert(results.end(), left_results.begin(), left_results.end());
        results.insert(results.end(), right_results.begin(), right_results.end());
    }

    return results;
}

void Phonebook::display_all_contacts() {
    display_inorder(root);
}

void Phonebook::display_inorder(TreeNode* node) {
    if (node != nullptr) {
        display_inorder(node->left);
        cout << "Name: " << node->contact.name << endl;
        cout << "Phone: " << node->contact.phone << endl;
        cout << "Email: " << node->contact.email << endl;
        cout << "Address: " << node->contact.address << endl;
        cout << endl;
        display_inorder(node->right);
    }
}

void Phonebook::destroy_tree(TreeNode* node) {
    if (node != nullptr) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
    }
}

bool Phonebook::is_valid_email(const string& email) {
    // Use a simple regex for email validation
    const regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, email_regex);
}

int main() {
    Phonebook phonebook;

    // Get input from the user
    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Delete contact" << endl;
        cout << "3. Search contacts" << endl;
        cout << "4. Display all contacts" << endl;
        cout << "5. Quit" << endl;

        int option;
        cin >> option;

        if (option == 1) {
            Contact contact;
            cout << "Enter name: ";
            cin >> contact.name;
            cout << "Enter phone: ";
            cin >> contact.phone;
            cout << "Enter email: ";
            cin >> contact.email;
            cout << "Enter address: ";
            cin >> contact.address;
            phonebook.add_contact(contact);
        } else if (option == 2) {
            string phone;
            cout << "Enter phone: ";
            cin >> phone;
            phonebook.delete_contact(phone);
        } else if (option == 3) {
            string query;
            cout << "Enter search query: ";
            cin >> query;
            vector<Contact> results = phonebook.search_contacts(query);
            for (const auto& contact : results) {
                cout << contact.name << " " << contact.phone << " " << contact.email << endl;
            }
        } else if (option == 4) {
            phonebook.display_all_contacts();
        } else if (option == 5) {
            break;
        } else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}