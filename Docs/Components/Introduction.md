A prototype is a type of component, such as `line`, `text`, `rect`, `icon`, and so on. The idea behind components is that they take prototypes, and define some visual elements about them such as the fill color, outline width, text weight, and so on. This can be thought of as a form of CSS, as rather than specify *where* the elements appear and what they do, component definitions simply define *how the element is displayed.*

A 'unit' is a file that defines multiple 'components.' For example, a 'networks' unit could define components
- lan_wire
- wan_wire
- wire_endpoint
- network_name
- device_name
- device_explanation
- device_rect

Each component can only be applied to one prototype, such as a line or rect. For example:
- `lan_wire` could only be applicable to lines
- `network_name` could only be applicable to text

Each prototype has a set of 'style attributes' which can be set, such as `color` or `width`. The full list of components: [line], [rect], [text], [icon]

When a new component is created for a prototype, it will inherit all the default style attributes for that prototype. These style attributes can then be overriden. An example will make this more clear in [[Basic Syntax]]
