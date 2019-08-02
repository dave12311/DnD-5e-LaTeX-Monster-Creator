#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>

class Monster : public QObject{
	Q_OBJECT

public:
	Monster();
	~Monster();

private:
	QString latexString;
	QList<QString> *inputListPointer;

public slots:
	//Textbox changed, regenerate latex
	void updateLatex();

	//Receive input data
	void receiveListPointer(QList<QString> *list);

signals:
	//Display text in GUI
	void sendText(QString *text);

	//Request input data
	void requestListPointer();
};

#endif // MONSTER_H
