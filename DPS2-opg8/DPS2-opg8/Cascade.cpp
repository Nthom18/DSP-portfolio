#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

# define PI 3.14159265358979323846  /* pi */

class Cascade
{
public:
	Cascade() {};
	~Cascade() {};
	Cascade(int l) {
		std::ofstream outputFile;

		std::vector<double> input;
		std::vector<double> output1;
		std::vector<double> output2;
		std::vector<double> output;

		for (size_t t = 0; t < l; t++) {
			// Test signal as input
			input.push_back(sin(2*PI*t));
			
			// Samples through H_1(z)
			output1.push_back(H1(input[t]));

			// Samples through H_2(z)
			output2.push_back(H2(output1[t]));

			// Combine H_1(z) & H_2(z) to give output
			output.push_back(output1[t] * output2[t]);

			// Write to .csv file
			outputFile.open("output.csv");
			if (t != 0) {
				outputFile << "," << output[t];
			}
			else {
				outputFile << output[t];
			}
		}
	}
	double H1(double in) {
		double out = in;
		return out;
	}
	double H2(double in) {
		double out = in;
		return out;
	}
};