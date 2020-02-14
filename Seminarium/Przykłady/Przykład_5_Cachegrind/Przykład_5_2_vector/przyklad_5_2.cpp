#include <vector>

using intContainer = std::vector<int>;

int main() {

	intContainer cont;
	for (int i = 0; i < 10000; ++i) {
		cont.push_back(i);
	}


	for (auto it = cont.begin(); it != cont.end(); ++it) {
		int temp = *it;
	}

}