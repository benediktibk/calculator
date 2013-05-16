#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QMainWindow>

namespace Ui
{
	class MainWindow;
}
class QLineEdit;

class MainWindow :
		public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private slots:
	void digitClicked();
	void dotClicked();
	void operatorClicked();
    void unaryOperatorClicked();

	void equalClicked();

	void clearAllClicked();
	void backspaceClicked();
	void exitClicked();

private:
	void connectButtons();

private:
	Ui::MainWindow* m_ui;
	QLineEdit *input;
	QLineEdit *display;
};

#endif
