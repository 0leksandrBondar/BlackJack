#include "playermodel.h"

#include "model/cardsuit.h"

PlayerModel::PlayerModel() {}

int PlayerModel::score() const { return _score; }

void PlayerModel::addCard(AbstractCard *cardValue)
{
    _cards.push_back(cardValue);
    calculateScore();
}

std::vector<AbstractCard *> PlayerModel::cards() const { return _cards; }

void PlayerModel::calculateScore()
{
    _score = 0;
    int value;
    for (const auto card : _cards)
    {
        if (card->cardVisible())
        {
            if (_score > 10)
                value = 10;
            else
                value = 1;
            switch (card->cardType().second)
            {
            case CardValue::Two:
                _score += 2;
                break;
            case CardValue::Three:
                _score += 3;
                break;
            case CardValue::Four:
                _score += 4;
                break;
            case CardValue::Five:
                _score += 5;
                break;
            case CardValue::Six:
                _score += 6;
                break;
            case CardValue::Seven:
                _score += 7;
                break;
            case CardValue::Eight:
                _score += 8;
                break;
            case CardValue::Nine:
                _score += 9;
                break;
            case CardValue::Ten:
                _score += 10;
                break;
            case CardValue::Jack:
                _score += 10;
                break;
            case CardValue::Queen:
                _score += 10;
                break;
            case CardValue::King:
                _score += 10;
                break;
            case CardValue::Ace:
                _score += value;
                break;
            case CardValue::Undefined:
                break;
            }
        }
    }
}
