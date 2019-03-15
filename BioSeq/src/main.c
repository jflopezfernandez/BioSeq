
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
    #if defined (__unix__)
    if (access(Filename, F_OK) != -1) {
        return TRUE;
    } else {
        return FALSE;
    }
    #endif //
}

FILE* OpenFile(const char* Filename) {
    //

    return NULL;
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

inline char Complement(char Monomer) {
    switch (Monomer) {
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

char* GetRNATranscription(const char* DNASequence) {
    const size_t Length = strlen(DNASequence);

    char* RNASequence = malloc(sizeof(char) * Length);
    strcpy(RNASequence, DNASequence);

    for (size_t i = 0; i < Length; ++i) {
        if (RNASequence[i] == THYMINE) {
            RNASequence[i] = URACYL;
        }
    }

    return RNASequence;
}

char* GetReverseComplement(const char* DNASequence) {
    const size_t Length = strlen(DNASequence);

    char* NewSequence = malloc(sizeof(char) * Length);
    memset(NewSequence, 0, Length);

    for (size_t i = 0; i < Length; ++i) {
        NewSequence[i] = Complement(DNASequence[i]);
    }

    char* ReverseSequence = malloc(sizeof(char) * Length);
    StringCopyReverse(ReverseSequence, NewSequence);

    return ReverseSequence;
}


int main(int argc, char *argv[])
{
    if (argc == 1) { return EXIT_SUCCESS; }

    FILE* inputFile = OpenFile(argv[1]);

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

    return EXIT_SUCCESS;
}
