#include "questioneditor.h"
#include "ui_questioneditor.h"

QuestionEditor::QuestionEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuestionEditor)
{
    ui->setupUi(this);
}

QuestionEditor::~QuestionEditor()
{
    delete ui;
}

void QuestionEditor::populateCurrentQuestion(vector<QString> questionData)
{
    currentQuestion = questionData;
}

void QuestionEditor::populateInputFields()
{
    ui->editQuestionName->setText(currentQuestion[0]);
    ui->editA->setText(currentQuestion[1]);
    ui->editB->setText(currentQuestion[2]);
    ui->editC->setText(currentQuestion[3]);
    ui->editD->setText(currentQuestion[4]);
}

void QuestionEditor::on_cancelButton_clicked()
{
    this->close();
}
