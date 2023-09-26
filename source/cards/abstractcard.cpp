#include "abstractcard.h"

#include "dialogWindows/settingwindow.h"
#include "model/cardmodel.h"

#include <QPixmap>
#include <Qpainter>

AbstractCard::AbstractCard(std::pair<CardSuit, CardValue> carType, QString path, QGraphicsItem* parent)
	: QGraphicsItem(parent)
	, _pathImage(path)
	, _cardModel{std::make_unique<CardModel>(carType.first, carType.second, QRectF(0, 0, 110, 160))}
{
}

QRectF AbstractCard::boundingRect() const
{
	return _cardModel.get()->boundingRect();
}

std::pair<CardSuit, CardValue> AbstractCard::cardType() const
{
	return _cardModel.get()->card();
}

void AbstractCard::setCardVisible(bool visible)
{
	_cardModel->setCardVisible(visible);
}

bool AbstractCard::cardVisible() const
{
	return _cardModel->cardVisible();
}

void AbstractCard::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	const QRect rect{boundingRect().toRect()};
	QString folderName;
	if (_isThemeChanged == CardTheme::WhiteTheme)
	{
		folderName = QStringLiteral("whiteCards");
	}
	if (_isThemeChanged == CardTheme::DarkTheme)
	{
		folderName = QStringLiteral("darkCards");
	}

	const auto fullPath = QStringLiteral(":/%1/%2").arg(folderName).arg(_pathImage);
	const auto pathToImage = _cardModel->cardVisible() ? fullPath : _pathBackImage;
	QPixmap pixmap(pathToImage);
	if (pixmap.isNull())
	{
		qDebug() << pathToImage;
		return;
	}

	painter->setBrush(pixmap);
	painter->setPen(Qt::black);
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawPixmap(rect, pixmap);
}

void AbstractCard::setCardTheme(CardTheme theme)
{
	_isThemeChanged = theme;
}

CardTheme AbstractCard::isThemeChanged() const
{
	return _isThemeChanged;
}
