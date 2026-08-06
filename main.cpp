#include <iostream>
#include <string_view>
#include <array>
#include <algorithm> // for std::shuffle
#include "Random.h"
struct Card
{
    enum Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_rank
    };
    enum Suit
    {
        suit_clubs,
        suit_diamonds,
        suit_hearts,
        suit_spades,

        max_suit
    };

    Rank rank{};
    Suit suit{};

    // void setRank(Rank r) { rank = r; }
    // void setSuit(Suit s) { suit = s; }

    static constexpr std::array<Rank, max_rank> all_ranks{rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king};
    static constexpr std::array<Suit, max_suit> all_suits{suit_clubs, suit_diamonds, suit_hearts, suit_spades};

    static std::string_view rank_string(Rank rank)
    {
        switch (rank)
        {
        case rank_2:
            return "2";
        case rank_3:
            return "3";
        case rank_4:
            return "4";
        case rank_5:
            return "5";
        case rank_6:
            return "6";
        case rank_7:
            return "7";
        case rank_8:
            return "8";
        case rank_9:
            return "9";
        case rank_10:
            return "10";
        case rank_jack:
            return "J";
        case rank_queen:
            return "Q";
        case rank_king:
            return "K";
        case rank_ace:
            return "A";
        default:
            return "?";
        }
    }

    static std::string_view suit_string(Suit suit)
    {
        switch (suit)
        {
        case suit_clubs:
            return "C";
        case suit_diamonds:
            return "D";
        case suit_hearts:
            return "H";
        case suit_spades:
            return "S";
        default:
            return "?";
        }
    }

    static int card_value(Card &card)
    {
        switch (card.rank)
        {
        case rank_2:
            return 2;
        case rank_3:
            return 3;
        case rank_4:
            return 4;
        case rank_5:
            return 5;
        case rank_6:
            return 6;
        case rank_7:
            return 7;
        case rank_8:
            return 8;
        case rank_9:
            return 9;
        case rank_10:
        case rank_jack:
        case rank_queen:
        case rank_king:
            return 10;
        case rank_ace:
            return 11;
        default:
            return 0;
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const Card &card)
    {
        out << rank_string(card.rank) << suit_string(card.suit);
        return out;
    }
};

class Deck
{
private:
    std::array<Card, 52> cards{};
    int cards_dealt{};

public:
    Deck()
    {
        int index{};
        for (auto suit : Card::all_suits)
            for (auto rank : Card::all_ranks)
            {
                cards[static_cast<std::size_t>(index++)] = Card{rank, suit};
            }
    }

    auto dealACard() -> Card &
    {
        return cards[static_cast<std::size_t>(cards_dealt++)];
    }

    auto shuffle() -> void
    {
        std::shuffle(cards.begin(), cards.end(), Random::mt);
        cards_dealt = 0;
    }
};

int main()
{
    Deck deck{};
    std::cout << deck.dealACard() << ' ' << deck.dealACard() << ' ' << deck.dealACard() << '\n';

    deck.shuffle();
    std::cout << deck.dealACard() << ' ' << deck.dealACard() << ' ' << deck.dealACard() << '\n';

    return 0;
}