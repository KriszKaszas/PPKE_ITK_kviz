#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    editor = new QuestionEditor(this);
    connect(editor, SIGNAL(closing()), this, SLOT(SaveModifiedQuestion()));
    engine = new GameEngine();
    ui->selectedQuiz->setText(engine->quizGame->GetQuizTitle());
    SetGameLabels();
    timer = new QTimer(this);
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
    ui->remainingTime->setText("59");
}

void MainWindow::StartNewGame()
{
    if(ui->playerName->text() != "")
    {
        ui->stackedWidget->setCurrentIndex(2);
        SetGameLabels();
        gametimer = 59;
        connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
        timer->start(1000);
    }
    else
    {
        QMessageBox::warning(this, "HIBA!", "Kérjük, adjon meg egy játékosnevet!");
    }
}

void MainWindow::advance()
{
    ui->remainingTime->setText(QString::number(gametimer));
    if(gametimer != 0)
    {
        gametimer--;
    }
    if(gametimer == 0)
    {
        ui->remainingTime->setText(QString::number(gametimer));
        engine->quizGame->Behavior("");
        if(!engine->quizGame->IsGameOver())
        {
            gametimer = 59;
            SetGameLabels();
        }
        else
        {
            ui->score->setText(engine->quizGame->GetScoreToQString());
            QString gameOverMessage = "Az Ön pontszáma: " + engine->quizGame->GetScoreToQString();
            QMessageBox::StandardButton reply =
                QMessageBox::information(this, "Vége a játéknak!", gameOverMessage);
            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT());
            if (reply == QMessageBox::Ok)
            {
                vector<QString> score = {ui->playerName->text(), ui->quizTitle->text(), engine->quizGame->GetScoreToQString()};

                engine->SetScore(score);
                engine->quizGame->ResetValues();
                ui->stackedWidget->setCurrentIndex(0);
            }

        }
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
            ui->A->setAutoExclusive(true);
        }
        if(ui->B->isChecked())
        {
            AnswerValue = "B";
            ui->B->setAutoExclusive(false);
            ui->B->setChecked(false);
            ui->B->setAutoExclusive(true);
        }
        if(ui->C->isChecked())
        {
            AnswerValue = "C";
            ui->C->setAutoExclusive(false);
            ui->C->setChecked(false);
            ui->C->setAutoExclusive(true);
        }
        if(ui->D->isChecked())
        {
            AnswerValue = "D";
            ui->D->setAutoExclusive(false);
            ui->D->setChecked(false);
            ui->D->setAutoExclusive(true);
        }
        engine->quizGame->Behavior(AnswerValue);
        if(!engine->quizGame->IsGameOver())
        {
            gametimer = 59;
            SetGameLabels();
        }
        else
        {
            ui->score->setText(engine->quizGame->GetScoreToQString());
            QString gameOverMessage = "Az Ön pontszáma: " + engine->quizGame->GetScoreToQString();
            QMessageBox::StandardButton reply =
                QMessageBox::information(this, "Vége a játéknak!", gameOverMessage);
            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT());
            if (reply == QMessageBox::Ok)
            {
                vector<QString> score = {ui->playerName->text(), ui->quizTitle->text(), engine->quizGame->GetScoreToQString()};
                engine->SetScore(score);
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
    ui->questionEditorTitle->clear();
    ui->questionList->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::PopulateQuestionsList()
{
    ui->questionEditorTitle->clear();
    ui->questionList->clear();
    ui->questionEditorTitle->setText(engine->quizGame->GetQuizTitle());
    for(int i=0; i<engine->quizGame->ReturnQuestionListLength(); i++)
    {
        ui->questionList->addItem(engine->quizGame->GetAllQuestions()[static_cast<unsigned long long int>(i)][0]);
    }
    ui->questionList->setCurrentRow(0);
}

void MainWindow::on_actionEditExistingQuiz_triggered()
{
    engine->quizGame->ResetValues();
    ui->stackedWidget->setCurrentIndex(1);
    PopulateQuestionsList();
}

vector<QString> MainWindow::GetSelectedListItem()
{
    vector<QString> selectedQuestion;
    for(int i = 0; i < static_cast<int>(engine->quizGame->GetAllQuestions().size()); i++)
    {
        if(i == ui->questionList->currentRow())
        {
            selectedQuestion = engine->quizGame->GetAllQuestions()[static_cast<unsigned long long int>(i)];
        }
    }
    return selectedQuestion;
}

vector<vector<QString>> MainWindow::UpdateQuestion()
{
    vector<vector<QString>> currentQuestions = engine->quizGame->GetAllQuestions();
    for(int i = 0; i < static_cast<int>(engine->quizGame->GetAllQuestions().size()); i++)
    {
        if(i == ui->questionList->currentRow())
        {
            currentQuestions[static_cast<unsigned long long int>(i)] = editor->currentQuestion;
        }
    }
    return currentQuestions;
}

vector<vector<QString>> MainWindow::AddQuestion()
{
    vector<vector<QString>> currentQuestions = engine->quizGame->GetAllQuestions();
    currentQuestions.push_back(editor->currentQuestion);
    return currentQuestions;
}

void MainWindow::SaveModifiedQuestion()
{
    if(!editor->isNewQuestion)
    {
        if(editor->currentQuestion[0] != "")
        {
            engine->datamanager->UpdateQuestions(ui->questionEditorTitle->text(), UpdateQuestion());
        }
    }
    if(editor->isNewQuestion)
    {
        if(editor->currentQuestion[0] != "")
        {
            engine->datamanager->UpdateQuestions(engine->datamanager->GetQuiz()->GetTitle(), AddQuestion());
        }
    }
    PopulateQuestionsList();
}

void MainWindow::on_editQuestion_clicked()
{
    editor->isNewQuestion = false;
    editor->PopulateCurrentQuestion(GetSelectedListItem());
    editor->PopulateInputFields();
    editor->show();
}

vector<vector<QString>> MainWindow::DeleteQuestion()
{
    vector<vector<QString>> currentQuestions = engine->quizGame->GetAllQuestions();
    for(int i = 0; i < static_cast<int>(engine->quizGame->GetAllQuestions().size()); i++)
    {
        if(i == ui->questionList->currentRow())
        {
            currentQuestions.erase(currentQuestions.begin()+i);
        }
    }
    return currentQuestions;
}

void MainWindow::on_deleteQuestion_clicked()
{
    engine->datamanager->UpdateQuestions(ui->questionEditorTitle->text(), DeleteQuestion());
    PopulateQuestionsList();
}

void MainWindow::on_cancelButton_clicked()
{
    ui->questionTitle->clear();
    ui->questionList->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_addQuestion_clicked()
{
    editor->isNewQuestion = true;
    editor->ClearQuestions();
    editor->ClearFields();
    editor->show();
}

void MainWindow::on_saveQuestion_clicked()
{
    engine->datamanager->SaveQuiz();
}

void MainWindow::on_actionBrowseFileInDirectory_triggered()
{
    QString filter = "Txt files (*.txt) ;; All file (.*)";
    QString filename = QFileDialog::getOpenFileName(this, "Válaszd ki a telefonkönyvet!", "C:/", filter);

    if (filename != "")
    {
       engine->datamanager->SetFilePath(filename);
       engine->datamanager->LoadDataFromLocalFile();
       engine->setQuiz(engine->datamanager->GetQuiz());
       ui->selectedQuiz->setText(engine->quizGame->GetQuizTitle());
       SetGameLabels();
    }
}

void MainWindow::on_actionChooseAppDefaultQuiz_triggered()
{
    QString filter = "Txt files (*.txt) ;; All file (.*)";
    QString filename = QFileDialog::getOpenFileName(this, "Válaszd ki a telefonkönyvet!", "./AppDefaultQuizes/quiz.txt", filter);

    if (filename != "")
    {
       engine->datamanager->SetFilePath(filename);
       engine->datamanager->LoadDataFromLocalFile();
       engine->setQuiz(engine->datamanager->GetQuiz());
       ui->selectedQuiz->setText(engine->quizGame->GetQuizTitle());
       SetGameLabels();
    }
}

void MainWindow::on_actionGameInfo_triggered()
{
    QMessageBox::information(this, "Játékinfó", "Kvízjáték\n\nPPKE-ITK Molekuláris Bionika Szak\n\nFelföldi Anna TM\n\n 2019 All Rights Reserved");
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::information(this, "Súgó", "BETÖLTÉS:\nÚj Kvizek feltöltésénél fokozottan kell ügyelni az adatfájl formátumára.\nReferenciaként használja a programhoz tartozó adatfájlokat (.txt).\nFokozottan ügyeljen a sorok elején található jelölőkre.\n\nFUNKCIÓK:\nA játék teljes mentés, módosítás és feltöltés funkciócsomaggal rendelkezik.\n\nJÁTÉK:\nA kvízek kitöltése időkorlátos.\n\nFIGYELEM:\nA termék használata előtt semmilyen tudatmódosító szer\nhasználatát nem ajánljuk.");
}
