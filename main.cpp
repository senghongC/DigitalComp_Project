#include <iostream>
#include <string>
using namespace std;

int main() {
    double height, length, width, weight;
    string fragile, unit;
    double distance, distanceKm;
    double baseFee = 5.0;   // base fee RM
    double perKmRate = 2.0; // fee per km
    double fragileFee = 5.0;
    double deliveryFee;

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
    cout << "Is this in km or m? (km/m): ";
    cin >> unit;

    // Convert to km if needed
    if (unit == "m" || unit == "M") {
        distanceKm = distance / 1000.0;
    } else {
        distanceKm = distance;
    }

    // Categorize package by weight
    if (weight <= 5) {
        perKmRate = 2.0;  // small package
    } else if (weight <= 20) {
        perKmRate = 3.5;  // medium package
    } else {
        perKmRate = 5.0;  // large package
    }

    // Delivery fee calculation
    deliveryFee = baseFee + (distanceKm * perKmRate);

    if (fragile == "yes" || fragile == "Yes") {
        deliveryFee += fragileFee;
    }

    // Show result
    cout << "\n==== Delivery Summary ====" << endl;
    cout << "Dimensions (cm): " << height << " x " << length << " x " << width << endl;
    cout << "Weight (kg): " << weight << endl;
    cout << "Fragile: " << fragile << endl;
    cout << "Distance: " << distanceKm << " km" << endl;
    cout << "Delivery Fee: RM " << deliveryFee << endl;

    return 0;
}
