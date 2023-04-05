#include "Question.h"
#include <iostream>
#include <cstring>

Question::Question(std::string text, std::string choice1, std::string choice2, std::string choice3, std::string choice4,int x) {
    this->text=text;
    this->choice1=choice1;
    this->choice2=choice2;
    this->choice3=choice3;
    this->choice4=choice4;
    this->x=x;
}

char Question::getCorrectAnswer() const{
    return correct_answer;
}
std::string Question::getCorrectAnswerText() const{
    return correct_answer_text;
}
void Question::display_question() {

    std::cout << text << "\na. " << choice1 << "\nb. " << choice2 << "\nc. " << choice3 << "\nd. " << choice4 << "\n";

}

void Question::set_correct_answer() {
    if (x==1)
    {
        correct_answer='a';
        correct_answer_text=choice1;

    }
    if (x==2)
    {
        correct_answer='b';
        correct_answer_text=choice2;
    }
    if (x==3)
    {
        correct_answer='c';
        correct_answer_text=choice3;
    }
    if (x==4)
    {
        correct_answer='d';
        correct_answer_text=choice4;
    }
}