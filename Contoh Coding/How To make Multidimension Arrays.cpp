//main.cp
#include <iostream>
using namespace std;

void Variant1(){
    /*
    Menggunakan 1 deret pointer yang kemudian di pecah pada setiap awal row:
        Pros:
        1. Simple
        Cons:
        1. penulisan "popoi[r]" menggunakan seluruh address pada table
            meungkinkan akses melebihi nilai kolom maksimal
            contoh popoi[0][25]
    */
    int *table = (int *) malloc ( 5 * 5 * sizeof(int)); //Contigous -> Cells
    int **popoi = (int **) malloc (5 * sizeof(int *)); //Can be translated as Rows
    for(int r=0; r < 5; r++){
        for(int c=0; c < 5; c++){
            table[(r * 5) + c] = (r * 5) + c;
        }
        popoi[r] = table + (r * 5);
    }
  //cout << popoi[4][0] << endl;
  for(int r = 0; r < 5 ; r++){
      for(int c= 0; c < 5; c++){
          cout << popoi[r][c] << endl;
      }
  }
}
void Variant2(){ // 2D Arrays
    int **table = (int **) malloc (5 * sizeof(int*));
    for(int r=0; r < 5; r++){
        table[r] = (int *) malloc (5 * sizeof(int));
        for(int c=0; c<5; c++){
            table[r][c] = (r * 5) + c;
        }
    }
    int r, c;
    for(int cell=0; cell < 25; cell++){
        r = cell / 5;
        c = cell % 5;
        cout << table[r][c] << endl;
    }
}
void Variant3(){ // 3D Arrays
    int counter = 0;
    int ***triplet = (int ***) malloc (sizeof(int**) * 100);
    for(int fst = 0; fst < 100; fst++){
        triplet[fst] = (int **) malloc (sizeof(int *) * 30);
        for(int scd = 0; scd < 30; scd++){
            triplet[fst][scd] =(int *) malloc (sizeof(int) * 5);
            for(int lst = 0; lst < 5; lst++){
                triplet[fst][scd][lst] = lst + (scd * 5) + (fst * 30 * 5);
            }
        }
    }
    for(int i = 0; i < 5; i++){
        cout << triplet[99][29] << endl;
    }
}
void Variant4(){ // 4D Arrays
    long ****Quadron = (long ****) malloc (sizeof(long ***) * 50);
    for(long one = 0; one < 50; one++){
        Quadron[one] = (long ***) malloc (sizeof(long **) * 50);
        for(long second = 0; second < 50; second++ ){
            Quadron[one][second] = (long **) malloc (sizeof(long *) * 50);
            for(long third = 0; third < 50; third++){
                Quadron[one][second][third] = \
                            (long *) malloc (sizeof(long) * 50);
                for(long forth = 0; forth < 50; forth++){
                    Quadron[one][second][third][forth] = \
                                    forth + (third * 50) + (second * 50 * 50) +\
                                    (one * 50 * 50 * 50);
                }
            }
        }
    }
    cout << Quadron[49][49][49][49] << endl;
}

int main(){
    Variant4();
}
