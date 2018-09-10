*Harrison March*
*hsmarch@wpi.edu*
*IMGD3000 || A18*
# Dragonfly Egg Readme:

### Compilation Instructions
Load dragonfly-egg.sln into Visual Studio
Run TestDF.cpp

### Notes:
This version is only compatible with Windows, to the best of my knowledge.

### Test Cases:
Every test is written to a logfile called DF_TEST.log

### Expected Results:
```
 - Starting Test Session - 
Initializing Log Manager Tests. GM and LM init Success!
LogManager MultiArg Test qwerty 3


 - Manager Test Suite -  
Manager getType() Test: Manager


 - Clock Test Suite -  
	Test: Clock Split 2
	Test: Clock Delta  5


 - Object Test Suite - 
	 Object type: Test Object
	 Object id: 5
	 Object position: x=5, y=4


 - ObjectList and ObjectListIterator Test Suite - 
	List size: 0
	Adding to list
	Object List Full! Cannot create!
	Object List Full! Cannot create!
	Object List Full! Cannot create!
	After insertion: getCount(): 5000	isEmpty(): 0
	After deletion: getCount(): 5	isEmpty(): 0
	Printing all Objects in List
	Object type: Test Object, isDone(): 0
	Object type: Test Object 2, isDone(): 0
	Object type: Test Object 2, isDone(): 0
	Object type: Test Object 2, isDone(): 0
	Object type: Test Object 2, isDone(): 0
	Object type: Test Object 2, isDone(): 0
	Object type: Test Object 2, isDone(): 0


 - WorldManager Test Suite - 
	Manager instance fetched.
	WorldManager Object List getCount(): 2, isEmpty: 0
	WorldManager Object List getCount(): 0, isEmpty: 1


 - GameManager Test Suite - 
Game Tick!
Game Shut Down.
```