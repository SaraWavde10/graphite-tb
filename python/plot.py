import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("bands.dat")
k = data[:, 0]
band1 = data[:, 1]
band2 = data[:, 2]

plt.figure(figsize=(6, 8))
plt.plot(k, band1, 'b-')
plt.plot(k, band2, 'r-')

# Mark high symmetry points
nk = 200
plt.axvline(x=0,        color='k', linewidth=0.5)
plt.axvline(x=nk,       color='k', linewidth=0.5)
plt.axvline(x=2*nk,     color='k', linewidth=0.5)
plt.axvline(x=3*nk,     color='k', linewidth=0.5)
plt.axhline(y=0,        color='k', linewidth=0.5, linestyle='--')

plt.xticks([0, nk, 2*nk, 3*nk], ['Γ', 'M', 'K', 'Γ'])
plt.ylabel('Energy (eV)')
plt.title('Graphene Band Structure')
plt.ylim(-4, 4)
plt.tight_layout()
plt.savefig("graphene_bands.png", dpi=150)
plt.show()
print("Saved to graphene_bands.png")
