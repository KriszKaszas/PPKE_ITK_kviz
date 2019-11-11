#include "connection.h"

Connection::Connection()
{
    currentQuiz = new Quiz();
    CreateAppDefaultQuiz();
    SetFilePath("./AppDefaultQuizes/quiz.txt");
    ReadDataFromLocalFile();
}

Quiz *Connection::GetQuiz()
{
    return currentQuiz;
}


void Connection::SetQuiz(QString title, vector<vector<QString>> questions)
{
    currentQuiz->SetTitle(title);
    currentQuiz->SetQuestions(questions);
}

void Connection::ReadDataFromLocalFile()
{
    rawQuiz.clear();
    QFile quizFile(filepath);
    if(!quizFile.open(QFile::ReadOnly))
    {
        cout<<"problem";
    }
    QTextStream in(&quizFile);
    in.setCodec("UTF-8");
    QString line;
    while(in.readLineInto(&line) && line != "")
    {
        QStringList splitLine = line.split(":");
        rawQuiz.push_back(splitLine[1]);
    }
    quizFile.close();
}

QString Connection::ParseQuizTitle()
{
    return rawQuiz[0];
}

vector<vector<QString>> Connection::ParseQuizQuestions()
{
    vector<vector<QString>> quizQuestions;
    vector<QString> currentQuestion;
    for(int i = 1; i < static_cast<int>(rawQuiz.size()-2); i+=6)
    {
        for(int j = 0; j < 6; j++)
        {
            currentQuestion.push_back(rawQuiz[static_cast<unsigned long long int>(i+j)]);
        }
        quizQuestions.push_back(currentQuestion);
        currentQuestion.clear();
    }
    return quizQuestions;
}

void Connection::SetUpLoadedQuiz()
{
    currentQuiz->SetTitle(ParseQuizTitle());
    currentQuiz->SetQuestions(ParseQuizQuestions());
}

void Connection::CreateAppDefaultQuiz()
{
    QString localTestQuizTitle = "Töltsön be egy kvízfájlt!";
    vector<vector<QString>> localTestQuizQuestions =
        {
            {"Töltsön be egy kvízfájlt!", "Töltsön be egy kvízfájlt!", "Töltsön be egy kvízfájlt!", "Töltsön be egy kvízfájlt!", "Töltsön be egy kvízfájlt!", "A"},
        };
    currentQuiz->SetTitle(localTestQuizTitle);
    currentQuiz->SetQuestions(localTestQuizQuestions);
}

void Connection::SaveQuiz()
{
    ReverseParseQuiz();
    WriteDataToLocalFile();
}

void Connection::ReverseParseQuiz()
{
    rawQuiz.clear();
    rawQuiz.push_back("Name:" + currentQuiz->GetTitle());
    for(vector<QString> question : currentQuiz->GetQuestions())
    {
        rawQuiz.push_back("Q:" + question[0]);
        rawQuiz.push_back("A:" + question[1]);
        rawQuiz.push_back("B:" + question[2]);
        rawQuiz.push_back("C:" + question[3]);
        rawQuiz.push_back("D:" + question[4]);
        rawQuiz.push_back("Ans:" + question[5]);
    }
}

void Connection::WriteDataToLocalFile()
{
    QFile savedQuiz(filepath);
    if(!savedQuiz.open(QFile::WriteOnly))
    {
        cout<<"problem";
    }
    QTextStream out(&savedQuiz);
    out.setCodec("UTF-8");
    for(QString elem : rawQuiz)
    {
        out << elem << "\n";
    }
    savedQuiz.flush();
    savedQuiz.close();
}

void Connection::SetFilePath(QString filepath = "./AppDefaultQuizes")
{
    this->filepath = filepath;
}

void Connection::SetScore(vector<QString> score)
{
    this->score = score;
    WritePlayerDataToFile();
}

void Connection::WritePlayerDataToFile()
{
    QFile scoreboard("./ScoreBoard/ScoreBoard.txt");
    if(!scoreboard.open(QFile::WriteOnly))
    {
        cout<<"problem";
    }
    QTextStream out(&scoreboard);
    out.setCodec("UTF-8");
    for(QString elem : score)
    {
        out << elem << " ; ";
    }
    scoreboard.flush();
    scoreboard.close();
}
