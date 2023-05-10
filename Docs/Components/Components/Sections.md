Component definitions can have sections that organise the prototype's attributes. The sections in question depend on which prototype is in use. For example, the `rect` prototype has sections `fill` and `outline`, so a `rect` component can be defined as follows.
```
device_rect(rect)
	fill
		color [255, 0, 0]
	outline
		color [255, 0, 0]
		width 2
```

Note that attributes that apply to all sections do not need to be duplicated. The above example can be rewritten as follows.
```
device_rect(rect)
	color [255, 0, 0]
	outline
		width 2
```
