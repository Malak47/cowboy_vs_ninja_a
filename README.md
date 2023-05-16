# cowboy_vs_ninja_a

In this exercise, we will create a simulation of a battle between ninjas and cowboys.

# Part 1 Point

First, we will write a class that will help us keep track of the position on the game board. The position is given by
two coordinates of type double that represent the unit's location along the x and y axes, respectively. The class
interface should support the following operations:

- `Constructor` that takes two coordinates.
- `distance` method that takes a point and calculates the distance between the two points.
- `print` method that prints the two coordinates within parentheses.
- `moveTowards` method that takes a source point, a target point, and a distance. The function returns the point closest
  to the target point that is within the given distance from the source point.

# Part 2 Character

This class represents a **character**. A character has a position (of type Point), a hit points value (represented by an
integer), and a name (represented by a string). The character class defines the following functions:

- `isAlive` method that returns a boolean value indicating whether the character is alive (i.e., has more than zero hit
  points).
- `distance` method that takes a pointer to another character and returns the distance between the characters (as a
  double).
- `hit` method that takes an integer value representing the damage points and subtracts it from the character's hit
  points.
- `getName` method that returns the character's name.
- `getLocation` method that returns the character's position.
- `print` method that prints the character's name, the number of hit points, and the character's position. If the
  character is dead (hit points are zero), the number of hit points will not be printed, and the name will be enclosed
  in parentheses. Before the name, there will be a letter indicating the type of character: "N" for ninja and "C" for
  cowboy.

For **cowboys**, there is an additional parameter defined called "bullets" (an integer). Cowboys are always created with six
bullets and 110 hit points. The following functions are defined specifically for cowboys:

- `shoot` method that takes a pointer to an enemy. If the cowboy is alive and has bullets remaining, the cowboy shoots
  the enemy, deducting 10 hit points from the enemy and losing one bullet. Otherwise, no damage will be inflicted on the
  enemy.
- `hasBullets` method that returns a boolean value indicating whether the cowboy has bullets left in the gun.
- `reload` method that reloads the gun with six new bullets.

For **ninjas**, there is a parameter defined called "speed" (an integer). The following functions are defined specifically
for ninjas:

- `move` method that takes a pointer to an enemy and advances towards the enemy. The ninja moves a distance equal to its
  speed.
- `slash` method that takes a pointer to an enemy. If the ninja is alive and the enemy is within a distance of less than
  one meter, the ninja causes 40 damage points to the enemy. Otherwise, no damage will be inflicted on the enemy.

There are **three types** of ninjas:

- `YoungNinja`: Created with 100 hit points, moves with a speed of 14.
- `TrainedNinja`: Created with 120 hit points, moves with a speed of 12.
- `OldNinja`: Created with 150 hit points, moves with a speed of 8.

# Part 3 Team

This class represents a **team** of up to ten fighters, where each fighter can be a ninja or a cowboy. Each team has a
leader, who is one of the fighters.

When a team is created, it receives a pointer to the leader. The class defines the following functions:

- `add` method that takes a pointer to a cowboy or ninja and adds it to the team.
- `attack` method that takes a pointer to an enemy team. The attack of the enemy team is performed as follows:
    - First, check if the attacking team's leader is alive. Otherwise, choose a new leader, which is the closest living
      character (in terms of location) to the deceased leader.
    - Then, the attacking team selects a target from the enemy team. The target is a member of the enemy team that is
      the closest living character to the attacking team's leader.
    - All living members of the attacking team will attack the selected target. Cowboys with bullets will shoot at the
      target, deducting damage points, and cowboys without bullets will reload their guns. Ninjas within a distance of
      less than one meter from the target will slash the target, and ninjas further away will move towards the target.
      At any stage, if the target dies, a new target will be chosen (again, the closest living character to the
      attacking team's leader).
    - If there are no living members in the attacking team or the enemy team, the attack ends.
- `stillAlive` method that returns an integer representing the number of living members in the team.
- `print` method that iterates over all characters in the team and prints their details.
- `Destructor` that frees the memory allocated for all the characters in the team.

When iterating over the members of the team (for attack, print, or comparison purposes), the order of iteration is as
follows: first, iterate over all the cowboys, and then iterate over all the ninjas. Within each team, the iteration
should be based on the order of adding the characters. The purpose of splitting cowboys and ninjas in this part is to
make it easier for you. If you find that the requirement complicates the implementation, think of an alternative
approach. When finding the closest character and two characters are at the same distance, choose the first character
checked between them.

# Team2

This class is similar to the `Team` class, but the iteration over the characters should be based on the order of
addition without distinguishing between cowboys and ninjas.

# SmartTeam

This class is similar to the `Team` class, but the iteration over the characters can be implemented based on any order
you consider appropriate, taking into account the positions and statuses of the characters. You are allowed and
encouraged at this stage to "ask" the second team about the positions and statuses of its forces and take into account
the situation of the attacking team to maximize the damage. When evaluating this task in a student lab with an
intelligent, creative, efficient, and effective algorithm, bonus points will be awarded (the maximum is 10 points, and
you can still receive 10 with a simple algorithm, but a good algorithm will help catch errors in other places).

**Part A**: You should write:

- A header file that includes all the required function declarations (without implementation). Note: The headers should
  be correct according to what was taught in the lectures - it is recommended to review the material before starting to
  write.
- Comprehensive tests for all the required functions.
    - No need to test the output operator since the format was not defined.

Write all the required files so that the following commands work without errors:

<div dir='ltr'>

    make demo && ./demo
	make test && ./test

</div>

It is also recommended to run:

<div dir='ltr'>

    make tidy
    make valgrind

</div>

Do not modify existing files, only add new files.

Good luck!