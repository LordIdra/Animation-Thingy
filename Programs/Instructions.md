## Standard Instructions (TODO)
Standard instructions are built-in and provide functionality such as pausing for a length of time, or modifying the position of an element.
- center
- show
- hide
- bind


## Block Instructions
Blocks can be used as instructions. When a block is used as an instruction, the program jumps to that block and executes it. Non-static blocks must be instantiated, much like classes, and assigned to a variable.
```
static block do_thing [x, y]
	center [x, y]
	lan_wire [x-4 y+3] [x-2 y+1]

block do_other_thing [x, y]
	center [x, y]
	wan_wire [x+3 y+3] [x-2 y-2]

static block main
	// static blocks cannot be instantiated, so call do_thing as normal
	block_do_thing [5, 6]

	// non-static blocks can be instantiated but cannot be called statically, so call do_other_thing to instantiate
	thing = do_other_thing
```


## Component Instructions
Each [[Components|component]] has its own instruction used to create it. The parameters that the instruction takes depends on which prototype the component inherits. 

Consider these two components.
```
pub computer_name(text)
	color [255, 255, 255]
	size 3

pub server_name(text)
	color [255, 255, 255]
	size 5
```

As both of these inherit from the [[text]] prototype, they will both take exactly the same arguments. An example of a call that creates a `computer_name` element at coordinates [5, 20] is as follows.
```
computer_name [5, 20]
```

According to the documentation for [[text]], there are two optional parameters, `horizontal-align` followed by `vertical-align`. 

To align our element to the left, we would write as follows.
```
computer_name [5, 20] left
```

To align it to the top, we would write as follows.
```
computer_name [5, 20] . top
```

We can also give the element a name `cname_1`, allowing it to be referenced in future calls. The second parameter in a component instruction is optional, and will always be the element name.
```
computer_name cname_1 [5, 20] . top
```
