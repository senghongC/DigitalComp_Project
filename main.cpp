#include <iostream>
#include <string>
using namespace std;

int main() {
    double height, length, width, weight;
    string fragile;
    double distance, distanceKm;
    double perKmRate = 0.0;
    double fragileFee = 5.0;
    double deliveryFee;
    double baseFee = 0.0;
    string vehicleType = "Not Available";

    // Get package details
    cout << "Enter item height (cm): ";
    cin >> height;
    cout << "Enter item length (cm): ";
    cin >> length;
    cout << "Enter item width (cm): ";
    cin >> width;
    cout << "Enter item weight (kg): ";
    cin >> weight;

    // Fragile input
    cout << "Is the item fragile? (yes/no): ";
    cin >> fragile;

    // Distance input
    cout << "Enter distance value: ";
    cin >> distance;

    // ===== Vehicle Selection =====
    if (weight >= 2 && weight <= 10 &&
        length <= 40 && width <= 40 && height <= 40) {
        vehicleType = "Motorcycle";
        baseFee = 5.0;
        perKmRate = 2.0;
    } else if (weight <= 40 &&
               length <= 50 && width <= 50 && height <= 50) {
        vehicleType = "Car";
        baseFee = 10.0;
        perKmRate = 3.0;
    } else if (weight <= 250 &&
               length <= 120 && width <= 91 && height <= 91) {
        vehicleType = "4x4 Pickup";
        baseFee = 15.0;
        perKmRate = 4.0;
    } else if (weight <= 500 &&
               length <= 170 && width <= 100 && height <= 120) {
        vehicleType = "Van (7-ft)";
        baseFee = 20.0;
        perKmRate = 5.0;
    } else if (weight <= 800 &&
               length <= 270 && width <= 130 && height <= 120) {
        vehicleType = "Large Van (9-ft)";
        baseFee = 25.0;
        perKmRate = 6.0;
    } else if (weight <= 1000 &&
               length <= 290 && width <= 140 && height <= 170) {
        vehicleType = "Small Lorry (10-ft)";
        baseFee = 30.0;
        perKmRate = 8.0;
    } else if (weight <= 2500 &&
               length <= 427 && width <= 220 && height <= 213) {
        vehicleType = "Medium Lorry (14-ft)";
        baseFee = 40.0;
        perKmRate = 10.0;
    } else if (weight <= 12000 &&
               length <= 510 && width <= 200 && height <= 210) {
        vehicleType = "Large Lorry (17-ft+)";
        baseFee = 50.0;
        perKmRate = 12.0;
    } else {
        vehicleType = "Not Available - Exceeds Lalamove limits";
        baseFee = 0.0;
        perKmRate = 0.0;
    }

    // Delivery fee calculation
    if (perKmRate > 0) {
        deliveryFee = baseFee + (distance * perKmRate);
    } else {
        deliveryFee = 0.0;
    }

    // Show result
    cout << "\n==== Delivery Summary ====" << endl;
    cout << "Dimensions (cm): " << height << " x " << length << " x " << width << endl;
    cout << "Weight (kg): " << weight << endl;
    cout << "Fragile: " << fragile << endl;
    cout << "Distance: " << distanceKm << " km" << endl;
    cout << "Assigned Vehicle: " << vehicleType << endl;

    if (perKmRate > 0)
        cout << "Base Fee: RM " << baseFee << "\nPer Km Rate: RM " << perKmRate
             << "\nDelivery Fee: RM " << deliveryFee << endl;
    else
        cout << "Delivery Fee: N/A (Item cannot be delivered)" << endl;

    // ===== Confirmation Step =====
    string confirm;
    if (perKmRate > 0) {
        cout << "\nDo you want to confirm the order? (yes/no): ";
        cin >> confirm;

        if (confirm == "yes" || confirm == "Yes") {
            cout << "Order Confirmed! Your " << vehicleType << " is on the way." << endl;
        } else {
            cout << "Order Cancelled. No vehicle has been booked." << endl;
        }
    }

    return 0;
}
