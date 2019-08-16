#include <iostream>
#include <map>
#include <cstdint>
#include <tuple>
#include <random>

//stable bucket sort??
//forgotten technology.

/** /
typedef std::tuple<std::uint64_t, std::uint64_t> Data;

bool operator<(const Data& A, const Data& B) {
	return std::get<0>(A) < std::get<0>(B);
}
/**/
typedef std::multimap<std::uint64_t, std::uint64_t> MM;

MM MakeMM(std::size_t N,unsigned int Seed) {

	MM M;
	std::minstd_rand mr(Seed);

	std::uniform_int_distribution<> UI(0, 7);

	for (std::size_t i = 0; i < N; i++) {
		M.insert(std::make_pair( UI(mr), UI(mr)));
	}
	return M;
}

int main() {

	auto M = MakeMM(128, 0);

	for (auto& o : M) {
		std::cout << o.first << ':' << o.second << std::endl;
	}

	return 0;
}