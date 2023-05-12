/**
 * Project III: Start here.
 */
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

vector<vector<string>> myArray;
int evidence_amount = 0;
const int ROWS = 5;
const int COLS = 2;
int choice;

// Functions to display text in a certain colour.

string getText(string file_name, int line) {
  fstream txt_file;
  txt_file.open(file_name, ios::in);
  string test_line = "";
  for (int i = 0; i < line; i++) {
    getline(txt_file, test_line);
  }
  printf("%c[%dm", 0x1B, 0);
  return test_line;
}

void detectiveText(string file_name, int line) {
  string speech = getText(file_name, line);
  printf("%c[%dm", 0x1B, 34);
  cout << speech << endl;
  sleep(1);
  printf("%c[%dm", 0x1B, 0);
}

int player_choice() {
  int p_choice;
  while (p_choice != 1 || p_choice != 2) {
    cin >> p_choice;
    if (p_choice == 1 || p_choice == 2) {
      return p_choice;
    }
  }
  return p_choice;
}

class Evidence {
public:
  void addEvidence(string evidence, string text) {
    if (myArray.size() < ROWS) { // Check if there is room for more rows
      vector<string> newRow;
      newRow.push_back(evidence);
      newRow.push_back(text);
      myArray.push_back(newRow);
    }
  }

  void printEvidence() { // Prints all, if any, evidence found
    if (myArray.empty()) {
      cout << endl;
      cout << "The evidence menu is empty." << endl;
      cout << endl;
      return;
    }
    for (int i = 0; i < int(myArray.size()); i++) {
      cout << " * ";
      for (int j = 0; j < int(myArray[i].size()); j++) {
        cout << myArray[i][j] << " : ";
      }
      cout << endl;
    }
  }
};

// Evidence Gathering Functions

// Room Call Functions
// PORCH
int callPorch() {
  string pc = "true";
  int porchChoice;
  while (pc == "true") {

    cout << "You walk out onto the porch." << endl;
    cout << "1) Leave the Westwood Residence (This action will conclude Act II)"
         << endl;
    cout << "2) Return to Main Lobby" << endl;

    cin >> porchChoice;
    if (porchChoice == 1) {
      cout << "You left." << endl << endl;
      pc = "false";
      return 1;

    } else if (porchChoice == 2) {
      cout << "You returned to the lobby." << endl << endl;
      pc = "false";
      return 2;

    } else {
      cout << "Invalid input" << endl;
      cout << endl;
      continue;
    }
  }
}

// STUDY
void callStudy() {
  string pc = "true";
  int studyChoice;
  Evidence evidence;
  while (pc == "true") {

    cout << endl;
    cout << "You are in the study." << endl;
    cout << "1) Search Alexander’s Books" << endl;
    cout << "2) Observe Record Player" << endl;
    cout << "3) Observe Alexander’s Corpse" << endl;
    cout << "4) Return to Main Lobby" << endl;

    cin >> studyChoice;
    if (studyChoice == 1) {
      cout << "There are books covering almost any topic imaginable. There is "
              "one with a bookmark in it."
           << endl
           << endl;
      cout << "\"Plants and Their Various Uses by Marcus Brown.\"" << endl;
      cout << "The bookmark is placed in a section named \"Shadowleaf the "
              "midnight flower of death\""
           << endl;
      cout << "This flower produces a black pollen. Ingesting a large amount "
              "will cause seizures and lung failure."
           << endl
           << endl;
      cout << "Additionally, there is a note on the bookmark that reads: 'To "
              "Victoria, from Elizabeth.'"
           << endl;

    } else if (studyChoice == 2) {
      evidence_amount += 1; // Increments evidence amount by one; used for
                            // ending decision at the end
      evidence.addEvidence("Classical Music Record",
                           "Music Record found in the Study Record Player. "
                           "Someone seems to enjoy classical music.");
      cout << "The record player is player a soft melody. It seems Alexander "
              "was a fan of classical music."
           << endl;
      cout << "Evidence Found!" << endl;
      evidence.printEvidence();

    } else if (studyChoice == 3) {
      evidence_amount += 1; // Increments evidence amount by one; used for
                            // ending decision at the end
      evidence.addEvidence(
          "Alexander’s Wedding Ring",
          "A normal wedding ring. Found on Alexander’s body in the study.");
      cout << "Evidence Found!" << endl;
      cout << "Alexander’s hands are grasping at his neck. He has drool marks "
              "running down his chin. He is wearing a wedding ring."
           << endl;
      cout << "Evidence Found!" << endl;
      evidence.printEvidence();

    } else if (studyChoice == 4) {
      cout << "You return to the lobby." << endl << endl;
      pc = false;
    }
  }
}

// BEDROOM
void callBedroom() {
  string pc = "true";
  int bedroomChoice;
  Evidence evidence;
  while (pc == "true") {

    cout << endl;
    cout << "You are in the bedroom." << endl;
    cout << "1) Search Bed" << endl;
    cout << "2) Search Closet" << endl;
    cout << "3) Search Nightstand" << endl;
    cout << "4) Return to Main Lobby" << endl;

    cin >> bedroomChoice;
    if (bedroomChoice == 1) {
      cout
          << "The bed is king sized and the blanket has a floral pattern on it."
          << endl;

    } else if (bedroomChoice == 2) {
      cout << "Just some clothes." << endl;

    } else if (bedroomChoice == 3) {
      evidence_amount += 1; // Increments evidence amount by one; used for
                            // ending decision at the end
      evidence.addEvidence(
          "Victoria’s Wedding Ring",
          "A very extravagant, diamond-encrusted wedding ring. Found in a "
          "nightstand drawer in the bedroom.");
      cout << "A small container is left open. Inside is a diamond "
              "encrusted-wedding ring."
           << endl;
      cout << "Evidence Found!" << endl;
      evidence.printEvidence();

    } else if (bedroomChoice == 4) {
      cout << "You return to the lobby." << endl << endl;
      pc = false;
    }
  }
}

/// KITCHEN
void callKitchen() {
  string pc = "true";
  int kitchenChoice;
  Evidence evidence;
  while (pc == "true") {

    cout << endl;
    cout << "You are in the kitchen." << endl;
    cout << "1) Search stove" << endl;
    cout << "2) Search cooler" << endl;
    cout << "3) Search garbage bin" << endl;
    cout << "4) Search cabinets" << endl;
    cout << "5) Return to Main Lobby" << endl;

    cin >> kitchenChoice;
    if (kitchenChoice == 1) {
      cout << "A pot containing leftover soup is on it. It does not look "
              "delectable."
           << endl;

    } else if (kitchenChoice == 2) {
      cout << "A lot of wine is stored here. It appears they are vintage and "
              "expensive."
           << endl;

    } else if (kitchenChoice == 3) {
      evidence_amount += 1; // Increments evidence amount by one; used for
                            // ending decision at the end
      evidence.addEvidence("Stained Vial",
                           "Empty vial stained with some dark powder on the "
                           "inside. Found in the garbage bin in the kitchen.");
      cout << "It is mostly rotting onion peels and potato skin. One thing of "
              "interest however is a vial with a black powder lightly coating "
              "the inside."
           << endl;
      cout << "Evidence Found!" << endl;
      evidence.printEvidence();

    } else if (kitchenChoice == 4) {
      cout << "A lot of pots and pans and other utensils can be found." << endl;

    } else if (kitchenChoice == 5) {
      cout << "You return to the lobby." << endl << endl;
      pc = false;
    }
  }
}

/// DINING ROOM
void callDining() {
  string pc = "true";
  int diningChoice;
  while (pc == "true") {

    cout << endl;
    cout << "You are in the dining room." << endl;
    cout << "1) Search dining table" << endl;
    cout << "2) Search window" << endl;
    cout << "3) Return to Main Lobby" << endl;

    cin >> diningChoice;
    if (diningChoice == 1) {
      cout << "On the table is an open bottle of wine. It seems one glass has "
              "been poured."
           << endl;

    } else if (diningChoice == 2) {
      cout << "It seems one of the large window panes in the dining room has "
              "been shattered. It appears to be a possible break-in"
           << endl;

    } else if (diningChoice == 3) {
      cout << "You return to the lobby." << endl << endl;
      pc = false;
    }
  }
}

/// LOBBY
void callLobby() {
  string pc = "true";
  int lobbyChoice;
  while (pc == "true") {

    cout << endl;
    cout << "You are in the main lobby room." << endl;
    cout << "1) Observe the Pictures on the Walls:" << endl;
    cout << "2) Return to lobby menu" << endl;

    cin >> lobbyChoice;
    if (lobbyChoice == 1) {
      cout << "Wedding photo: A black and white photo of Victoria and "
              "Alexander on their wedding day. On it, there’s a date: 24th of "
              "December, 1909."
           << endl
           << endl;
      cout << "Alexander's portrait: It seems to be a portrait when he was "
              "younger and in the army."
           << endl
           << endl;
      cout << "Well-known painting: An extremely valuable painting of a vase "
              "full of sunflowers."
           << endl
           << endl;
      cout << "Starry painting: A painting of a violet sky, swirling with stars"
           << endl;

    } else if (lobbyChoice == 2) {
      pc = false;
    }
  }
}

// End of Evidence Gathering Functions

void act_1() { // Act 1 of story

  cout << endl;
  sleep(1);
  cout << "[Searching for Connection...]" << endl;
  sleep(1);
  cout << "[Connection Found. Receiving…]" << endl;
  cout << endl;

  sleep(1);
  detectiveText("act1_davis.txt", 1); // Prints detective text in blue
  sleep(1); // sleep() function serves as a means of spacing out dialogue in
            // digestible chunks.
  cout << "1) " << getText("act1_player.txt", 1)
       << endl; // Gives player two dialogue
  cout << "2) " << getText("act1_player.txt", 2)
       << endl;             // options to chose from
  choice = player_choice(); // Player inputs choice, story continues
  sleep(1);

  detectiveText("act1_davis.txt", 2);
  sleep(1);
  cout << "1) " << getText("act1_player.txt", 3) << endl;
  cout << "2) " << getText("act1_player.txt", 4) << endl;
  choice = player_choice();
  sleep(1);

  if (choice == 1) {
    detectiveText("act1_davis.txt", 3);
    detectiveText("act1_davis.txt", 4);
  } else {
    detectiveText("act1_davis.txt", 5);
    detectiveText("act1_davis.txt", 6);
  }
  cout << "1) " << getText("act1_player.txt", 5) << endl;
  cout << "2) " << getText("act1_player.txt", 6) << endl;

  choice = player_choice();
  sleep(1);
  detectiveText("act1_davis.txt", 7);
  sleep(2);
  detectiveText("act1_davis.txt", 8);
  cout << "1) " << getText("act1_player.txt", 7) << endl;
  cout << "2) " << getText("act1_player.txt", 8) << endl;
  choice = player_choice();
  sleep(1);
  if (choice == 1) {
    detectiveText("act1_davis.txt", 9);
    sleep(1);
    cout << "1) " << getText("act1_player.txt", 9) << endl;
    cout << "2) " << getText("act1_player.txt", 10) << endl;
    choice = player_choice();
    sleep(1);
  }

  detectiveText("act1_davis.txt", 10);
  sleep(1);
  cout << "1) " << getText("act1_player.txt", 11) << endl;
  cout << "2) " << getText("act1_player.txt", 12) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act1_davis.txt", 11);
  detectiveText("act1_davis.txt", 12);
  detectiveText("act1_davis.txt", 13);
  sleep(1);
  cout << "1) " << getText("act1_player.txt", 13) << endl;
  cout << "2) " << getText("act1_player.txt", 14) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act1_davis.txt", 14);
  detectiveText("act1_davis.txt", 15);
  sleep(1);
  cout << "1) " << getText("act1_player.txt", 15) << endl;
  cout << "2) " << getText("act1_player.txt", 16) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act1_davis.txt", 16);
  detectiveText("act1_davis.txt", 17);
  detectiveText("act1_davis.txt", 18);
  sleep(1);
  cout << "1) " << getText("act1_player.txt", 17) << endl;
  cout << "2) " << getText("act1_player.txt", 18) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act1_davis.txt", 19);
  detectiveText("act1_davis.txt", 20);
  sleep(1);
  cout << "1) " << getText("act1_player.txt", 19) << endl;
  cout << "2) " << getText("act1_player.txt", 20) << endl;
  choice = player_choice();
  sleep(1);

  if (choice == 1) {
    detectiveText("act1_davis.txt", 21);
    detectiveText("act1_davis.txt", 22);
    sleep(1);
  } else {
    detectiveText("act1_davis.txt", 22);
    detectiveText("act1_davis.txt", 21);
    sleep(1);
  }
  detectiveText("act1_davis.txt", 23);
  detectiveText("act1_davis.txt", 24);
  detectiveText("act1_davis.txt", 25);
  sleep(1);
  cout << "1) " << getText("act1_player.txt", 21) << endl;
  cout << "2) " << getText("act1_player.txt", 22) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act1_davis.txt", 26);
  detectiveText("act1_davis.txt", 27);
  cout << "[Connection lost.]" << endl;
}

void act_2_beginning() { // Dialogue for the beginning of Act 2
  Evidence evidence;
  cout << "[Searching for Connection…]" << endl;
  cout << "[Connection found. Reconnecting…]" << endl;
  cout << endl;
  sleep(1);

  detectiveText("act2_davis.txt", 1);
  sleep(1);
  cout << "1) " << getText("act2_player.txt", 1) << endl;
  cout << "2) " << getText("act2_player.txt", 2) << endl;
  choice = player_choice();
  sleep(1);
  detectiveText("act2_davis.txt", 2);
  detectiveText("act2_davis.txt", 3);
  detectiveText("act2_davis.txt", 4);

  evidence_amount += 1; // Increments evidence amount by one; used for ending
                        // decision at the end. This evidence is guaranteed.
  evidence.addEvidence("Robert’s Cigarettes",
                       "Robert seems to be an avid smoker. He probably won’t "
                       "last very long using those.");
  cout << "Evidence Found!" << endl;
  evidence.printEvidence();

  sleep(1);
  cout << "1) " << getText("act2_player.txt", 3) << endl;
  cout << "2) " << getText("act2_player.txt", 4) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act2_davis.txt", 5);
  detectiveText("act2_davis.txt", 6);
  sleep(1);
  cout << "1) " << getText("act2_player.txt", 5) << endl;
  cout << "2) " << getText("act2_player.txt", 6) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act2_davis.txt", 7);
  sleep(1);
  cout << "1) " << getText("act2_player.txt", 7) << endl;
  cout << "2) " << getText("act2_player.txt", 8) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act2_davis.txt", 8);
  detectiveText("act2_davis.txt", 9);
  sleep(1);
}
void evidenceGame() {
  char roomChoice;
  bool Act2Flag = false;
  vector<string> houseRooms = {"(p)orch",   "(s)tudy",       "(b)edroom",
                               "(k)itchen", "(d)ining room", "(l)ook in lobby"};

  while (Act2Flag == false) {
    cout << "You are in the main lobby. Where will you go next?" << endl
         << "(Type the first character of your choice.)" << endl
         << endl;
    for (unsigned int i = 0; i < houseRooms.size(); i++) {
      cout << "(" << houseRooms.at(i) << ")" << endl;
    }

    cin >> roomChoice;
    cout << endl;

    switch (roomChoice) {
    case 'p': {
      int call = callPorch();
      if (call == 1) {
        Act2Flag = true;
        break;
      } else if (call == 2) {
        break;
      }
    }
    case 's': {
      callStudy();
      break;
    }
    case 'b': {
      callBedroom();
      break;
    }
    case 'k': {
      callKitchen();
      break;
    }
    case 'd': {
      callDining();
      break;
    }
    case 'l': {
      callLobby();
      break;
    }
    default:
      cout << "Please select a room." << endl;
    }
  }
  Act2Flag = true;
}

void act_2_end(int evidence_amount) { // Dialogue for end of Act 2. Depending on
                                      // the amount of evidence found, different
                                      // dialogue will play from Davis

  if (evidence_amount < 2) {
    detectiveText("act2_davis.txt", 11);
    sleep(1);
  } else {
    detectiveText("act2_davis.txt", 10);
    sleep(1);
  }
  cout << "1) " << getText("act2_player.txt", 9) << endl;
  cout << "2) " << getText("act2_player.txt", 10) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act2_davis.txt", 12);
  detectiveText("act2_davis.txt", 13);

  cout << "[Connection lost.]" << endl;
}

void act_3_ending1() { // Ending given if player did not find more than two
                       // evidences. The Bad Ending: The Unhelpful.

  cout << "[Searching for Connection…]" << endl;
  sleep(1);
  cout << "[Connection found. Reconnecting]" << endl;
  cout << endl;
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 1);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 1) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 2) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 2);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 3) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 4) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 3);
  detectiveText("act3_ending1_davis.txt", 4);
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 5);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 5) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 6) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 6);
  detectiveText("act3_ending1_davis.txt", 7);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 7) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 8) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 8);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 9) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 10) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 9);
  sleep(1);
  cout << "[Connection lost.]" << endl;
  cout << "[Searching for Connection...]" << endl;
  sleep(5);
  cout << "[Connection found. Reconnecting...]" << endl;
  cout << endl;
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 10);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 11) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 12) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 11);
  detectiveText("act3_ending1_davis.txt", 12);
  sleep(1);
  detectiveText("act3_ending1_davis.txt", 13);
  detectiveText("act3_ending1_davis.txt", 14);
  detectiveText("act3_ending1_davis.txt", 15);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 13) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 14) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 16);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 15) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 16) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 17);
  detectiveText("act3_ending1_davis.txt", 18);
  sleep(1);
  cout << "1) " << getText("act3_ending1_player.txt", 17) << endl;
  cout << "2) " << getText("act3_ending1_player.txt", 18) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 19);
  detectiveText("act3_ending1_davis.txt", 20);
  sleep(1);
  detectiveText("act3_ending1_davis.txt", 21);
  sleep(2);
  detectiveText("act3_ending1_davis.txt", 22);
  detectiveText("act3_ending1_davis.txt", 23);
  sleep(1);
  detectiveText("act3_ending1_davis.txt", 24);
  sleep(1);
  cout << "[Connection lost.]" << endl;
  sleep(1);
  cout << "[Searching for Connection...]" << endl;
  sleep(2);
  cout << "[Connection terminated. Exiting...]" << endl;
  sleep(2);

  cout << "Ending Reached: The Unhelpful." << endl;
  sleep(1);
}

void act_3_ending2() { // Ending given if player found about two evidences, but
                       // not all evidences. The Good Ending: The Detective.

  cout << "[Searching for Connection…]" << endl;
  cout << "[Connection found. Reconnecting]" << endl;
  cout << endl;
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 1);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 1) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 2) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 2);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 3) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 4) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 3);
  detectiveText("act3_ending2_davis.txt", 4);
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 5);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 5) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 6) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 6);
  detectiveText("act3_ending2_davis.txt", 7);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 7) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 8) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 8);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 9) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 10) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 9);
  sleep(1);
  cout << "[Connection lost.]" << endl;
  sleep(1);
  cout << "[Searching for Connection...]" << endl;
  sleep(5);
  cout << "[Connection found. Reconnecting...]" << endl;
  cout << endl;
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 10);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 11) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 12) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 11);
  detectiveText("act3_ending2_davis.txt", 12);
  sleep(1);
  detectiveText("act3_ending2_davis.txt", 13);
  detectiveText("act3_ending2_davis.txt", 14);
  detectiveText("act3_ending2_davis.txt", 15);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 13) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 14) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 16);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 15) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 16) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 17);
  detectiveText("act3_ending2_davis.txt", 18);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 17) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 18) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 19);
  sleep(1);
  detectiveText("act3_ending2_davis.txt", 20);
  detectiveText("act3_ending2_davis.txt", 21);
  detectiveText("act3_ending2_davis.txt", 22);
  detectiveText("act3_ending2_davis.txt", 23);
  sleep(1);
  detectiveText("act3_ending2_davis.txt", 24);
  sleep(1);
  detectiveText("act3_ending2_davis.txt", 25);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 19) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 20) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending2_davis.txt", 26);
  detectiveText("act3_ending2_davis.txt", 27);
  detectiveText("act3_ending2_davis.txt", 28);
  sleep(1);
  cout << "1) " << getText("act3_ending2_player.txt", 21) << endl;
  cout << "2) " << getText("act3_ending2_player.txt", 22) << endl;
  choice = player_choice();
  sleep(1);

  cout << "[Connection lost.]" << endl;
  sleep(1);
  cout << "[Searching for Connection...]" << endl;
  sleep(2);
  cout << "[Connection terminated. Exiting...]" << endl;
  sleep(2);

  cout << "Ending Reached: The Detective." << endl;
  sleep(1);
}

void act_3_ending3() { // Ending given if player found all evidences. The True
                       // Ending: The Just.

  cout << "[Searching for Connection…]" << endl;
  cout << "[Connection found. Reconnecting]" << endl;
  cout << endl;
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 1);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 1) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 2) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 2);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 3) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 4) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 3);
  detectiveText("act3_ending3_davis.txt", 4);
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 5);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 5) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 6) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 6);
  detectiveText("act3_ending3_davis.txt", 7);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 7) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 8) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 8);
  detectiveText("act3_ending3_davis.txt", 9);
  detectiveText("act3_ending3_davis.txt", 10);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 9) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 10) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 11);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 11) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 12) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 12);
  detectiveText("act3_ending3_davis.txt", 13);
  detectiveText("act3_ending3_davis.txt", 14);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 13) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 14) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 15);
  detectiveText("act3_ending3_davis.txt", 16);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 17);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 18);
  cout << "1) " << getText("act3_ending3_player.txt", 15) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 16) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending1_davis.txt", 19);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 17) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 18) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 19);
  detectiveText("act3_ending3_davis.txt", 20);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 21);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 22);
  cout << "1) " << getText("act3_ending3_player.txt", 19) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 20) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 24);
  sleep(1);
  cout << "[Connection lost.]" << endl;
  sleep(1);
  cout << "[Searching for Connection...]" << endl;
  sleep(5);
  cout << "[Connection found. Reconnecting...]" << endl;
  cout << endl;
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 25);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 21) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 22) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 26);
  detectiveText("act3_ending3_davis.txt", 27);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 28);
  detectiveText("act3_ending3_davis.txt", 29);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 30);
  detectiveText("act3_ending3_davis.txt", 31);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 32);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 23) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 24) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 33);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 25) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 26) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 34);
  detectiveText("act3_ending3_davis.txt", 35);
  sleep(3);
  detectiveText("act3_ending3_davis.txt", 36);
  detectiveText("act3_ending3_davis.txt", 37);
  cout << "1) " << getText("act3_ending3_player.txt", 27) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 28) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 38);
  detectiveText("act3_ending3_davis.txt", 39);
  cout << "1) " << getText("act3_ending3_player.txt", 29) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 30) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 40);
  detectiveText("act3_ending3_davis.txt", 41);
  cout << "1) " << getText("act3_ending3_player.txt", 31) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 32) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 42);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 33) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 34) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 43);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 44);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 45);
  detectiveText("act3_ending3_davis.txt", 46);
  detectiveText("act3_ending3_davis.txt", 47);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 48);
  detectiveText("act3_ending3_davis.txt", 49);
  detectiveText("act3_ending3_davis.txt", 50);
  detectiveText("act3_ending3_davis.txt", 51);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 52);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 53);
  detectiveText("act3_ending3_davis.txt", 54);
  detectiveText("act3_ending3_davis.txt", 55);
  detectiveText("act3_ending3_davis.txt", 56);
  detectiveText("act3_ending3_davis.txt", 57);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 58);
  detectiveText("act3_ending3_davis.txt", 59);
  sleep(2);
  detectiveText("act3_ending3_davis.txt", 60);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 61);
  sleep(2);
  detectiveText("act3_ending3_davis.txt", 62);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 35) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 36) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 63);
  detectiveText("act3_ending3_davis.txt", 64);
  detectiveText("act3_ending3_davis.txt", 65);
  sleep(1);
  cout << "1) " << getText("act3_ending3_player.txt", 37) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 38) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 66);
  detectiveText("act3_ending3_davis.txt", 67);
  detectiveText("act3_ending3_davis.txt", 68);
  detectiveText("act3_ending3_davis.txt", 69);
  sleep(1);
  detectiveText("act3_ending3_davis.txt", 70);
  cout << "1) " << getText("act3_ending3_player.txt", 37) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 38) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 71);
  detectiveText("act3_ending3_davis.txt", 72);
  detectiveText("act3_ending3_davis.txt", 73);
  cout << "1) " << getText("act3_ending3_player.txt", 37) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 38) << endl;
  choice = player_choice();
  sleep(1);

  detectiveText("act3_ending3_davis.txt", 74);
  sleep(2);
  detectiveText("act3_ending3_davis.txt", 75);
  cout << "1) " << getText("act3_ending3_player.txt", 39) << endl;
  cout << "2) " << getText("act3_ending3_player.txt", 40) << endl;
  choice = player_choice();
  sleep(1);

  cout << "[Response Unsuccessful.]" << endl;
  sleep(1);
  cout << "[Connection lost.]" << endl;
  sleep(2);
  cout << "[Searching for Connection…]" << endl;
  sleep(3);
  cout << "[Connection terminated. Exiting…]" << endl;
  sleep(2);

  cout << "True Ending Reached: The Just." << endl;
  sleep(1);
}

void game() { // Function called for the game itself.
  // Act 1: The "Detective"
  act_1();
  sleep(3);
  // Act 2: The Search
  act_2_beginning();
  evidenceGame();
  act_2_end(evidence_amount);
  sleep(3);
  // Act 3: [Different Endings]
  if (evidence_amount ==
      5) { // If player has all 5 evidences, the true ending is given. This also
           // semi-prevents player to play the game too many times and
           // incrementing the counter past 5. Doing so will just give the
           // regular ending.
    act_3_ending3();
  } else if (evidence_amount < 2) { // If player did not find more than 2
                                    // evidences, the bad ending is given.
    act_3_ending1();
  } else { // The default ending is the good ending. This happens if the
           // player's evidence amount is between 2 and 5 (or past 5 in the rare
           // case).
    act_3_ending2();
  }
}

void startUp(
    Evidence &evidence) { // Start-up for game. Has menus for starting the game,
                          // viewing the evidence menu, or quitting the game.

  do {
    cout << "Welcome to Smoke and Mirrors™ A game full of mystery" << endl;
    cout << "Pick an option" << endl;
    cout << "(1) Start Game" << endl;
    cout << "(2) Evidence Menu" << endl;
    cout << "(3) Quit " << endl;
    try { // Uses catch and throw to check for invalid user input
      cin >> choice;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Invalid input. Please enter a number.");
      }
      switch (choice) {
      case 1:
        game();
        break;
      case 2:
        evidence.printEvidence();
        break;
      case 3:
        break;
      default:
        cout << "Enter Valid number" << endl;
      }
    } catch (exception &e) {
      cout << "Error: " << e.what() << endl;
    }
  } while (choice != 3);
  cout << "Have a nice day!" << endl;
}
