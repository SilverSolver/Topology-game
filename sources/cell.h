#ifndef CELL_H
#define CELL_H

enum {EMPTY, WALL, EXIT}; // Отрицательные номера зарезервированы для случаев когда в
                          // ячейке находится рычаг. Тогда в type находится -номер рычага.

enum {NONE, LEFT, RIGHT, UP, DOWN};   // Сопоставим различным направлениям числа от 1 до 4

// Тут будем хранить информацию о ячейке лабиринта
class Cell
{
public:
    Cell(int type=EMPTY, int hasWormHole=NONE);
    int type;           // тип ячейки или -номер переключателя в ячейке.
    int hasWormHole;    // 0, если не имеет червоточины, 1-4 если имеет в направлении
                        // соотв. 1-4
};

#endif // CELL_H
