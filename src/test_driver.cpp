/**
 * Project III: Start testing here.
 */
#include "library.h"
#include <assert.h>
#include <iostream>
#include <assert.h>
#include <sstream>

using namespace std;

int main() {
    //testing get text function
    string actual_output = getText("act1_player.txt", 1);
    assert(actual_output == "Yes, I can hear you, over.");

    //testing evidence class
    stringstream output;
    Evidence evidence;
    streambuf* oldCoutStreamBuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());
    evidence.addEvidence("Evidence 1", "Text 1");
    evidence.printEvidence();
    cout.rdbuf(oldCoutStreamBuf);
    assert(output.str() == " * Evidence 1 : Text 1 : \n");

    detectiveText("act1_davis.txt", 1);
}
