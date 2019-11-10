#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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
    vector<QString> getSelectedListItem();
    vector<vector<QString>> DeleteQuestion();
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
};
#endif // MAINWINDOW_H
