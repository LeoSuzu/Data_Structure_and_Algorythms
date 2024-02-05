#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class StockTransaction {
public:
    std::string month;
    int shares;
    int price;

    StockTransaction(std::string m, int s, int p) : month(m), shares(s), price(p) {}
};

int main() {
    std::vector<StockTransaction> transactions = {
            {"buy", 100, 10},
            {"buy", 100, 30},
            {"sell", 100, 20},
            {"buy", 100, 50},
            {"sell", 100, 30}
    };

    std::vector<std::pair<int, int>> stockOwned;
    int fifoResult = 0;
    int lifoResult = 0;

    for (auto& transaction : transactions) {
        if (transaction.month == "buy") {
            stockOwned.push_back(std::make_pair(transaction.shares, transaction.price));
        } else if (transaction.month == "sell") {
            // FIFO
            while (transaction.shares > 0 && !stockOwned.empty()) {
                auto& [sharesOwned, purchasePrice] = stockOwned.front();
                int soldShares = std::min(sharesOwned, transaction.shares);
                fifoResult += soldShares * (transaction.price - purchasePrice);
                transaction.shares -= soldShares;

                if (sharesOwned > soldShares) {
                    stockOwned.front() = std::make_pair(sharesOwned - soldShares, purchasePrice);
                } else {
                    stockOwned.erase(stockOwned.begin());
                }
            }

            // LIFO
            while (transaction.shares > 0 && !stockOwned.empty()) {
                auto& [sharesOwned, purchasePrice] = stockOwned.back();
                int soldShares = std::min(sharesOwned, transaction.shares);
                lifoResult += soldShares * (transaction.price - purchasePrice);
                transaction.shares -= soldShares;

                if (sharesOwned > soldShares) {
                    stockOwned.back() = std::make_pair(sharesOwned - soldShares, purchasePrice);
                } else {
                    stockOwned.pop_back();
                }
            }
        }
    }

    std::cout << "Total Capital Gain/Loss using FIFO: $" << fifoResult << std::endl;
    std::cout << "Total Capital Gain/Loss using LIFO: $" << lifoResult << std::endl;

    return 0;
}
