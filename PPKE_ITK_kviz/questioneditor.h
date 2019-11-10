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
    explicit QuestionEditor(QWidget *parent = nullptr);
    ~QuestionEditor();
    void populateCurrentQuestion(vector<QString> questionData);
    void populateInputFields();
    vector<QString> currentQuestion;
private slots:
    void on_cancelButton_clicked();

private:
    Ui::QuestionEditor *ui;
};

#endif // QUESTIONEDITOR_H
