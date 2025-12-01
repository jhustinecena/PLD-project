#include <iostream>
#include <limits>
using namespace std;

int main() {

    // simple data for the 4 items
    int id[4] = {1, 2, 3, 4};
    string name[4] = {"stick-o", "kape 3in1", "bread", "piattos"};
    double price[4] = {2.5, 2.0, 3.0, 5.5};
    int stock[4] = {10, 8, 5, 3};

    // cart
    int cartQty[4] = {0, 0, 0, 0};

    bool running = true;

    while (running) {
        cout << "\n=== tindahan ni aling nena ===\n";
        cout << "1 - Show items\n";
        cout << "2 - Add to cart\n";
        cout << "3 - View cart\n";
        cout << "4 - Checkout\n";
        cout << "5 - Exit\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        // basic fix if user types a letter
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a NUMBER only.\n";
            continue;
        }

        if (choice == 1) {

            cout << "\nID  Name        Price  Stock\n";
            for (int i = 0; i < 4; i++) {
                cout << id[i] << "   "
                     << name[i] << "   "
                     << price[i] << "     "
                     << stock[i] << endl;
            }

        } else if (choice == 2) {

            int itemId, qty;
            cout << "Enter item ID: ";
            cin >> itemId;

            // letter check
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter numbers only.\n";
                continue;
            }

            int index = itemId - 1;

            if (index < 0 || index >= 4) {
                cout << "Invalid ID.\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> qty;

            // letter check
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter numbers only.\n";
                continue;
            }

            if (qty <= 0) {
                cout << "Invalid quantity.\n";
            } else if (qty > stock[index]) {
                cout << "Not enough stock.\n";
            } else {
                cartQty[index] += qty;
                cout << "Added!\n";
            }

        } else if (choice == 3) {

            cout << "\n--- Cart ---\n";
            double total = 0;

            for (int i = 0; i < 4; i++) {
                if (cartQty[i] > 0) {
                    double line = cartQty[i] * price[i];
                    cout << cartQty[i] << " x " << name[i]
                         << " = " << line << endl;
                    total += line;
                }
            }

            cout << "Total: " << total << endl;

        } else if (choice == 4) {

            cout << "\n--- Receipt ---\n";
            double total = 0;

            for (int i = 0; i < 4; i++) {
                if (cartQty[i] > 0) {
                    double line = cartQty[i] * price[i];
                    cout << cartQty[i] << " x " << name[i]
                         << " = " << line << endl;
                    total += line;

                    // update stock
                    stock[i] -= cartQty[i];

                    // show new stock
                    cout << "New stock of " << name[i]
                         << ": " << stock[i] << endl;

                    cartQty[i] = 0;
                }
            }

            cout << "Total: " << total << endl;
            cout << "Thank you!\n";

        } else if (choice == 5) {

            running = false;

        } else {

            cout << "Invalid option.\n";

        }
    }

    cout << "Goodbye!\n";

    return 0;
}
