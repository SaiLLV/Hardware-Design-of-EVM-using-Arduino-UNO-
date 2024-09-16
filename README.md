
# Hardware Design of EVM using Arduino Uno Board


## Overview
This Arduino project implements a basic Electronic Voting Machine (EVM) using Arduino, push buttons, and a 16x2 LCD display. The EVM allows users to cast votes for multiple candidates and displays real-time vote counts. The system is designed to be intuitive and user-friendly, with features like scrolling through candidates, casting votes, and removing votes.
## Components Used

 * Arduino Board
 * 16x2 LCD Display
* Push Buttons for navigation and voting
* Resistors for button pull-up
* LEDs for visual feedback
* Jumper wires
## Software Libraries Used
* SoftwareSerial (for communication with the LCD)
* LiquidCrystal (for controlling the LCD display)
## Project Description
### 1. Initialization
The setup function initializes the necessary pins, sets up the LCD display, and waits for the number of candidates to be input through the Serial Monitor.
### 2. Main Loop
The main loop continuously displays the current number of candidates on the LCD. Users can navigate through candidates using push buttons, and votes can be cast or removed based on user input.
### 3. Voting Mechanism
* Buttons (10, 7, 8, 13) are used for navigation, allowing the user to scroll through candidates in both directions.
* Buttons A0 and A1 are used for casting and removing votes, respectively.
* The LCD displays the candidate number being voted for or removed.
### 4. Vote Counting
* Votes are stored in an array ('store[]') for each candidate.
* The system continuously updates the LCD with the vote count for each candidate in real-time.
* The candidate with the maximum votes is determined and displayed.
### 5. Visual Feedback
* LEDs on pins 9, 10, 11, and 13 provide visual feedback when buttons are pressed.
* The LCD display shows messages like "+1 vote for candX" or "your vote has been removed".
### 6. Winner Determination
At the end of the voting process, the system identifies the candidate with the maximum votes and displays the winner(s) on the Serial Monitor.
### 7. Extra features
* Users can both cast and remove votes, allowing for a more flexible and user-friendly voting experience.
* LEDs provide instant visual feedback for button presses, enhancing user interactivity and confirming successful actions.
* The LCD dynamically updates in real-time, showing the current number of candidates and vote counts, providing users with continuous feedback.
## Conclusion
This Arduino-based EVM project demonstrates a simple yet effective electronic voting system. It can be further enhanced with additional security features, candidate names, and a more robust user interface. The project serves as a foundation for understanding the basics of building electronic voting systems using Arduino.
## Contributors
Lavanya Vinnakota   
Divya Kilaru

