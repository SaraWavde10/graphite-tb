# graphite-tb: Project Log

## Goal
Build a C++/Python tight-binding solver for graphene and graphite

Learning objectives: 
- C++ (Eigen, CMake, pybind11, templates)
- Integrating C++ with Python
- Condensed matter physics of graphite from a graphene foundation

---

## Project Scope

### Step 1 — C++ Foundation
- [x] CMake + Eigen project structure
- [ ] Generic `TightBindingModel` class (Hamiltonian input, diagonalisation over k-path)
- [x] Reproduce graphene band structure (sanity check)
- [ ] pybind11 bindings — expose `get_bands(k_points)` to Python
- [x] Plot band structure from Python (matplotlib)

### Step 2 — Graphite Physics
- [ ] Bilayer graphene: AB vs AA stacking, verify band splitting
- [ ] N-layer stacking, track Dirac cone evolution toward bulk
- [ ] Slonczewski-Weiss-McClure (SWMcC) model implementation
- [ ] 3D Fermi surface computation and plotting

### Extras 
- [ ] Landau levels in a magnetic field
- [ ] Stacking disorder: random AB/ABC domain walls in a supercell
- [ ] DOS computation, flat-band signatures in rhombohedral stacking

---

## Physics Background
- Graphite = stacked graphene (Bernal AB stacking by default)
- In-plane hopping γ₀ ≈ 3 eV (same as graphene)
- Interlayer coupling adds γ₁ ≈ 0.39 eV (and higher terms in SWMcC)
- Result: semimetallic band overlap, electron/hole pockets at K/K'
- SWMcC model: 6 parameters (γ₀–γ₅ + crystal field Δ) — standard for Bernal graphite

---

## C++ Skills 
- Eigen (matrix algebra, eigensolvers)
- CMake build system
- pybind11 (Python bindings)
- Class design with templates
- Performance profiling (later, for large supercells)

---

## Progress Log

### Session 1: Setting up the environment 
- Identified MSYS2/MinGW toolchain on Windows (g++ 15.2.0)
- Configured VS Code to use MINGW64 terminal by default
- Installed via pacman:
  - `cmake` (4.1.0)
  - `eigen3` (3.4.0)
  - `git` (2.51.0)
- Created GitHub repo: https://github.com/SaraWavde10/graphite-tb
- Cloned locally, created folder structure:
  ```
  graphite-tb/
  ├── CMakeLists.txt
  ├── src/main.cpp
  ├── include/
  ├── python/
  └── build/
  ```
- Written first `CMakeLists.txt` linking Eigen
- Written sanity-check `main.cpp` (2x2 Hermitian diagonalisation) — eigenvalues ±1 confirmed

### Session 2: Graphene band structure
- Installed `mingw-w64-x86_64-gcc` (g++ was missing from PATH despite MSYS2 being present)
- Installed `mingw-w64-x86_64-python` and `mingw-w64-x86_64-python-matplotlib`
- Implemented graphene tight-binding Hamiltonian in `src/main.cpp`:
  - 2x2 k-dependent H(k) with hopping parameter γ₀ = 3 eV
  - Structure factor f(k) for honeycomb lattice
  - k-path: Γ → M → K → Γ (200 points per segment)
  - Outputs eigenvalues to `build/bands.dat`
- Wrote `python/plot.py` to read `bands.dat` and plot band structure
- Successfully reproduced graphene band structure:
  - Dirac point (linear crossing at zero energy) visible at K
  - Bandwidth ±3 eV = γ₀ × 2 ✓
  - Van Hove singularity at M ✓
- **Next:** extend to bilayer graphene (AB stacking), 4x4 Hamiltonian, interlayer hopping γ₁ = 0.39 eV

---

## Resources
- Slonczewski, Weiss, McClure original papers (Bernal graphite model)
- Kwant documentation (Python TB, for reference/comparison)
- Eigen documentation: https://eigen.tuxfamily.org
