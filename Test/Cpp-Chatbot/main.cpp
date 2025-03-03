/*
Jack Martin

ChatBot
Version 1.0

This program creates a simple chatbot

Allows user to ask bot a question
If the bot knows the m_answer to the question, the bot will reply with the m_answer
If the bot does not know the m_answer to the question, the bot will ask the user the same question and store the m_answer for future use
*/

#include "bot.h"
#include "question.h"


int main()
{

    bot bot;
    bool loop = true;
    std::string userInput;
    while (loop)
    {
        std::cout << "Hello! Ask me a question!" << std::endl;
        getline(std::cin, userInput);
        for (int i = 0; i != userInput.length(); i++)
        {
            userInput.at(i) = tolower(userInput.at(i));
        }
        if (bot.isQuestion(userInput) == true)					// check if bot knows m_answer to the question.
        {														// if bot knows the m_answer, reply with m_answer if bot does not know the m_answer then bot will ask the same question,
            if (bot.check(userInput) == true)					//and store the users m_answer in the linked list as well as the text file
            {
                bot.reply(userInput);
            }
            else
            {
                bot.storeNewQuestion(userInput);
            }
        }
        else
        {
            std::cout << "You did not ask your question with the right format! Correct questions end with a '?'" << std::endl;
        }
        system("pause");
        system("cls");
    }


    system("pause");
    return 0;
}
