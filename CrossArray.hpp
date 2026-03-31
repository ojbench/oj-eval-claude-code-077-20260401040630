#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

namespace sjtu {
    class CrossArray {
    private:
        struct ArrayInfo {
            int* data;
            int size;

            ArrayInfo() : data(nullptr), size(0) {}
        };

        ArrayInfo* arrays;
        int capacity;
        int count;

    public:
        explicit CrossArray(int lines) : capacity(lines), count(0) {
            arrays = new ArrayInfo[capacity];
        }

        CrossArray(const CrossArray& o) : capacity(o.capacity), count(o.count) {
            arrays = new ArrayInfo[capacity];
            for (int i = 0; i < count; i++) {
                if (o.arrays[i].data != nullptr) {
                    arrays[i].size = o.arrays[i].size;
                    arrays[i].data = new int[arrays[i].size];
                    for (int j = 0; j < arrays[i].size; j++) {
                        arrays[i].data[j] = o.arrays[i].data[j];
                    }
                }
            }
        }

        CrossArray& WhichGreater(CrossArray& o) {
            int thisTotal = 0;
            for (int i = 0; i < count; i++) {
                thisTotal += arrays[i].size;
            }

            int oTotal = 0;
            for (int i = 0; i < o.count; i++) {
                oTotal += o.arrays[i].size;
            }

            if (thisTotal >= oTotal) {
                return *this;
            } else {
                return o;
            }
        }

        bool IsSame(const CrossArray& o) {
            return arrays == o.arrays;
        }

        bool InsertArrays(const int* Input, int size) {
            if (count >= capacity) {
                return false;
            }

            arrays[count].size = size;
            arrays[count].data = new int[size];
            for (int i = 0; i < size; i++) {
                arrays[count].data[i] = Input[i];
            }
            count++;
            return true;
        }

        void AppendArrays(const int* Input, int Line, int size) {
            int oldSize = arrays[Line].size;
            int newSize = oldSize + size;

            int* newData = new int[newSize];
            for (int i = 0; i < oldSize; i++) {
                newData[i] = arrays[Line].data[i];
            }
            for (int i = 0; i < size; i++) {
                newData[oldSize + i] = Input[i];
            }

            delete[] arrays[Line].data;
            arrays[Line].data = newData;
            arrays[Line].size = newSize;
        }

        void DoubleCrossLength() {
            int newCapacity = capacity * 2;
            ArrayInfo* newArrays = new ArrayInfo[newCapacity];

            for (int i = 0; i < count; i++) {
                newArrays[i].data = arrays[i].data;
                newArrays[i].size = arrays[i].size;
            }

            delete[] arrays;
            arrays = newArrays;
            capacity = newCapacity;
        }

        const int* AtArray(int i) {
            return arrays[i].data;
        }

        int& At(int i, int j) {
            return arrays[i].data[j];
        }

        ~CrossArray() {
            for (int i = 0; i < count; i++) {
                delete[] arrays[i].data;
            }
            delete[] arrays;
        }
    };
}

#endif
