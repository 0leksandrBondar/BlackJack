#include "playermodel.h"

#include "model/cardsuit.h"

PlayerModel::PlayerModel() {}

int PlayerModel::score() const { return _score; }

void PlayerModel::resetScore() { _score = 0; }

int PlayerModel::balance() const { return _balance; }

void PlayerModel::updateBalance(int value) { _balance = value; }

void PlayerModel::addCard(std::shared_ptr<AbstractCard> cardValue)
{
    _cards.push_back(cardValue);
    calculateScore();
}

std::vector<std::shared_ptr<AbstractCard>> PlayerModel::cards() const { return _cards; }

void PlayerModel::calculateScore()
{
    resetScore();
    int aceValue;
    for (const auto &card : _cards)
    {
        if (card->cardVisible())
        {
            if (_score > 10)
                aceValue = 1;
            else
                aceValue = 11;
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
            case CardValue::Jack:
            case CardValue::Queen:
            case CardValue::King:
                _score += 10;
                break;
            case CardValue::Ace:
                _score += aceValue;
                break;
            case CardValue::Undefined:
                break;
            }
        }
    }
}

void PlayerModel::clear() { _cards.clear(); }
