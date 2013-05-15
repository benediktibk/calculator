#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "operatortree.h"

class MainWindow :
		public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private slots:
    void digitClicked();
    void dotClicked();

    void equalClicked();

    void clearAllClicked();
    void backspaceClicked();
    void exitClicked();

private:
    Ui::MainWindow* m_ui;
    void connectButtons();

    QLineEdit *input;
    QLineEdit *display;
};

#endif
