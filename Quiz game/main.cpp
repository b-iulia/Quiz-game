#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Question.h"
#include <fstream>
#include <bits/stdc++.h>
#include <windows.h>
void create_vector(std::vector<Question>&);
void display_vector(const std::vector<Question>&);
void menu();
void showalldatabase();
void play();
std::string check(std:: string str, std::string x);
void highest_score();
void delete_line(std::string);
std::string split(std::string str);
int main() {

    std::fstream my_file;
    menu();
//using an integer x in order to make the game interactive for the user
    int x;
    int backtomenu=0;

    std::cin>>x;
//this while is also used to make the menu interactive for the user
    while (x != 5)
    {
        //This checks if the users accidentally gives to our input an invalid option
        if(x==0 || x>5){
            std::cout<<"===================================================="<<std::endl<<std::endl;
            std::cout<<"            Please select a valid option!"<<std::endl<<std::endl;
            std::cout<<"===================================================="<<std::endl<<std::endl;
            menu();
            std::cin>>x;

        }
        //this if is created for the first option
        if (x==1)
        {
            backtomenu=0;
            while(backtomenu==0){

                play();
                std::cout<<std::endl;
                std::cout<<"===================================================="<<std::endl<<std::endl;
                std::cout<<"   If you want to go back to the menu introduce 1"<<std::endl<<std::endl;
                std::cout<<"===================================================="<<std::endl;
                std::cin>>backtomenu;
                if(backtomenu==1)
                    backtomenu=1;
                else
                    break;
            }

            menu();
            std::cin>>x;
        }
        //this if is created for the second option
        else if (x==2)
        {
            backtomenu=0;
            while(backtomenu==0){

                highest_score();
                std::cout<<std::endl;
                std::cout<<"   If you want to go back to the menu introduce 1"<<std::endl<<std::endl;
                std::cout<<"===================================================="<<std::endl;
                std::cin>>backtomenu;
                if(backtomenu==1)
                    backtomenu=1;
                else
                    break;
            }
            std::cout<<std::endl<<std::endl<<std::endl;
            menu();
            std::cin>>x;
        }
        //this if is created for the third option
        else if (x==3)
        {
            backtomenu=0;
            while(backtomenu==0){

                showalldatabase();
                std::cout<<std::endl;
                std::cout<<"   If you want to go back to the menu introduce 1"<<std::endl<<std::endl;
                std::cout<<"===================================================="<<std::endl;
                std::cin>>backtomenu;
                if(backtomenu==1)
                    backtomenu=1;
                else
                    break;
            }
            std::cout<<std::endl<<std::endl<<std::endl;
            menu();
            std::cin>>x;
        }
        //this if is created for the fourth option
        else if (x==4)
        {
            x=5;
            //close message if our user decides to leave the game
            std::cout<<std::endl<<std::endl;
            std::cout<<"===================================================="<<std::endl<<std::endl;
            std::cout<<"            Hope to see you back soon!"<<std::endl<<std::endl;
            std::cout<<"===================================================="<<std::endl;

        }

    }

    return 0;
}
//function that creates our game menu
void menu(){
std::cout<<"====================================================";
std::cout<<std::endl;
std::cout<<"      ~Welcome to general culture Quiz Game~"<<std::endl<<std::endl;
std::cout<<"           Please select an option:"<<std::endl<<std::endl;
std::cout<<"         Option 1: Start a new game"<<std::endl;
std::cout<<"         Option 2: Search your highest score"<<std::endl;
std::cout<<"         Option 3: See all players' highest score"<<std::endl;
std::cout<<"         Option 4: Stop the game"<<std::endl;
std::cout<<"===================================================="<<std::endl;
}
//this functions opens the txt file and outputs from it all past players in our games
void showalldatabase(){
    std::fstream my_file;
    my_file.open("../database.txt",std::ios::in);
    if(my_file.is_open()){
        std::string line;
        std::cout<<"===================================================="<<std::endl;
        std::cout<<"       All past players who tried our game:"<<std::endl<<std::endl;
        while(getline(my_file,line)){

            std::cout<<"                 "<<line<<" points"<<std::endl;

        }
        std::cout<<std::endl;
        std::cout<<"===================================================="<<std::endl;
        my_file.close();
    }
}


void play()
{
    std::vector<Question> q_vector;
    create_vector(q_vector);
    std::cout<<"Please introduce your nickname:"<<std::endl;
    std::string nickname;
    std::cin>>nickname;

    int v[51]={0};
    srand(time(0));
    int i=0,n=1;
    while (i<10)
    {
        int c=rand()%50;
        if (v[c]==0)
        {
            v[c]=1;
            i++;
        }
    }

    int score=0;
    for (i=0; i<50; i++)
        if (v[i]!=0)
        {
            std::cout<<"===================================================="<<std::endl;
            std::cout<<"player: "<<nickname<<"                             score:"<<score<<std::endl<<std::endl;
            q_vector[i].display_question();
            std::cout<<"===================================================="<<std::endl;
            std::cout<<"Please enter the letter corresponding to the correct answer:"<<std::endl;
            char a;
            std::cin>>a;
            if (a==q_vector[i].getCorrectAnswer())
            {
                score++;

                std::cout<<"You're right!"<<std::endl;
            }
            else
                std::cout<<"Wrong. The correct answer is "<<q_vector[i].getCorrectAnswer()<<". "<<q_vector[i].getCorrectAnswerText()<<std::endl;

        }
                std::cout<<std::endl;
                std::cout<<"               Your final score is: "<<score;

    int ok=0;
    std::fstream my_file;
    my_file.open("../database.txt",std::ios::in);
    if(my_file.is_open()) {
        std::string line;
        while (getline(my_file, line) && ok!=2) {

            if (check(line, nickname) != "") {
                ok=1;
                std::string score_database;
                score_database.assign(check(line, nickname));
                if (score_database=="10")
                    break;
                else
                {
                    int intsd=(int)score_database[0]-48;
                    if (score>intsd)
                        ok=2;
                }
            }
            n++;
        }

    }
    my_file.close();
    if (ok==2)
    {
        delete_line(nickname);
    }

    if(ok==0 || ok==2){

    my_file.open("../database.txt",std::ios::app);
    if(my_file.is_open()) {
        if(ok==0)
            my_file<<std::endl;
        my_file<<nickname<<' ';
        if(score==10)
            my_file<<"10";
        else if(score==9)
            my_file<<"9";
        else if(score==8)
            my_file<<"8";
        else if(score==7)
            my_file<<"7";
        else if(score==6)
            my_file<<"6";
        else if(score==5)
            my_file<<"5";
        else if(score==4)
            my_file<<"4";
        else if(score==3)
            my_file<<"3";
        else if(score==2)
            my_file<<"2";
        else if(score==1)
            my_file<<"1";
        else
            my_file<<"0";
    }
    my_file.close();
}
}

void delete_line(std::string s)
{
    std::fstream my_file;
    my_file.open("../database.txt",std::ios::in);
    std::fstream temp;
    temp.open("../temp.txt",std::ios::out);
    if(my_file.is_open()) {
        std::string line;
        while(getline(my_file,line)){
            if(split(line)!=s){
                temp<<line;
                temp<<std::endl;
            }
        }
    }
    my_file.close();
    temp.close();
    temp.open("../temp.txt",std::ios::in);
    my_file.open("../database.txt",std::ios::out);
    if(temp.is_open()) {
        std::string line;
        while(getline(temp,line)){
            my_file<<line;
            my_file<<std::endl;
            }
        }
    my_file.close();
    temp.close();

}

std::string check(std:: string str, std::string x)
{
    std:: istringstream ss(str);
    std:: string word;
    std::string text;
    ss>>word;

    text.assign(word);
    if(text==x)
    {
        ss>>word;
        return word;
    }
    return "";
}
std::string split(std::string str){
    std:: istringstream ss(str);
    std:: string word;
    std::string text;
    ss>>word;
    return word;
}


void highest_score()
{
    std::string x;
    std:: cout<<std::endl;
    std::cout<<"Please introduce the player's nickname:"<<std::endl;
    std::cin>>x;
    int ok=0;
    std::fstream my_file;
    my_file.open("../database.txt",std::ios::in);
    if(my_file.is_open()){
        std::string line;
        while(getline(my_file,line)){
            if(check(line, x)!="") {
                std::string score;
                score.assign(check(line, x));
                std::cout<<"===================================================="<<std::endl;
                std::cout<<"                    The user is:"<<std::endl;
                std::cout<<"                      "<<x<<" "<<score<<std::endl;
                std::cout<<"===================================================="<<std::endl;
                ok=1;
                break;
            }

            }
        }

        my_file.close();
    if(ok==0){
        std::cout<<"===================================================="<<std::endl;
        std::cout<<"            This user was not found"<<std::endl;
        std::cout<<"===================================================="<<std::endl;
    }


}


//this function creates te questions and adds them into a vector in order to be able to randomly generate a question in our game latter
void create_vector(std::vector<Question>& v){
    //number of questions
    int n=50;

    //Constructing the Questions
    //Q1
    Question q={"When did Romania join EU?", "2015", "2009", "2007", "1999", 3};
    v.push_back(q);
    //Q2
    q={"Which is the highest peak in Romania?", "Omu", "Moldoveanu", "Negoiu", "Pietrosul Rodnei", 2};
    v.push_back(q);
    //Q3
    q={"Which is the longest river in Romania?", "Tisa", "Olt", "Bega", "Mures", 1};
    v.push_back(q);
    //Q4
    q={"Which is the capital of Lithuania?", "Vilnius", "Paris", "Riga", "Dublin", 1};
    v.push_back(q);
    //Q5
    q={"When did the World War II started?", "2007", "1918", "1938", "1939", 4};
    v.push_back(q);
    //Q6
    q={"What was the name of the first president of Romania?", "Ion Iliescu", "Nicolae Ceausescu", "Victor Ponta", "Traina Basescu", 2};
    v.push_back(q);
    //Q7
    q={"When did the World War I ended?", "2015", "1945", "1914", "1918", 4};
    v.push_back(q);
    //Q8
    q={"Which country has the biggest population?", "India", "Brazil", "China", "United States of America", 3};
    v.push_back(q);
    //Q9
    q={"When did the Cold War ended?", "1981", "2000", "1948", "1920", 1};
    v.push_back(q);
    //Q10
    q={"Which is the highest peak in the World?", "Mount Lhotse", "Mount Kangchenjunga", "Mount K2", "Mount Everest", 4};
    v.push_back(q);
    //Q11
    q={"What does \" HTTP \" stand for?", "Horizontal Trail Trace Pants", "HyperText Transfer Protocol", "High Transformation Translation Powerpoint", "High Technology Transfer Protocol", 2};
    v.push_back(q);
    //Q12
    q={"When was Iphone\'s first model released?", "2006", "1890", "2007", "2004", 3};
    v.push_back(q);
    //Q13
    q={"Which band has the highest earnings?", "Queen", "Nirvana", "Metallica", "The Beatles", 4};
    v.push_back(q);
    //Q14
    q={"In which state is Area 51 located", "Nevada", "California", "Utah", "Idaho", 1};
    v.push_back(q);
    //Q15
    q={"What is the Earth\'s largest continent?", "Europe", "Asia", "North America", "Africa", 2};
    v.push_back(q);
    //Q16
    q={"Which is the biggest ocean in the world?", "Artic Ocean", "Indian Ocean", "Pacific Ocean", "Atlantic Ocean", 3};
    v.push_back(q);
    //Q17
    q={"How many elements are in the periodic table?", "20", "130", "78", "118", 4};
    v.push_back(q);
    //Q18
    q={"Which actor played in the movie Deadpool?", "Ryan Reynolds", "Tom Holand", "Leonardo di Caprio", "Brad Pitt", 1};
    v.push_back(q);
    //Q19
    q={"What year did the Titanic sink in the Atlantic Ocean on 15 April, on its maiden voyage from Southampton?", "1960", "1909", "1912", "1999", 3};
    v.push_back(q);
    //Q20
    q={"What is the capital of Portugal?", "Roma", "Lisbon", "Athens", "Zagreb", 2};
    v.push_back(q);
    //Q21
    q={"Which animal can be seen on the Porsche logo?", "a cow", "a pig", "a tiger", "a horse", 4};
    v.push_back(q);
    //Q22
    q={"Which country produces the most coffee in the world?", "France", "Italy", "Brazil", "Bolivia", 3};
    v.push_back(q);
    //Q23
    q={"Which European nation was said to invent hot dogs?", "Germany", "USA", "Italy", "Ireland", 1};
    v.push_back(q);
    //Q24
    q={"Which planet is the hottest in the solar system?", "Mars", "Venus", "Jupiter", "Saturn", 2};
    v.push_back(q);
    //Q25
    q={"If there are six apples and you take away four, how many do you have?", "four", "two", "six", "ten", 1};
    v.push_back(q);
    //Q26
    q={"Larry Page is the CEO of which company?", "IBM", "Microsoft", "Amazon", "Google", 4};
    v.push_back(q);
    //Q27
    q={"Which mammal has no vocal cords?", "Elephant", "Whale", "Giraffe", "Monkey", 3};
    v.push_back(q);
    //Q28
    q={"Which of the following is not a sport brand?", "Adidas", "Nivea", "Nike", "Puma", 2};
    v.push_back(q);
    //Q29
    q={"Which team won the most UEFA Champions League trophies?", "Real Madrid", "Barcelona", "Manchester United", "Arsenal", 1};
    v.push_back(q);
    //Q30
    q={"Which country borders 14 nations and crosses 8 time zones?", "China", "India", "Russia", "Romania", 3};
    v.push_back(q);
    //Q31
    q={"Who has won more tennis grand slam titles?", "Simona Halep", "Venus Williams", "Martina Hingis", "Serena Williams", 4};
    v.push_back(q);
    //Q32
    q={"Which country won the first-ever soccer World Cup in 1930?", "Romania", "Uruguay", "Germany", "Brazil", 2};
    v.push_back(q);
    //Q33
    q={"Which sport is dubbed the \"king of sports\"?", "Basketball", "Tennis", "Football", "Ice Hockey", 3};
    v.push_back(q);
    //Q34
    q={"How many points did Michael Jordan scored in his first game?", "2", "8", "10", "16", 4};
    v.push_back(q);
    //Q35
    q={"How many teeth does an adult human have?", "32", "33", "43", "29", 1};
    v.push_back(q);
    //Q36
    q={"What is the world\'s most earthquake-prone country?", "Malaysia", "Japan", "North Korea", "Taiwan", 2};
    v.push_back(q);
    //Q37
    q={"What river runs through Paris?", "Hudson River", "Rhine River", "Seine River", "Mississippi River", 3};
    v.push_back(q);
    //Q38
    q={"What is the only country that borders the United Kingdom?", "Sweden", "Greece", "Austria", "Ireland", 4};
    v.push_back(q);
    //Q39
    q={"How many countries are inside the United Kingdom?", "4", "3", "5", "1", 1};
    v.push_back(q);
    //Q40
    q={"What is the world\'s biggest island?", "Iceland", "Finland", "Greenland", "Ireland", 3};
    v.push_back(q);
    //Q41
    q={"What year was the United States Declaration of Independence signed?", "1775", "1776", "1545", "1606", 2};
    v.push_back(q);
    //Q42
    q={"When did the Berlin Wall fall?", "1988", "1990", "1993", "1989", 4};
    v.push_back(q);
    //Q43
    q={"What is the world\'s smallest country?", "France", "Malta", "Vatican", "Maldives", 3};
    v.push_back(q);
    //Q44
    q={"Which natural disaster is measured with a Richter scale?", "Earthquakes", "Floods", "Hurricane", "Tornado", 1};
    v.push_back(q);
    //Q45
    q={"What does DNA stand for?", "Duoribonuclear Acid", "Deoxyribonucleic Acid", "Duoxyribonucleic Acid", "Deoxyribonuclear Acid", 2};
    v.push_back(q);
    //Q46
    q={"Who was the first woman to win a Nobel Prize in 1903?", "Marie Curie", "Pearl Buck", "Rosalind Franklin", "Jane Addams", 1};
    v.push_back(q);
    //Q47
    q={"\"K\" is the chemical symbol for which element?", "Chromium", "Titanium", "Hydrogen", "Potassium", 4};
    v.push_back(q);
    //Q48
    q={"Who was the first person to walk on the Moon?", "James B. Irwin", "Pete Conrad", "Neil Armstrong", "Alan Shepard", 3};
    v.push_back(q);
    //Q49
    q={"What kind of animal is an \"Orca\"?", "Seal", "Whale", "Shark", "Octopus", 2};
    v.push_back(q);
    //Q50
    q={"What\'s the national sport of Canada?", "Lacrosse", "Football", "Basketball", "Bowling", 1};
    v.push_back(q);


    //setting up the correct answer for each question
    for(int i=0; i<n; i++)
    {
        v[i].set_correct_answer();
    }

}