#include "playermodel.h"

PlayerModel::PlayerModel()
{

}

int PlayerModel::score() const
{
    return _score;
}

void PlayerModel::addCard(CardValue cardValue)
{
    _cardValues.push_back(cardValue);
    calculateScore();
}

void PlayerModel::calculateScore()
{
    for (const auto card : _cardValues)
    {
        switch (card)
        {
        case CardValue::Two:
            _score += 2;
        case CardValue::Three:
            _score += 3;
        case CardValue::Four:
            _score += 4;
        case CardValue::Five:
            _score += 5;
        case CardValue::Six:
            _score += 6;
        case CardValue::Seven:
            _score += 7;
        case CardValue::Eight:
            _score += 8;
        case CardValue::Nine:
            _score += 9;
        case CardValue::Ten:
            _score += 10;
        case CardValue::Jack:
            _score += 10;
        case CardValue::Queen:
            _score += 10;
        case CardValue::King:
            _score += 10;
        case CardValue::Ace:
            _score = _score > 10 ? 10 : 11;
        case CardValue::Undefined:
            break;
        }
    }
}
