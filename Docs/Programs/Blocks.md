## Blocks
Blocks are groups of instructions that can be called from other places in the program. Each block is either static or non-static. 

Static blocks can be called at any point in the program, and can also store data. Importantly, when a static block is called for the first time, it instantiates its member variables. Any attempts to call the static block after the first time are disallowed. However, the static block **can** be destroyed, meaning all the member variables are deleted. It can then be initialized again. This allows for static blocks to represent sections of the diagram, and be hidden or shown very easily to facilitate animations.

Non-static blocks must be instantiated and assigned to a variable. The instance of that block is then considered independently. If it is destroyed (either directly, or indirectly when the block that owns it is destroyed), only that instance is destroyed.

Every static block is 'owned' by the program, while every non-static block is owned by the block that instantiated it. Ownership cannot be transferred.
