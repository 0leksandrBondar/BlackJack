#pragma once

#include "dialogWindows/settingwindow.h"

#include <QGraphicsItem>
#include <memory>

class CardModel;
enum class CardSuit;
enum class CardValue;

class AbstractCard : public QGraphicsItem
{
public:
	AbstractCard(std::pair<CardSuit, CardValue> carType, QString path, QGraphicsItem* parent = nullptr);

	QRectF boundingRect() const override;

	std::pair<CardSuit, CardValue> cardType() const;

	void setCardVisible(bool visible);
	bool cardVisible() const;
	void setCardTheme(CardTheme theme);
	CardTheme isThemeChanged() const;

protected:
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
	QString _pathImage;
	CardTheme _cardTheme;
	QString _pathBackImage{QStringLiteral(":/whiteCards/back.png")};
	std::unique_ptr<CardModel> _cardModel;
};
