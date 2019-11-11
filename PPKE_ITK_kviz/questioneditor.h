#ifndef QUESTIONEDITOR_H
#define QUESTIONEDITOR_H

#include <QMainWindow>

#include <QString>

#include <vector>

using namespace std;

namespace Ui {
class QuestionEditor;
}

class QuestionEditor : public QMainWindow
{
    Q_OBJECT

public:
    Ui::QuestionEditor *ui;
    explicit QuestionEditor(QWidget *parent = nullptr);
    ~QuestionEditor();
    void PopulateCurrentQuestion(vector<QString> questionData);
    void PopulateInputFields();
    vector<QString> currentQuestion;
    bool isNewQuestion;
    void ClearQuestions();
    void ClearFields();
protected:
    void closeEvent(QCloseEvent *event);
signals:
    void closing();
private slots:
    void on_cancelButton_clicked();
    void RetrieveFieldData();
    void on_okButton_clicked();
};

#endif // QUESTIONEDITOR_H
