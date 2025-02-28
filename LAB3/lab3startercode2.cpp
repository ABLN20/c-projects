#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype> 

// Function to convert a string to lowercase
std::string toLowerCase(const std::string& str) {
    // TODO code goes here
    std::string res;
    for (char i: str)
    {
        res += tolower(i);
    }
    return res;
}

// Function to read spam words from a file
std::vector<std::string> readSpamWords(const std::string& filename) {
    std::vector<std::string> spamWords;
    std::ifstream file(filename);
    std::string word;

    // Read each word from the file and add it to the spamWords vector
    while (file >> word) {
        spamWords.push_back(toLowerCase(word));
    }

    file.close();
    return spamWords;
}

// Function to check if a message contains 3 or more spam words
// Remeber, the messages and spam words can be in any case so you need to account for that
bool isSpam(const std::string& message, const std::vector<std::string>& spamWords) {
    // TODO code goes here
    std::string lowerMessage = toLowerCase(message);
    for (const auto& spamWord : spamWords) 
    {
        if (lowerMessage.find(spamWord) != std::string::npos) 
        {
            return true;
        }
    }
    return false;
}

// Function to check messages from a list of filenames for spam
void checkMessagesForSpam(const std::vector<std::string>& spamWords, const std::vector<std::string>& filenames) {
    for (const auto& filename : filenames) {
        std::ifstream file("messages/" + filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            continue; 
        }

        std::string message;
        std::getline(file, message, '\0'); // Read the entire file as a single message

        // Check if the message contains any spam words
        if (isSpam(message, spamWords)) {
            std::cout << "Spam detected in file: " << filename << std::endl;
        } else {
            std::cout << "Not spam in file: " << filename << std::endl;
        }

        file.close();
    }
}

int main() {
    // Load spam words from a file
    std::vector<std::string> spamWords = readSpamWords("spam-words-EN.txt");

    // List of filenames in the "messages" folder
    std::vector<std::string> filenames = {
        "message1.txt",
        "message2.txt",
        "message3.txt",
        "message4.txt",
        "message5.txt",
        "longmessage.txt",
        "shortmessage.txt"
    };

    // Check each message file for spam
    checkMessagesForSpam(spamWords, filenames);

    return 0;
}
