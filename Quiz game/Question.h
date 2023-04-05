#ifndef PROGRAMMINGPROJECTQUIZ_QUESTION_H
#define PROGRAMMINGPROJECTQUIZ_QUESTION_H
#include <iostream>

class Question {
protected:
//    char *text;
//    char *choice1, *choice2, *choice3, *choice4;
std::string text;
std::string choice1;
std::string choice2;
std::string choice3;
std::string choice4;
    int x;
    char correct_answer;
    std::string correct_answer_text;
public:
//    Question(char *text, char *choice1, char *choice2, char *choice3,  char *choice4, int x);
    Question(std::string text, std::string choice1, std::string choice2, std::string choice3,  std::string choice4, int x);
//    Question(const Question&);
    char getCorrectAnswer() const;
    std::string getCorrectAnswerText() const;
    void display_question();
    void set_correct_answer();



};


#endif //PROGRAMMINGPROJECTQUIZ_QUESTION_H
