# FBU_FBDU_Sbox
AUTHORS.
David Carcaño Ventura (carvendavid@gmail.com)
Lil Rodríguez Henríquez (lmrodriguez@inaoep.mx)
Saúl Pomares Hernández (spomares@inaoep.mx)

DESCRIPTION.
This tool can measure:

	1. The FBU of a bijective/non-bijective S-box, with 4 <= n <= 8 and 4 <= n <= 8 
	2. The FBDU of a bijective S-box, with 4 <= n <= 8 and 4 <= n <= 8 

Also they can print the values of the FBCT and FBDT.

In 2025, we added an extension to measure CarD1 and CarL1 properties of S-boxes when n=m=4.

HOW TO USE?
In the main.cpp file, you can find some examples. But if you to need some new S-boxes you only add a unsigned char matrix with the values of the S-box and its input size (n).
Every function (FBCT, FBDT, DDT, LAT) takes three input parameters:

	1. S-box
 	2. Input size (n)
  	3. int band (If band==1, then the tool print the table)

Used In Research.
1. Ventura, D. C., Henríquez, L. M. R., & Hernández, S. E. P. (2023, September). Requirements for Feistel-based Lightweight Block Cipher S-boxes to be Resilient to Boomerang Attacks. In 2023 Mexican International Conference on Computer Science (ENC) (pp. 1-8). IEEE.

Based on the Following Works.
1. Boukerrou, H., Huynh, P., Lallemand, V., Mandal, B., & Minier, M. (2020). On the feistel counterpart of the boomerang connectivity table. IACR Transactions on Symmetric Cryptology, 2020(1), 331-362.

2. Eddahmani, S., & Mesnager, S. (2022). Explicit values of the DDT, the BCT, the FBCT, and the FBDT of the inverse, the gold, and the Bracken-Leander S-boxes. Cryptography and Communications, 14(6), 1301-1344.

3. Zhang, W., Bao, Z., Rijmen, V., & Liu, M. (2015). A New Classification of 4-bit Optimal S-boxes and Its Application to PRESENT, RECTANGLE and SPONGENT. In Fast Software Encryption: 22nd International Workshop, FSE 2015, Istanbul, Turkey, March 8-11, 2015, Revised Selected Papers 22 (pp. 494-515). Springer Berlin Heidelberg. 
