#include "../include/main.hpp"


int main() {
#if WIN32
	setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
	std::cout << "\tСтруктурные шаблоны: Proxy, Decorator, Adapter\n\n" << std::endl;
	
	auto real_db = VeryHeavyDatabase();
	auto cached_db = CacheProxyDB(std::addressof(real_db));
	auto test_db = TestDB(std::addressof(real_db));
	std::cout << cached_db.GetData("key") << std::endl;
	std::cout << cached_db.GetData("key") << std::endl;
	std::cout << test_db.GetData("key") << std::endl << std::endl;

	std::cout << "-----------------------------------------\n" << std::endl;

	auto real_db2 = VeryHeavyDatabase();
	auto limit_db2 = OneShotDB(std::addressof(real_db2), 2);
	std::cout << limit_db2.GetData("key") << std::endl;
	std::cout << limit_db2.GetData("key") << std::endl;
	std::cout << limit_db2.GetData("key") << std::endl;
	std::cout << limit_db2.GetData("key") << std::endl;
	std::cout << limit_db2.GetData("key") << std::endl;
	std::cout << limit_db2.GetData("key") << std::endl;

	std::cin.get();
	return 0;
}
