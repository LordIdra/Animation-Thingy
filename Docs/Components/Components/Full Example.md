```
wire(line)
	width 2
	opacity 0.9

pub lan_wire(wire)
	color [200, 100, 30]

pub wan_wire(wire)
	color [255, 100, 30]

pub wire_endpoint(rect)
	color [200, 100, 30]
	outline
		width 2

pub network_name(text)
	color [255, 255, 255]
	size 5
	bold true

pub device_name(text)
	color [255, 255, 255]
	size 3
	bold true

pub device_explanation(icon)
	style question_circle
	color [255, 255, 255]

pub device_rect(rect)
	outline
		color [30, 100, 200]
		width 2
```
