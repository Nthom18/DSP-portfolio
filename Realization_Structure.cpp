#include <iostream>
#include <vector>
#include <string>
class Realization_Structure
{
public:
	Realization_Structure() {};
	Realization_Structure(std::vector<double> Numerator, std::vector<double> Denominator) {
		for (double x : Numerator) { H_Numerator.push_back(x); }
		for (double x : Denominator) { H_Denominator.push_back(x); }
	};

	double x(double n) {  //delta function
		if (n == 0) 
			return 1;
		else
			return 0;
	}

	double W(double n) { //   w[n] = x[n] - a1*w[n-1] - a2 * w[n-2]...
		if (n < 0)
		{
			return 0;
		}
		else
		{
			double A = x(n), B = 0;			//x[n]
			for (size_t i = 1; i < H_Denominator.size(); i++)
			{
				B -= H_Denominator[i] * W(n - i);				//- a1*w[n-1] - a2 * w[n-2]...
			}
			return A + B;
		}
	}


	double DirectForm2(double n) {
		double res = 0;
		for (size_t i = 0; i < H_Numerator.size(); i++)
		{
			 res += H_Numerator[i] * W(n - i);
		}
		return res;
	};

	void PrintDirectForm2() {
	
		std::cout << "y(n) = ";
		for (size_t i = 0; i < H_Numerator.size(); i++)
		{
			if (H_Numerator[i] != 0)
			{
				std::cout << H_Numerator[i];
					if (i != 0)
					{
						std::cout << " * W(n - ";
						std::cout << i;
					}
					else
					{
						std::cout << " * W(n";
					}
					if (i < H_Numerator.size()-1)
					{
						if (H_Numerator[i+1] > 0)
						{
							std::cout << ") + ";
						}
						else
						{
							std::cout << ") ";
						}	
					}
					else
					{
						std::cout << ")"<<std::endl;
					}
			}	
		}
	};



	void DirectForm2Inteval(double n1, double n2) {
		PrintDirectForm2();
		for (size_t i = n1; i < n2; i++)
		{
			//std::cout << DirectForm2(i) << std::endl;
			yn.push_back(DirectForm2(i));
		}
		yn_length = yn.size();
	}

	double Cascade() {
	}

	double getYn(int &index) {
		return yn[index];
	}

	double yn_length=0;

	~Realization_Structure() {};

	std::vector<double> H_Numerator;
	std::vector<double> H_Denominator;
	std::vector<double> yn;
};