#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>

void zeroFlag(int& goal) {
    while (goal <= 0) {
        std::cin >> goal;
        std::cin.ignore();
        if (goal <= 0) {
            std::cout << "Error, enter a number bigger than 0" << std::endl;
        }
    }
}

//function for petition name input
void nameEnter(std::vector<std::string>& nameVect, int iteration);

//function for petiton phone number input
void phoneEnter(std::vector<std::string>& phoneVect, int iterarion);

//function for petiton email address input
void emailEnter(std::vector<std::string>& emailVect, int iteration);

//file writting function;
void petitionfileWrite(std::string &petitionTitle,std::vector<std::string> &nameVect, std::vector<std::string> &phoneVect,
std::vector<std::string> &emailVect, std::ofstream &file);

int main() {
    //Variable declarations
    std::ofstream contactFile("PetitionList.txt");
    if (!contactFile.is_open()) { //Ensuring file opens with no errors
        std::cerr << "Error opening file!" << std::endl;
        return 1; // Exit with an error code
    }

    std::vector<std::string> petitionNames;
    std::vector<std::string> phoneNumbers;
    std::vector<std::string> emailAddresses;
    int startingGoal = 0;
    std::string title = "";

    //User prompt 
    std::cout << "What is your petition starting goal?: ";
    //loop function to ensure a negative number or 0 can't be inputted
    zeroFlag(startingGoal);

    std::cout << "Enter petition title: ";
    getline(std::cin, title);

    for (int i = 0; i < startingGoal; i++) {
        nameEnter(petitionNames, i);
        phoneEnter(phoneNumbers, i);
        emailEnter(emailAddresses, i);
    }
    
    //Writing all the vector info into a txt file
    petitionfileWrite(title, petitionNames, phoneNumbers, emailAddresses, contactFile);

    contactFile.close();
    return 0;
}

//WELCOME TO THE FUNCTION ZONE, COME ONE COME ALL!!!
void nameEnter(std::vector<std::string>& nameVect ,int iteration) {
    std::string name;
    std::cout << "Enter name: ";
    getline(std::cin, name);
    nameVect.push_back(name);
}

void phoneEnter(std::vector<std::string> &phoneVect, int iteration) {
    std::string phoneNum;
    std::cout << "Enter phone number: ";
    getline(std::cin, phoneNum);
    phoneVect.push_back(phoneNum);
}

void emailEnter(std::vector<std::string> &emailVect, int iteration) {
    std::string email;
    std::cout << "Enter email address: ";
    getline(std::cin, email);
    emailVect.push_back(email);
}

void petitionfileWrite(std::string &petitionTitle, std::vector<std::string> &nameVect, std::vector<std::string> &phoneVect, 
                       std::vector<std::string> &emailVect, std::ofstream &file) {
    file << petitionTitle << std::endl;
    file << "Names" << std::setw(30) << "Phone Numbers" << std::setw(30) << "Emails" << std::endl;
    for (int i = 0; i < nameVect.size(); i++) {
        file << nameVect[i] << std::setw(30) << std::setfill('*') << phoneVect[i] << std::setw(30) << std::setfill('*') << emailVect[i] << std::endl;
    }
}