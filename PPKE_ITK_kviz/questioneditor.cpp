#include "questioneditor.h"
#include "ui_questioneditor.h"

QuestionEditor::QuestionEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuestionEditor)
{
    ui->setupUi(this);
    currentQuestion = {"", "", "", "", "", ""};
    ui->correctAnswer->addItem("A");
    ui->correctAnswer->addItem("B");
    ui->correctAnswer->addItem("C");
    ui->correctAnswer->addItem("D");
}

QuestionEditor::~QuestionEditor()
{
    delete ui;
}

void QuestionEditor::PopulateCurrentQuestion(vector<QString> questionData)
{
    currentQuestion = questionData;
}

void QuestionEditor::ClearFields()
{
    ui->editQuestionName->clear();
    ui->editA->clear();
    ui->editB->clear();
    ui->editC->clear();
    ui->editD->clear();
    ui->correctAnswer->setCurrentIndex(0);

}

void QuestionEditor::ClearQuestions()
{
    currentQuestion[0] = "";
    currentQuestion[1] = "";
    currentQuestion[2] = "";
    currentQuestion[3] = "";
    currentQuestion[4] = "";
    currentQuestion[5] = "";
}

void QuestionEditor::PopulateInputFields()
{
    ui->editQuestionName->setText(currentQuestion[0]);
    ui->editA->setText(currentQuestion[1]);
    ui->editB->setText(currentQuestion[2]);
    ui->editC->setText(currentQuestion[3]);
    ui->editD->setText(currentQuestion[4]);
    if(currentQuestion[5] == "A")
    {
        ui->correctAnswer->setCurrentIndex(0);
    }
    if(currentQuestion[5] == "B")
    {
        ui->correctAnswer->setCurrentIndex(1);
    }
    if(currentQuestion[5] == "C")
    {
        ui->correctAnswer->setCurrentIndex(2);
    }
    if(currentQuestion[5] == "D")
    {
        ui->correctAnswer->setCurrentIndex(3);
    }
}

void QuestionEditor::RetrieveFieldData()
{
    currentQuestion[0] = ui->editQuestionName->text();
    currentQuestion[1] = ui->editA->text();
    currentQuestion[2] = ui->editB->text();
    currentQuestion[3] = ui->editC->text();
    currentQuestion[4] = ui->editD->text();
    currentQuestion[5] = ui->correctAnswer->currentText();
}

void QuestionEditor::on_cancelButton_clicked()
{
    this->close();
}

void QuestionEditor::on_okButton_clicked()
{
    RetrieveFieldData();
    ClearFields();
    this->close();
}

void QuestionEditor::closeEvent(QCloseEvent *event)
{
    emit closing();
}
