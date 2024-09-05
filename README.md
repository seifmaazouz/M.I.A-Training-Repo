
# **Task 8: Final Showdown Update** ⚔️🦇

## **Overview** 📝
This task required simulating a battle between Batman and Joker in a turn-based gameplay where characters choose to attack with gadgets or defend with shields. The game ends when one character's health drops to zero, or when both characters lack the energy to use any remaining gadgets.

---

## **Progress Updates** 🚀
### **1. Game Mechanics :video_game:**
- Developed the **turn-based system** where Batman and Joker take turns to either attack or defend.
- Actions include choosing an attack strategy or activating a shield for defense.
### **2. Character Attributes & Actions :dart:** 
- Characters are defined with key attributes: `Health`, `Energy`, and `Shield`.
- Implemented methods to manage these attributes: `setHealth()`, `setEnergy()`, and `setShield()`.
### **3. Inheritance Structure :dna:** 
- Created separate classes for **Batman** and **Joker** that inherit from the **Character** class.
- This inheritance ensures that both Batman and Joker share common attributes and methods while allowing for specific customization in their gadgets and actions.
### **4. Gadget Implementation :tools:** 
- Gadgets for both Batman and Joker are implemented with attributes such as:
  - **Energy:** Defines how much energy a gadget uses.
  - **Damage:** Specifies the damage dealt to the opponent.
  - **Use:** Limits how many times a gadget can be used.
  - For example, Batman's **'Grapple Gun'** has 5 uses and requires 88 energy per use, while Joker's **'Laughing Gas'** has 8 uses and costs 56 energy.
### **5. User Interface and Input Handling :keyboard:** 
- Integrated keyboard inputs for choosing between attacks and shields.
- Created a clean interface that diplays who's turn it is and options for each turn which consists of three main options: **Choose Shield**, **Choose Weapon**, or **Skip Turn**.
- Weapon and shield selections directly influence the opposing character's attributes during gameplay and after each round each players stats are updated and displayed.
### **6. Game Completion Logic :white_check_mark:** 
- The game ends when either Batman or Joker's health reaches zero or when both characters lack sufficient energy to perform any further attacks.
- Displays a message declaring the **winner** and the final status of both characters.
### **Links 🔗️** 
- [Game Start Screen](https://postimg.cc/3yWF2VJK)
- [Weapon Selection Screen](https://postimg.cc/jnY60j65)
- [Shield Selection Screen](https://postimg.cc/67DnnQm0)
- [Round Example Screen](https://postimg.cc/VdD7MjBW)
- [End Game Screen](https://postimg.cc/WhWntsT9)

**Checkout Task 8 code and State Machine Diagram Here: [Task 8 Github](https://github.com/seifmaazouz/M.I.A-Training-Repo/tree/task8)**