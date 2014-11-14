CS220
=====

Submission git for Comp Sci 220

GAME
====

Play
----
If you have a Mac, you can unzip the file in the `Packages` directory to get a playable version of the first level.  It's missing several assets and uses debug messages to notify of events, but it *_IS_* playable.

Instructions for Compiling
---------------------------

Prior to compiling, you need to download Unreal Engine 4.5.1.  You can get it for free through github or pay $20 for a personal license.  Once you have UE4 installed you can continue with these instructions.

To compile and run the game (in-editor) follow these steps:

1) Right-Click on the `Platformer.uproject` file and select `generate [XCode/Visual Studio] project`

2) Open the generated project in [XCode/Visual Studio]

3) Change the target to the Game Editor option and compile 

  3a) you can ignore the asset missing message if it appears
  
4) Once the edito opens, you can play the game by pressing `Play`

Instructions for Unit Testing
-----------------------------

Unit testing is only setup for Mac in XCode, but uses GTEST so you should be able to run them on windows as well.  For unit testing, we copied out the code we wanted to test, so that we didn't have to worry about conflicting with the unreal engine code.

1) In Xcode, create a new target `Command Line Program` called `Unit Tests`

2) Add all the code in the `UnitTests` directory to the project

3) Make sure those files are only included in the `Unit Tests` target

4) Edit the `UnitTests` scheme 

  4a) Under Run->Environment Variables add
      `DYLD_FRAMEWORK_PATH` with the value being the absolute path to the `gtest.framework` stored in the `UnitTests`
      
5) Make sure that the main.cpp that looks like the one here:

```
int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

6) Now you can build the `UnitTests` target


(4) please suggest some acceptance tests for the TA to try (i.e., what inputs to use, and what outputs are expected)


Writeup
-------
Play the game! Open the executable file we have included on the GitHub. The following are the controls:

Arrow keys : move and jump
s : sprint
d : attack
shift: shield

Note: A lot of assets like attack and death animations haven't been added yet, but you should be able to "d" (attack) while facing an enemy and eventually the enemy will die. Pressing "s" (sprint) while moving with the arrow keys will also allow you to move faster. Both of these will drain your "stamina," which is represented in the HUD up in the upper left corner. Also, colliding into an enemy will deal damage to the player. There has not been a death state implemented yet.

(5) text description of what is implemented. You can refer to the use cases and user stories in your design document.

The following have been implemented:
- Jump/Fall
- Run left/right
- Weapon
- Shield (prevent damage from being taken)
- Take damage
- Die (health hits 0, notification pops up)

(6) who did what: who paired with who; which part is implemented by which pair

Items/Inventory
- Betty/Max
Battle States & Actions
- TJ/David
Movement/Base Classes
- John/Adam
Animations/Assets/Graphics
- Melinda/Steven

(7) What changed

We changed our iteration two goals after starting to work with Unreal Engine.  We found that we needed more time to learn the API before we could begin to incorporate some of the more advanced features we wanted to. In light of this we changed the use cases we were going to implement.
