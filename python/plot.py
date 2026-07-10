import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("bands.dat")
k = data[:, 0]

nk = 200
plt.figure(figsize=(6, 8))
colors = ['blue', 'red', 'red', 'blue']
for i in range(4):
    plt.plot(k, data[:, i+1], color=colors[i])

plt.axvline(x=0,    color='k', linewidth=0.5)
plt.axvline(x=nk,   color='k', linewidth=0.5)
plt.axvline(x=2*nk, color='k', linewidth=0.5)
plt.axvline(x=3*nk, color='k', linewidth=0.5)
plt.axhline(y=0,    color='k', linewidth=0.5, linestyle='--')

plt.xticks([0, nk, 2*nk, 3*nk], ['Γ', 'M', 'K', 'Γ'])
plt.ylabel('Energy (eV)')
plt.title('AB-stacked Bilayer Graphene Band Structure')
plt.ylim(-4, 4)
plt.tight_layout()
plt.savefig("bilayer_bands.png", dpi=150)
plt.show()
print("Saved to bilayer_bands.png")
