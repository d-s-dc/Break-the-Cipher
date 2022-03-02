#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

const uint8_t Si[8][4][16] =
                            {
                                {
                                14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
                                0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
                                4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
                                15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
                                },
                                {
                                15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
                                3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
                                0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
                                13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
                                },
                                {
                                10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
                                13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
                                13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
                                1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
                                },
                                {
                                7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
                                13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
                                10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
                                3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
                                },
                                {
                                2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
                                14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
                                4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
                                11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
                                },
                                {
                                12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
                                10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
                                9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
                                4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
                                },
                                {
                                4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
                                13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
                                1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
                                6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
                                },
                                {
                                13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
                                1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
                                7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
                                2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
                                }
                            };

const uint8_t PC1[56] =
                        {
                        57, 49, 41, 33, 25, 17,  9,
                         1, 58, 50, 42, 34, 26, 18,
                        10,  2, 59, 51, 43, 35, 27,
                        19, 11,  3, 60, 52, 44, 36,
                        63, 55, 47, 39, 31, 23, 15,
                         7, 62, 54, 46, 38, 30, 22,
                        14,  6, 61, 53, 45, 37, 29,
                        21, 13,  5, 28, 20, 12,  4
                        };
 
const uint8_t PC2[48] =
                        {
                        14, 17, 11, 24,  1,  5,
                         3, 28, 15,  6, 21, 10,
                        23, 19, 12,  4, 26,  8,
                        16,  7, 27, 20, 13,  2,
                        41, 52, 31, 37, 47, 55,
                        30, 40, 51, 45, 33, 48,
                        44, 49, 39, 56, 34, 53,
                        46, 42, 50, 36, 29, 32
                        };

const uint8_t P[32] =
                    {
                        16,  7, 20, 21,
                        29, 12, 28, 17,
                        1, 15, 23, 26,
                        5, 18, 31, 10,
                        2,  8, 24, 14,
                        32, 27,  3,  9,
                        19, 13, 30,  6,
                        22, 11,  4, 25
                    };

// Utility function to convert an array of 32 binaries to its number
uint32_t btoi32(uint8_t arr[32])
{
    uint32_t num = 0;
    for (int itr = 0; itr < 32; itr++)
    {
        if (arr[itr] == 1)
        {
            num = num | ((uint32_t)1 << (31 - itr));
        }
    }
    return num;
}

// Utility function to convert 32 bit number to an array of 32 binaries
uint8_t* itob32(uint32_t num)
{
    uint8_t *arr = calloc(sizeof(uint8_t), 32);
    for (int itr = 0; itr < 32; itr++)
    {
        arr[31 - itr] = (num & 1) == 1 ? 1 : 0;
        num = num >> 1;
    }
    return arr;
}

// Utility function to convert an array of 64 binaries to its number
uint64_t btoi64(uint8_t arr[64])
{
    uint64_t num = 0;
    for (int itr = 0; itr < 64; itr++)
    {
        if (arr[itr] == 1)
        {
            num = num | ((uint64_t)1 << (63 - itr));
        }
    }
    return num;
}

// Utility function to convert 64 bit number to an array of 64 binaries
uint8_t* itob64(uint64_t num)
{
    uint8_t *arr = calloc(sizeof(uint8_t), 64);
    for (int itr = 0; itr < 64; itr++)
    {
        arr[63 - itr] = (num & 1) == 1 ? 1 : 0;
        num = num >> 1;
    }
    return arr;
}

void print_arr(void *ptr, uint8_t size, char *phrase)
{
    for (uint8_t itr = 0; itr < size; itr++)
        printf("%s%3" PRIu8 " - %" PRIu8 "\n",phrase, itr, ((uint8_t*)ptr)[itr]);
    printf("\n");
}

void p_arr(void *ptr, uint8_t size)
{
    for (uint8_t itr = 0; itr < size; itr++)
        printf("%" PRIu8 " ", ((uint8_t*)ptr)[itr]);
    printf("\n");
}

uint64_t* key_scheduling(uint64_t input_key)
{
    uint8_t Vi[17] = {0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    uint64_t parity_discarder = 0;
    uint8_t temp = UINT8_MAX >> 1;
    int itr;
    // Discarding parity check bits
    for (itr = 0; itr < 8; itr++)
    {
        parity_discarder = parity_discarder | ((uint64_t)(temp) << itr);
    }
    input_key = input_key & parity_discarder;

    uint32_t keys[17][2];       // Stores Ci, Di differently
    uint64_t *key = calloc(sizeof(uint64_t), 16);   // Stores the combined key
    uint8_t *binary_form = itob64(input_key);

    //Preparing C0, D0
    uint8_t c0[32], d0[32];
    for (itr = 0; itr < 28; itr++)
    {
        c0[itr + 4] = binary_form[PC1[itr] - 1];
    }
    for (itr = 28; itr < 56; itr++)
    {
        d0[itr - 24] = binary_form[PC1[itr] - 1];
    }
    keys[0][0] = btoi32(c0);
    keys[0][1] = btoi32(d0);
    //Generating 16 keys
    uint32_t unrequired = UINT32_MAX >> 4;  // 32 bit number with last 28 bits one
    uint8_t *p1, *p2;
    uint64_t sum;
    for (itr = 1; itr <= 16; itr++)
    {
        keys[itr][0] = ((keys[itr - 1][0] << Vi[itr]) & unrequired) | (keys[itr - 1][0] >> (28 - Vi[itr]));
        keys[itr][1] = ((keys[itr - 1][1] << Vi[itr]) & unrequired) | (keys[itr - 1][1] >> (28 - Vi[itr]));
        sum = (uint64_t)keys[itr][0];
        sum = sum << 28;
        sum |= (uint64_t)keys[itr][1];
        p1 = itob64(sum);
        p2 = calloc(sizeof(uint8_t), 64);
        for (temp = 0; temp < 48; temp++)
            p2[temp + 16] = p1[PC2[temp] - 1];
        key[itr - 1] = btoi64(p2);
        free(p2);
        free(p1);
    }
    return key;
}

uint64_t IP(uint64_t plaintext)
{
    uint8_t ar1[4] = {}, ar2[4] = {}, temp = 0;
    int itr, c1;
    for(itr = 7; itr >= 0; itr--)
    {
        for (c1 = 3; c1 >= 0; c1--)
        {
            temp = (uint8_t)(plaintext & (uint64_t)1);
            temp = temp << itr;
            ar1[c1] |= temp;
            plaintext >>= 1;

            temp = (uint8_t)(plaintext & (uint64_t)1);
            temp = temp << itr;
            ar2[c1] |= temp;
            plaintext >>= 1;
        }
    }
    uint64_t ans = 0;
    uint32_t num1 = 0, num2 = 0;
    for (itr = 0; itr < 4; itr++)
    {
        num1 |= ((uint32_t)ar1[itr]) << ((3 - itr) * 8);
    }

    for (itr = 0; itr < 4; itr++)
    {
        num2 |= ((uint32_t)ar2[itr]) << ((3 - itr) * 8);
    }
    ans = num1;
    ans = ans << 32;
    ans |= num2;
    return ans;
}

uint64_t IPI(uint64_t plaintext)
{
    // 40, 8, 48, 16, 56, 24, 64, 32,
    // 39, 7, 47, 15, 55, 23, 63, 31,
    // 38, 6, 46, 14, 54, 22, 62, 30,
    // 37, 5, 45, 13, 53, 21, 61, 29,
    // 36, 4, 44, 12, 52, 20, 60, 28,
    // 35, 3, 43, 11, 51, 19, 59, 27,
    // 34, 2, 42, 10, 50, 18, 58, 26,
    // 33, 1, 41,  9, 49, 17, 57, 25
    // Defining shifts according to permutation
    uint8_t loc[8] = {6, 4, 2, 0, 7, 5, 3, 1};
    uint8_t arr[8] = {}, temp = 0;
    int itr, c1;
    for(itr = 7; itr >= 0; itr--)
    {
        for (c1 = 0; c1 < 8; c1++)
        {
            temp = (uint8_t)(plaintext & (uint64_t)1);
            temp = temp << loc[itr];
            arr[c1] |= temp;
            plaintext >>= 1;
        }
    }
    uint64_t ans = 0;
    for(itr = 0; itr < 8; itr++)
    {
        ans |= ((uint64_t)arr[itr]) << ((7 - itr)*8);
    }

    return ans;
}

uint64_t EXP(uint32_t input)
{
    uint64_t ans = 0, temp;
    ans = input & (uint32_t)1;
    // Putting value of 32nd bit at start
    ans = ans << 47;
    // Putting value of 1st bit at last
    ans |= input & (!(UINT32_MAX >> 1));
    // Setting 28 - 32 of the last row
    ans |= (input & (uint32_t)(UINT8_MAX >> 3)) << 1;

    input = input >> 3;
    uint32_t req = (uint32_t)(UINT8_MAX >> 2);
    for(int itr = 1; itr <= 7; itr++)
    {
        temp = (uint64_t)(input & req);
        temp = temp << (itr * 6);
        ans |= temp;
        input >> 4;
    }
    return ans;
}

uint32_t SUB_BOX(uint64_t input)
{
    uint8_t Barr[8] = {};
    uint8_t itr; 
    for (itr = 0; itr < 8; itr++)
    {
        Barr[7 - itr] = ((uint8_t)input) & (UINT8_MAX >> 2);
        input >> 6;
    }
    uint8_t req_col = UINT8_MAX >> 4;
    req_col <<= 1;
    uint8_t req_row = 32;
    uint8_t row, col;
    uint8_t Sarr[8] = {};
    for (itr = 0; itr < 8; itr++)
    {
        row = Barr[itr] & req_row;
        row = row > 0 ? 2 : 0;
        row |= Barr[itr] & 1;
        col = Barr[itr] & req_col;
        Sarr[itr] = Si[itr][row][col];
    }
    uint32_t ans = 0, temp;
    for (itr = 0; itr < 8; itr++)
    {
        temp = (uint32_t)Sarr[itr];
        temp <<= ((7 - itr) * 4);
        ans |= temp;
    }

    return ans;
}

uint32_t PERM(uint32_t input)
{
    uint8_t *binary_form = itob32(input);
    uint8_t ans_binary[32] = {};
    for (uint8_t itr = 0; itr < 32; itr++)
        ans_binary[itr] = binary_form[P[itr] - 1];
    uint32_t ans = btoi32(ans_binary);
    return ans;
}

uint32_t FUN(uint32_t input, uint32_t key)
{
    uint64_t t64;
    uint32_t t32;
    t64 = EXP(input);
    t64 ^= key;
    t32 = SUB_BOX(t64);
    t32 = PERM(t32);
    return t32;
}

void main()
{
    // FILE *fptr = fopen(".\\input.txt", "r");
    uint64_t key, plaintext;
    printf("Enter plaintext(numbers only, no alphabets) - ");
    scanf("%" SCNu64, &plaintext);
    printf("\n");
    
    uint64_t ipermval = IP(plaintext);
    uint64_t ipermvali;
    
    printf("Enter key - ");
    scanf("%" SCNu64 , &key);
    printf("\n");
    uint64_t *keys = key_scheduling(key);
    
    printf("ENCRYPTING---------------------------------------------------------------\n");
    printf("IP - %" PRIu64 "\n", ipermval);
    uint64_t encrypt = ipermval;
    uint32_t l, r, lnew, rnew;
    int itr;
    for (itr = 1; itr <= 15; itr++)
    {
        l = (uint32_t)(encrypt >> 32);
        r = (uint32_t)encrypt;
        lnew = r;
        rnew = FUN(r, keys[itr]) ^ l;
        encrypt = lnew;
        encrypt <<= 32;
        encrypt |= rnew;
        printf("At round %d:\n\tKey - %" PRIu64 "\n\t%Val - %" PRIu64 "\n", itr, keys[itr], encrypt);
    }
    l = (uint32_t)(encrypt >> 32);
    r = (uint32_t)encrypt;
    rnew = r;
    lnew = FUN(r, keys[itr]) ^ l;
    encrypt = lnew;
    encrypt <<= 32;
    encrypt |= rnew;
    printf("At round %d:\n\tKey - %" PRIu64 "\n\t%Val - %" PRIu64 "\n", itr, keys[itr], encrypt);
    ipermvali = IPI(encrypt);
    encrypt = ipermvali;
    printf("IPI or Final Permuattion - %" PRIu64 "\n", ipermvali);
    
    //Decryption
    printf("Decrypting--------------------------------------------------------------------\n");
    uint64_t decrypt = encrypt;
    ipermvali = IP(decrypt);
    decrypt = ipermvali;
    printf("IPI - %" PRIu64 "\n", ipermvali);
    l = (uint32_t)(decrypt >> 32);
    r = (uint32_t)decrypt;
    rnew = r;
    lnew = FUN(r, keys[itr]) ^ l;
    decrypt = lnew;
    decrypt <<= 32;
    decrypt |= rnew;
    printf("At round 1:\n\tKey - %" PRIu64 "\n\t%Val - %" PRIu64 "\n", keys[itr], decrypt);
    for (itr = 15; itr > 0; itr--)
    {
        l = (uint32_t)(decrypt >> 32);
        r = (uint32_t)decrypt;
        rnew = l;
        lnew = FUN(l, keys[itr]) ^ r;
        decrypt = lnew;
        decrypt <<= 32;
        decrypt |= rnew;
        printf("At round %d:\n\tKey - %" PRIu64 "\n\t%Val - %" PRIu64 "\n", 17 - itr, keys[itr], decrypt);
    }
    ipermval = IPI(decrypt);
    decrypt = ipermval;
    printf("Decrypted text - %" PRIu64 "\n", ipermval);
    printf("Ptxt - %" PRIu64 "\n", plaintext);
    free(keys);

}