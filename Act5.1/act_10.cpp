#include<iostream>
#include<list> 
#include<cstring>
using namespace std;

class Hash
{
    int BUCKET;    // No. of buckets

    // Pointer to an array containing buckets
    list <int> *table;
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x); 

    static void chain(Hash h, int a[], int n);

    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

int Hash::hashFunction(int x){
    return (x % BUCKET);
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
  // get the hash index of key
  int index = hashFunction(key);

  // find the key in (index)th list
  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }

  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}

void Hash::chain(Hash h, int a[], int n){
    for (int i = 0; i < n; i++)
    h.insertItem(a[i]);
}

// Driver program

// Function to print an array
void printArray(int arr[], int n)
{
    // Iterating and printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Function to implement the
// quadratic probing
void quadratic(int table[], int tsize,
             int arr[], int N)
{
    // Iterating through the array
    for (int i = 0; i < N; i++)
    {
        // Computing the hash value
        int hv = arr[i] % tsize;

        // Insert in the table if there
        // is no collision
        if (table[hv] == -1)
            table[hv] = arr[i];
        else
        {
            // If there is a collision
            // iterating through all
            // possible quadratic values
            for (int j = 0; j < tsize; j++)
            {
                // Computing the new hash value
                int t = (hv + j * j) % tsize;
                if (table[t] == -1)
                {
                    // Break the loop after
                    // inserting the value
                    // in the table
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
}

void tableh(int hash_table[],int tsize){
     for (int i = 0; i < tsize; i++)
    {
        hash_table[i] = -1;
    }
}
// Driver code

int main()
{
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);

  // insert the keys into the hash table
  Hash h(7);   // 7 is count of buckets in
               // hash table

  Hash::chain(h,a,n);

  // display the Hash table
  cout << "Insercion tipo chain." << endl;
  h.displayHash();

  cout << endl;

  int arr[] = {50, 700, 76,
                 85, 92, 73, 101};
    int N = 7;

    // Size of the hash table
    int L = 7;
    int hash_table[7];

    tableh(hash_table, L);

    // Quadratic probing
    quadratic(hash_table, L, arr, N);

    cout << "Insercion por metodo cuadratico." << endl;
    printArray(hash_table, N);

  return 0;
}