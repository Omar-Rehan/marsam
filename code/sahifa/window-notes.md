# Layers:
1. **Application code:**
	- <u>Description</u>: code using the library.
	- <u>Files</u>: `examples` files.

<br/>

2. **Generic interface:**
	- <u>Description</u>: interface used by the application code.
	- <u>Files</u>: `window.hpp` file.

<br/>

3. **Core implementation**.
	- <u>Decription</u>: hidden implementation providing the actual functionality.
	- <u>Files</u>: `core` sub-directory.

<br/><br/>

# Design:
- **Generic interface for window management:**
	- Description:
		- A struct of function pointers was chosen over the alternative of an interface class with pure virtual functions.
	- Reasons:
		- Paradigm:
			- Avoids the use of OOP, which is one of the goals of this side project.
		- Simplicity:
			- Avoids dealing with classes & inheritance.
		- Performance:
			- Avoids the cost of virtual functions (particularly the `process_event` function that'll probably be called in a hot loop).
- **Separate window construction/desctruction from initialization/deinitialization:**
	- Description:
		- Window setup was designed to involve two separate steps: (construction & initialization), instead of bundling them in one step.
	- Reasons:
		- Window Re-use:
			- Enables the reuse of a pre-constructed window.
		- Delayed Initialization:
			- Avoids forcing initialization at construction. (~~RAII~~)
