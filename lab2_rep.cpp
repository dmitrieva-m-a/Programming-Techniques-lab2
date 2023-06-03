#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <chrono>
#include <map>

using namespace std;

class Articles {
public:
    /**
    *  @brief Parameterized constructor
    *  @details Used for initialization an object of the class according to the parameters
    *  @param name_ parameter with string type, country_ parameter with string type, volume_ parameter with the float type, summa_ parameter with the float type
    *  @return There is no return value
    *  @code
        Articles(string name_, string country_, float volume_, float summa_){
            name = name_;
            country = country_;
            volume = volume_;
            summa = summa_;
            }
    *  @endcode
    */

    Articles(string name_, string country_, float volume_, float summa_){
    name = name_;
    country = country_;
    volume = volume_;
    summa = summa_;
    }

    /**
    *  @brief Default constructor
    *  @details Used for filling class fields with empty strings or zeros, depending on the datd type of the field (string or float)
    *  @param There are no parameters
    *  @return There is no return value
    *  @code
        Articles() {
            name = "";
            country = "";
            volume = 0;
            summa = 0;
        }
    *  @endcode
    */

    Articles() {
        name = "";
        country = "";
        volume = 0;
        summa = 0;
    }

    /**
     *  @brief Input file stream constructor
     *  @details Used for reading class fields from the input file stream
     *  @param File stream reference
     *  @return There is no return value
     *  @code
        Articles(ifstream& in) {
            in >> name >> country >> volume >> summa;
        }
     *  @endcode
     */

    Articles(ifstream& in) {
        in >> name >> country >> volume >> summa;
    }

    /**
     *  @brief Destructor
     *  @details Used for default description of class methods
     *  @param There are no parameters
     *  @return There is no return value
     *  @code
        ~Articles() {}
     *  @endcode
     */

    ~Articles() {}

    /**
     *  @brief Assignment operator
     *  @details Used for storing a value of fields in the object specified by the left operand from object specified by the right operand
     *  @param There are no parameters
     *  @return There is no return value
     *  @code
        Articles& Articles::operator= (const Articles& art) {
            name = art.name;
            country = art.country;
            volume = art.volume;
            summa = art.summa;

            return *this;
        }
     *  @endcode
     */

    Articles& operator= (const Articles& art);

    /**
     *  @brief Output operator
     *  @details Used for output a class object (class fields) to the output stream; a friend of class
     *  @param Output stream reference and constant reference of class object
     *  @return Output steam
     *  @code
        ostream& operator<< (ostream& out, const Articles& art){
            out << art.name << " ";
            out << art.country << " ";
            out << art.volume << " ";
            out << art.summa << " ";

            out << endl;

            return out;
        }
     *  @endcode
     */

    friend ostream& operator<< (ostream& out, const Articles& art);

    /**
     *  @brief Class fields
     *  @details The name of the product, the country of export, the volume of products supplied and the amount of sale
     *  @code
            string name;
            string country;
            float volume;
            float summa;
     *  @endcode
     */

    string name;
    string country;
    float volume;
    float summa;

};



Articles& Articles::operator= (const Articles& art) {
        name = art.name;
        country = art.country;
        volume = art.volume;
        summa = art.summa;

        return *this;
    }

ostream& operator<< (ostream& out, const Articles& art){
    out << art.name << " ";
    out << art.country << " ";
    out << art.volume << " ";
    out << art.summa << " ";

    out << endl;

    return out;
}

/**
 *  @brief Comparison operator for strict equality
 *  @details Used for checking strict equality between left and right operands
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if parameters are equal, False otherwise
 *  @code
    bool operator== (const Articles& art1, const Articles& art2) {
        return ((art1.name == art2.name) && (art1.volume == art2.volume) && (art1.country == art2.country));
    }
 *  @endcode
 */

bool operator== (const Articles& art1, const Articles& art2) {
    return ((art1.name == art2.name) && (art1.volume == art2.volume) && (art1.country == art2.country));
}

/**
 *  @brief Comparison operator for strict inequality
 *  @details Used for checking strict inequality between left and right operands
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if parameters are unequal, False otherwise
 *  @code
    bool operator!= (const Articles& art1, const Articles& art2) {
        return !(art1 == art2);
    }
 *  @endcode
 */

bool operator!= (const Articles& art1, const Articles& art2) {
    return !(art1 == art2);
}

/**
 *  @brief Comparison operator "strictly greater"
 *  @details Used for checking whether the left operand is strictly greater than the right one
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if left operand is strictly greater than right operand, False otherwise
 *  @code
    bool operator> (const Articles& art1, const Articles& art2) {
        if (art1 == art2)
            return false;

        if (art1.name != art2.name)
            return (art1.name > art2.name);

        if (art1.volume != art2.volume)
            return (art1.volume > art2.volume);

        if (art1.country != art2.country)
            return (art1.country > art2.country);
    }
 *  @endcode
 */

bool operator> (const Articles& art1, const Articles& art2) {
    if (art1 == art2)
        return false;

    if (art1.name != art2.name)
        return (art1.name > art2.name);

    if (art1.volume != art2.volume)
        return (art1.volume > art2.volume);

    if (art1.country != art2.country)
        return (art1.country > art2.country);
}

/**
 *  @brief Comparison operator "not strictly greater"
 *  @details Used for checking whether the left operand is not strictly greater than the right one
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if left operand is not strictly greater than right operand, False otherwise
 *  @code
    bool operator>= (const Articles& art1, const Articles& art2) {
        return ((art1 > art2) || (art1 == art2));
    }
 *  @endcode
 */

bool operator>= (const Articles& art1, const Articles& art2) {
    return ((art1 > art2) || (art1 == art2));
}

/**
 *  @brief Comparison operator "strictly less"
 *  @details Used for checking whether the left operand is strictly less than the right one
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if left operand is strictly less than right operand, False otherwise
 *  @code
    bool operator< (const Articles& art1, const Articles& art2) {
        return !(art1 >= art2);
    }
 *  @endcode
 */

bool operator< (const Articles& art1, const Articles& art2) {
    return !(art1 >= art2);
}

/**
 *  @brief Comparison operator "not strictly less"
 *  @details Used for checking whether the left operand is not strictly less than the right one
 *  @param Constant reference of left and right operands of the type Articles
 *  @return True if left operand is not strictly less than right operand, False otherwise
 *  @code
    bool operator< (const Articles& art1, const Articles& art2) {
        return !(art1 >= art2);
    }
 *  @endcode
 */

bool operator<= (const Articles& art1, const Articles& art2) {
    return ((art1 < art2) || (art1 == art2));
}

/**
 *  @brief Template function of bubble sorting
 *  @details Used for sorting data array by the bubble sorting method
 *  @param Pointer to the first element of the sorted array with data type T, array size with data type size_t
 *  @return There is no return value
 *  @code
    template <typename T>
    void bubleSort (T* A, size_t n) {
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - 1 - i; j++){
                if (A[j] > A[j + 1])
                    swap(A[j], A[j + 1]);
            }
        }
    }
 *  @endcode
 */

template <typename T>
void bubbleSort(T* A, size_t n) {
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
}

/**
 *  @brief Template function of shaker sorting
 *  @details Used for sorting data array by the shaker sorting method
 *  @param Pointer to the first element of the sorted array with data type T, array size with data type size_t
 *  @return There is no return value
 *  @code
    template <typename T>
    void shakerSort (T* A, size_t n) {
        int low = 0, up = n - 1;

        int last;

        T tmp;

        while (low < up) {
            last = -1;

            for (int i = low; i < up; i++) {
                if (A[i] > A[i + 1]) {
                    tmp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = tmp;
                    last = i;
                }
            }

            up = last;

            last = n;
            for (int i = up - 1; i >= low; i--) {
                if (A[i] > A[i + 1]) {
                    tmp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = tmp;
                    last = i;
                }
            }

            low = last + 1;
        }
    }
 *  @endcode
 */


template <typename T>
void shakerSort(T* A, size_t n) {
    int low = 0, up = n - 1;

    int last;

    T tmp;

    while (low < up) {
        last = -1;

        for (int i = low; i < up; i++) {
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                last = i;
            }
        }

        up = last;

        last = n;
        for (int i = up - 1; i >= low; i--) {
            if (A[i] > A[i + 1]) {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                last = i;
            }
        }

        low = last + 1;
    }
}

/**
 *  @brief Template function of merge sorting
 *  @details Used for sorting data array by the merge sorting method
 *  @param Pointer to the first element of the sorted array with data type T, array size with data type size_t
 *  @return There is no return value
 *  @code
    template <typename T>
    void mergeSort(T* A, size_t n){
        if (n == 1)
            return;

        mergeSort(A, n / 2);
        mergeSort(&A[n / 2], n - n / 2);

        int i = 0, j = n / 2, c = 0;

        T* N = new T[n];

        while(c < n){
            if (i == n / 2){
                N[c] = A[j];
                j++;
            }
            else
            if (j == n){
                N[c] = A[i];
                i++;
            }
            else
            if (A[i] < A[j]){
                N[c] = A[i];
                i++;
            }
            else
            {
                N[c] = A[j];
                j++;
            }
            c++;
        }

        for (size_t i = 0; i < n; i++)
            A[i] = N[i];
    }
 *  @endcode
 */

template <typename T>
void mergeSort(T* A, size_t n){
    if (n == 1)
        return;

    mergeSort(A, n / 2);
    mergeSort(&A[n / 2], n - n / 2);

    int i = 0, j = n / 2, c = 0;

    T* N = new T[n];

    while(c < n){
        if (i == n / 2){
            N[c] = A[j];
            j++;
        }
        else
        if (j == n){
            N[c] = A[i];
            i++;
        }
        else
        if (A[i] < A[j]){
            N[c] = A[i];
            i++;
        }
        else
        {
            N[c] = A[j];
            j++;
        }
        c++;
    }

    for (size_t i = 0; i < n; i++)
        A[i] = N[i];
}

/**
 *  @brief Template function of linear searching
 *  @details Used for linear search for a given element in an array of objects by key
 *  @param Pointer to the first element of the sorted array with data type T, array size with data type size_t, key with data type string
 *  @return The number of the desired element or -1 in case of an error
 *  @code
    template <typename T>
    int linearSearch(T* A, size_t n, string key) {
        for (size_t i = 0; i < n; i++) {
            if (A[i].name == key)
                return i;
        }
        return -1;
    }
 *  @endcode
 */

template <typename T>
int linearSearch(T* A, size_t n, string key) {
    for (size_t i = 0; i < n; i++) {
        if (A[i].name == key)
            return i;
    }
    return -1;
}

/**
 *  @brief Template function of binary searching
 *  @details Used for binary search for a given element in an array of objects by key
 *  @param Pointer to the first element of the sorted array with data type T, array size with data type size_t, key with data type string
 *  @return The number of the desired element or -1 in case of an error
 *  @code
    template <typename T>
    int binarySearch(T* A, size_t n, string key) {

        size_t l = 0, r = n, m;

        while (l <= r){
            m = (l + r) / 2;

            if (A[m].name == key)
                return m;

            if (A[m].name > key)
                r = m - 1;

            else
                l = m + 1;
        }

        return -1;
    }
 *  @endcode
 */

template <typename T>
int binarySearch(T* A, size_t n, string key) {

    size_t l = 0, r = n, m;

    while (l <= r){
        m = (l + r) / 2;

        if (A[m].name == key)
            return m;

        if (A[m].name > key)
            r = m - 1;

        else
            l = m + 1;
    }

    return -1;
}

/**
 *  @brief Main function
 *  @details Used for reading samples from files, searching for a key element in the read arrays in various ways, measuring the search time
 *  @param There is no parameters
 *  @return There is no return value
 *  @code
    int main(){

    Articles *d_100 = new Articles[100], *d_500 = new Articles[500], *d_1000 = new Articles[1000], *d_5000 = new Articles[5000], *d_10000 = new Articles[10000], *d_50000 = new Articles[50000], *d_100000 = new Articles[100000];

        ifstream f_100("100.txt");
        if (f_100.is_open())
            for (size_t i = 0; i < 100; i++)
                d_100[i] = Articles(f_100);
        f_100.close();

        ifstream f_500("500.txt");
        if (f_500.is_open())
            for (size_t i = 0; i < 500; i++)
                d_500[i] = Articles(f_500);
        f_500.close();

        ifstream f_1000("1000.txt");
        if (f_1000.is_open())
            for (size_t i = 0; i < 1000; i++)
                d_1000[i] = Articles(f_1000);
        f_1000.close();

        ifstream f_5000("5000.txt");
        if (f_5000.is_open())
            for (size_t i = 0; i < 5000; i++)
                d_5000[i] = Articles(f_5000);
        f_5000.close();

        ifstream f_10000("10000.txt");
        if (f_10000.is_open())
            for (size_t i = 0; i < 10000; i++)
                d_10000[i] = Articles(f_10000);
        f_10000.close();

        ifstream f_50000("50000.txt");
        if (f_50000.is_open())
            for (size_t i = 0; i < 50000; i++)
                d_50000[i] = Articles(f_50000);
        f_50000.close();

        ifstream f_100000("100000.txt");
        if (f_100000.is_open())
            for (size_t i = 0; i < 100000; i++)
                d_100000[i] = Articles(f_100000);
        f_100000.close();

        int option;
        cout << "What option do you want?\nLinear - print 1,\nBinary without sorting array - print 2,\nBinary with sorting array - print,3\nMultimap - print 4\n";
        cin >> option;

        if (option == 1) {
            cout << "Array with a volume of 100:\t";
            auto s_t = chrono::steady_clock::now();
            int t = linearSearch(d_100, 100, "fgcj");
            auto e_t = chrono::steady_clock::now();
            auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 500:\t";
            s_t = chrono::steady_clock::now();
            t = linearSearch(d_500, 500, "sosl");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 1000:\t";
            s_t = chrono::steady_clock::now();
            t = linearSearch(d_1000, 1000, "iwsw");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 5000:\t";
            s_t = chrono::steady_clock::now();
            t = linearSearch(d_5000, 5000, "qxqu");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 10000:\t";
            s_t = chrono::steady_clock::now();
            t = linearSearch(d_10000, 10000, "knac");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 50000:\t";
            s_t = chrono::steady_clock::now();
            t = linearSearch(d_50000, 50000, "pjsa");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 100000:\t";
            s_t = chrono::steady_clock::now();
            t = linearSearch(d_100000, 100000, "xyao");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";
        }

        if (option == 2) {

            cout << "Array with a volume of 100:\t";
            auto s_t = chrono::steady_clock::now();
            mergeSort(d_100, 100);
            int t = binarySearch(d_100, 100, "fgcj");
            auto e_t = chrono::steady_clock::now();
            auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 500:\t";
            s_t = chrono::steady_clock::now();
            mergeSort(d_500, 500);
            t = binarySearch(d_500, 500, "sosl");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 1000:\t";
            s_t = chrono::steady_clock::now();
            mergeSort(d_1000, 1000);
            t = binarySearch(d_1000, 1000, "iwsw");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 5000:\t";
            s_t = chrono::steady_clock::now();
            mergeSort(d_5000, 5000);
            t = binarySearch(d_5000, 5000, "qxqu");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 10000:\t";
            s_t = chrono::steady_clock::now();
            mergeSort(d_10000, 10000);
            t = binarySearch(d_10000, 10000, "knac");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 50000:\t";
            s_t = chrono::steady_clock::now();
            mergeSort(d_50000, 50000);
            t = binarySearch(d_50000, 50000, "pjsa");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 100000:\t";
            s_t = chrono::steady_clock::now();
            mergeSort(d_100000, 100000);
            t = binarySearch(d_100000, 100000, "xyao");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";
        }

        if (option == 3) {
            mergeSort(d_100, 100);
            mergeSort(d_500, 500);
            mergeSort(d_1000, 1000);
            mergeSort(d_5000, 5000);
            mergeSort(d_10000, 10000);
            mergeSort(d_50000, 50000);
            mergeSort(d_100000, 100000);

            cout << "Array with a volume of 100:\t";
            auto s_t = chrono::steady_clock::now();
            int t = binarySearch(d_100, 100, "fgcj");
            auto e_t = chrono::steady_clock::now();
            auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 500:\t";
            s_t = chrono::steady_clock::now();
            t = binarySearch(d_500, 500, "sosl");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 1000:\t";
            s_t = chrono::steady_clock::now();
            t = binarySearch(d_1000, 1000, "iwsw");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 5000:\t";
            s_t = chrono::steady_clock::now();
            t = binarySearch(d_5000, 5000, "qxqu");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 10000:\t";
            s_t = chrono::steady_clock::now();
            t = binarySearch(d_10000, 10000, "knac");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 50000:\t";
            s_t = chrono::steady_clock::now();
            t = binarySearch(d_50000, 50000, "pjsa");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 100000:\t";
            s_t = chrono::steady_clock::now();
            t = binarySearch(d_100000, 100000, "xyao");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";
        }

        if (option == 4){
            multimap <string, Articles> m_100 = {}, m_500 = {}, m_1000 = {}, m_5000 = {}, m_10000 = {}, m_50000 = {}, m_100000 = {};


            for (int i = 0; i < 100; i++)
                m_100.insert(pair <string, Articles>(d_100[i].name, d_100[i]));

            for (int i = 0; i < 500; i++)
                m_500.insert(pair <string, Articles>(d_500[i].name, d_500[i]));

            for (int i = 0; i < 1000; i++)
                m_1000.insert(pair <string, Articles>(d_1000[i].name, d_1000[i]));

            for (int i = 0; i < 5000; i++)
                m_5000.insert(pair <string, Articles>(d_5000[i].name, d_5000[i]));

            for (int i = 0; i < 10000; i++)
                m_10000.insert(pair <string, Articles>(d_10000[i].name, d_10000[i]));

            for (int i = 0; i < 50000; i++)
                m_50000.insert(pair <string, Articles>(d_50000[i].name, d_50000[i]));

            for (int i = 0; i < 100000; i++)
                m_100000.insert(pair <string, Articles>(d_100000[i].name, d_100000[i]));

            cout << "Array with a volume of 100:\t";
            auto s_t = chrono::steady_clock::now();
            auto t = m_100.find("fgcj");
            auto e_t = chrono::steady_clock::now();
            auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 500:\t";
            s_t = chrono::steady_clock::now();
            t = m_500.find("sosl");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 1000:\t";
            s_t = chrono::steady_clock::now();
            t = m_1000.find("iwsw");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 5000:\t";
            s_t = chrono::steady_clock::now();
            t = m_5000.find("qxqu");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 10000:\t";
            s_t = chrono::steady_clock::now();
            t = m_10000.find("knac");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 50000:\t";
            s_t = chrono::steady_clock::now();
            t = m_50000.find("pjsa");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";

            cout << "Array with a volume of 100000:\t";
            s_t = chrono::steady_clock::now();
            t = m_100000.find("xyao");
            e_t = chrono::steady_clock::now();
            ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
            cout << ns.count() << " nanoseconds\n";
        }
    }
 *  @endcode
 */


int main(){

Articles *d_100 = new Articles[100], *d_500 = new Articles[500], *d_1000 = new Articles[1000], *d_5000 = new Articles[5000], *d_10000 = new Articles[10000], *d_50000 = new Articles[50000], *d_100000 = new Articles[100000];

    ifstream f_100("100.txt");
    if (f_100.is_open())
        for (size_t i = 0; i < 100; i++)
            d_100[i] = Articles(f_100);
    f_100.close();

    ifstream f_500("500.txt");
    if (f_500.is_open())
        for (size_t i = 0; i < 500; i++)
            d_500[i] = Articles(f_500);
    f_500.close();

    ifstream f_1000("1000.txt");
    if (f_1000.is_open())
        for (size_t i = 0; i < 1000; i++)
            d_1000[i] = Articles(f_1000);
    f_1000.close();

    ifstream f_5000("5000.txt");
    if (f_5000.is_open())
        for (size_t i = 0; i < 5000; i++)
            d_5000[i] = Articles(f_5000);
    f_5000.close();

    ifstream f_10000("10000.txt");
    if (f_10000.is_open())
        for (size_t i = 0; i < 10000; i++)
            d_10000[i] = Articles(f_10000);
    f_10000.close();

    ifstream f_50000("50000.txt");
    if (f_50000.is_open())
        for (size_t i = 0; i < 50000; i++)
            d_50000[i] = Articles(f_50000);
    f_50000.close();

    ifstream f_100000("100000.txt");
    if (f_100000.is_open())
        for (size_t i = 0; i < 100000; i++)
            d_100000[i] = Articles(f_100000);
    f_100000.close();

    int option;
    cout << "What option do you want?\nLinear - print 1,\nBinary without sorting array - print 2,\nBinary with sorting array - print,3\nMultimap - print 4\n";
    cin >> option;

    if (option == 1) {
        cout << "Array with a volume of 100:\t";
        auto s_t = chrono::steady_clock::now();
        int t = linearSearch(d_100, 100, "fgcj");
        auto e_t = chrono::steady_clock::now();
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 500:\t";
        s_t = chrono::steady_clock::now();
        t = linearSearch(d_500, 500, "sosl");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 1000:\t";
        s_t = chrono::steady_clock::now();
        t = linearSearch(d_1000, 1000, "iwsw");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 5000:\t";
        s_t = chrono::steady_clock::now();
        t = linearSearch(d_5000, 5000, "qxqu");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 10000:\t";
        s_t = chrono::steady_clock::now();
        t = linearSearch(d_10000, 10000, "knac");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 50000:\t";
        s_t = chrono::steady_clock::now();
        t = linearSearch(d_50000, 50000, "pjsa");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 100000:\t";
        s_t = chrono::steady_clock::now();
        t = linearSearch(d_100000, 100000, "xyao");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";
    }

    if (option == 2) {

        cout << "Array with a volume of 100:\t";
        auto s_t = chrono::steady_clock::now();
        mergeSort(d_100, 100);
        int t = binarySearch(d_100, 100, "fgcj");
        auto e_t = chrono::steady_clock::now();
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 500:\t";
        s_t = chrono::steady_clock::now();
        mergeSort(d_500, 500);
        t = binarySearch(d_500, 500, "sosl");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 1000:\t";
        s_t = chrono::steady_clock::now();
        mergeSort(d_1000, 1000);
        t = binarySearch(d_1000, 1000, "iwsw");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 5000:\t";
        s_t = chrono::steady_clock::now();
        mergeSort(d_5000, 5000);
        t = binarySearch(d_5000, 5000, "qxqu");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 10000:\t";
        s_t = chrono::steady_clock::now();
        mergeSort(d_10000, 10000);
        t = binarySearch(d_10000, 10000, "knac");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 50000:\t";
        s_t = chrono::steady_clock::now();
        mergeSort(d_50000, 50000);
        t = binarySearch(d_50000, 50000, "pjsa");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 100000:\t";
        s_t = chrono::steady_clock::now();
        mergeSort(d_100000, 100000);
        t = binarySearch(d_100000, 100000, "xyao");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";
    }

    if (option == 3) {
        mergeSort(d_100, 100);
        mergeSort(d_500, 500);
        mergeSort(d_1000, 1000);
        mergeSort(d_5000, 5000);
        mergeSort(d_10000, 10000);
        mergeSort(d_50000, 50000);
        mergeSort(d_100000, 100000);

        cout << "Array with a volume of 100:\t";
        auto s_t = chrono::steady_clock::now();
        int t = binarySearch(d_100, 100, "fgcj");
        auto e_t = chrono::steady_clock::now();
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 500:\t";
        s_t = chrono::steady_clock::now();
        t = binarySearch(d_500, 500, "sosl");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 1000:\t";
        s_t = chrono::steady_clock::now();
        t = binarySearch(d_1000, 1000, "iwsw");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 5000:\t";
        s_t = chrono::steady_clock::now();
        t = binarySearch(d_5000, 5000, "qxqu");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 10000:\t";
        s_t = chrono::steady_clock::now();
        t = binarySearch(d_10000, 10000, "knac");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 50000:\t";
        s_t = chrono::steady_clock::now();
        t = binarySearch(d_50000, 50000, "pjsa");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 100000:\t";
        s_t = chrono::steady_clock::now();
        t = binarySearch(d_100000, 100000, "xyao");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";
    }

    if (option == 4){
        multimap <string, Articles> m_100 = {}, m_500 = {}, m_1000 = {}, m_5000 = {}, m_10000 = {}, m_50000 = {}, m_100000 = {};


        for (int i = 0; i < 100; i++)
            m_100.insert(pair <string, Articles>(d_100[i].name, d_100[i]));

        for (int i = 0; i < 500; i++)
            m_500.insert(pair <string, Articles>(d_500[i].name, d_500[i]));

        for (int i = 0; i < 1000; i++)
            m_1000.insert(pair <string, Articles>(d_1000[i].name, d_1000[i]));

        for (int i = 0; i < 5000; i++)
            m_5000.insert(pair <string, Articles>(d_5000[i].name, d_5000[i]));

        for (int i = 0; i < 10000; i++)
            m_10000.insert(pair <string, Articles>(d_10000[i].name, d_10000[i]));

        for (int i = 0; i < 50000; i++)
            m_50000.insert(pair <string, Articles>(d_50000[i].name, d_50000[i]));

        for (int i = 0; i < 100000; i++)
            m_100000.insert(pair <string, Articles>(d_100000[i].name, d_100000[i]));

        cout << "Array with a volume of 100:\t";
        auto s_t = chrono::steady_clock::now();
        auto t = m_100.find("fgcj");
        auto e_t = chrono::steady_clock::now();
        auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 500:\t";
        s_t = chrono::steady_clock::now();
        t = m_500.find("sosl");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 1000:\t";
        s_t = chrono::steady_clock::now();
        t = m_1000.find("iwsw");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 5000:\t";
        s_t = chrono::steady_clock::now();
        t = m_5000.find("qxqu");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 10000:\t";
        s_t = chrono::steady_clock::now();
        t = m_10000.find("knac");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 50000:\t";
        s_t = chrono::steady_clock::now();
        t = m_50000.find("pjsa");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";

        cout << "Array with a volume of 100000:\t";
        s_t = chrono::steady_clock::now();
        t = m_100000.find("xyao");
        e_t = chrono::steady_clock::now();
        ns = std::chrono::duration_cast<std::chrono::nanoseconds>(e_t - s_t);
        cout << ns.count() << " nanoseconds\n";
    }
}
