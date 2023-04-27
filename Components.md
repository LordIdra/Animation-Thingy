### Introduction



### Basic Syntax



### Inheritance



### Sections


### Full Example

  
  
  

## Instructions

### Overview



  

### Components

`line_component` **[x1, y1] [x2, y2] style**

- Draws a line from **[x1, y1]** to **[x2, y3]** with style **style**

  

`rect` **[x1, y1] [x2, y2] style**

- Draws a rectangle with corners at **[x1, y1]** and **[x2, y3]** with style **style**

  

`text` **[x, y] text style**

- Draws text at **[x, y]** containing text **text** with style **style**

  

`icon` **[x, y] style**

- Draws an icon at **[x, y]** with style **style**

  
  

### Jumps

`jump` **block**

- Jump to block **block**.

  
  

## Explanations

### Scopes

- Blocks are universal and can be called from anywhere

- Themes are also universal and can be applied from anywhere

- The current theme will 'go out of scope' when the block ends

- After a theme goes out of scope, the theme that was in use before jumping to the block will go back to being in use