#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QMainWindow>
#include <vector>
#include <string>

using namespace std;

namespace Ui
{
	class MainWindow;
}
class QLineEdit;
class QTextEdit;

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
    void clearClicked();
	void clearAllClicked();
	void backspaceClicked();
	void exitClicked();
    void clearHistoryClicked();

private:
    void connectButtons();
    void insertStringToInputAtCurrentCursorPosition(const QString &insertText);

private:
    Ui::MainWindow* m_ui;
	QLineEdit *input;
	QLineEdit *display;
    QTextEdit *history;

    double m_lastAnswer;
};

#endif
