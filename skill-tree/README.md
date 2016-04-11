## Skill Tree

### Instructions

One central feature of an RPG is the "skill tree". The skill tree shows players how they can advance their character's skills and abilities. For this lab you will implement a basic skill tree. Your implementation will simply create and display the tree.

Each skill has a name, a description, and a level requirement. Each skill, except for one, has prerequisite skills that must be obtained first. For example, the skill of "reading" depends on the character first obtaining the skill of "alphabet". This dependency relationship naturally leads to the use of a tree to represent the entire list of skills. Thus the "skill tree". The one skill that does not require any previous skill will be the root of the tree.

Your program will support the building and display of this tree. The provided [**main.cpp**](https://github.com/dotman14/Data-Structure-Summer-15/blob/master/skill-tree/main.cpp) will build up two different skill trees. One for a student and one for a warrior.

#### Implementation Requirements

Your implementation should have a class called "SkillTree" that manages the skill tree. You will also need a "Skill" class that holds the name, description, and level for a skill. You are welcome to add additional classes as you see the need.

#### The "Skill" class

The "Skill" class encapsulates the skill data: name, description, level. At a minimum this class needs to have a method called **Display()**. The **Display()** method takes an ostream parameter and then prints output to that stream. You will need to create constructors and a destructor for the class. You will also need to create other methods for accessing the data elements. But the specifics of those methods depend on how you implement the rest of your program.

#### The "SkillTree" class

Each skill tree class contains a title (e.g. "Warrior") and a tree of all of the skills that skill tree contains. The tree should be implemented as a general tree with a maximum number of children for a given node being 3. Note that the use of "3" for the max number of children is just so that you can test to make sure that your tree can properly handle the error case where too many children are being inserted for a node. In reality this number would be set to something like 7. There is no limitation to the depth of the tree.

You are free to implement your tree in any of the ways that we talked about in class for implementing trees.

The "SkillTree" class needs to support the following methods: constructor, add skill, find skill, display. Memory management can be tricky with a tree. You will need to be careful with your tree destructor. Many people find that they spend more time on the destructor than any other method when implmenting a tree so be sure to give yourself enough time on that.

The required constructor for the SkillTree takes in a title. This title is printed with the tree is displayed.

The **AddSkill()** method is used to add a skill to the tree. There are two versions of this method: **AddSkill(char* name,char* desc,int level)**, **AddSkill(char* name,char* desc,int level,char* parentName)**. The first method passes in the new skill's name, description, and level. Since no parent skill is included in the call, this methods adds the skill as a new root to the tree. If there was a root of the tree already (i.e., it wasn't empty) then the old root becomes a child of the new root. The second version of **AddSkill()** has a fourth parameter which is the parent skill. This method should find the parent node in the tree and then insert a new skill as a child of that parent. This can fail in two ways. First, the parent might not be in the tree. Second, the parent might already have the max number of children. Be sure to handled both cases.

Note that the **AddSkill()** method doesn't take in a Skill object, instead it just takes in the strings and integer that are needed to make a Skill object. The **AddSkill()** method is responsible for creating the actual Skill object while it puts it in the tree.

The **FindSkill()** method finds a skill by name and returns a pointer to that skill object. If the skill can't be found then it should return a NULL pointer.

The **Display** method takes in an ostream object. The method prints the entire tree to the ostream object. See the sample output to see the format.

As mentioned above, the destructor can be tricky. Part of the difficulty is that a tree destructor is recursive. When deleting a node in the tree you have to first delete all of the children. And since those are tree nodes, they also have to delete their children first, and so on. Usually you can use a post-order traversal for destroying a tree. You don't call a destructor explicity. Instead you call a destructor by using the delete statement on the node you want to delete.

Due to time constraints I dialed back this assignment quite a bit. In particular, I didn't include the need to have your tree support the remove operation. Deleting from this tree could be tricky since there is an explicit ordering (you can't just swap an internal node with a leaf node) and it is tricky to deal with children of a deleted node.

#### Other requirements

The [**main.cpp**](https://github.com/dotman14/Data-Structure-Summer-15/blob/master/skill-tree/main.cpp) is attached with the assignment. In order for this to work correctly you will need to make sure to use correct file name [**"SkillTree.h"**](https://github.com/dotman14/Data-Structure-Summer-15/blob/master/skill-tree/SkillTree.h). You will also need to make sure to name your classes and methods as described above.

When you run your program using this main function your program should generate the output shown in the [**expected.txt**](https://github.com/dotman14/Data-Structure-Summer-15/blob/master/skill-tree/expected.txt) file that is attached to the assignment. You need to match the text exactly (including spaces and newlines).
