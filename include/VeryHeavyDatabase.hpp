#pragma once

#include <map>
#include <string>
#include <iostream>


class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};

class CacheProxyDB : VeryHeavyDatabase {
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object) : mp_real_db(real_object) {}
    std::string GetData(const std::string& key) noexcept;

private:
    std::map<std::string, std::string> m_cache;
    VeryHeavyDatabase* mp_real_db;
};

class TestDB : VeryHeavyDatabase {
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : mp_real_db(real_object) {}
    std::string GetData(const std::string& key) noexcept;

private:
    VeryHeavyDatabase* mp_real_db;
};

class OneShotDB : VeryHeavyDatabase {
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1) : mp_real_db(real_object), m_shots(shots) {}
    std::string GetData(const std::string& key) noexcept;

private:
    VeryHeavyDatabase* mp_real_db;
    size_t m_shots;
};