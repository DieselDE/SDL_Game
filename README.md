# 🗡️ SDL_Game — Roguelike

A roguelike game with graphics built in **C++** using **SDL2**. Navigate through encounters, fight enemies, defend yourself, use items, or flee — all controlled with just your keyboard.

---

## 🎮 About

SDL_Game is a C++ roguelike with a turn-based battle system and BMP sprite graphics rendered via SDL2. The game is designed to be fully playable with just the arrow keys and Enter — no mouse required.

---

## ⚔️ Battle System

Every encounter presents the player with **4 options**:

| Option | Description |
|---|---|
| ⚔️ Attack | Deal damage to the enemy |
| 🛡️ Defend | Reduce incoming damage |
| 🎒 Item | Use an item from your inventory |
| 🏃 Flee | Attempt to escape the encounter |

Navigation is done with **arrow keys** to move between options and **Enter** to confirm. The cursor always starts on the first option.

---

## 🔧 Tech Stack

- **Language:** C++ (100%)
- **Graphics Library:** SDL2
- **Image Format:** BMP sprites (via SDL surfaces)

---

## 📁 Project Structure

| File | Description |
|---|---|
| `main.cpp` | Entry point — game loop and SDL initialization |
| `Character.cpp / .h / .hpp` | Character class — stats, actions, battle logic |
| `Battle_Attack.bmp` | Attack button sprite |
| `Battle_Defend.bmp` | Defend button sprite |
| `Battle_Item.bmp` | Item button sprite |
| `Battle_Flee.bmp` | Flee button sprite |
| `Battle_temp.xcf` | Source image (GIMP format) for battle UI |

---

## 🚀 Getting Started

### Requirements

- A C++ compiler (GCC, Clang, or MSVC)
- SDL2 library installed

#### Installing SDL2

**Linux (Debian/Ubuntu):**
```bash
sudo apt-get install libsdl2-dev
```

**Windows:** Download from [libsdl.org](https://www.libsdl.org/download-2.0.php) and link against your project.

### Building

```bash
# Example using g++
g++ main.cpp Character.cpp -o sdl_game -lSDL2

# Run
./sdl_game
```

---

## 🕹️ Controls

| Key | Action |
|---|---|
| `↑` / `↓` | Navigate menu options |
| `Enter` | Confirm selection |
| Mouse | Not used |

---

## 👤 Author

**DieselDE** (Vincent Domsta)
