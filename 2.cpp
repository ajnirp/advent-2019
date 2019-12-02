#include <iostream>
#include <fstream>
#include <vector>

// Run the program and return the value at position 0
int run_program(std::vector<int>& program, int seed1, int seed2) {
	program[1] = seed1;
	program[2] = seed2;
	int instruction_ptr = 0;
	while (instruction_ptr < program.size()) {
		switch (program[instruction_ptr]) {
			case 1: {
				program[program[instruction_ptr+3]] = program[program[instruction_ptr+1]] + program[program[instruction_ptr+2]];
				break;
			}
			case 2: {
				program[program[instruction_ptr+3]] = program[program[instruction_ptr+1]] * program[program[instruction_ptr+2]];
				break;
			}
			case 99:
				return program[0];
			default:
				break;
		}
		instruction_ptr += 4;
	}
	return program[0];
}

// Given an archived program, find the two seeds that when placed in positions 1 and 2 will halt the program
// with 19690720 at position 0
void find_inputs(const std::vector<int>& archived_program, int& seed1, int& seed2) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			std::vector<int> program = archived_program;
			program[1] = i;
			program[2] = j;
			if (run_program(program, i, j) == 19690720) {
				seed1 = i;
				seed2 = j;
				return;
			}
		}
	}
}

int main() {
	std::ifstream input_file("2.txt");
	char comma;
	int data;
	std::vector<int> archived_program;
	while (input_file >> data) {
		archived_program.push_back(data);
		if (not(input_file >> comma)) {
			break;
		}
	}
	std::vector<int> program = archived_program;
	std::cout << "value at position 0: " << run_program(program, 12, 2) << std::endl;

	int seed1_result = 0;
	int seed2_result = 0;
	find_inputs(archived_program, seed1_result, seed2_result);
	std::cout << "seeds: " << seed1_result << seed2_result << std::endl;

	return 0;
}