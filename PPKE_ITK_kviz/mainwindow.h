#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "questioneditor.h"
#include "BusinessLogicLayer/gameengine.h"
#include "questioneditor.h"

#include <QStringListModel>
#include <QList>
#include <QString>
#include <QListWidgetItem>
#include <QListWidget>

#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QuestionEditor *editor;
    GameEngine *engine;
    void SetGameLabels();
    void StartNewGame();
    vector<QString> GetSelectedListItem();
    vector<vector<QString>> DeleteQuestion();
    vector<vector<QString>> UpdateQuestion();
    vector<vector<QString>> AddQuestion();
    void PopulateQuestionsList();
private slots:
    void on_startGame_clicked();
    void on_nextQuestion_clicked();
    void on_actionExit_triggered();
    void on_actionStartNewGame_triggered();
    void on_actionQuitCurrentGame_triggered();
    void on_actionCreateNewQuiz_triggered();
    void on_actionEditExistingQuiz_triggered();
    void on_editQuestion_clicked();
    void on_deleteQuestion_clicked();
    void on_cancelButton_clicked();
    void SaveModifiedQuestion();
    void on_addQuestion_clicked();
    void on_saveQuestion_clicked();
    void on_actionBrowseFileInDirectory_triggered();
    void on_actionChooseAppDefaultQuiz_triggered();
};
#endif // MAINWINDOW_H
