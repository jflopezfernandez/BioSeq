
#include "BioSeq.h"

#if defined (TRUE) || defined (FALSE)
#error "TRUE and FALSE constants already defined!"
#else
#define TRUE  1
#define FALSE 0
#endif // TRUE/FALSE

void StringCopyReverse(char* s1, const char* s2) {
    const size_t Length = strlen(s2);

    for (size_t i = 0; i < Length; ++i) {
        s1[Length - i - 1] = s2[i];
    }
}

int FileExists(const char* Filename) {
    // TODO: Implement _WIN32 handler

    #if defined (__unix__)
    if (access(Filename, F_OK) != -1) {
        return TRUE;
    } else {
        return FALSE;
    }
    #endif // unix
}

FILE* OpenFile(const char* Filename, const char* Mode) {
    FILE* fileHandle = fopen(Filename, Mode);

    if (!fileHandle) {
        // TODO: Handle error.

        exit(EXIT_FAILURE);
    }

    return fileHandle;
}

#define ADENINE  'A'
#define CYTOSINE 'C'
#define GUANINE  'G'
#define THYMINE  'T'
#define URACYL   'U'

typedef enum monomers_t {
    Adenine,
    Cytosine,
    Guanine,
    Thymine,
    Uracyl
} Monomers;

typedef char  Monomer;
typedef char* Sequence;

inline char Complement(Monomer base) {
    switch (base) {
        case ADENINE: {
            return THYMINE;
        }

        case CYTOSINE: {
            return GUANINE;
        }

        case GUANINE: {
            return CYTOSINE;
        }

        case THYMINE: {
            return ADENINE;
        }

        /** TODO: Implement this properly */
        default: {
            return URACYL;
        }
    }
}

Sequence AllocateSequence(size_t length) {
    Sequence newSequence = malloc(sizeof(char) * length);

    if (!newSequence) {
        // TODO: Handle error

        exit(EXIT_FAILURE);
    }

    memset(newSequence, 0, length);

    return newSequence;
}

Sequence GetRNATranscription(Sequence DNASequence) {
    const size_t Length = strlen(DNASequence);

    Sequence RNASequence = AllocateSequence(Length);
    strcpy(RNASequence, DNASequence);

    for (size_t i = 0; i < Length; ++i) {
        if (RNASequence[i] == THYMINE) {
            RNASequence[i] = URACYL;
        }
    }

    return RNASequence;
}

Sequence GetReverseComplement(Sequence DNASequence) {
    const size_t Length = strlen(DNASequence);

    Sequence NewSequence = AllocateSequence(Length);

    for (size_t i = 0; i < Length; ++i) {
        NewSequence[i] = Complement(DNASequence[i]);
    }

    Sequence ReverseSequence = AllocateSequence(Length);
    StringCopyReverse(ReverseSequence, NewSequence);

    return ReverseSequence;
}

Sequence CopyStringAtIndex(Sequence dest, Sequence source, size_t index) {
    Sequence handle = &dest[index];

    strcpy(handle, source);

    return handle;
}

Sequence AppendToSequence(Sequence Sequence, Sequence Addition) {
    const size_t L1 = strlen(Sequence);
    const size_t L2 = strlen(Addition);
    const size_t ln = L1 + L2;

    Sequence newSequence = AllocateSequence(ln);

    strcpy(newSequence, Sequence);
    CopyStringAtIndex(newSequence, Addition, L1);

    return newSequence;
}

Sequence PrependToSequence(Sequence Sequence, Sequence Addition) {
    const size_t L1 = strlen(Sequence);
    const size_t L2 = strlen(Addition);
    const size_t ln = L1 + L2;

    Sequence newSequence = AllocateSequence(ln);

    strcpy(newSequence, Addition);
    CopyStringAtIndex(newSequence, Sequence, L2);

    return newSequence;
}


//int main(int argc, char *argv[])
int main()
{
    //if (argc == 1) { return EXIT_SUCCESS; }

    //FILE* inputFile = OpenFile(argv[1]);

    // Part 1
    // char* DNA = "ACGGGAGGACGGGAAAATTACTACGGCATTAGC";
    // char* RNA = GetRNATranscription(DNA);

    // printf("DNA: %s\n", DNA);
    // printf("RNA: %s\n", RNA);
    // printf("\n");

    // char* Com = GetReverseComplement(DNA);

    // printf("DNA: %s\n", DNA);
    // printf("Com: %s\n", Com);
    // printf("\n");

    // size_t LineLength = 128;
    // char* Line = malloc(sizeof(char) * LineLength);
    // memset(Line, 0, LineLength);

    // const char* inputFileName = (argc == 2) ? argv[1] : "NM_021964fragment.pep";

    // // Part 2
    // FILE* inputFile = fopen(inputFileName, "r");

    // // Option 1: Line by Line
    // // while (!feof(inputFile)) {
    // //     fgets(Line, LineLength, inputFile);
    // //     printf("%s", Line);
    // //     memset(Line, 0, LineLength);
    // // }

    // // Option 2: Char by Char
    // char data = fgetc(inputFile);

    // int Adenine = 0;
    // int Cytosine = 0;
    // int Guanine = 0;
    // int Thymine = 0;

    // do {
    //     printf("%c", data);
    //     data = fgetc(inputFile);

    //     if (data == ADENINE) {
    //         ++Adenine;
    //     } else if (data == CYTOSINE) {
    //         ++Cytosine;
    //     } else if (data == GUANINE) {
    //         ++Guanine;
    //     } else if (data == THYMINE) {
    //         ++Thymine;
    //     }
    // } while (data != EOF);

    // fclose(inputFile);

    // printf("Adenine:  %d\n", Adenine);
    // printf("Cytosine: %d\n", Cytosine);
    // printf("Guanine:  %d\n", Guanine);
    // printf("Thymine:  %d\n", Thymine);

    Sequence s1 = "ACGT";
    Sequence s2 = "CC";
    Sequence s3 = AppendToSequence(s1, s2);
    Sequence s4 = PrependToSequence(s3, s2);

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);
    printf("s4: %s\n", s4);

    return EXIT_SUCCESS;
}
