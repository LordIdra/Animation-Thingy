## Calls
Calls are structured as `(instruction) (parameter1) (parameter2) ... (parameterXYZ)`

Instructions can either be **standard instructions**, **block instructions**, or **component instructions**. These are explained in [[Instructions]].


## Parameters
Parameters can have different requirements:
- Parameters without any decoration must be specified
- Parameters surrounded with square brackets indicate coordinates. The square brackets are required in the instruction call
- Parameters surrounded with (parentheses) are optional

Each parameter has a type, and will only accept values of that type. For example, a parameter of type `rgb` would accept `255, 0, 0` but reject `5.6`

Note that an optional requirement can be set to default by passing a `.`