#ifndef BENCHMARKING_FUNCION_H
#define BENCHMARKING_FUNCTION_H
#include <iostream>
#include <chrono>

class benchmarkingFunction {
	public:
		benchmarkingFunction() : start(std::chrono::high_resolution_clock::now()) {}
		~benchmarkingFunction() {
			using namespace std::chrono;
			high_resolution_clock::time_point end = high_resolution_clock::now();
			std::cout << duration<double, std::milli>(end - start).count() << " ms" << std::endl;
		}
	private:
		std::chrono::high_resolution_clock::time_point start;
};
#endif // !BENCHMARKING_FUNCION_H

