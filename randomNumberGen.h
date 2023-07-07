#include <random>

class randomNumberGen {     // The class
	public:           // Access specifier
		randomNumberGen(int number_max) {     // Constructor
			a = number_max;
		}

		int getNumber(){
			std::default_random_engine e1(r());
			std::uniform_int_distribution<int> uniform_dist(-1*a,a);
			return uniform_dist(e1);
		}

		std::random_device r;
		int a = 0;
};
