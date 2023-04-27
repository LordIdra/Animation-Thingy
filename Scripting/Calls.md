## Programs (TODO)

## Blocks (TODO)
Blocks are groups of instructions that can be called from other places in the program. A block can 'jump' to another block and the program will continue executing there. 

## Calls
Calls are structured as `(instruction) (parameter1) (parameter2) ... (parameterXYZ)`

Instructions can either be **standard instructions** or **component instructions**. These will be explained in the following sections.

## Parameters
Parameters can have different requirements:
- Parameters without any decoration must be specified
- Parameters surrounded with square brackets indicate coordinates. The square brackets are required in the instruction call
- Parameters surrounded with (parentheses) are optional

Each parameter has a type, and will only accept values of that type. For example, a parameter of type `rgb` would accept `255, 0, 0` but reject `5.6`

Note that an optional requirement can be set to default by passing a `.`

## Standard Instructions (TODO)
Standard instructions are built-in and provide functionality such as jumping between code blocks, pausing for a length of time, or modifying the position of an element. For example, `jump DrawComputer` would jump to the `DrawComputer` block.

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
