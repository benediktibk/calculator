#include "mainwindow.h"
#include "operatortree.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow() :
	QMainWindow(0),
	m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);
	input = m_ui->inputLineEdit;
	display = m_ui->displayLineEdit;

	this->setFixedSize(550, 380);
	display->setText(tr("0"));

	connectButtons();
}

void MainWindow::connectButtons()
{
	connect(m_ui->backspaceButton, SIGNAL(clicked()), this, SLOT(backspaceClicked()));
	connect(m_ui->clearAllButton, SIGNAL(clicked()), this, SLOT(clearAllClicked()));
	connect(m_ui->exitButton, SIGNAL(clicked()), this, SLOT(exitClicked()));

	connect(m_ui->digit0Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit1Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit2Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit3Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit4Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit5Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit6Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit7Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit8Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->digit9Button, SIGNAL(clicked()), this, SLOT(digitClicked()));
	connect(m_ui->dotButton, SIGNAL(clicked()), this, SLOT(dotClicked()));

	connect(m_ui->additionButton, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(m_ui->multiplicateButton, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(m_ui->substractButton, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(m_ui->divisionButton, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(m_ui->potencyButton, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(m_ui->bracketOpenButton, SIGNAL(clicked()), this, SLOT(operatorClicked()));
	connect(m_ui->bracketCloseButton, SIGNAL(clicked()), this, SLOT(operatorClicked()));

	connect(m_ui->equalButton, SIGNAL(clicked()), this, SLOT(equalClicked()));
	connect(m_ui->inputLineEdit, SIGNAL(returnPressed()), this, SLOT(equalClicked()));
}

void MainWindow::digitClicked()
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
	int digitValue = clickedButton->text().toInt();

	input->setText(input->text() + QString::number(digitValue));
}

void MainWindow::dotClicked()
{
	input->setText(input->text() + ".");
}

void MainWindow::operatorClicked()
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
	QString clickedOperator = clickedButton->text();

	input->setText(input->text() + clickedOperator);
}

void MainWindow::equalClicked()
{
	const std::string myCalculationString(input->text().toStdString());

	OperatorTree myCalculation(myCalculationString);

	if (myCalculation.parsingFailed())
		display->setText(tr("Parsing failed"));
	else
		display->setText(QString::number(myCalculation.calculateValue()));
}

void MainWindow::backspaceClicked()
{
	QString text = input->text();

	if (text.isEmpty())
		return;

	text.chop(1);
	input->setText(text);
}

void MainWindow::clearAllClicked()
{
	display->setText("0");
	input->setText("");
}

void MainWindow::exitClicked()
{
	this->close();
}
