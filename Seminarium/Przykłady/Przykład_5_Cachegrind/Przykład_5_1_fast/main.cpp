// Źródło: http://valgrind.org/docs/phd2004.pdf

int main() {
	int a[1024][1024];

	for (int h = 0; h < 10; ++h) {
		for (int i = 0; i < 1024; ++i) {
			for (int j = 0; j < 1024; ++j) {
				a[i][j] = 0;
			}
		}
	}

	return 0;
}