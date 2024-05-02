#include <iostream>
#include <string>
#include <array> 
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class PharmacyData {
public:
    struct Drug {
        string code;
        string name;
        int quantity;
        float price;
    };

private:
    static const int ARRAY_SIZE = 20; // Constant for array Max size
    array<Drug, ARRAY_SIZE> data; // An array of Drug structures
    int lastIndex = -1; // Variable to keep track of the last inserted index
    string filename_path = "C:/Users/MostafaPC/C_C_PlusPlus/data.csv"; // File path to save the data

public:
    // Constructor for PharmacyData to load data from a file into the array of Drugs
    PharmacyData() {
        readPharmacyData();
    }

    void readPharmacyData() {
        ifstream file(filename_path);
        string line;
        int index = 0;

        while (getline(file, line) && index < ARRAY_SIZE) {
            stringstream ss(line);
            string field;
            Drug drug;

            // Get code
            getline(ss, field, ',');
            drug.code = field;

            // Get name
            getline(ss, field, ',');
            drug.name = field;

            // Get quantity
            getline(ss, field, ',');
            drug.quantity = stoi(field);

            // Get price
            getline(ss, field, ',');
            drug.price = stof(field);

            // Add drug to array
            data[index++] = drug;
        }

        lastIndex = index - 1;
        file.close();
    }

    // Method to overwrite the data array to the CSV file
    void save() {
        ofstream file(filename_path);

        for (int i = 0; i <= lastIndex; ++i) {
            Drug& drug = data[i];
            file << drug.code << "," << drug.name << "," << drug.quantity << "," << drug.price << "\n";
        }

        file.close();
    }

    // Method to add new Drug to the array
    void add(Drug value) {
        if (lastIndex < ARRAY_SIZE - 1) {
            data[++lastIndex] = value;
        }
    }



    // Method to get a Drug from the array by code
    Drug get(string code) {
        for (int i = 0; i <= lastIndex; ++i) {
            if (data[i].code == code && data[i].quantity > 0) {
                data[i].quantity -= 1; // Decrease the quantity by 1
                return data[i];
            }
        }
        return Drug{}; // Return an empty Drug if code is not found
    }

    void returnDrug(string code) {
        for (int i = 0; i <= lastIndex; ++i) {
            if (data[i].code == code) {
                data[i].quantity += 1; // Increase the quantity by 1
            }
        }
    }

    // return the last index
    int getLastIndex() {
        return lastIndex;
    }

    //return total number of drugs
    int getTotalDrugs() {
        return lastIndex + 1;
    }
};


class Order {
private:
    PharmacyData pharmacyData;
    vector<PharmacyData::Drug> orderData; // Array of Drugs for the order

public:
    // Constructor for Order
    Order() {
        // Initialize pharmacyData
        pharmacyData = PharmacyData();
    }

    // Method to add a Drug to the order
    void addDrug(string code) {
        PharmacyData::Drug drug = pharmacyData.get(code);
        orderData.push_back(drug); // Add the drug to the order
    }

    // Method to remove a Drug from the order
    void removeDrug(string code) {
        for (int i = 0; i < orderData.size(); ++i) {
            if (orderData[i].code == code) {
                orderData.erase(orderData.begin() + i); // Remove the drug from the order
                pharmacyData.returnDrug(code); // Return the drug to the pharmacy
                break;
            }
        }
    }

    // Method to get the total price of the order
    float getTotalPrice() {
        float total = 0;

        for (int i = 0; i < orderData.size(); ++i) {
            total += orderData[i].price ;
        }

        return total;
    }

    // Method to checkout the order. This will complete the order and save the data to the file
    void checkout() {
        for (int i = 0; i < orderData.size(); ++i) {
            //print the order
            cout << orderData[i].code << " " << orderData[i].name << " " << orderData[i].price << endl;
        }
        //print the total price
        cout << "Total Price: " << getTotalPrice() << endl;
        pharmacyData.save(); // Save the data to the file
        orderData.clear(); // Clear the order
    }
    
    //Method to return the order to pharmacy and clear it
    void cancelOrder() {
        for (int i = 0; i < orderData.size(); ++i) {
            pharmacyData.returnDrug(orderData[i].code); // Return the drug to the pharmacy
        }
        orderData.clear(); // Clear the order
    }




};

int main() {
  PharmacyData pharmacyData;

  cout << pharmacyData.getLastIndex() << endl;
  cout<<"Hello World" << endl;
  //cout << pharmacyData.get("AMO").name <<endl ;
  pharmacyData.add(PharmacyData::Drug{"ZAN", "Zantac", 100, 105.5});
  pharmacyData.save();
  cout << pharmacyData.getLastIndex() << endl;
  cout << "total drugs: " << pharmacyData.getTotalDrugs() << endl;
  

/*Order order;
order.addDrug("AMO");
order.addDrug("CIP");
order.checkout();*/
  return 0;
}