#include <stdio.h>
void clearset(int set[], int n);
int ispresent(int set[], int n, int element);
void display(int set[], int n);
void makeSet(int universal[], int set[], int n, int bitstr[]);
void Union(int set1[], int set2[], int n);
void Intersec(int set1[], int set2[], int n, int inter[]);
void Diff(int set1[], int set2[], int n);
void createset(int universal[], int set[], int n, int n1);

void clearset(int set[], int n) {
    for (int i = 0; i < n; i++)
        set[i] = 0;
}

int ispresent(int set[], int n, int element) {
    for (int i = 0; i < n; i++)
        if (set[i] == element)
            return 1;
    return 0;
}

void display(int set[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", set[i]);
    printf("\n");
}

void makeSet(int universal[], int set[], int n, int bitstr[]) {
    for (int i = 0; i < n; i++) {
        if (ispresent(set, n, universal[i]))
            bitstr[i] = 1;
        else
            bitstr[i] = 0;
    }
}

void Union(int set1[], int set2[], int n) {
    for (int i = 0; i < n; i++) {
        if (set1[i] == 1 || set2[i] == 1)
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
}

void Intersec(int set1[], int set2[], int n, int inter[]) {
    for (int i = 0; i < n; i++) {
        if (set1[i] == 1 && set2[i] == 1)
            inter[i] = 1;
        else
            inter[i] = 0;
    }
}

void Diff(int set1[], int set2[], int n) {
    for (int i = 0; i < n; i++) {
        if (set1[i] == 1 && set2[i] == 0)
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
}

void createset(int universal[], int set[], int n, int n1) {
    clearset(set, n);
    int element;
    if (n1 > n || n1 < 0)
        printf("size of set1 is greater than universal set! or invalid size \n");
    else {
        int count = 0;
        while (count < n1) {
            printf("Enter your %dth element : ", count + 1);
            scanf("%d", &element);

            if (ispresent(set, n, element) == 0 && ispresent(universal, n, element) == 1) {
                set[count] = element;
                count++;
            } else {
                printf("Sorry, Can't allow Duplicated values or element not in universal set!\n");
            }
        }
    }
}

int main() {
    int n, n1, n2, element;
    printf("Enter No of elements in Universal Set : ");
    scanf("%d", &n);
    int universal[n], bitstr1[n], bitstr2[n];
    clearset(universal, n);
    for (int i = 0; i < n; i++) {
        printf("Enter your %dth element : ", i + 1);
        scanf("%d", &element);

        if (ispresent(universal, n, element) == 0)
            universal[i] = element;
        else {
            printf("Sorry, Can't allow Duplicated values!\n");
            i--;
        }
    }

    printf("Enter No of elements in your Set 1 : ");
    scanf("%d", &n1);
    int Set1[n];
    clearset(Set1, n);
    createset(universal, Set1, n, n1);

    printf("Enter No of elements in your Set 2 : ");
    scanf("%d", &n2);
    int Set2[n];
    clearset(Set2, n);
    createset(universal, Set2, n, n2);

    printf("Universal ");
    display(universal, n);
    printf("\n1st ");
    display(Set1, n1);
    printf("2nd ");
    display(Set2, n2);

    printf("\nBitstring of 1st ");
    makeSet(universal, Set1, n, bitstr1);
    display(bitstr1, n);

    printf("Bitstring of 2nd ");
    makeSet(universal, Set2, n, bitstr2);
    display(bitstr2, n);

    int inter[n];
    printf("\nUNION ");
    Union(bitstr1, bitstr2, n);
    Intersec(bitstr1, bitstr2, n, inter);
    printf("INTERSECTION ");
    display(inter, n);
    printf("\nSet1 - Set2 DIFFERENCE ");
    Diff(bitstr1, bitstr2, n);
    printf("Set2 - Set1 DIFFERENCE ");
    Diff(bitstr2, bitstr1, n);

    return 0;
}
