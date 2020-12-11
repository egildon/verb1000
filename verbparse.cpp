#include "verbparse.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cctype>
#include <map>
#include <vector>

using namespace std;
verbParse::verbParse()
{

    int i = 1;
    string originalPhrase;
    string nuPhrase;
    //string extracted;
    //string test = "Test!";
    string originalVerb;
    string nuVerb;
    string usedPronoun;
    string verbEnd;
    string nuVerbEnd;
    char userAnswer[25];
    string correctAnswer;
    //char userSubmission[25];
    //bool playing = true;


    vector<string> verbsList;///fill these before
    vector<string> pronounsList;///fill these before

    verbsList.push_back("Assistir");
    verbsList.push_back("Falar");
    verbsList.push_back("Beber");
    verbsList.push_back("Pular");
    verbsList.push_back("Decidir");
    verbsList.push_back("Correr");
    verbsList.push_back("Viver");

    pronounsList.push_back("Eu");///PRONOUNS LIST REPEATS SEEE IF I CAN ELIMINATE THIS
    pronounsList.push_back("Tu");
    pronounsList.push_back("Voce");
    pronounsList.push_back("Voces");
    pronounsList.push_back("Ele");
    pronounsList.push_back("Ela");
    pronounsList.push_back("Nos");
    pronounsList.push_back("Eles");
    pronounsList.push_back("Elas");

    vector<string>::const_iterator iter;
    vector<string>::const_iterator iter2;

    map<int,string> pronounsMap = {{1,"Eu"},{2,"Tu"},{3,"Voce"},{4,"Voces"},{5,"Ele"},{6,"Ela"},{7,"Nos"},{8,"Eles"},{9,"Elas"}};///Should this be a case??? or nested map?

    map<string,string> verbFormEu = {{"ar","o"},{"er","o"},{"ir","o"}};//#1
    map<string,string> verbFormTu = {{"ar","as"},{"er","es"},{"ir","es"}};//#2
    map<string,string> verbFormVoce = {{"ar","a"},{"er","e"},{"ir","e"}};//#3
    map<string,string> verbFormVoces = {{"ar","a"},{"er","e"},{"ir","e"}};//#4
    map<string,string> verbFormEle = {{"ar","e"},{"er","e"},{"ir","e"}};//#5
    map<string,string> verbFormEla = {{"ar","e"},{"er","e"},{"ir","e"}};//#6
    map<string,string> verbFormNos = {{"ar","amos"},{"er","emos"},{"ir","imos"}};//#7
    map<string,string> verbFormEles = {{"ar","am"},{"er","em"},{"ir","em"}};//#8
    map<string,string> verbFormElas = {{"ar","am"},{"er","em"},{"ir","em"}};// #9


    srand(static_cast < unsigned int > (time(0)));//time based random seed

    random_shuffle(verbsList.begin(),verbsList.end()); //scramble verb list
    random_shuffle(pronounsList.begin(),pronounsList.end());//scramble pronoun list





    //// test for and extract endings from strings


    iter2 = pronounsList.begin(); iter != pronounsList.end(); ++iter2;
    iter = verbsList.begin(); iter != verbsList.end(); ++iter;
    cout << "Number of times 'iter and iter2 loop is hit: " << i << endl;
    i++;

        {

    {
         {

        originalVerb = *iter;
        usedPronoun = *iter2;

        verbEnd = originalVerb.substr(originalVerb.size()-2,originalVerb.size()); //removes last two characters from theVerb string places it in verbEnd

        originalPhrase = usedPronoun + " " + originalVerb;


        if (usedPronoun == "Eu"){
            auto iter3 = verbFormEu.find(verbEnd); ///iterates over map to find key
            if (iter3 != verbFormEu.end())
            {
                nuVerbEnd = iter3->second;
                cout << "Eu FOUND: " << iter3->second  << endl; ///do something with the returned value
                nuVerb = originalVerb.replace(originalVerb.end()-2,originalVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
                nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
                //cout << nuPhrase << endl;

             }

        }
        else if (usedPronoun == "Tu")
            {
            auto iter3 = verbFormTu.find(verbEnd); ///iterates over map to find key
            if (iter3 != verbFormTu.end())
            {
                nuVerbEnd = iter3->second;
                cout << "Tu FOUND: " << iter3->second  << endl; ///do something with the returned value
                nuVerb = originalVerb.replace(originalVerb.end()-2,originalVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
                nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
               // cout << nuPhrase << endl;

             }

        }
        else if (usedPronoun == "Voce" || "Voces")
            {
            auto iter3 = verbFormVoce.find(verbEnd); ///iterates over map to find key
            if (iter3 != verbFormVoce.end())
            {
                nuVerbEnd = iter3->second;
                cout << "Voce/ Voces FOUND: " << iter3->second  << endl; ///do something with the returned value
                nuVerb = originalVerb.replace(originalVerb.end()-2,originalVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
                nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
               // cout << nuPhrase << endl;

             }

        }
        else if (usedPronoun == ("Ele") || "Ela")
        {
            auto iter3 = verbFormEle.find(verbEnd); ///iterates over map to find key
            if (iter3 != verbFormEle.end())
            {
                nuVerbEnd = iter3->second;
                cout << "Ele/Ela FOUND: " << iter3->second  << endl; ///do something with the returned value
                nuVerb = originalVerb.replace(originalVerb.end()-2,originalVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
                nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
               // cout << nuPhrase << endl;

             }

        }
        else if (usedPronoun == "Nos")
        {
            auto iter3 = verbFormNos.find(verbEnd); ///iterates over map to find key
            if (iter3 != verbFormNos.end())
            {
                nuVerbEnd = iter3->second;
                cout << "Nos FOUND: " << iter3->second  << endl; ///do something with the returned value
                nuVerb = originalVerb.replace(originalVerb.end()-2,originalVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
                nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
                //cout << nuPhrase << endl;

             }

        }
        else if (usedPronoun == "Eles" || "Elas")
        {
            auto iter3 = verbFormEles.find(verbEnd); ///iterates over map to find key
            if (iter3 != verbFormEles.end())
            {
                nuVerbEnd = iter3->second;
                cout << "Eles/Elas FOUND: " << iter3->second  << endl; ///do something with the returned value
                nuVerb = originalVerb.replace(originalVerb.end()-2,originalVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
                nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
               // cout << nuPhrase << endl;

             }
        }

    cout << "This is an exercise to practice conjugating regular verbs."<< endl;
    cout << "It will display a verb and pronoun in Portugese." << endl;
    cout <<"You should asess the pronoun and provide the proper verb ending for the phrase." << endl;
    cout <<"Here is a phrase. Correctly conjugate it: " << originalPhrase << "..." << endl;
    cout << "Here is the ANSWER: " << nuPhrase << endl;
    cin.get(userAnswer,25);
    cout << "You entered: "<< userAnswer << endl;

    //userAnswer = tolower(userSubmission);     ///Create iterator to loop over strings to make this work!

    //correctAnswer = tolower(nuPhrase);     ///Create iterator to loop over strings to make this work!




    if (userAnswer == nuPhrase){
        cout << "You Got It RIGHT!!!" << endl;
    }

    else{
        cout << "Wrong!!! YOU SUCK!!!" << endl;

    }



        }}}}



    /// Make switch case work instead of if else
    //            switch ()
    //            {
    //            case 1: //"Eu": //TRY TO MAKE THIS WORK WITH A SWITCH CASE
    //                auto iter3 = verbFormEu.find(verbEnd); ///iterates over map to find key
    //                if (iter3 != verbFormEu.end())
    //                {
    //                    nuVerbEnd = iter3->second;
    //                    cout << "FOUND: " << iter3->second  << endl; ///do something with the returned value
    //                    nuVerb = oldVerb.replace(oldVerb.end()-2,oldVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
    //                    nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
    //                    cout << nuPhrase << endl;
    //            break;


    //           case 2: //"Tu":
    //                {
    //                auto iter3 = verbFormTu.find(verbEnd); ///iterates over map to find key
    //                if (iter3 != verbFormTu.end())
    //                {
    //                    nuVerbEnd = iter3->second;
    //                    cout << "Tu FOUND: " << iter3->second  << endl; ///do something with the returned value
    //                    nuVerb = oldVerb.replace(oldVerb.end()-2,oldVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
    //                    nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
    //                    cout << nuPhrase << endl;

    //                 }

    //            }
    //            case 3: //"Voce" || "Voces":
    //                {
    //                auto iter3 = verbFormVoce.find(verbEnd); ///iterates over map to find key
    //                if (iter3 != verbFormVoce.end())
    //                {
    //                    nuVerbEnd = iter3->second;
    //                    cout << "Voce/ Voces FOUND: " << iter3->second  << endl; ///do something with the returned value
    //                    nuVerb = oldVerb.replace(oldVerb.end()-2,oldVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
    //                    nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
    //                    cout << nuPhrase << endl;

    //                 }

    //            }
    //            case 4: //"Ele" || "Ela":
    //            {
    //                auto iter3 = verbFormEle.find(verbEnd); ///iterates over map to find key
    //                if (iter3 != verbFormEle.end())
    //                {
    //                    nuVerbEnd = iter3->second;
    //                    cout << "Ele/Ela FOUND: " << iter3->second  << endl; ///do something with the returned value
    //                    nuVerb = oldVerb.replace(oldVerb.end()-2,oldVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
    //                    nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
    //                    cout << nuPhrase << endl;

    //                 }

    //            }
    //            case 5: //"Nos":
    //            {
    //                auto iter3 = verbFormNos.find(verbEnd); ///iterates over map to find key
    //                if (iter3 != verbFormNos.end())
    //                {
    //                    nuVerbEnd = iter3->second;
    //                    cout << "Nos FOUND: " << iter3->second  << endl; ///do something with the returned value
    //                    nuVerb = oldVerb.replace(oldVerb.end()-2,oldVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
    //                    nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
    //                    cout << nuPhrase << endl;

    //                 }

    //            }
    //            case 6: //"Eles" || "Elas":
    //            {
    //                auto iter3 = verbFormEles.find(verbEnd); ///iterates over map to find key
    //                if (iter3 != verbFormEles.end())
    //                {
    //                    nuVerbEnd = iter3->second;
    //                    cout << "Eles/Elas FOUND: " << iter3->second  << endl; ///do something with the returned value
    //                    nuVerb = oldVerb.replace(oldVerb.end()-2,oldVerb.end() , nuVerbEnd); //insert the map coordinates to the end of theVerb replacing the last 2 letters with new suffix
    //                    nuPhrase = usedPronoun + " " + nuVerb;//concatinate to create final correct phrase
    //                    cout << nuPhrase << endl;

    //                 }

    //            default:{
    //                    cout << "ending" << endl;
    //                    }
    //                }}}














