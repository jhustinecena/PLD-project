#include <iostream>
using namespace std;

int main() {
    int id[4] = {1, 2, 3, 4};
    string name[4] = {"mang juan", "kape", "monay with peanut", "stick-o"};
    double price[4] = {2.5, 2.0, 3.0, 5.5};
    int stock[4] = {10, 8, 5, 3};

    int cartQty[4] = {0, 0, 0, 0};

    bool running = true;

    while (running) {
        cout << "\n=== tindahan ng mga alaala ===\n";
        cout << "1) Show items\n";
        cout << "2) Add to cart\n";
        cout << "3) View cart\n";
        cout << "4) Checkout\n";
        cout << "5) Exit\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "\nID  Name       Price  Stock\n";
            for (int i = 0; i < 4; i++) {
                cout << id[i] << "   "
                     << name[i] << "   "
                     << price[i] << "    "
                     << stock[i] << endl;
            }
        }
        else if (choice == 2) {
            int chooseId, qty;
            cout << "Enter item ID: ";
            cin >> chooseId;

            int index = chooseId - 1;

            if (index < 0 || index > 3) {
                cout << "Invalid item.\n";
                continue;
            }

            cout << "Enter quantity: ";
            cin >> qty;

            if (qty <= 0) {
                cout << "Invalid quantity.\n";
                continue;
            }

            if (qty > stock[index]) {
                cout << "Not enough stock.\n";
                continue;
            }

            cartQty[index] += qty;
            cout << "Added to cart!\n";
        }
        else if (choice == 3) {
            cout << "\nYour cart:\n";
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
        }
        else if (choice == 4) {
            cout << "\n--- Receipt ---\n";
            double total = 0;

            for (int i = 0; i < 4; i++) {
                if (cartQty[i] > 0) {
                    double line = cartQty[i] * price[i];
                    cout << cartQty[i] << " x " << name[i]
                         << " = " << line << endl;
                    total += line;

                    stock[i] -= cartQty[i];
                    cartQty[i] = 0;
                }
            }

            cout << "Total: " << total << endl;
            cout << "Thank you!\n";
        }
        else if (choice == 5) {
            running = false;
        }
        else {
            cout << "Invalid option.\n";
         }
    }

    cout << "Goodbye!\n";
    return 0;
}