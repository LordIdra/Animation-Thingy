The syntax for defining a component is as follows.
```
component_name(prototype)
	attribute1 value1
	attribute2 value2
```

Here's an example.
```
wire(line)
	color [200, 70, 70]
	width 2
```

Components are not public by default, meaning they cannot be used outside of the component file, and can only be [[Inheritance|inherited]] by other components. Components must have the `pub` keyword in front of them to make them public. To use the above component, we'd have to add the `pub` keyword like so.
```
pub wire(line)
	color [200, 70, 70]
	width 2
```
