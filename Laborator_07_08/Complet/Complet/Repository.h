#ifndef REPOSITORY_H
#define REPOSITORY_H

template <typename T>
class Repository {
private:
    T elements[100];  // Colecția de elemente (dimensiune fixă de 100)
    int currentSize;  // Numărul curent de elemente

public:
    // Constructor
    Repository() : currentSize(0) {}

    // Destructor (nu este necesar în cazul nostru, dar poate fi adăugat)
    ~Repository() {}

    // Adaugă un element în repository
    bool add(const T& element) {
        if (currentSize < 100) {  // Verificăm dacă mai este loc
            elements[currentSize] = element;
            currentSize++;
            return true;
        }
        return false;  // Dacă nu mai există loc, returnăm false
    }

    // Șterge un element la un anumit index
    bool remove(int index) {
        if (index >= 0 && index < currentSize) {
            for (int i = index; i < currentSize - 1; ++i) {
                elements[i] = elements[i + 1];
            }
            currentSize--;  // Diminuăm numărul de elemente
            return true;
        }
        return false;  // Dacă indexul nu este valid, returnăm false
    }

    // Obține un element după index
    T get(int index) const {
        if (index >= 0 && index < currentSize) {
            return elements[index];  // Returnează elementul valid
        }
        return T();  // Returnează un obiect implicit de tipul T dacă indexul nu este valid
    }

    // Obține numărul de elemente din repository
    int getSize() const {
        return currentSize;
    }

    // Obține toate elementele din repository
    T* getAll(int& size) const {
        size = currentSize;  // Setăm dimensiunea colecției
        return const_cast<T*>(elements);  // Returnăm pointerul la colecția de elemente
    }

    bool update(int index, const T& newElement) {
        if (index >= 0 && index < currentSize) {
            elements[index] = newElement;
            return true;
        }
        return false;
    }

    int find(const T& element) const {
        for (int i = 0; i < currentSize; ++i) {
            if (elements[i] == element)
                return i;
        }
        return -1;
    }
};

#endif
