#ifndef EVIDENCE_H
#define EVIDENCE_H

#include <vector>
#include <string>

const int ROWS = 5;
const int COLS = 2;

class Evidence {

public:
    void addEvidence(std::string evidence, std::string text);
    void printEvidence();
};

#endif