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
    input->setFocus();
    m_ui->divisionButton->setText(tr("\367"));
    m_ui->multiplicateButton->setText(tr("\327"));

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

    connect(m_ui->exponentialButton, SIGNAL(clicked()), this, SLOT(unaryOperatorClicked()));
    connect(m_ui->sinButton, SIGNAL(clicked()), this, SLOT(unaryOperatorClicked()));
    connect(m_ui->cosButton, SIGNAL(clicked()), this, SLOT(unaryOperatorClicked()));
    connect(m_ui->tanButton, SIGNAL(clicked()), this, SLOT(unaryOperatorClicked()));

	connect(m_ui->equalButton, SIGNAL(clicked()), this, SLOT(equalClicked()));
	connect(m_ui->inputLineEdit, SIGNAL(returnPressed()), this, SLOT(equalClicked()));
}


void MainWindow::insertStringToInputAtCurrentCursorPosition(const QString &insertText)
{
    QString inputText = input->text();
    int cursorPosition = input->cursorPosition();

    inputText.insert(cursorPosition, insertText);
    input->setText(inputText);
    input->setFocus();
    input->setCursorPosition(cursorPosition + insertText.length());
}

void MainWindow::digitClicked()
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    insertStringToInputAtCurrentCursorPosition(clickedButton->text());
}

void MainWindow::dotClicked()
{
    QString clickedOperator = tr(".");

    insertStringToInputAtCurrentCursorPosition(clickedOperator);
}

void MainWindow::operatorClicked()
{
	QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
	QString clickedOperator = clickedButton->text();

    if (clickedOperator == tr("\327"))
        clickedOperator = tr("*");
    else if (clickedOperator == tr("\367"))
        clickedOperator = tr("/");

    insertStringToInputAtCurrentCursorPosition(clickedOperator);
}

void MainWindow::unaryOperatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    clickedOperator += tr("(");

    insertStringToInputAtCurrentCursorPosition(clickedOperator);
}

void MainWindow::equalClicked()
{
	const std::string myCalculationString(input->text().toStdString());
	bool error;

	OperatorTree myCalculation(myCalculationString);

	if (myCalculation.parsingFailed())
        display->setText(tr("Syntax Error!"));
	else
    {
        double result;
        result = myCalculation.calculateValue(error);
        if (error)
            display->setText(tr("Math Error!"));
        else
            display->setText(QString::number(result));

    }
}

void MainWindow::backspaceClicked()
{
	QString text = input->text();
    int cursorPosition = input->cursorPosition();

	if (text.isEmpty())
		return;

    text.remove(cursorPosition -1, 1);
	input->setText(text);
    input->setFocus();
    input->setCursorPosition(cursorPosition - 1);

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
