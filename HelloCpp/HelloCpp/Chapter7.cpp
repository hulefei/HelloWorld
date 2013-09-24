//
//  Chapter7.cpp
//  HelloCpp
//
//  Created by Hanson on 13-9-24.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

#include <iostream>
#include <string>
#include "Chapter7.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void Chapter7::helloworld() {
    cout << "helloworld" << endl;
};

void Chapter7::method01() {
    long number = 50L;
    long* pnumber;                               // Pointer declaration
    pnumber = &number;                           // Store the address of number
    cout << endl
    << "The value stored in the variable number is "
    << *pnumber
    << endl;
};

void Chapter7::method02() {
    long* pnumber;                        // Pointer declaration
    long number1 = 55L;
    long number2 = 99L;                   // A couple of variables
    
    pnumber = &number1;                   // Store address in pointer
    *pnumber += 11;                       // Increment number1 by 11
    cout << endl
    << "number1 = "     << number1
    << "   &number1 = " << pnumber
    << endl; //number1 = 66   &number1 = 内存地址
    
    pnumber = &number2;                   // Change pointer to address of number2
    number1 = *pnumber * 10;              // 10 times number2
    
    cout << "number1 = "     << number1
    << "   pnumber = "  << pnumber
    << "   *pnumber = " << *pnumber
    << endl;//number1 = 990   pnumber = 内存地址   *pnumber = 99
}

void Chapter7::method03() {
    // The lucky stars referenced through pointers
    const char* pstar1 = "Mae West";
    const char* pstar2 = "Arnold Schwarzenegger";
    const char* pstar3 = "Lassie";
    const char* pstar4 = "Slim Pickens";
    const char* pstar5 = "Greta Garbo";
    const char* pstar6 = "Oliver Hardy";
    const char* pstr   = "Your lucky star is ";
    
    int choice = 0;                       // Star selector
    
    cout << endl
    << "Pick a lucky star!"
    << " Enter a number between 1 and 6: ";
    cin >> choice;
    
    cout << endl;
    
    switch(choice) {
        case 1:
            cout << pstr << pstar1;
            break;
        case 2:
            cout << pstr << pstar2;
            break;
        case 3:
            cout << pstr << pstar3;
            break;
        case 4:
            cout << pstr << pstar4;
            break;
        case 5:
            cout << pstr << pstar5;
            break;
        case 6:
            cout << pstr << pstar6;
            break;
        default:
            cout << "Sorry, you haven't got a lucky star.";
    }
    
    cout << endl;
}
//指针数组
void Chapter7::method04() {
    const char* pstars[] = {
        "Mae West",                      // Initializing a pointer array
        "Arnold Schwarzenegger",
        "Lassie",
        "Slim Pickens",
        "Greta Garbo",
        "Oliver Hardy"
    };
    const char* pstr = "Your lucky star is ";
    int choice = 0;
    
    const int starCount = sizeof pstars / sizeof pstars[0];   // Get array size
    
    cout << endl
    << "Pick a lucky star!"
    << " Enter a number between 1 and "
    << starCount
    << ": ";
    cin >> choice;
    
    cout << endl;
    if(choice >= 1 && choice <= starCount)                    // Check for valid input
        cout << pstr << pstars[choice - 1];                     // Output star name
    else
        cout << "Sorry, you haven't got a lucky star.";         // Invalid input
    
    cout << endl;
}

void Chapter7::method05() {
    string text;                                            // The string to be sorted
    const string separators = " ,.\"\n";                    // Word delimiters
    const int max_words = 1000;                             // Maximum number of words
    string words[max_words];                                // Array to store the words
    string* pwords[max_words];                              // Array of pointers to the words
    
    // Read the string to be searched from the keyboard
    cout << endl << "Enter a string terminated by #:" << endl;
    getline(cin, text, '#');
    
    // Extract all the words from the text
    long start = text.find_first_not_of(separators);         // Word start index
    long end = 0;                                            // End delimiter index
    int word_count = 0;                                     // Count of words stored
    while(start != string::npos && word_count < max_words) {
        end = text.find_first_of(separators, start + 1);
        if(end == string::npos)                               // Found a separator?
            end = text.length();                                // No, so set to last + 1
        
        words[word_count] = text.substr(start, end - start);  // Store the word
        pwords[word_count] = &words[word_count];              // Store the pointer
        word_count++;                                         // Increment count
        
        // Find the first character of the next word
        start = text.find_first_not_of(separators, end + 1);
    }
    
    //选择排序
    // Sort the words in ascending sequence by direct insertion
    int lowest = 0;                                         // Index of lowest word
    
    for(int j = 0; j < word_count - 1; j++) {
        lowest = j;                                           // Set lowest
        
        // Check current against all the following words
        for(int i = j + 1 ; i < word_count ; i++)
            if(*pwords[i] < *pwords[lowest])                    // Current is lower?
                lowest = i;
        
        if(lowest != j) {          // Then swap pointers...
            string* ptemp = pwords[j];                          // Save current
            pwords[j] = pwords[lowest];                         // Store lower in current
            pwords[lowest] = ptemp;                             // Restore current
        }
    }
    
    // Output the words in ascending sequence
    for(int i = 0 ; i < word_count ; i++)
        cout << endl << *pwords[i];
    
    cout << endl;
}
