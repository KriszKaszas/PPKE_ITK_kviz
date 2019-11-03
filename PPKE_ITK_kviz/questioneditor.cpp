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
