# CPTR 142: Project III

## Game: Smoke and Mirrors

The goal for this project is to create a text-based game about a murder mystery. This story is told through the perspective of a detective talking to the player, and the player's objective is to find evidence and guide the detective to the true suspect. We will need to organize the text and branching choices into functions to call from. There will be different endings depending on the amount of evidence found.

* Known Bugs:
    * Certain text lines carry over into the next line (formatting issue).
    * Going back into a room after finding evidence causes evidence counter to be offset.
    * Typing character into option during evidence gathering causes infinite loop.
    * Not typing '1' or '2' into option during dialogue portion causes player to be softlocked.
    * The file **test_driver.cpp** is not running. This file is used to test functions in **library.cpp**.

## How to Play

Start the game by selecting option (1), Start Game.

During dialogue portion of the game, select your dialogue option using the prompts (type 1 or 2).

During the evidence gathering portion of the game, follow the prompts to go into different rooms. In the rooms, you can try to find evidence and context clues by observing and interacting with certain objects.
To end evidence gathering, go to the porch and leave the Westwood estate.

## Additional Notes

Not satisfied with your ending? It is likely that you didn't find all of the evidence. Replay the game and find the different endings!