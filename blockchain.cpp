#include <string>
#include <time>
#include <iostream>
#include <sstream>
#include "sha256.h"

class block {
public:
    std::string previous_hash;

    block(uint32_t i, const string &d) : index(i), data(d), nonce(-1), time(nullptr) {};

    const string& get_hash();

    void mine_block(uint32_t difficulty) {
       char cstr[difficulty + 1];
       for (uint32_t i = 0; i < nDifficulty; ++i) {
         cstr[i] = '0';
       }
       cstr[difficulty] = '\0';

       std::string str(cstr);

       do {
        nonce++;
        hash = calculate_hash();
      } while (hash.substr(0, difficulty) != str);
    };

private:
    std::uint32_t index;
    std::int64_t nonce;;
    std::string data;
    std::string hash;
    std::time_t time;

    std::string calculate_hash() const {
       std::stringstream ss;
       ss << index << time << data << nonce << previous_hash;

       return sha256(ss.str());
    };
};

class blockchain {
public:
    blockchain() {
      chain.emplace_back(block(0, "Genesis Block"));
      difficulty = 6;
    }

    void add_block(block b) {
       b.sPrevHash = get_last_block().GetHash();
       b.mine_block(_nDifficulty);
       v.push_back(b);
    };

private:
    uint32_t difficulty;;
    vector<block> chain;

    block& get_last_block() const {
     return v.back();
   };
};

int main() {
    blockchain chain; 

    std::cout << "Mining block 1..." << std::endl;
    chain.add_block(block(1, "Block 1 Data"));

    std::cout << "Mining block 2..." << std::endl;
    chain.add_block(block(2, "Block 2 Data"));

    std::cout << "Mining block 3..." << std::endl;
    chain.add_block(Block(3, "Block 3 Data"));

    return 0;
}
