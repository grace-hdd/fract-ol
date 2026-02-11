# 🌀 Fractol - Beautiful Fractal Explorer

A stunning fractal visualization program built in C using MiniLibX that renders beautiful mathematical fractals in real-time.

## 🎨 Featured Fractals

- **Mandelbrot Set** - The classic fractal that reveals infinite complexity at its boundaries
- **Julia Set** - Dynamic fractals with customizable parameters for endless variations  
- **Burning Ship** - A unique fractal resembling a burning ship silhouette

## ✨ Features

- 🖱️ **Interactive Controls**: Pan, zoom, and explore fractals in real-time
- 🎨 **Psychedelic Colors**: Vibrant color schemes that bring fractals to life
- ⌨️ **Keyboard Shortcuts**: Intuitive navigation and parameter adjustment
- 🔄 **Dynamic Julia Set**: Mouse tracking for real-time Julia set variations
- 📐 **High Precision**: Double-precision math for smooth zooming and detail

## 🚀 Quick Start

### Prerequisites

- Linux system with X11
- GCC compiler
- MiniLibX library
- Make

### Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd fractol
```

2. Install MiniLibX (if not already installed):
```bash
# On Ubuntu/Debian:
sudo apt-get install libmlx-dev libx11-dev libxext-dev

# Or clone and build MiniLibX:
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
cd ..
```

3. Compile the project:
```bash
make
```

## 🎮 Usage

### Launch Commands

```bash
# Mandelbrot Set
./fractol mandelbrot

# Julia Set (with custom parameters)
./fractol julia -0.7 0.27015

# Burning Ship
./fractol burning_ship
```

### Controls

| Key | Action |
|-----|--------|
| `←` `→` `↑` `↓` | Pan around the fractal |
| `Mouse Wheel` | **Smart zoom** - zooms toward mouse cursor |
| `+` `-` | Increase/decrease iteration depth |
| `Q` | Toggle render quality (1-4, higher = faster) |
| `S` | Toggle smooth color mode |
| `ESC` | Exit program |

**Julia Set Special Feature**: Move your mouse to dynamically change the Julia set parameters in real-time!

## 🏗️ Project Structure

```
fractol/
├── src/
│   ├── main.c          # Program entry point and argument parsing
│   ├── init.c          # MLX initialization and setup
│   ├── render.c        # Core fractal rendering engine
│   ├── events.c        # Event handling (keyboard/mouse)
│   ├── math_utils.c    # Complex number mathematics
│   └── string_utils.c  # String manipulation utilities
├── includes/
│   └── fractol.h       # Header file with structures and prototypes
├── Makefile            # Build system
└── README.md           # Project documentation
```

## 🧮 Mathematical Background

### Complex Numbers
Fractals are generated using complex number iterations:
- **z = x + yi** (where i is the imaginary unit)
- Each pixel represents a complex number on the complex plane

### Mandelbrot Set
For each complex number c, iterate: **z₍ₙ₊₁₎ = z²ₙ + c**
- Start with z₀ = 0
- If |z| remains bounded, the point is in the set

### Julia Set  
Similar iteration but with fixed c: **z₍ₙ₊₁₎ = z²ₙ + c**
- Start with z₀ = pixel coordinate
- The parameter c determines the fractal's shape

### Burning Ship
Modified iteration: **z₍ₙ₊₁₎ = (|Re(z)| + i|Im(z)|)² + c**
- Takes absolute values of real and imaginary parts
- Creates the distinctive "burning ship" appearance

## 🎨 Color Schemes

The program uses a psychedelic color palette:
- **Magenta Burst** - Deep magentas and purples
- **Lime Shock** - Electric lime greens  
- **Neon Orange** - Vibrant orange highlights
- **Aqua Dream** - Cool cyan and teal tones
- **Hot Pink** - Striking pink accents
- **Electric Blue** - Brilliant blue variations
- **Lava Red** - Fiery red gradients

## 🔧 Technical Details

- **Language**: C
- **Graphics**: MiniLibX
- **Precision**: Double-precision floating point
- **Resolution**: 800x600 (customizable via WIDTH/HEIGHT macros)
- **Default Iterations**: 42 (adjustable via +/- keys)
- **Escape Radius**: 2.0

## 🚀 **Ultra-Smooth Video Performance** 

### **Adaptive Quality System:**
- **Quality Level 1**: Full resolution (highest detail)
- **Quality Level 2**: 2x2 pixel blocks (4x faster)
- **Quality Level 3**: 3x3 pixel blocks (9x faster)
- **Quality Level 4**: 4x4 pixel blocks (16x faster)

### **Smart Zoom Technology:**
- **Mouse-centered zooming** - Zoom toward cursor position
- **Smooth 10% increments** for buttery transitions
- **Intelligent coordinate transformation**
- **Real-time quality adaptation**

### **Performance Features:**
- **Block rendering** for ultra-fast preview
- **Smooth color interpolation** mode
- **Optimized memory access patterns**
- **Responsive controls** - never blocks UI

## 🎯 Example Usage

```bash
# Explore the classic Mandelbrot set
./fractol mandelbrot

# Create a beautiful Julia set
./fractol julia -0.8 0.156

# Discover the mysterious Burning Ship
./fractol burning_ship
```

## 🤝 **Advanced Controls**

- **Navigation**: Arrow keys for smooth panning
- **Smart Zoom**: Mouse wheel zooms toward cursor
- **Detail Control**: +/- keys adjust iteration depth
- **Speed Control**: Q key cycles render quality (1-4)
- **Visual Mode**: S key toggles smooth color gradients
- **Julia Magic**: Mouse movement changes Julia parameters
- **Exit**: ESC key to quit

### **Pro Tips for Buttery Performance:**
1. **Use Quality 4** for ultra-fast navigation
2. **Switch to Quality 1** for final detailed view
3. **Enable Smooth Mode (S)** for cinematic colors
4. **10% zoom steps** feel perfectly smooth

## 📝 Notes

- Higher iteration counts reveal more detail but may slow rendering
- Julia set parameters between -2.0 and 2.0 typically produce interesting results
- Experiment with different zoom levels to discover hidden patterns
- The program automatically handles window closing and memory cleanup

Enjoy exploring the infinite beauty of fractals! 🌀✨
