A component can inherit from another component by specifying the component name instead of the prototype. In this example, `lan_wire` and `wan_wire` inherit from the `wire` component defined above, and override the `color`.
```
lan_wire(wire)
	color [70, 70, 255]

wan_wire(wire)
	color [70, 255, 70]
```
