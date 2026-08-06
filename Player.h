#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int wallet{100}; // Player's initial gold amount
public:
    Player(int initialWallet = 100) : wallet(initialWallet) {}
    auto getWallet() const -> int { return wallet; }
    auto deductFromWallet(int amount) -> void { wallet -= amount; }
};

#endif