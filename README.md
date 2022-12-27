# CSci3081W-Program-Design
Course materials including slides, code, workshop, lab, and projects


### OOP
- Classes are **Abstract Data Types (ADT)** with **inheritance** and **polymorphism**.
- Abstract data types (ADTs) are the foundation for object oriented programming (OOP).
- **Classes** are type definitions
- **Objects** are specific realizations / instances / items

- Low cohesion makes code hard to change and overly complex.
- **High cohesion** makes code simpler, extensible, and reusable.

- desirable characteristics for a good software design?
  - Minimal complexity
  - Ease of maintenance
  - Loose coupling
  - Extensibility
  - Reusability

- The **protected** access qualifier allows *derived classes* to use member variables and methods.
- **Polymorphism** 
  - allows subclasses to *override* functionality of the base class. 
  - allows us to override methods using virtual functions.
  - enables high cohesion & low coupling
- Pointers use the actual object rather than making a copy.
- Pure virtual functions enforce a contract, but don’t allow “instantiation” or an object (or “creation” of an object).

- OO Basics
  - Abstraction
  - Encapsulation
  - Polymorphism
  - Inheritance

### Intro to Design Patterns
- Design Patterns are object oriented designs (OOD) that increase flexibility.
- Low coupling, high cohesion
- Readability and code style
- SOLID:
  - **Single responsibility principle**
  - **Open to extension, closed to modification**
  - **Liskov substitution principle**: Objects should be replaceable with instances of their subtypes without altering program correctness.
  - **Interface segregation principle**: Many client-specific interfaces better than one general-purpose interface.
  - **Dependency inversion**: High-level modules should not depend on low-level modules. Both should depend on abstractions.