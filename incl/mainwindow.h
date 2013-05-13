#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow :
		public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private:
	Ui_MainWindow m_ui;
};

#endif
