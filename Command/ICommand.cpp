#include "ICommand.h"

void MoveLeftCommand::Exec(Player& player) { player.MoveLeft(); }

void MoveRightCommand::Exec(Player& player) { player.MoveRight(); }
