#include "../include/VeryHeavyDatabase.hpp"


std::string CacheProxyDB::GetData(const std::string& key) noexcept {
    if (m_cache.find(key) == m_cache.end()) {
        std::cout << "Get from real object\n";
        m_cache[key] = mp_real_db->GetData(key);
    }
    else {
        std::cout << "Get from cache\n";
    }
    return m_cache.at(key);
}

std::string TestDB::GetData(const std::string& key) noexcept {
    return "test_data\n";
}

std::string OneShotDB::GetData(const std::string& key) noexcept {
    if (m_shots != 0) {
        m_shots--;
        return mp_real_db->GetData(key) + "\n";
    }
    else {
        return "error\n";
    }
}
