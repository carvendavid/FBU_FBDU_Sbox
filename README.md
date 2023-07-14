# FBU_FBDU_Sbox
Authors:
David Carcaño Ventura (carvendavid@gmail.com)
Lil Rodríguez Henríquez (lmrodriguez@inaoep.mx)
Saúl Pomares Hernández (spomares@inaoep.mx)

This tool can measure:

	1. The FBU of a bijective/non-bijective S-box, with 4 <= n <= 8 and 4 <= n <= 8 
	2. The FBDU of a bijective S-box, with 4 <= n <= 8 and 4 <= n <= 8 

Also they can print the values of the FBCT and FBDT.

In the main.cpp file, you can find some examples. But if you to need some new S-boxes you only add a unsigned char matrix with the values of the S-box and its input size (n).

This tool is based on the next articles:

1. Boukerrou, H., Huynh, P., Lallemand, V., Mandal, B., & Minier, M. (2020). On the feistel counterpart of the boomerang connectivity table. IACR Transactions on Symmetric Cryptology, 2020(1), 331-362.

2. Eddahmani, S., & Mesnager, S. (2022). Explicit values of the DDT, the BCT, the FBCT, and the FBDT of the inverse, the gold, and the Bracken-Leander S-boxes. Cryptography and Communications, 14(6), 1301-1344.
