# SpellsMaster:
Spell Master is a two-player game in which wizards battle by taking turns casting spells. Players are provided with a list of spells they can choose from. Each player must continue to cast a spell that is more powerful than the one cast by the other player. For a spell to be more powerful, it should satisfy two requirements: it should not have been cast during the battle before, and the first character of the spell should be the same as the last character of the spell chosen in the previous round by the other player.
Rules:
  1. A spell may only be chosen from the provided list of spells.
  2. A spell may only be chosen once (repetitions are not allowed).
  3. With the exception of the first spell, every chosen spell’s first character must match the last character of the previously chosen spell.
  4. A player wins if their opponent fails to cast a spell satisfying the previously stated conditions (1-3). That is:
     (a) if the opponent casts a spell that is not part of the provided list, or
     (b) if the opponent chooses a spell that has already been cast during the battle, or
     (c) if the opponent chooses a spell whose first character does not match the last character of the previously chosen spell, or
     (d) if the opponent runs out of spells that satisfy the matching characters condition.
  5. The game ends if one of the players wins.
Note that spells are formed of single words that begin and end with lower case characters and contain no spaces or special characters.
