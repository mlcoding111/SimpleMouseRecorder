// Simple Mouse Recorder.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Coded by Michael Lacroix
// This is a simple mouse recorder just to play around with vectors

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;


// Function to print the mouse location
void printMousePos(POINT mouseLoc) {
    cout << "X : " << mouseLoc.x << "| Y : " << mouseLoc.y << endl;
}

// Store the main menu
// int& to pass the value by reference and not by value
void mainMenu(int& userChoice) {
    cout << "Mouse Recorder v0.1 by Michael\n\n";
    cout << "1. Start recording\n";
    cout << "2. Play previous recording\n";
    cout << "3. Exit\n";
    cin >> userChoice;
}

// We receive the vector and push_back the current mouse location
void recordMouse(vector<int>& x, vector<int>& y, POINT& p) {
        GetCursorPos(&p); // we get mouse coords from the received location ( POINT )
        cout << "X : " << p.x << "| Y : " << p.y << endl;
        x.push_back(p.x);
        y.push_back(p.y);    
}

// We loop trough the vector mouseX and mouseY using position as a reference which is a reference to ( playCount )
// Once the loop completed 1 time , it will set the vector at : mouseX.at(1), mouseX.at(2), and so on..
void play(vector<int>& x, vector<int>& y, int& position) {
    SetCursorPos(x.at(position), y.at(position));
}


int main()
{
    // VARIABLES
    vector<int> mouseX{};
    vector<int> mouseY{};
    
    int choice{ 0 }; // User menu choice
    int recordAmount{ 50 }; // This variable store how many locations you want to record before closing
    int recordingCount{ 0 };
    int playCount{ 0 }; // Keep tracks of how many time it played

    bool isRecording{ false }; 
    bool exit{ false };
    bool playLoop{ false };


    POINT p; // We must initialize a new point to play around with the mouse location

    // This loop wont exit until the user enter 3 as a choice
    while (!exit){

        // If we are recording run the loop X times
        while (isRecording) {
            if (recordingCount == recordAmount) {
                isRecording = false;
            }            
            system("cls");
            recordMouse(mouseX, mouseY, p);
            recordingCount++;
        } 
        // If user want to play the loop
        while (playLoop) {
            if (playCount == recordAmount) {
                playLoop = false;
            }
            system("cls");
            play(mouseX, mouseY, playCount);
            playCount++;
        }

         system("cls");
         mainMenu(choice);

        // Process the desired choice
        switch (choice) {
        case 1: 
            mouseX.clear();
            mouseY.clear();
            isRecording = true;
            break;
        case 2:
            playLoop = true;
            break;
        case 3:
            exit = true;
            break;
        }
    }


}

