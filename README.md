# Roni Suka Merah
## Verdict
AC saat Pratikum (kompensasi mas Rifki)

## Bukti
![Verdict Roni Suka Merah](https://user-images.githubusercontent.com/81666422/115306470-15532600-a192-11eb-81ea-45e029154ac7.jpg)

## Penjelasan Soal
Di dalam soal Roni Suka Merah diminta untuk memasukkan angka pada binary tree dan mencetak angka tersebut.

## penjelasan Solusi
```
int main () {
    BST set;
    set.init();
    
    int testcase,N;
    cin >> testcase;
        for (int i=1; i<= testcase; i++) {
        cin >> N;
            set.insert(N);
        }
        
        set.traverseInorder();
        puts("");
        return 0;
}
```
Pertama, pada soal Roni Suka Merah menggunakan InOrder karena sesuai dengan contoh input dan output pada soal. Menginisialisasi binary search tree dengan ``` BST set; ``` dilanjutkan dengan ``` set.init();```. Selanjutnya  ```cin >> testcase;``` berfungsi untuk menginputkan testcase jika di soal testcasenya yaitu 6, lalu dilanjutkan dengan ```cin >> N;``` untuk menginputkan angka sesuai yang diminta pada soal. ``` set.insert(N);``` berfungsi untuk memasukkan angka inputan pada binary search tree. Lalu untuk ```set.traverseInorder();``` berfungsi sebagai mencetak angka sesuai dengan cara InOrder.

## Visualisasi Solusi
Input :
6 1 8 12 3 7

![Visualisasi Roni Suka Merah](https://user-images.githubusercontent.com/81666422/115307953-2f8e0380-a194-11eb-8f87-1d0a2690635e.jpg)
Disini inputan dimasukkan pada tree, lalu angka di cetak menggunakan InOrder dengan langkah pertama dari urutan kiri ke akar dan dilnjutkan ke kanan.

Output : 1 3 6 7 8 12


# Genjil Ganap V2
## Verdict
AC saat Revisi

## Bukti
![Verdict Ganjil Ganap V2](https://user-images.githubusercontent.com/81666422/115308859-9c55cd80-a195-11eb-802b-5d1169d304c0.jpg)

## Penjelasan Soal
Pasa soal Genjil Ganap V2, diminta untuk membuat binary search tree yang berisi angka genap semua. Jika memasukkan angka ganjil, maka angka genap yang terakhir dimasukkan akan di remove dari tree. Lalu, angka dicetak dengan urutan dari besar ke kecil.

## Penjelasan Solusi
```
int main(){
    BST set;
    set.init();

    int testcase;
    cin >> testcase;
        for(int i=1; i<=testcase; i++){
        int angka[testcase];
        cin >> angka[i];
        if(i==0){
            if(angka[i]%2==0){
                set.insert(angka[i]);
            }
        }
        else{
            if(angka[i]%2==0){
                set.insert(angka[i]);
            }
            else{
                for(int j=i; j>=0; j--){
                    if(angka[j]%2==0){
                        set.remove(angka[j]);
                        angka[j]++;
                        break;
                    }
                }
            }
        }
    }

    if(set.isEmpty()){
        cout << "Tree Kosong!";
    }
    else{
        set.traverseInorder();
    }
    cout<< endl;
    puts("");
    
    return 0;
}
```
Pertama  Menginisialisasi binary search tree dengan ``` BST set; ``` dilanjutkan dengan ``` set.init();```. Dilanjutkan dengan ```cin >> testcase;``` untuk menginputkan testcase jika contoh padasoal yaitu 7. Lalu ```cin >> angka[i];``` berfungsi untuk memasukkan angka yang sesuai. Lalu ``` if(angka[i]%2==0){
                set.insert(angka[i]);
            }``` berfungsi untuk jika angka genap maka angka akan dimasukkan pada tree. Lalu, untuk ``` for(int j=i; j>=0; j--){
                    if(angka[j]%2==0){
                        set.remove(angka[j]);``` berfungs sebagai jika ada angka genap dan setelahnya merupakan angka ganjil maka angka genap sebelumnya akan di remove dari tree. ```  if(set.isEmpty()){
        cout << "Tree Kosong!";
    }``` jika kosong maka akan mencetak Tree Kosong!, dan ```set.traverseInorder();``` untuk mencetak angka yang sudah diurutkan dari besar ke kecil. 
    
## Visualisasi Solusi 
![Visualisasi Ganjil Ganap 1](https://user-images.githubusercontent.com/81666422/115310168-9234ce80-a197-11eb-9b67-a743b6740dfe.jpg)

Setelah itu angka akan dicetak membentuk tree sesuai urutan.
![Visualisasi Ganjil Ganap 2](https://user-images.githubusercontent.com/81666422/115310278-bc868c00-a197-11eb-9444-df2020eb73a5.jpg)

# Penomoran Garasi Saha
## Verdict
AC saat revisi

## Bukti
![Verdict Garasi Mobil Saha](https://user-images.githubusercontent.com/81666422/115310600-3d458800-a198-11eb-8b79-3181f7c1f07b.jpg)

## Penjelasan Soal
Pada soal Penomoran Garasi Mobil Saha diminta untuk mendata ruangan garasi saha dengan binary search tree dengan ketentuan ruangan pada tingkat terbawah sampai tingkat teratas dengan pola nilai minimal, maksimal, minimal, dst.

## Penjelasan Solusi
```
int checker1, temp;
    void printInorder(BSTNode *root){
        int h = height(root);
        int i, checker=0;
        for (i=h; i>=1; i--){
            if(checker==0){
                temp=100000;
                printLevel(root, i, checker);
                cout << checker1;
                checker++;
            }
            else{
                temp=0;
                printLevel(root, i, checker);
                cout << checker1;
                checker--;
            }
            cout << (" ");
        }
    }
    
    void printLevel(BSTNode *root, int level, int checker){
        if (root == NULL){
            return;
        }   
        if (level == 1){
            if(checker==0){
                if(root->key<=temp){
                    temp=root->key;
                    checker1=temp;
                }
            }
            else{
                if(root->key>=temp){
                    temp=root->key;
                    checker1=temp;
                }
            }
        }
        else if (level > 1){
            printLevel(root->left, level-1, checker);
            printLevel(root->right, level-1, checker);
        }
    }

```
Berfungsi untuk mencari nilai minimal dan maksimalnya pada setiap level. Lalu dilanjutkan dengan
```
 int height(BSTNode *root){
        if (root==NULL){
            return 0;
        }
        else{
            int lheight = height(root->left);
            int rheight = height(root->right);
 
            if (lheight > rheight)
                return(lheight+1);
            else return(rheight+1);
        }
    }
};
```
Berfungsi untuk mecari pada level berapakah angka yang diminta pada inputan.

```
int main (){
    BST set;
    set.init();
    
    int testcase,N;
    cin >> testcase;
        for (int i=1; i <= testcase; i++){
            cin >> N;
            set.insert(N);
        }
        
    set.traverseInorder ();
    return 0;
}
```
Pertama  Menginisialisasi binary search tree dengan ``` BST set; ``` dilanjutkan dengan ``` set.init();```. Dilanjutkan dengan ```cin >> testcase;``` untuk menginputkan testcase, jika pada soal yaitu 7. Lalu ```cin >> N;``` menginputan angka yang diminta, ``` set.insert(N);``` memasukkan angka pada tree. Lalu angka dicetak menggunakan ``` set.traverseInorder ();``` dan mengunjungi setiap node lalu mencari mencari nilai minimal dan minimumnya.

## Visualisasi Solusi


 


