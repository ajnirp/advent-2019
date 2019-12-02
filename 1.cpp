#include <fstream>
#include <iostream>
#include <string>

int calculate_fuel(int mass) {
	return (mass/3) - 2;
}

int calculate_fuel_recursive(int mass) {
	int total_fuel = 0;
	mass = calculate_fuel(mass);
	while (mass > 0) {
		total_fuel += mass;
		mass = calculate_fuel(mass);
	}
	return total_fuel;
}

int main() {
	std::ifstream input_file("1.txt");
	std::string line;
	int total_fuel = 0;
	int total_fuel_recursive = 0;
	while (std::getline(input_file, line)) {
		int mass = std::stoi(line);
		total_fuel += calculate_fuel(mass);
		total_fuel_recursive += calculate_fuel_recursive(mass);
	}
	std::cout << "total fuel: " << total_fuel << std::endl;
	std::cout << "total fuel recursive: " << total_fuel_recursive << std::endl;
	return 0;
}