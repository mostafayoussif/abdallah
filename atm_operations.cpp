#include <iostream>

using namespace std;
int main() {
    int i=0, x, y, z, c, a, b, choice, password;
    int balance = 10000;
    char yes_no;
    start:
    cout << "Enter your password: ";
    cin >> password;
    if (password == 6270) {
        while (i < 6) {
            cout << "\n         Menu         \n";
            cout << "1-Show my balance\n";
            cout << "2-Deposit\n";
            cout << "3-Withdrawal\n";
            cout << "4-Transfer money\n";
            cout << "5-Make a payment\n";
            cout << "6-Exit\n";
            cout << "\nEnter your choice: ";

            cin >> choice;
            if(cin.fail()) {
                cin.clear(); // clear the error flags
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
                cout << "Error! You entered a non-numeric value.";
                continue;
            } 

            switch (choice) {
            case 1:
                cout << "Your balance is " << balance;
                break;
            case 2:
                cout << "How much you want to deposit: ";
                cin >> x;
                if(cin.fail()) {
                    cin.clear(); // clear the error flags
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
                    cout << "Error! You entered a non-numeric value.";
                    continue;
                }                 
                balance= balance + x;
                cout << "Your balance now is " << balance;
                break;
            case 3:
                cout << "How much money you want to withdraw: ";
                cin >> y;
                if(cin.fail()) {
                    cin.clear(); // clear the error flags
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
                    cout << "Error! You entered a non-numeric value.";
                    continue;
                }                 
                if (y > balance) {
                    cout << "Error!  your balance is less than  " << y;
                } else {
                    balance = balance - y;
                    cout << "Your balance now is " << balance;
                }
                break;
            case 4:
                cout << "How much you want to transfer: ";
                cin >> z;
                if (z > balance) {
                    cout << "Error! your balance is less than " << z;
                } else {
                    cout << "Enter card number you want to trasfer to: ";
                    cin >> c;
                    if(cin.fail()) {
                        cin.clear(); // clear the error flags
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
                        cout << "Error! You entered a non-numeric value.";
                        continue;
                    } 
                    
                    balance=balance-z;
                    cout << "You have transfered " << (z) << " to person who have card number " << (c) << " and your balance now is " << balance ;
                }
                break;
            case 5:
                cout << "How much you want to pay: ";
                cin >> a;

                if(cin.fail()) {
                    cin.clear(); // clear the error flags
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
                    cout << "Error! You entered a non-numeric value.";
                    continue;
                }                 

                if (a > balance) {
                    cout << "Error! your balance is less than " << a;
                } else {
                    cout << "Enter card number you want to pay to ";
                    cin >> b;

                    if(cin.fail()) {
                        cin.clear(); // clear the error flags
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
                        cout << "Error! You entered a non-numeric value.";
                        continue;
                    }                     
                    balance = balance - a;
                    cout << "You have payed " << (a) << " for person who have card number " << (b) << " and your balance now is " << balance;
                }
                break;
            case 6:
                cout << "Thank you.\n";
                return 0;
            default:
                cout << "Error! You entered wrong number.";
                break;
            }

            cout << "\nDo you want to do other operation? (y / n)";
            
            cin >> yes_no;

            switch (yes_no) {
            case 'Y':
                i = 1;
                break;
            case 'y':
                i = 1;
                break;
            case 'N':
                i = 0;
                break;
            case 'n':
                i = 0;
                break;
            }
        }
    } else {
        cout << "your password is wrong! \n if you want to try again press (y) for yes or (n) for no. ";
        char yes_or_no;
        cin >> (yes_or_no);
        switch (yes_or_no) {
        case 'Y':
            i = 1;
            break;
        case 'y':
            i = 1;
            break;
        case 'N':
            i = 0;
            break;
        case 'n':
            i = 0;
            break;
        }
        if (i == 1) {
            goto start;
        } else {
            cout << "Thank you.\n";
            return 0;
        }
    }
    return 0;
}