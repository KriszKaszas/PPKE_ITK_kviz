#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    engine = new GameEngine();
    ui->selectedQuiz->setText(engine->quizGame->GetQuizTitle());
    SetGameLabels();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetGameLabels()
{
    ui->quizTitle->setText(engine->quizGame->GetQuizTitle());
    ui->questionNumber->setText(engine->quizGame->GetCurrentQuestionNumberToQString());
    ui->questionNumberFromTotal->setText(engine->quizGame->GetQuestionNumberFromTotalToString());
    ui->questionTitle->setText(engine->quizGame->GetNextQuizQuestion()[0]);
    ui->A->setText(engine->quizGame->GetNextQuizQuestion()[1]);
    ui->B->setText(engine->quizGame->GetNextQuizQuestion()[2]);
    ui->C->setText(engine->quizGame->GetNextQuizQuestion()[3]);
    ui->D->setText(engine->quizGame->GetNextQuizQuestion()[4]);
    ui->score->setText(engine->quizGame->GetScoreToQString());
}

void MainWindow::StartNewGame()
{
    if(ui->playerName->text() != "")
    {
        ui->stackedWidget->setCurrentIndex(2);
        SetGameLabels();
    }
    else
    {
        QMessageBox::warning(this, "HIBA!", "Kérjük, adjon meg egy játékosnevet!");
    }
}

void MainWindow::on_startGame_clicked()
{
    StartNewGame();
}


void MainWindow::on_nextQuestion_clicked()
{
    QString AnswerValue;
    if(ui->A->isChecked() || ui->B->isChecked() || ui->C->isChecked() || ui->D->isChecked())
    {
        if(ui->A->isChecked())
        {
            AnswerValue = "A";
            ui->A->setAutoExclusive(false);
            ui->A->setChecked(false);
            ui->A->setAutoExclusive(false);
        }
        if(ui->B->isChecked())
        {
            AnswerValue = "B";
            ui->B->setAutoExclusive(false);
            ui->B->setChecked(false);
            ui->B->setAutoExclusive(false);
        }
        if(ui->C->isChecked())
        {
            AnswerValue = "C";
            ui->C->setAutoExclusive(false);
            ui->C->setChecked(false);
            ui->C->setAutoExclusive(false);
        }
        if(ui->D->isChecked())
        {
            AnswerValue = "D";
            ui->D->setAutoExclusive(false);
            ui->D->setChecked(false);
            ui->D->setAutoExclusive(false);
        }
        engine->quizGame->Behavior(AnswerValue);
        if(!engine->quizGame->IsGameOver())
        {
            SetGameLabels();
        }
        else
        {
            ui->score->setText(engine->quizGame->GetScoreToQString());
            QString gameOverMessage = "Az Ön pontszáma: " + engine->quizGame->GetScoreToQString();
            QMessageBox::StandardButton reply =
                QMessageBox::information(this, "Vége a játéknak!", gameOverMessage);
            if (reply == QMessageBox::Ok)
            {
                engine->quizGame->ResetValues();
                ui->stackedWidget->setCurrentIndex(0);
            }

        }
    }
    else
    {
        QMessageBox::warning(this, "HIBA!", "A továbblépéshez jelölje ki az egyik választ!");
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionStartNewGame_triggered()
{
    StartNewGame();
}

void MainWindow::on_actionQuitCurrentGame_triggered()
{
    engine->quizGame->ResetValues();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionCreateNewQuiz_triggered()
{
    engine->quizGame->ResetValues();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_actionEditExistingQuiz_triggered()
{
    engine->quizGame->ResetValues();
    ui->stackedWidget->setCurrentIndex(1);
    ui->questionEditorTitle->setText(engine->quizGame->GetQuizTitle());
    for(int i=0; i<engine->quizGame->ReturnQuestionListLength(); i++)
    {
        ui->questionList->addItem(engine->quizGame->GetAllQuestions()[i][0]);
    }
        //TODO
    //Fix so that its self filling
}

void MainWindow::on_editQuestion_clicked()
{
    if(ui->questionList->count())
    {
        vector<QString> selectedQuestion;
        QModelIndex index = ui->questionList->currentIndex();
        QString itemText = index.data(Qt::DisplayRole).toString();
        for(int i=0; i<engine->quizGame->ReturnQuestionListLength(); i++)
        {
            if(engine->quizGame->GetAllQuestions()[i][0] == itemText)
            {
                selectedQuestion = engine->quizGame->GetAllQuestions()[i];
            }
        }
        editor = new QuestionEditor(this);
        editor->
        editor->show();
    }
}
